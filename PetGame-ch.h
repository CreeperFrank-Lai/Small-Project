#pragma once
#include "Pet-ch.h"
#include "Shop-ch.h"

class PetGame {
public:
    PetGame();           // 建構子
    void startGame();    // 統一啟動函式

private:
    bool _isRunning;     // 遊戲執行狀態標記
    Pet _pet;            // 組合關係（Composition）

    void showMenu() const;
    void handleInput(char input);
    void forceMedicalCheck();
};