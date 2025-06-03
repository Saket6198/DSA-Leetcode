#include<bits/stdc++.h>
using namespace std;

// Component Interface: defines a common interface for Mario and all power-up decorators.

class Character {
public:
    virtual string getAbilities() = 0;
    virtual ~Character() {}
};

// Concrete Component: Basic Mario character with no power-ups.
class Mario : public Character {
public:
    string getAbilities() override {
        return "Mario";
    }
};

// Abstract Decorator: CharacterDecorator "is-a" Character and "has-a" Character.

class CharacterDecorator : public Character {
protected:
    Character* character;
public:
    CharacterDecorator(Character* ch) : character(ch) {}
};

// Concrete Decorator: Height-Increasing Power-Up.
class HeightUp : public CharacterDecorator {
public:
    HeightUp(Character* c) : CharacterDecorator(c) {}
      string getAbilities() override {
            return character->getAbilities() + " with Height Up";
    }    
};

// Concrete Decorator : Gun Power-Up.

class GunPowerUp : public CharacterDecorator {
public:
    GunPowerUp(Character* c) : CharacterDecorator(c) {}
    string getAbilities() override {
        return character->getAbilities() + " with Gun Power Up";
    }
    
};

// Concrete Decorator: Star Power-Up (temporary ability).

class StarPowerUp : public CharacterDecorator{
public:
    StarPowerUp(Character* c) : CharacterDecorator(c) {}
    
    string getAbilities() override {
        return character->getAbilities() + " with Star Power Up";
    }  
};

int main(){
    Character* mario = new Mario();
    cout<< "Basic Character: " << mario->getAbilities() << endl;

    mario = new HeightUp(mario);
    cout<< "After Height Up: " << mario->getAbilities() << endl;

    mario = new GunPowerUp(mario);
    cout<< "After Gun Power Up: " << mario->getAbilities() << endl;

    mario = new StarPowerUp(mario);
    cout<< "After Star Power Up: " << mario->getAbilities() << endl;

    delete mario;
}