#pragma once
#include <string>
using namespace std;

class Pet {
public:
    // 建構子：限定必須傳入寵物名字
    explicit Pet(const string& name);

    // 寵物互動與照顧方法
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

    // === 商店系統所需的方法 ===
    void spendCoins(int amount) { _coins -= amount; }
    bool hasCrown() const { return _hasCrown; }
    void obtainCrown() { _hasCrown = true; }

    // 直接調整數值的方法（供商店道具使用）
    void adjustHunger(int amount);
    void adjustHappiness(int amount);

private:
    string _name;       // 寵物名字
    int _hunger;        // 飢餓度
    int _happiness;     // 快樂度
    int _cleanliness;   // 清潔度
    int _coins;         // 金幣數量
    bool _isSick;       // 是否生病
    bool _hasCrown;     // 是否擁有皇冠（通關道具）

    // 內部健康檢查機制
    void checkHealth();
};