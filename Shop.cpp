#include "Shop.h"
#include <iostream>
using namespace std;

void Shop::show(Pet& pet, bool& gameRunning) {
    cout << "\n===== Welcome to the Pet Shop ====="
        << "\n1. Premium Pet Food (20 coins)  - Hunger -30, Happiness +10"
        << "\n2. Deluxe Toy Pack (25 coins)   - Happiness +30"
        << "\n3. Strong Cleaning Spray (20 coins) - Cleanliness +50"
        << "\n4. Legendary King’s Crown (500 coins) - Buy to win the game!"
        << "\n0. Exit shop"
        << "\n=====================================\nEnter item number: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        if (pet.getCoins() >= 20) {
            pet.spendCoins(20);
            cout << " >> Yum! Your pet happily ate the premium food.\n";
            pet.adjustHunger(-30);
            pet.adjustHappiness(10);
        }
        else cout << " >> Not enough coins to buy premium food.\n";
        break;

    case 2:
        if (pet.getCoins() >= 25) {
            pet.spendCoins(25);
            cout << " >> Your pet got new toys and is thrilled!\n";
            pet.adjustHappiness(30);
        }
        else cout << " >> Not enough coins to buy deluxe toy pack.\n";
        break;

    case 3:
        if (pet.getCoins() >= 20) {
            pet.spendCoins(20);
            cout << " >> Spray! Your pet smells fresh and clean!\n";
            pet.clean(); // +25
            pet.clean(); // another +25, total +50
        }
        else cout << " >> Not enough coins to buy cleaning spray.\n";
        break;

    case 4:
        if (pet.getCoins() >= 500 && !pet.hasCrown()) {
            pet.spendCoins(500);
            pet.obtainCrown();
            cout << "\n👑 Congratulations! You bought the Legendary King’s Crown and achieved ultimate victory! 👑\n";
            gameRunning = false;
        }
        else cout << " >> Not enough coins, or you already own the crown.\n";
        break;

    case 0:
        cout << " >> Leaving the shop...\n";
        break;

    default:
        cout << " >> Invalid item number!\n";
        break;
    }
}
