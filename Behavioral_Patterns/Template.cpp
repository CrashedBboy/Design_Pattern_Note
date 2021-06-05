#include <iostream>
#include <string>

using namespace std;

// abstract class
class Record {
public:
    void save() {
        this->validate();
        this->beforeSave();

        // saving to DB

        this->afterSave();
    }

    virtual void validate() = 0;
    virtual void beforeSave() = 0;
    virtual void afterSave() = 0;
};

// class using the template
class User : public Record {

    void validate() {
        cout << "Check user validility" << endl;
    }

    void beforeSave() {
        cout << "Convert special character in user name" << endl;
    }

    void afterSave() {
        // doing nothing is allowed.
    }
};

// class using the template
class Post : public Record {

    void validate() {
        cout << "Check post validility" << endl;
    }

    void beforeSave() {
        // doing nothing is allowed.
    }

    void afterSave() {
        cout << "Posting it to timeline" << endl;
    }
};

// client code
int main() {

    User* user = new User();
    user->save();

    Post* post = new Post();
    post->save();

    return 0;
}