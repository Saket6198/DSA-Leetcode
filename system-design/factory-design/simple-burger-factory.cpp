#include<bits/stdc++.h>
using namespace std;

class Burger {
public:
    virtual void prepare() = 0; // Abstract method for preparing the burger
    virtual ~Burger() {} // Virtual destructor for proper cleanup
};

class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing a basic burger with lettuce, tomato, and cheese." << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing a standard burger with lettuce, tomato, cheese, and a beef patty." << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing a premium burger with lettuce, tomato, cheese, a beef patty, and bacon." << endl;
    }
};

class BurgerFactory {
public: 
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicBurger();
        }else if(type == "standard") {
            return new StandardBurger();
        }else if(type == "premium"){
            return new PremiumBurger();
        }else{
            cout << "Unknown burger type: " << type << endl;
            return nullptr; // Return nullptr for unknown types
        }
    }
};

int main() {
    string type = "standard";
    BurgerFactory* myBurgerFactory = new BurgerFactory(); // pointer to BurgerFactory instance 
    Burger* myBurger = myBurgerFactory->createBurger(type); // returns a pointer to the created burger
    myBurger->prepare();
}