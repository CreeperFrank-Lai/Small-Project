#include "PetGame-ch.h"
#include <iostream>
using namespace std;

// 建構子初始化成員
PetGame::PetGame() : _pet("未命名"), _isRunning(false) {}

// 遊戲主循環
void PetGame::startGame() {
    _isRunning = true;

    // 設置寵物名字
    string name;
    cout << "請輸入寵物的名字: ";
    getline(cin, name);
    _pet = Pet(name);

    while (_isRunning) {
        _pet.timePass(1);  // 每小時自動變化
        _pet.showStatus();
        forceMedicalCheck();

        if (!_isRunning) break; // 防止在醫療檢查中選擇退出後仍跳出選單

        showMenu();
        char input;
        cin >> input;
        handleInput(input);
        cin.ignore();  // 清除輸入緩衝
    }
    cout << "遊戲進度已儲存。再見！\n";
}

// 強制醫療檢查 (已修正自動扣錢看醫生 Bug)
void PetGame::forceMedicalCheck() {
    while (_pet.isSick()) {
        cout << "\n🚨 !!! 緊急狀況 !!! "
            << _pet.getName() << " 生重病了，必須立刻看醫生 !!! 🚨\n";
        _pet.showStatus();

        cout << "【請選擇醫療處置：】\n"
            << "1. 花費 20 金幣看醫生\n"
            << "2. 讓寵物強行賣藝賺錢 (沒錢看醫生時使用)\n"
            << "3. 結束遊戲（無情棄養）\n"
            << "請輸入選擇 > ";

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
            cout << " >> 無效指令，請重新選擇！\n";
        }
    }
}

// 顯示互動選單
void PetGame::showMenu() const {
    cout << "\n===== 互動與經濟系統 ====="
        << "\n[F] 餵食 (花費 5 金幣)"
        << "\n[P] 陪牠玩耍"
        << "\n[C] 幫牠洗澡"
        << "\n[A] 讓牠賣藝賺錢 (+15 金幣)"
        << "\n[D] 帶牠看醫生 (花費 20 金幣)"
        << "\n[S] 進入寵物商店"
        << "\n[Q] 離開遊戲"
        << "\n==========================\n請輸入指令 > ";
}

// 输入处理
void PetGame::handleInput(char input) {
    switch (toupper(input)) {
    case 'F': _pet.feed(); break;
    case 'P': _pet.play(); break;
    case 'C': _pet.clean(); break;
    case 'A': _pet.perform(); break;
    case 'D':
        if (!_pet.seeDoctor()) {
            cout << " >> 金幣不足，無法看醫生！\n";
        }
        break;
    case 'S':
        Shop::show(_pet, _isRunning);
        break;
    case 'Q': _isRunning = false; break;
    default:
        cout << " >> 無效的指令，請重新輸入！\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}