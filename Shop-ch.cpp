#include "Shop-ch.h"
#include <iostream>
using namespace std;

void Shop::show(Pet& pet, bool& gameRunning) {
    cout << "\n===== 歡迎光臨寵物商店 ====="
        << "\n1. 特級寵物糧 (20 金幣)  - 飽食度 +30 (飢餓度 -30), 快樂 +10"
        << "\n2. 豪華玩具包 (25 金幣)  - 快樂指數 +30"
        << "\n3. 強效清潔噴霧 (20 金幣)- 清潔程度 +50"
        << "\n4. 傳奇國王皇冠 (500 金幣)- 購買即可贏得遊戲勝利！"
        << "\n0. 離開商店"
        << "\n============================\n請輸入商品編號: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        if (pet.getCoins() >= 20) {
            pet.spendCoins(20);
            cout << " >> 嗷嗚！寵物開心地吃下了特級寵物糧。\n";
            pet.adjustHunger(-30);    // 飽食+30，等於飢餓-30
            pet.adjustHappiness(10);  // 快樂+10
        }
        else cout << " >> 金幣不足，買不起特級寵物糧。\n";
        break;

    case 2:
        if (pet.getCoins() >= 25) {
            pet.spendCoins(25);
            cout << " >> 寵物拿到新玩具，玩得不亦樂乎！\n";
            pet.adjustHappiness(30);  // 快樂+30
        }
        else cout << " >> 金幣不足，買不起豪華玩具包。\n";
        break;

    case 3:
        if (pet.getCoins() >= 20) {
            pet.spendCoins(20);
            cout << " >> 咻咻！使用了強效清潔噴霧，變得香噴噴！\n";
            pet.clean(); // 呼叫兩次等於+50
            pet.clean();
        }
        else cout << " >> 金幣不足，買不起強效清潔噴霧。\n";
        break;

    case 4:
        if (pet.getCoins() >= 500 && !pet.hasCrown()) {
            pet.spendCoins(500);
            pet.obtainCrown();
            cout << "\n👑 恭喜！你成功購買了【傳奇國王皇冠】！贏得了最終的輝煌勝利！ 👑\n";
            gameRunning = false;
        }
        else cout << " >> 金幣不足，或是你已經擁有皇冠了。\n";
        break;

    case 0:
        cout << " >> 正在離開商店...\n";
        break;

    default:
        cout << " >> 無效的商品編號！\n";
        break;
    }
}