#include <iostream>

using namespace std;

// abstract interface
class GateState {
public:
    virtual void pay() = 0;
    virtual void enter() = 0;
};

class Gate {
public:
    Gate(GateState* initial) {
        this->state = initial;
    }
    void pay() {
        this->state->pay();
    }
    void enter() {
        this->state->enter();
    }

    // state transition
    void changeState(GateState* state) {
        this->state = state;
    }

private:
    GateState* state;
};

class OpenGateState {
public:
    OpenGateState(Gate* g) {
        this->gate = g;
    }

    void pay() {
        // do nothing
    }

    void enter() {
        // lock the gate
        // this->gate->lock();

        // change state
        this->gate->changeState(new CloseGateState(this->gate));
    }
private:
    Gate* gate;
};

class CloseGateState {
public:
    CloseGateState (Gate* g) {
        this->gate = g;
    }

    void pay() {
        // this->gate->validate();
        // this->gate->open();

        // change state
        this->gate->changeState(new OpenGateState(this->gate));
    }

    void enter() {
        // do nothing
    }
private:
    Gate* gate;
};