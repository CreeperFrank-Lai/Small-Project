#include "Pet.h"
#include <iostream>
#include <algorithm>
using namespace std;

Pet::Pet(const string& name) :
    _name(name),
    _hunger(70),
    _happiness(40),
    _cleanliness(30),
    _coins(30),
    _isSick(false),
    _hasCrown(false) {
}

void Pet::checkHealth() {
    _isSick = (_hunger >= 75 && _cleanliness <= 20); // Modified condition
}

bool Pet::feed() {
    if (_coins < 5) {
        cout << " >> Feeding requires 5 coins! Not enough coins!\n";
        return false;
    }
    _coins -= 5;
    _hunger = max(0, _hunger - 15);
    _happiness = min(100, _happiness + 5);
    cout << " >> " << _name << " enjoyed a delicious meal!\n";
    checkHealth();
    return true;
}

void Pet::perform() {
    _coins += 15;
    _happiness = max(0, _happiness - 25);
    _hunger = min(100, _hunger + 20);
    _cleanliness = max(0, _cleanliness - 15);
    cout << " >> " << _name << " performed on the street and earned 15 coins 💰\n";
    checkHealth();
}

void Pet::play() {
    _happiness = min(100, _happiness + 15);
    _hunger = min(100, _hunger + 10);
    cout << " >> " << _name << " had fun playing!\n";
    checkHealth();
}

void Pet::clean() {
    _cleanliness = min(100, _cleanliness + 25);
    cout << " >> " << _name << " took a refreshing bath!\n";
    checkHealth();
}

bool Pet::seeDoctor() {
    if (_coins < 20) {
        cout << " >> Seeing a doctor requires 20 coins! Not enough coins!\n";
        return false;
    }
    _coins -= 20;
    _isSick = false;

    // Restore to good state
    _hunger = 50;
    _cleanliness = 70;
    _happiness = 70;

    cout << " >> " << _name << " recovered and is now in good condition!\n";
    showStatus();
    return true;
}

void Pet::timePass(int hours) {
    _hunger = min(100, _hunger + 5 * hours);
    _happiness = max(0, _happiness - 3 * hours);
    _cleanliness = max(0, _cleanliness - 3 * hours);
    checkHealth();
}

void Pet::showStatus() const {
    cout << "\n=== " << _name << "'s Status Panel ==="
        << "\n| Coins:        " << _coins
        << "\n| Hunger:       " << _hunger << "/100 (higher means hungrier)"
        << "\n| Happiness:    " << _happiness << "/100"
        << "\n| Cleanliness:  " << _cleanliness << "/100"
        << "\n| Health:       " << (_isSick ? "[Sick 💢]" : "Healthy 😊")
        << "\n====================================\n";
}

void Pet::adjustHunger(int amount) {
    _hunger = max(0, min(100, _hunger + amount));
    checkHealth();
}

void Pet::adjustHappiness(int amount) {
    _happiness = max(0, min(100, _happiness + amount));
    checkHealth();
}
