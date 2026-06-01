#pragma once
#include "Pet.h"
#include "Shop.h"

class PetGame {
public:
    PetGame();          // 建構子
    void startGame();    // 統一啟動函式

private:
    bool _isRunning;
    Pet _pet;           // 組合關係（Composition）

    void showMenu() const;
    void handleInput(char input);
    void forceMedicalCheck();
};