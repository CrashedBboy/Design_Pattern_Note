#include <iostream>

using namespace std;

class Beverage {
public:
    virtual int getPrice() = 0;
};

class Coffee : public Beverage {
public:
    int getPrice() {
        return 30;
    }
};

class Tea : public Beverage {
public:
    int getPrice() {
        return 15;
    }
};

class AddOnDecorator : public Beverage {
public:
    Beverage* beverage;

    AddOnDecorator(Beverage* b) : beverage(b) {}

    int getPrice() {
        return beverage->getPrice();
    }
};

class Milk : public AddOnDecorator {
public:
    Milk(Beverage* b) : AddOnDecorator(b) {}

    int getPrice() {
        return 30 + beverage->getPrice();
    }
};

class Chocolate : public AddOnDecorator {
public:
    Chocolate(Beverage* b) : AddOnDecorator(b) {}

    int getPrice() {
        return 12 + beverage->getPrice();
    }
};

int main() {

    // Suppose we would like to order a cup of milk tea
    cout << (new Milk(new Tea()))->getPrice() << endl;

    // Coffee + Milk + Chocolate
    cout << (new Milk(new Chocolate(new Coffee())))->getPrice() << endl;

    // Coffee + tons of Milk
    cout << (new Milk(new Milk(new Milk(new Coffee()))))->getPrice() << endl;

    return 0;
}