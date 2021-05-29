#include <iostream>

using namespace std;

// Receiver
class Light {
public:
    void turnOn() {
        cout << "Light on!" << endl;
    }
    void turnDown() {
        cout << "Light off!" << endl;
    }
};

// abstract command interface
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class TurnOnCommand : public Command {
public:
    TurnOnCommand(Light* receiver) {
        this->receiver = receiver;
    }
    void execute() {
        this->receiver->turnOn();
    }
    void undo() {
        this->receiver->turnDown();
    }
private:
    Light* receiver;
};

class TurnDownCommand : public Command {
public:
    TurnDownCommand(Light* receiver) {
        this->receiver = receiver;
    }
    void execute() {
        this->receiver->turnDown();
    }
    void undo() {
        this->receiver->turnOn();
    }
private:
    Light* receiver;
};

// Invoker
class RemoteController {
public:
    RemoteController(Command* turnOnCommand, Command* turnDownCommand) {
        this->turnOnCommand = turnOnCommand;
        this->turnDownCommand = turnDownCommand;
    }

    void turnOn() {
        this->turnOnCommand->execute();
    }

    void turnDown() {
        this->turnDownCommand->execute();
    }
private:
    Command* turnOnCommand;
    Command* turnDownCommand;
};

int main() {

    Light* bulb = new Light();
    RemoteController* controller = new RemoteController(new TurnOnCommand(bulb), new TurnDownCommand(bulb));

    controller->turnOn();
    controller->turnDown();
    controller->turnOn();
    controller->turnDown();

    return 0;
}