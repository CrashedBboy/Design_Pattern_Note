#include <iostream>
#include <string>

using namespace std;

class IGameController {
public:
    virtual void onKeyDown(int key) = 0;
};

class NormalGameController : public IGameController {
public:
    void onKeyDown(int key) {
        if (key == 1) {
            // jump
        }
        else if (key == 2) {
            // dash
        }
    }
};

class NullGameController : public IGameController {
public:
    void onKeyDown(int key) {
        // do nothing
    }
};

// client code
class Game {
public:
    void onUpdateGameStatus(string status) {
        if (status == 'game over') {
            delete this->controller;
            this->controller = new NullGameController();
        }
        else if (status == 'other') {
            // do other things...
        }
    }

    void onKeyDown(int key) {
        this->controller->onKeyDown(key);
    }

private:
    IGameController* controller;
};