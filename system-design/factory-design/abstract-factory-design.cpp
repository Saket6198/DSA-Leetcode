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

/* Product2 --> Garlic Bread  */

class GarlicBread{
public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() {} // Virtual destructor for proper cleanup
};

class BasicGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing basic garlic bread with butter and garlic." << endl;   
    }    
};

class CheeseGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing cheese garlic bread with butter, garlic, and cheese." << endl;   
    }
};

class BasicWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing basic wheat garlic bread with butter and garlic." << endl;   
    }    
};

class CheeseWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing cheese wheat garlic bread with butter, garlic, and cheese." << endl;   
    }
};

// Abstract Factory Interface
class MealFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;
};

class SinghFactory : public MealFactory {
public: 
    Burger* createBurger(string& type) override {
        if(type == "basic"){
            BasicBurger* burger = new BasicBurger();
            burger->prepare();
            return burger;
        }else if(type == "standard"){
            StandardBurger* burger = new StandardBurger();
            burger->prepare();
            return burger;
        }else if(type == "premium"){
            PremiumBurger* burger = new PremiumBurger();
            burger->prepare();
            return burger;
        }else{
            cout << "Invalid burger type for Singh Factory." << endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string& type) override {
        if(type == "basic"){
            BasicGarlicBread* bread = new BasicGarlicBread();
            bread->prepare();
            return bread;
        }else if(type == "cheese"){
            CheeseGarlicBread* bread = new CheeseGarlicBread();
            bread->prepare();
            return bread;
        }else{
            cout << "Invalid garlic bread type for Singh Factory." << endl;
            return nullptr;
        }
    }
};

class KingFactory : public MealFactory {
public:
    Burger* createBurger(string& type) override {
        if(type == "basic"){
            BasicWheatBurger* burger = new BasicWheatBurger();
            burger->prepare();
            return burger;
        }else if(type == "standard"){
            StandardWheatBurger* burger = new StandardWheatBurger();
            burger->prepare();
            return burger;
        }else if(type == "premium"){
            PremiumWheatBurger* burger = new PremiumWheatBurger();
            burger->prepare();
            return burger;
        }else{
            cout << "Invalid wheat burger type for King Factory." << endl;
            return nullptr;
        }
    }
    GarlicBread* createGarlicBread(string& type) override {
        if(type == "basic") {
            BasicWheatGarlicBread* bread = new BasicWheatGarlicBread();
            bread->prepare();
            return bread;
        }else if(type == "cheese") {
            CheeseWheatGarlicBread* bread = new CheeseWheatGarlicBread();
            bread->prepare();
            return bread;
        }else {
            cout << "Invalid wheat garlic bread type for King Factory." << endl;
            return nullptr;
        }
    }
};

int main(){
    string burgerType = "basic";
    string garlicBreadType = "cheese";

    MealFactory* mealFactory = new KingFactory();

    Burger* burger = mealFactory->createBurger(burgerType);
    GarlicBread* garlicBread = mealFactory->createGarlicBread(garlicBreadType);

    burger->prepare();
    garlicBread->prepare();


}