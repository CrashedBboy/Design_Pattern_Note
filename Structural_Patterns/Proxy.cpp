#include <iostream>
#include <string>

using namespace std;

// There're lots of forms of proxy pattern: virtual proxy, remote proxy, protection proxy, etc.
// What we demonstrate here is example of protection proxy: credit card is a kind of proxy of bank account

// abstract interface
class Payment {
public:
    virtual void pay(int amount) = 0;
};

// Heavy weight service
class BankAccount : public Payment {
public:
    BankAccount(int amount) : balance(amount) {}
    void pay(int amount) {
        cout << "spent $" << amount << endl;
        this->balance -= amount;
    }
    int getBalance() {
        return this->balance;
    }
private:
    int balance;
};

// Lightweight proxy (just a piece of card)
class CreditCard : public Payment {
public:
    CreditCard(BankAccount* account) {
        this->account = account;
    }

    bool checkAccess() {
        // do some validation
        return true;
    }

    void pay(int amount) {
        // protection proxy
        if (this->checkAccess()) {
            this->account->pay(amount);
        }
    }
private:
    BankAccount* account;
};

// Another example of proxy pattern: virtual proxy
// Parsing a book (very long string) is a heavy work, so we initialize the parsed book once we need it
// (lazy initialization)

class Book {
public:
    string data;
};

// abstract interface of book parser
class IBookParser {
public:
    virtual int getPageNumber() = 0;
};

// real heavy weight class
class BookParser : public IBookParser {
public:
    BookParser(string book) {
        // !!!!
        // do a very heavy task for paring the whole book
        // !!!!
        this->pageNumber = 46293;
    }
    int getPageNumber() {
        return this->pageNumber;
    }
private:
    int pageNumber;
};

// virtual proxy class
class LazyBookParserProxy : public IBookParser {
public:
    LazyBookParserProxy(string book) {
        this->book = book;
    }
    int getPageNumber() {
        if (this->parser == nullptr) {
            this->parser = new BookParser(this->book);
        }
        return this->parser->getPageNumber();
    }
private:
    BookParser* parser;
    string book;
};

// client code
int main() {

    string book = "A story begins from .... (very long story) ...";
    LazyBookParserProxy* parser = new LazyBookParserProxy(book);

    // do a bunch of other things

    // now, once we need to parse the book, the book will be parsed.
    cout << parser->getPageNumber() << endl;

    return 0;
}