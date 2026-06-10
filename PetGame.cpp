#include "PetGame.h"
#include <iostream>
using namespace std;

PetGame::PetGame() : _pet("Unnamed"), _isRunning(false) {}

void PetGame::startGame() {
    _isRunning = true;

    string name;
    cout << "Please enter your pet's name: ";
    getline(cin, name);
    _pet = Pet(name);

    while (_isRunning) {
        _pet.timePass(1);
        _pet.showStatus();
        forceMedicalCheck();

        if (!_isRunning) break;

        showMenu();
        char input;
        cin >> input;
        handleInput(input);
        cin.ignore();
    }
    cout << "Game progress saved. Goodbye!\n";
}

void PetGame::forceMedicalCheck() {
    while (_pet.isSick()) {
        cout << "\n🚨 Emergency! "
            << _pet.getName() << " is seriously ill and must see a doctor immediately! 🚨\n";
        _pet.showStatus();

        cout << "[Choose medical treatment:]\n"
            << "1. Spend 20 coins to see a doctor\n"
            << "2. Force the pet to perform for money (if you lack coins)\n"
            << "3. End the game (abandon)\n"
            << "Enter choice > ";

        char cmd;
        cin >> cmd;

        if (cmd == '1') {
            _pet.seeDoctor();
        }
        else if (cmd == '2') {
            _pet.perform();
        }
        else if (cmd == '3') {
            _isRunning = false;
            break;
        }
        else {
            cout << " >> Invalid command, please try again!\n";
        }
    }
}

void PetGame::showMenu() const {
    cout << "\n===== Interaction & Economy System ====="
        << "\n[F] Feed (cost 5 coins)"
        << "\n[P] Play"
        << "\n[C] Clean"
        << "\n[A] Perform (+15 coins)"
        << "\n[D] See doctor (cost 20 coins)"
        << "\n[S] Enter pet shop"
        << "\n[Q] Quit game"
        << "\n========================================\nEnter command > ";
}

void PetGame::handleInput(char input) {
    switch (toupper(input)) {
    case 'F': _pet.feed(); break;
    case 'P': _pet.play(); break;
    case 'C': _pet.clean(); break;
    case 'A': _pet.perform(); break;
    case 'D':
        if (!_pet.seeDoctor()) {
            cout << " >> Not enough coins to see a doctor!\n";
        }
        break;
    case 'S':
        Shop::show(_pet, _isRunning);
        break;
    case 'Q': _isRunning = false; break;
    default:
        cout << " >> Invalid command, please try again!\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}
