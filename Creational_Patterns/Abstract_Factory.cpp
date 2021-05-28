#include <iostream>

using namespace std;

// abstract product class
class Button {
public:
    virtual void render() = 0;
};

class MacButton : public Button {
public:
    void render() {
        cout << "Rendering a button for MAC OS" << endl;
    }
};

class WinButton : public Button {
public:
    void render() {
        cout << "Rendering a button for Windows OS" << endl;
    }
};

// abstract product class
class Checkbox {
public:
    virtual void render() = 0;
};

class MacCheckbox : public Checkbox {
public:
    void render() {
        cout << "Rendering a checkbox for MAC OS" << endl;
    }
};

class WinCheckbox : public Checkbox {
public:
    void render() {
        cout << "Rendering a checkbox for Windows OS" << endl;
    }
};

// abstract creator class
class GUIFactory {
public:
    Button* createButton() = 0;
    Checkbox* createCheckbox() = 0;
};

class MacFactory : public GUIFactory {
public:
    Button* createButton() {
        return new MacButton();
    }

    Checkbox* createCheckbox() {
        return new MacCheckbox();
    }
};

class WinFactory : public GUIFactory {
public:
    Button* createButton() {
        return new WinButton();
    }

    Checkbox* createCheckbox() {
        return new WinCheckbox();
    }
};

class Application {
public:

    GUIFactory* factory;
    Button* button;
    Checkbox* checkbox;

    Application(GUIFactory* factory) {
        this->factory = factory;
    }

    void createUI() {
        this->button = factory->createButton();
        this->checkbox = factory->createCheckbox();
    }

    void render() {
        this->button->render();
        this->checkbox->render();
    }
};

int main () {

    int os;
    cout << "Choose your OS (1 for MACOS, 2 for Windows):";
    cin >> os;

    Application* app = nullptr;
    if (os == 1) {
        app = new Application(new MacFactory());
    }
    else if (os == 2) {
        app = new Application(new WinFactory());
    }

    app->createUI();
    app->render();

    return 0;
}