#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Player {
    string name;
    string position;
    int goals;
    int matches;
    double rating;
};

void addPlayer(vector<Player>& team) {
    Player newPlayer;
    cout << "Введіть ім'я гравця: ";
    cin >> newPlayer.name;
    cout << "Введіть позицію гравця: ";
    cin >> newPlayer.position;
    cout << "Введіть кількість голів гравця: ";
    cin >> newPlayer.goals;
    cout << "Введіть кількість матчів гравця: ";
    cin >> newPlayer.matches;
    cout << "Введіть середній рейтинг гравця: ";
    cin >> newPlayer.rating;
    team.push_back(newPlayer);
    cout << "Гравець доданий!\n";
}

void displayPlayers(const vector<Player>& team) {
    if (team.empty()) {
        cout << "Список гравців порожній.\n";
        return;
    }

    cout << "Гравці команди:\n";
    for (const auto& player : team) {
        cout << "Ім'я: " << player.name << ", Позиція: " << player.position
             << ", Голи: " << player.goals << ", Матчі: " << player.matches
             << ", Рейтинг: " << player.rating << endl;
    }
}

void searchPlayersByPosition(const vector<Player>& team, const string& position) {
    bool found = false;
    for (const auto& player : team) {
        if (player.position == position) {
            cout << "Ім'я: " << player.name << ", Голи: " << player.goals
                 << ", Матчі: " << player.matches << ", Рейтинг: " << player.rating << endl;
            found = true;
        }
    }
    if (!found) cout << "Гравців на позиції " << position << " не знайдено.\n";
}

void updatePlayerStats(vector<Player>& team) {
    string name;
    cout << "Введіть ім'я гравця для оновлення даних: ";
    cin >> name;
    for (auto& player : team) {
        if (player.name == name) {
            cout << "Введіть нову кількість голів: ";
            cin >> player.goals;
            cout << "Введіть нову кількість матчів: ";
            cin >> player.matches;
            cout << "Введіть новий рейтинг: ";
            cin >> player.rating;
            cout << "Дані гравця оновлено!\n";
            return;
        }
    }
    cout << "Гравця з таким ім'ям не знайдено.\n";
}

void calculateTotalGoals(const vector<Player>& team) {
    int totalGoals = 0;
    for (const auto& player : team) {
        totalGoals += player.goals;
    }
    cout << "Загальна кількість голів команди: " << totalGoals << endl;
}

void findBestScorerAndPlayer(const vector<Player>& team) {
    if (team.empty()) {
        cout << "Список гравців порожній.\n";
        return;
    }

    const Player* bestScorer = &team[0];
    const Player* bestPlayer = &team[0];

    for (const auto& player : team) {
        if (player.goals > bestScorer->goals) {
            bestScorer = &player;
        }
        if (player.rating > bestPlayer->rating) {
            bestPlayer = &player;
        }
    }

    cout << "Найкращий бомбардир: " << bestScorer->name << " з " << bestScorer->goals << " голами.\n";
    cout << "Гравець з найвищим рейтингом: " << bestPlayer->name << " з рейтингом " << bestPlayer->rating << ".\n";
}

void bubbleSortByRating(vector<Player>& team) {
    for (size_t i = 0; i < team.size() - 1; ++i) {
        for (size_t j = 0; j < team.size() - i - 1; ++j) {
            if (team[j].rating < team[j + 1].rating) {
                swap(team[j], team[j + 1]);
            }
        }
    }
}

void formOptimalTeam(const vector<Player>& team) {
    if (team.empty()) {
        cout << "Список гравців порожній.\n";
        return;
    }

    cout << "Оптимальний склад команди (за рейтингом):\n";
    vector<Player> sortedTeam = team;

    bubbleSortByRating(sortedTeam);

    for (size_t i = 0; i < min((size_t)11, sortedTeam.size()); ++i) {
        cout << "Ім'я: " << sortedTeam[i].name << ", Позиція: " << sortedTeam[i].position
             << ", Рейтинг: " << sortedTeam[i].rating << endl;
    }
}


int main() {
    vector<Player> team;
    int choice;

    do {
        cout << "Меню:\n";
        cout << "1. Додати гравця\n";
        cout << "2. Вивести інформацію про гравців\n";
        cout << "3. Пошук гравців за позицією\n";
        cout << "4. Оновити дані гравця\n";
        cout << "5. Підрахувати загальну кількість голів\n";
        cout << "6. Знайти найкращого бомбардира та гравця\n";
        cout << "7. Сформувати оптимальний склад\n";
        cout << "8. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: addPlayer(team); break;
            case 2: displayPlayers(team); break;
            case 3: {
                string position;
                cout << "Введіть позицію для пошуку: ";
                cin >> position;
                searchPlayersByPosition(team, position);
                break;
            }
            case 4: updatePlayerStats(team); break;
            case 5: calculateTotalGoals(team); break;
            case 6: findBestScorerAndPlayer(team); break;
            case 7: formOptimalTeam(team); break;
            case 8: cout << "Вихід з програми.\n"; break;
            default: cout << "Неправильний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 8);

    return 0;
}

