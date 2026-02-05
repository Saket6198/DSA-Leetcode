#ifndef User_H
#define User_H
#include "Cart.h"
#include <bits/stdc++.h>
using namespace std;

class User {
private:
    string name;
    string userId;
    string address;
    Cart* cart;

public: 
    User(int userId, const string& name, const string& address){
        this->userId = to_string(userId);
        this->name = name;
        this->address = address;
        cart = new Cart();
    }
    ~User() {
        delete cart;
        cout << "Destroying User: " << name << endl;
    }

    void setName(const string& n) {
        name = n;
    }
    string getName() const {
        return name;
    }
    string getAddress() const {
        return address;
    }
    void setAddress(const string& addr) {
        address = addr;
    }

    Cart* getCart() const {
        return cart;
    }
};

#endif