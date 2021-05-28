#include <iostream>
#include <string>

using namespace std;

// abstract product class
class Transportation {
public:
    virtual void delivery() = 0;
};

class Ship : public Transportation {
public:
    void delivery() {
        cout << "delivered by ship" << endl;
    }
};

class Car : public Transportation {
public:
    void delivery() {
        cout << "delivered by car" << endl;
    }
};

// abstract creator class
class Logistics {
public:
    virtual Transportation* createTransport() = 0;
};

class RoadLogistics {
public:
    Transportation* createTransport() {
        return new Car();
    }
};

class SeaLogistics {
public:
    Transportation* createTransport() {
        return new Ship();
    }
};


int main() {

    cout << "Delivery Logistics? (1 for sea, 2 for road):";

    // decide which product to generate based on configs, user inputs,etc
    int method;
    cin >> method;

    Transportation* trans = nullptr;
    switch (method) {
        case 1:
            trans = (new SeaLogistics()) -> createTransport();
            break;
        case 2:
            trans = (new RoadLogistics())->createTransport();
            break;
    }

    trans->delivery();

    return 0;
}