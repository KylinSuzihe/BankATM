#include "user.h"
#include <cstring>
#include <iostream>
using namespace std;
#include <QMessageBox>

User::User() {}

User::User(string id, string password) {
    this -> id = id;
    this -> password = password;
    this -> money = 0;
    this -> dwrecords = new DWRecords();
}

int User::getMoney() {
    return this -> money;
}

string User::getId() {
    return this -> id;
}

string User::getPassword() {
    return this -> password;
}

void User::setId(string id) {
    this -> id = id;
}

void User::setPassword(string password) {
    this -> password = password;
}

void User::setMoney(int money) {
    this -> money = money;
}

void User::saveMoney(int money, string time) {
    this -> money += money;
    this -> setDerecords(money, time);
}
bool User::withdrawalMoney(int money, string time) {
    if (this -> money < money) return 0;
    this -> money -= money;
    this -> setDerecords(-money, time);
    return 1;
}
void User::setDerecords(int x, string time) {
    dwrecords->insert(x, time);
}

int User::getDerecords(string st, string et) {
    return dwrecords->search(st, et);
}
DWRecords* User::getDWRecords() {
    return this -> dwrecords;
}
