// Reference:
// https://refactoring.guru/design-patterns/strategy

#include <iostream>
#include <string>

using namespace std;

class IRouteStrategy {
public:
    virtual void buildRoute(string positionA, string positionB) = 0;
};

class CarRouteStrategy : public IRouteStrategy {
public:
    void buildRoute(string positionA, string positionB) {
        cout << "Driving from " << positionA << " to " << positionB << endl;
    }
};

class BikeRouteStrategy : public IRouteStrategy {
public:
    void buildRoute(string positionA, string positionB) {
        cout << "Riding from " << positionA << " to " << positionB << endl;
    }
};


class Navigator {
public:
    IRouteStrategy* routeStrategy;

    void setRouteStrategy(IRouteStrategy* strategy) {
        routeStrategy = strategy;
    }

    void execute(string positionA, string positionB) {
        routeStrategy->buildRoute(positionA, positionB);
    }
};

int main() {

    string positionA = "Taipei";
    string positionB = "Taichung";

    Navigator* navA = new Navigator();
    navA->setRouteStrategy(new CarRouteStrategy());
    navA->execute(positionA, positionB);

    Navigator* navB = new Navigator();
    navB->setRouteStrategy(new BikeRouteStrategy());
    navB->execute(positionB, positionA);

    return 0;
}