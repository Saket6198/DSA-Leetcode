#include<bits/stdc++.h>
#include<mutex>
using namespace std;

class Singleton {
private:
    static Singleton* instance; // Static pointer to hold the single instance of the class
    static mutex mtx; // Mutex for thread safety
    // Private constructor to prevent instantiation from outside the class
    Singleton() {
        cout << "Singleton Constructor called. New Object created." << endl;
    }

public:
    static Singleton* getInstance(){
        if(instance == nullptr){
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr) {  // Second check (after acquiring lock)
                instance = new Singleton();
            }
        }
        return instance;
    }
};
 
// Initialize static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}