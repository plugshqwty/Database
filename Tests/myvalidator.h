#ifndef MYVALIDATOR_H
#define MYVALIDATOR_H

#include <string>
#include <regex>

using namespace std;

class MyValidator {
private:
    bool hasMinimumLength(const string &password){
        return password.length() >= 8;
    }
    bool hasUppercaseLetter(const string &password){
        regex reg("[A-Z]");
        return regex_search(password, reg);
    }
    bool hasLowercaseLetter(const string &password){
        regex reg("[a-z]");
        return regex_search(password, reg);
    }
    bool hasDigit(const string &password){
        regex reg("[0-9]");
        return regex_search(password, reg);
    }

public:
    bool validatePassword(const string &password){
        return (hasMinimumLength(password) && hasUppercaseLetter(password) && hasLowercaseLetter(password) && hasDigit(password));
    }

    bool validateLogin(const string& login) {
        return login.length() >= 5 && login.length() <= 20 && (hasUppercaseLetter(login) || hasLowercaseLetter(login));
    }
};

#endif // MYVALIDATOR_H
