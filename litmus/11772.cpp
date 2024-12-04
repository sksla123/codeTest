#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Library {
private:
    vector<string> books;

public:
    void addBook(const string& title) {
        books.push_back(title);
        cout << "add " << title << endl;
    }

    void insertBook(int index, const string& title) {
        if (index >= 0 && index <= books.size()) {
            books.insert(books.begin() + index, title);
            cout << "add " << title << " to " << index << endl;
        } else {
            cout << "Error" << endl;
        }
    }

    void removeBook(int index) {
        if (index >= 0 && index < books.size()) {
            cout << "remove " << books[index] << endl;
            books.erase(books.begin() + index);
        } else {
            cout << "Error" << endl;
        }
    }

    void displayLastBook() {
        if (books.empty()) {
            cout << "Empty vector" << endl;
        } else {
            cout << books.back() << endl;
        }
    }

    void displayAllBooks() {
        if (books.empty()) {
            cout << "Empty vector" << endl;
        } else {
            for (size_t i = 0; i < books.size(); ++i) {
                cout << i << ": " << books[i] << endl;
            }
        }
    }
};

int main() {
    Library library;
    int choice, index;
    string title;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> title;
                library.addBook(title);
                break;
            case 2:
                cin >> index >> title;
                library.insertBook(index, title);
                break;
            case 3:
                cin >> index;
                library.removeBook(index);
                break;
            case 4:
                library.displayLastBook();
                break;
            case 5:
                library.displayAllBooks();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}