#pragma once
#include <string>
using namespace std;

class Pet {
public:
    explicit Pet(const string& name);

    // Pet actions
    bool feed();
    void perform();
    void play();
    void clean();
    bool seeDoctor();
    void showStatus() const;
    void timePass(int hours);

    // Getters
    bool isSick() const { return _isSick; }
    int getCoins() const { return _coins; }
    const string& getName() const { return _name; }

    // Economy system
    void spendCoins(int amount) { _coins -= amount; }
    bool hasCrown() const { return _hasCrown; }
    void obtainCrown() { _hasCrown = true; }

    // Adjust values
    void adjustHunger(int amount);
    void adjustHappiness(int amount);

private:
    string _name;       // Pet name
    int _hunger;        // Hunger level
    int _happiness;     // Happiness level
    int _cleanliness;   // Cleanliness level
    int _coins;         // Coins
    bool _isSick;       // Sick status
    bool _hasCrown;     // Crown possession

    // Health check
    void checkHealth();
};
