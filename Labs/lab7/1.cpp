#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int gradeCount;
    double *grades;
};

bool studentExists(const Student *students, int studentCount, const string &name) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].name == name) {
            return true;
        }
    }
    return false;
}

void addStudent(Student *&students, int &studentCount) {
    string newName;
    cout << "Введіть ім'я студента: ";
    cin >> newName;

    if (studentExists(students, studentCount, newName)) {
        cout << "Студент з таким ім'ям вже існує!" << endl;
        return;
    }

    Student *newStudents = new Student[studentCount + 1];

    for (int i = 0; i < studentCount; i++) {
        newStudents[i] = students[i];
    }

    newStudents[studentCount].name = newName;

    cout << "Введіть кількість оцінок: ";
    cin >> newStudents[studentCount].gradeCount;

    newStudents[studentCount].grades = new double[newStudents[studentCount].gradeCount];
    for (int i = 0; i < newStudents[studentCount].gradeCount; i++) {
        cout << "Введіть оцінку " << i + 1 << ": ";
        cin >> newStudents[studentCount].grades[i];
    }

    delete[] students;
    students = newStudents;
    studentCount++;

    cout << "Студента додано!" << endl;
}

void removeStudent(Student *&students, int &studentCount) {
    string nameToRemove;
    cout << "Введіть ім'я студента, якого потрібно видалити: ";
    cin >> nameToRemove;

    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].name == nameToRemove) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Студента з таким ім'ям не знайдено!" << endl;
        return;
    }

    Student *newStudents = new Student[studentCount - 1];
    for (int i = 0, j = 0; i < studentCount; i++) {
        if (i == index) {
            delete[] students[i].grades;
            continue;
        }
        newStudents[j++] = students[i];
    }

    delete[] students;
    students = newStudents;
    studentCount--;

    cout << "Студента видалено!" << endl;
}

void calculateAverageGrade(const Student *students, int studentCount) {
    if (studentCount == 0) {
        cout << "Список студентів порожній!" << endl;
        return;
    }

    string studentName;
    cout << "Введіть ім'я студента для обчислення середнього балу: ";
    cin >> studentName;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].name == studentName) {
            if (students[i].gradeCount == 0) {
                cout << "У студента немає оцінок!" << endl;
                return;
            }

            double total = 0.0;
            for (int j = 0; j < students[i].gradeCount; j++) {
                total += students[i].grades[j];
            }

            double average = total / students[i].gradeCount;
            cout << "Середній бал студента " << students[i].name << ": " << average << endl;
            return;
        }
    }

    cout << "Студента з таким ім'ям не знайдено!" << endl;
}

void displayStudents(const Student *students, int studentCount) {
    if (studentCount == 0) {
        cout << "Список студентів порожній!" << endl;
        return;
    }

    cout << "Список студентів з оцінками:\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "Ім'я: " << students[i].name << ", Оцінки: ";
        for (int j = 0; j < students[i].gradeCount; j++) {
            cout << students[i].grades[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Student *students = nullptr;
    int studentCount = 0;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Додати студента\n";
        cout << "2. Видалити студента\n";
        cout << "3. Показати список студентів\n";
        cout << "4. Обчислити середній бал\n";
        cout << "5. Завершити\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                removeStudent(students, studentCount);
                break;
            case 3:
                displayStudents(students, studentCount);
                break;
            case 4:
                calculateAverageGrade(students, studentCount);
                break;
            case 5:
                cout << "Програма завершена." << endl;
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 5);

    // Видалення усіх студентів (для пам'яті)
    for (int i = 0; i < studentCount; i++) {
        delete[] students[i].grades;
    }
    delete[] students;

    return 0;
}

