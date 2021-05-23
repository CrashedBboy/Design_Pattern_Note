// Reference
// Refactoring Guru: https://refactoring.guru/design-patterns/observer
// Christopher Okhravi, Observer Pattern (ep 2): https://youtu.be/_BpmfnqjgzQ

#include <iostream>
#include <unordered_set>

using namespace std;

class IWeatherDisplay {
public:
    virtual void update(int temperature) = 0;
};

class IWeatherStation {
public:
    virtual void subscribe(IWeatherDisplay* display) = 0;
    virtual void unsubscribe(IWeatherDisplay* display) = 0;
    virtual void notify() = 0;
};

class MyWeatherStation : public IWeatherStation {
public:

    MyWeatherStation() {
        subscribers = unordered_set<IWeatherDisplay*>();
    }

    void subscribe(IWeatherDisplay* display) {
        if (subscribers.find(display) == subscribers.end()) {
            subscribers.insert(display);
        }
    }

    void unsubscribe(IWeatherDisplay* display) {
        subscribers.erase(display);
    }

    void notify() {
        for (auto& sub : subscribers) {
            sub->update(temperature);
        }
    }

    void setTemperature() {
        cout << "New temperature: ";
        cin >> temperature;
        notify();
    }

private:
    unordered_set<IWeatherDisplay*> subscribers;
    int temperature;
};

class PhoneWeatherDisplay : public IWeatherDisplay {
public:
    void update(int temperature) {
        display(temperature);
    }

    void display(int temperature) {
        cout << "Phone screen: " << temperature << "*C" << endl;
    }
};

class DesktopWeatherDisplay : public IWeatherDisplay {
public:
    void update(int temperature) {
        display(temperature);
    }

    void display(int temperature) {
        cout << "Computer screen: " << temperature << "*C" << endl;
    }
};

int main() {

    MyWeatherStation* station = new MyWeatherStation();
    PhoneWeatherDisplay* phone = new PhoneWeatherDisplay();
    DesktopWeatherDisplay* desktop = new DesktopWeatherDisplay();

    station->subscribe(phone);
    station->subscribe(desktop);

    station->setTemperature();

    return 0;
}