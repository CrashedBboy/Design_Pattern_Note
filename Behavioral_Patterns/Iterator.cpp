#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UserIterator {
public:
    virtual User* next() = 0;
};

class UserCollection {
public:
    virtual Iterator* getIterator() = 0;
};

class User {
public:
    string sex;
    string name;
    User(string name, string sex): name(name), sex(sex) {}
};

class MaleUserIterator : public UserIterator {
public:
    int index;
    UserGroup* group;
    MaleUserIterator(UserGroup* group) : group (group) {}

    User* next() {

        while (index < (group->users.size()-1)) {
            index += 1;

            if (group->users[index]->sex == 'male') {
                return group->users[index];
            }
        }

        return nullptr;
    }
};

class FemaleUserIterator : public UserIterator {
public:
    int index;
    UserGroup* group;
    FemaleUserIterator(UserGroup* group) : group (group) {}

    User* next() {

        while (index < (group->users.size()-1)) {
            index += 1;

            if (group->users[index]->sex == 'female') {
                return group->users[index];
            }
        }

        return nullptr;
    }
};

class UserGroup : public UserCollection {
public:
    vector<User*> users;
    UserGroup(vector<User*> users) : users(users) {}
    Iterator* getIterator(string sex) {
        if (sex == 'male') {
            return new MaleUserIterator(this);
        }
        else {
            return new FemaleUserIterator(this);
        }
    }
};