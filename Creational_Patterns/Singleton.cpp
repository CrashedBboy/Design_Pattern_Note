#include <iostream>

using namespace std;

class Government {

public:
    string president;
    string mayor;

    // delete default constructors
    Government(Government& other) = delete;
    void operator=(const Government& other) = delete;


    static Government* getInstance() {
        if (instance == nullptr) {
            instance = new Government();
        }
        return instance;
    }

private:

    Government() {
        this->president = "Adam";
        this->mayor = "Jimmy";
    }

    static Government* instance;
};

// In the case of a static class member, we initialize the static member independently, 
// with a separate statement outside the class declaration.
// That's because the static class member is stored separately rather than as part of an object.
Government* Government::instance = nullptr;

int main() {

    Government* gov = Government::getInstance();

    cout << gov->president << endl;
    cout << gov->mayor << endl;
    cout << gov << endl;

    Government* gov2 = Government::getInstance();
    cout << gov2 << endl;

    return 0;
}