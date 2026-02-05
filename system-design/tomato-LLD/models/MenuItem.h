#ifndef MENUITEM_H
#define MENUITEM_H
#include<bits/stdc++.h>
using namespace std;

class MenuItem {
private:
    string prod_id;
    string name;
    int price;
public:
    MenuItem(const string& prod_id, const string& name, int price){
        this->prod_id = prod_id;
        this->name = name;
        this->price = price;
    }

    //Getters and setters
    string getCode() const {
        return prod_id;
    }

    void setCode(const string &c) {
        prod_id = c;
    }

    string getName() const {
        return name;
    }

    void setName(const string &n) {
        name = n;
    }

    int getPrice() const {
        return price;
    }

    void setPrice(int p) {
        price = p;
    }
};

#endif // MENUITEM_H