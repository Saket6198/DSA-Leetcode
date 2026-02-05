#include<bits/stdc++.h>
using namespace std;

class Singleton {
private: 
    static Singleton* instance; // Static pointer to hold the single instance of the class
    // Private constructor to prevent instantiation from outside the class
    Singleton(){
        cout << "Singleton Constructor called. New Object created." << endl;
    }
public:
    static Singleton* getInstance() { // Static method to get the singleton instance
        // If instance is null, create a new instance
        if(instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;

int main(){
    Singleton *s1 = Singleton::getInstance(); // getInstance() returns a pointer to the singleton instance
    Singleton s2 = *Singleton::getInstance();
    cout << (s1 == &s2) << endl; // This will print 0 because s1 and s2 are different objects
}


