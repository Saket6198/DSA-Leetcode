#include<bits/stdc++.h>
using namespace std;

class NoSingleton {
public:
    NoSingleton() { // default constructor with the same name as the class
        cout << "Singleton Constructor called. New Object created." << endl;
    }
};

int main(){
    NoSingleton* s1 = new NoSingleton();
    NoSingleton* s2 = new NoSingleton();
    cout<< (s1 == s2) << endl;
}