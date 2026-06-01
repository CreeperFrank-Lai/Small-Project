#include "Shop.h"
#include <iostream>
using namespace std;

void Shop::show(Pet& pet, bool& gameRunning) {
    cout << "\n=== Pet Shop ==="
        << "\n1.  Premium Food (20 coins) - Satiety +30 (Hunger -30), Happiness +10"
        << "\n2.  Toy Pack (25 coins) - Happiness +30"
        << "\n3.  Clean Spray (20 coins) - Cleanliness +50"
        << "\n4.  Crown (500 coins) - Win the game"
        << "\n0. Exit shop"
        << "\n=====================\nChoice: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        if (pet.getCoins() >= 20) {
            pet.spendCoins(20);
            cout << " >> Yum! Premium food eaten.\n";
            pet.adjustHunger(-30);    // 飽食+30，等於飢餓-30
            pet.adjustHappiness(10);  // 快樂+10
        }
        else cout << " >> Not enough coins.\n";
        break;

    case 2:
        if (pet.getCoins() >= 25) {
            pet.spendCoins(25);
            cout << " >> Pet enjoyed new toys!\n";
            pet.adjustHappiness(30);  // 快樂+30
        }
        else cout << " >> Not enough coins.\n";
        break;

    case 3:
        if (pet.getCoins() >= 20) {
            pet.spendCoins(20);
            cout << " >> Clean spray used!\n";
            pet.clean(); // 清潔+50 (原本的clean一次是+25)
            pet.clean();
        }
        else cout << " >> Not enough coins.\n";
        break;

    case 4:
        if (pet.getCoins() >= 500 && !pet.hasCrown()) {
            pet.spendCoins(500);
            pet.obtainCrown();
            cout << "\n👑 You bought the CROWN! Victory achieved!\n";
            gameRunning = false;
        }
        else cout << " >> Not enough coins or already purchased.\n";
        break;

    case 0:
        cout << " >> Leaving shop.\n";
        break;

    default:
        cout << " >> Invalid option.\n";
        break;
    }
}