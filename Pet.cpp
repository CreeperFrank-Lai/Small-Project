#include "Pet.h"
#include <iostream>
#include <algorithm>  // 供 std::clamp 使用（雖然目前是用 max/min）
using namespace std;

// 嚴苛的初始狀態
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
    _isSick = (_hunger >= 85 || _cleanliness <= 20);
}

// 餵食需 5 金幣（飢餓-15，快樂+5）
bool Pet::feed() {
    if (_coins < 5) {
        cout << " >> Need 5 coins to feed!\n";
        return false;
    }
    _coins -= 5;
    _hunger = max(0, _hunger - 15);
    _happiness = min(100, _happiness + 5);
    cout << " >> " << _name << " ate food!\n";
    checkHealth(); // 數值改變，觸發健康檢查
    return true;
}

// 賣藝賺 15 金幣（快樂-25，飢餓+20，清潔-15）
void Pet::perform() {
    _coins += 15;
    _happiness = max(0, _happiness - 25);
    _hunger = min(100, _hunger + 20);
    _cleanliness = max(0, _cleanliness - 15);
    cout << " >> " << _name << " performed! Earned 15 coins\n";
    checkHealth(); // 數值改變，觸發健康檢查
}

// 玩耍（快樂+15，飢餓+10）
void Pet::play() {
    _happiness = min(100, _happiness + 15);
    _hunger = min(100, _hunger + 10);
    cout << " >> " << _name << " played happily!\n";
    checkHealth(); // 數值改變，觸發健康檢查
}

// 清潔（清潔+25）
void Pet::clean() {
    _cleanliness = min(100, _cleanliness + 25);
    cout << " >> " << _name << " took a bath!\n";
    checkHealth(); // 數值改變，觸發健康檢查
}

// 看病需 20 金幣（解除生病狀態）
bool Pet::seeDoctor() {
    if (_coins < 20) {
        cout << " >> Need 20 coins to see doctor!\n";
        return false;
    }
    _coins -= 20;
    _isSick = false;
    cout << " >> " << _name << " recovered!\n";
    return true;
}

// 每小時變化（飢餓+5，快樂-3，清潔-3）
void Pet::timePass(int hours) {
    _hunger = min(100, _hunger + 5 * hours);
    _happiness = max(0, _happiness - 3 * hours);
    _cleanliness = max(0, _cleanliness - 3 * hours);
    checkHealth();
}

// 顯示完整狀態
void Pet::showStatus() const {
    cout << "\n=== " << _name << "'s Status ==="
        << "\n| Coins:     " << _coins
        << "\n| Hunger:    " << _hunger << "/100"
        << "\n| Happiness: " << _happiness << "/100"
        << "\n| Clean:     " << _cleanliness << "/100"
        << "\n| Health:    " << (_isSick ? "[SICK]" : "Healthy")
        << "\n============================\n";
}

void Pet::adjustHunger(int amount) {
    // amount 為負數代表變飽（飢餓度減少）
    _hunger = max(0, min(100, _hunger + amount));
    checkHealth(); // 商店道具改變數值，觸發健康檢查
}

void Pet::adjustHappiness(int amount) {
    _happiness = max(0, min(100, _happiness + amount));
    checkHealth(); // 商店道具改變數值，觸發健康檢查
}