#pragma once
#pragma once
#include "Pet.h"
#include "Shop.h"

class PetGame {
public:
    PetGame();
    void startGame();

private:
    bool _isRunning;
    Pet _pet;

    void showMenu() const;
    void handleInput(char input);
    void forceMedicalCheck();
};
