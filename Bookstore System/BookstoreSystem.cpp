#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Book {
public:
    string isbn;
    string title;
    string author;
    double price;
    int num_copies;

    Book(string isbn, string title, string author, double price, int num_copies) {
        this->isbn = isbn;
        this->title = title;
        this->author = author;
        this->price = price;
        this->num_copies = num_copies;
    }

    void display_info() {
        cout << setw(10) << left << isbn << setw(30) << left << title << setw(20) << left << author
             << setw(10) << right << fixed << setprecision(2) << price << setw(10) << right << num_copies << endl;
    }

    void update_inventory(int quantity) {
        num_copies += quantity;
    }
};

class Cart {
public:
    vector<pair<Book*, int>> books;
    double total_cost;

    Cart() {
        total_cost = 0;
    }

    void add_book(Book* book, int quantity) {
        for (pair<Book*, int>& item : books) {
            if (item.first == book) {
                item.second += quantity;
                total_cost += book->price * quantity;
                return;
            }
        }
        books.push_back(make_pair(book, quantity));
        total_cost += book->price * quantity;
    }

    void remove_book(Book* book) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].first == book) {
                total_cost -= books[i].first->price * books[i].second;
                books.erase(books.begin() + i);
                break;
            }
        }
    }

    double calculate_total() {
        return total_cost;
    }

    void checkout() {
        books.clear();
        total_cost = 0;
        cout << "Checkout successful!" << endl;
    }
};

class Store {
public:
    vector<Book*> inventory;

    void add_book(Book* book) {
        inventory.push_back(book);
    }

    void remove_book(Book* book) {
        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i] == book) {
                inventory.erase(inventory.begin() + i);
                break;
            }
        }
    }

    vector<Book*> search_book(string query) {
        vector<Book*> results;
        for (Book* book : inventory) {
            if (book->isbn == query || book->title == query || book->author == query) {
                results.push_back(book);
            }
        }
        return results;
    }

    void display_available_books() {
        cout << setw(10) << left << "ISBN" << setw(30) << left << "Title" << setw(20) << left << "Author"
             << setw(10) << right << "Price" << setw(10) << right << "Quantity" << endl;
        for (Book* book : inventory) {
            book->display_info();
        }
    }
};

int main() {
    Store store;
    Cart cart;

    // Add some books to the store
    store.add_book(new Book("ISBN123", "Book 1", "Author 1", 19.99, 10));
    store.add_book(new Book("ISBN456", "Book 2", "Author 2", 24.99, 5));

    while (true) {
        cout << "1. View all books" << endl;
        cout << "2. Add book to cart" << endl;
        cout << "3. Remove book from cart" << endl;
        cout << "4. Checkout" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            store.display_available_books();
        } else if (choice == 2) {
            cout << "Enter ISBN: ";
            string isbn;
            cin >> isbn;

            cout << "Enter quantity: ";
            int quantity;
            cin >> quantity;

            vector<Book*> results = store.search_book(isbn);
            if (results.size() == 0) {
                cout << "Book not found." << endl;
            } else if (results[0]->num_copies < quantity) {
                cout << "Insufficient stock." << endl;
            } else {
                cart.add_book(results[0], quantity);
                results[0]->update_inventory(-quantity);
                cout << "Book added to cart." << endl;
            }
        } else if (choice == 3) {
            cout << "Enter ISBN: ";
            string isbn;
            cin >> isbn;

            vector<Book*> results = store.search_book(isbn);
            if (results.size() == 0) {
                cout << "Book not found." << endl;
            } else {
                cart.remove_book(results[0]);
                cout << "Book removed from cart." << endl;
            }
        } else if (choice == 4) {
            cart.checkout();
        } else if (choice == 5) {
            break;
        }
    }

    return 0;
}