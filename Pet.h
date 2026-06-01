#pragma once
#include <string>
using namespace std;

class Pet {
public:
    explicit Pet(const string& name);

    bool feed();
    void perform();
    void play();
    void clean();
    bool seeDoctor();
    void showStatus() const;
    void timePass(int hours);

    // 狀態訪問器（Getter）
    bool isSick() const { return _isSick; }
    int getCoins() const { return _coins; }
    const string& getName() const { return _name; }

    // === 新增：為了搭配商店系統所需的方法 ===
    void spendCoins(int amount) { _coins -= amount; }
    bool hasCrown() const { return _hasCrown; }
    void obtainCrown() { _hasCrown = true; }

    // 直接調整數值的方法（供商店道具使用）
    void adjustHunger(int amount);
    void adjustHappiness(int amount);

private:
    string _name;
    int _hunger;
    int _happiness;
    int _cleanliness;
    int _coins;
    bool _isSick;
    bool _hasCrown;     // 新增：是否擁有皇冠

    void checkHealth();
};