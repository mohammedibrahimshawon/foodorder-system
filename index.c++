#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item {
public:
    string name;
    int quantity;
    double price;

    Item(string n, int q, double p) : name(n), quantity(q), price(p) {}
};

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(const string& name, int quantity, double price) {
        items.push_back(Item(name, quantity, price));
    }

    void viewItems() {
        cout << "Inventory:\n";
        for (const auto& item : items) {
            cout << "Name: " << item.name << ", Quantity: " << item.quantity << ", Price: $" << item.price << endl;
        }
    }

    bool orderItem(const string& name, int quantity) {
        for (auto& item : items) {
            if (item.name == name) {
                if (item.quantity >= quantity) {
                    item.quantity -= quantity;
                    cout << "Order placed: " << quantity << " x " << name << endl;
                    return true;
                } else {
                    cout << "Insufficient quantity for " << name << endl;
                    return false;
                }
            }
        }
        cout << "Item not found: " << name << endl;
        return false;
    }
};

int main() {
    Inventory inventory;
    int choice;
    string name;
    int quantity;
    double price;

    do {
        cout << "\nRestaurant Inventory System\n";
        cout << "1. Add Item\n";
        cout << "2. View Inventory\n";
        cout << "3. Place Order\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter quantity: ";
                cin >> quantity;
                cout << "Enter price: ";
                cin >> price;
                inventory.addItem(name, quantity, price);
                break;
            case 2:
                inventory.viewItems();
                break;
            case 3:
                cout << "Enter item name to order: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter quantity to order: ";
                cin >> quantity;
                inventory.orderItem(name, quantity);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
