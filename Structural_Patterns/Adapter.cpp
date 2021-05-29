#include <iostream>
#include <string>

using namespace std;

// adaptee class
class FahDisplayer {
public:
    void display(float degree) {
        cout << degree << "F" << endl;
    }
};

// abstract adapter interface
class ITarget {
public:
    virtual void request(float celsius) = 0;
};

class C2FAdapter : public ITarget {
public:
    FahDisplayer* adaptee;
    C2FAdapter(FahDisplayer* adaptee) {
        this->adaptee = adaptee;
    }

    void request(float celsius) {
        float fahrenheit = convert(celsius);
        this->adaptee->display(fahrenheit);
    }

    float convert(float celsius) {
        return celsius * 1.8 + 32;
    }
};

// client class
class CelThermometer {
public:
    void setDisplayer(ITarget* displayer) {
        this->displayer = displayer;
    }

    void display() {
        this->displayer->request(getTemperature());
    }

    float getTemperature() {
        float celcius;
        cout << "Enter degree in celcius:";
        cin >> celcius;

        return celcius;
    }
private:
    ITarget* displayer;
};

int main() {

    CelThermometer* sensor = new CelThermometer();
    FahDisplayer* screen = new FahDisplayer();
    C2FAdapter* adapter = new C2FAdapter(screen);

    // set adapter
    sensor->setDisplayer(adapter);

    sensor->display();

    return 0;
}