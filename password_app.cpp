/* password_app module */

#include <string>

using namespace std;

// password validation
bool is_password_valid(string password) {
    const string valid_password = "qwerty";
    bool status;

    if (password == valid_password) {
        status = true;
    } else {
        status = false;
    }

    return status;
}

// try counter
bool count_validation(int count, int max_count) {
    bool status;

    if (count < max_count) {
        status = true;
    } else {
        status = false;
    }

    return status;
}

// ask password
string ask_password(string greeting) {
    string password;

    cout << greeting << " ";
    cin >> password;
    cout << endl;
    return password;
}

// password check
void check_password() {
    string user_password;
    int count = 1;
    const int max_count = 3;

    user_password = ask_password("Введите пароль");

    while (!is_password_valid(user_password) && count_validation(count, max_count)) {
        cout << "Неа, не тот пароль." << endl;
        cout << "Осталось попыток: " << (max_count - count) << endl;
        count++;
        user_password = ask_password("Введите новый пароль");
    }
    if ( count_validation(count, max_count)) {
        cout << "Ок, пароль правильный." << endl;
    } else {
        cout << "У вас кончились попытки" << endl;
    }

}