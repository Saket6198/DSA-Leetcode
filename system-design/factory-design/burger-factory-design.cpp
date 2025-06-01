#include<bits/stdc++.h>
using namespace std;

class Burger {
public: 
    virtual void prepare() = 0;
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

class BasicWheatBurger : public Burger {
public: 
    void prepare() override {
        cout << "Preparing a basic wheat burger with lettuce, tomato, and cheese." << endl;   
    }
};

class StandardWheatBurger : public Burger {
public: 
    void prepare() override {
        cout << "Preparing a standard wheat burger with lettuce, tomato, cheese, and a beef patty." << endl;   
    }
};

class PremiumWheatBurger : public Burger {
public: 
    void prepare() override {
        cout << "Preparing a premium wheat burger with lettuce, tomato, cheese, a beef patty, and bacon." << endl;   
    }
};

// factory and it's concrete factories

class BurgerFactory {
public:
    virtual Burger* createBurger(string& type) = 0; // Abstract method for creating burgers  
};

class SinghBurgerFactory: public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if(type == "basic") {
            return new BasicBurger();
        } else if(type == "standard") {
            return new StandardBurger();
        } else if(type == "premium") {
            return new PremiumBurger();
        } else {
            cout << "Unknown burger type: " << type << endl;
            return nullptr; // Return nullptr for unknown types
        }
    }
};

class KingBurgerFactory: public BurgerFactory {
    Burger* createBurger(string& type) override {
        if(type == "basic") {
            return new BasicWheatBurger();
        } else if(type == "standard") {
            return new StandardWheatBurger();
        } else if(type == "premium") {
            return new PremiumWheatBurger();
        } else {
            cout << "Unknown burger type: " << type << endl;
            return nullptr; // Return nullptr for unknown types
        }
    }
};


int main() {
    string type, factoryType;
    cout << "Enter burger type (basic/standard/premium) and factoryType: ";
    cin >> type >> factoryType;
    if(factoryType == "singh") {
        BurgerFactory* myBurgerFactory = new SinghBurgerFactory();
        Burger* myBurger = myBurgerFactory->createBurger(type);
        myBurger->prepare();

    } else if(factoryType == "king") {
        BurgerFactory* myBurgerFactory = new KingBurgerFactory();
        auto myBurger = myBurgerFactory->createBurger(type);
        myBurger->prepare();
    } else {
        cout << "Unknown factory type: " << factoryType << endl;
        return 1; // Exit if unknown factory type
    }
}
