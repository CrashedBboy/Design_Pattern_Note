#include <iostream>
#include <string>

using namespace std;

// abstract resource class
class IResource {
public:
    virtual string snippet() = 0;
    virtual string image() = 0;
    virtual string title() = 0;
    virtual string url() = 0;
};

// resource 1
class Book : public IResource {
public:
    string snippet() {
        return "<Book cover content>";
    }
    string image() {
        return "<Book cover image>";
    }
    string title() {
        return "<Book name>";
    }
    string url() {
        return "<Book DOI>";
    }
};

// resource 2
class Artist : public IResource {
public:
    string snippet() {
        return "<Artist bio>";
    }
    string image() {
        return "<Artist avatar>";
    }
    string title() {
        return "<Artist name>";
    }
    string url() {
        return "<Artist website url>";
    }
};


// abstract view class
class View {
public:
    View(IResource* resource) : resource(resource) {}
    virtual void show() = 0;
protected:
    IResource* resource; // the 'bridge'
};

// view class 1
class LongForm : public View {
public:
    LongForm(IResource* resource) : View(resource) {}
    void show() {
        cout << this->resource->image() << endl;
        cout << this->resource->title() << ":" << this->resource->snippet() << endl;
        cout << this->resource->url() << endl;
    }
};

// view class 2
class ShortForm : public View {
public:
    ShortForm(IResource* resource) : View(resource) {}
    void show() {
        cout << this->resource->image() << endl;
        cout << this->resource->title() << endl;
    }
};

// client code
int main() {

    // because resources and views are implemented independently
    // we can combine them flexibly

    // suppose we want an artist shown in long form and book shown in short form
    Artist* me = new Artist();
    Book* dictionary = new Book();

    LongForm* detailedIntro = new LongForm(me);
    detailedIntro->show();
    ShortForm* briefIntro = new ShortForm(dictionary);
    briefIntro->show();

    return 0;
}