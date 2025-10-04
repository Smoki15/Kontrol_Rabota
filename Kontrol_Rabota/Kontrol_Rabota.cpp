#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

struct Task {
    string title;
    string priority;
    string description;
    string datetime;
};

void addTask(vector<Task>& tasks) {
    Task t;
    cin.ignore();
    cout << "Назва: ";
    getline(cin, t.title);
    cout << "Пріоритет (низький/середній/високий): ";
    getline(cin, t.priority);
    cout << "Опис: ";
    getline(cin, t.description);
    cout << "Дата і час виконання (наприклад 2025-10-05 14:30): ";
    getline(cin, t.datetime);
    tasks.push_back(t);
    cout << "Справу додано!\n";
}

void showTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Список справ порожній.\n";
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << "\n№" << i + 1 << "\n";
        cout << "Назва: " << tasks[i].title << endl;
        cout << "Пріоритет: " << tasks[i].priority << endl;
        cout << "Опис: " << tasks[i].description << endl;
        cout << "Дата і час: " << tasks[i].datetime << endl;
    }
}

void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Немає справ для видалення.\n";
        return;
    }
    int n;
    cout << "Введіть номер справи для видалення: ";
    cin >> n;
    if (n > 0 && n <= tasks.size()) {
        tasks.erase(tasks.begin() + n - 1);
        cout << "Справу видалено.\n";
    }
    else cout << "Невірний номер.\n";
}

void editTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Немає справ для редагування.\n";
        return;
    }
    int n;
    cout << "Введіть номер справи для редагування: ";
    cin >> n;
    if (n < 1 || n > tasks.size()) {
        cout << "Невірний номер.\n";
        return;
    }
    cin.ignore();
    cout << "Нова назва (або Enter щоб залишити): ";
    string tmp;
    getline(cin, tmp);
    if (!tmp.empty()) tasks[n - 1].title = tmp;
    cout << "Новий пріоритет: ";
    getline(cin, tmp);
    if (!tmp.empty()) tasks[n - 1].priority = tmp;
    cout << "Новий опис: ";
    getline(cin, tmp);
    if (!tmp.empty()) tasks[n - 1].description = tmp;
    cout << "Нова дата і час: ";
    getline(cin, tmp);
    if (!tmp.empty()) tasks[n - 1].datetime = tmp;
    cout << "Справу змінено.\n";
}

void searchTask(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Список порожній.\n";
        return;
    }
    cin.ignore();
    string key;
    cout << "Введіть слово для пошуку: ";
    getline(cin, key);

    bool found = false;
    for (auto& t : tasks) {
        if (t.title.find(key) != string::npos ||
            t.priority.find(key) != string::npos ||
            t.description.find(key) != string::npos ||
            t.datetime.find(key) != string::npos) {
            cout << "\nНазва: " << t.title << "\nПріоритет: " << t.priority
                << "\nОпис: " << t.description << "\nДата і час: " << t.datetime << "\n";
            found = true;
        }
    }
    if (!found) cout << "Нічого не знайдено.\n";
}

void sortTasks(vector<Task>& tasks) {
    int ch;
    cout << "1 - Сортувати за пріоритетом\n";
    cout << "2 - Сортувати за датою і часом\n";
    cout << "Ваш вибір: ";
    cin >> ch;

    if (ch == 1) {
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.priority < b.priority;
            });
    }
    else if (ch == 2) {
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.datetime < b.datetime;
            });
    }
    cout << "Відсортовано.\n";
}

int main() {
    system("chcp 1251>null");
    vector<Task> tasks;
    int choice;
    do {
        cout << "\n=== СПИСОК СПРАВ ===\n";
        cout << "1. Додати справу\n";
        cout << "2. Відобразити список\n";
        cout << "3. Видалити справу\n";
        cout << "4. Редагувати справу\n";
        cout << "5. Пошук справ\n";
        cout << "6. Сортування\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        switch (choice) {
        case 1: addTask(tasks); break;
        case 2: showTasks(tasks); break;
        case 3: deleteTask(tasks); break;
        case 4: editTask(tasks); break;
        case 5: searchTask(tasks); break;
        case 6: sortTasks(tasks); break;
        }
    } while (choice != 0);
    cout << "До побачення!\n";
    return 0;
}
