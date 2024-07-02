#ifndef MYVALIDATOR_H
#define MYVALIDATOR_H

#include <QString>
#include <QRegularExpression>

class MyValidator {
private:
    bool hasMinimumLength(const QString &password){
        return password.length() >= 8;
    }
    bool hasUppercaseLetter(const QString &password){
        QRegularExpression regex("[A-Z]");
        return password.contains(regex);
    }
    bool hasLowercaseLetter(const QString &password){
        QRegularExpression regex("[a-z]");
        return password.contains(regex);
    }
    bool hasDigit(const QString &password){
        QRegularExpression regex("[0-9]");
        return password.contains(regex);
    }

public:
    bool validatePassword(const QString &password){
        return (hasMinimumLength(password) && hasUppercaseLetter(password) && hasLowercaseLetter(password) && hasDigit(password));
    }

    bool validateLogin(const QString& login) {
        return login.length() >= 5 && login.length() <= 20 && (hasUppercaseLetter(login) || hasLowercaseLetter(login));
    }
};

#endif // MYVALIDATOR_H
