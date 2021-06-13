#include <iostream>
#include <string>
#include <vector>

using namespace std;

// abstract interface
class TodoList {
public:
    virtual string getHTML() = 0;
};

class Todo : public TodoList {
public:
    Todo(string t): text(t) {}
    string getHTML() {
        return this->text;
    }
private:
    string text;
};

class Project : public TodoList {
public:
    Project(vector<TodoList*> todos) : todos(todos) {}
    string getHTML() {
        string html = "<ul>";

        for (auto& t : this->todos) {
            html += "<li>";
            html += t->getHTML();
            html += "</li>";
        }

        html += "</ul>";
        return html;
    }

private:
    vector<TodoList*> todos;
};