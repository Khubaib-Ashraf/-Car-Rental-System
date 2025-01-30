#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class User {
public:
    string username;
    string password;

    User(string user, string pass) : username(user), password(pass) {}
};

class Car {
public:
    string model;
    double pricePerDay;

    Car(string m, double p) : model(m), pricePerDay(p) {}
};

class CarRentalSystem {
private:
    unordered_map<string, User> users;
    vector<Car> cars;
    User* loggedInUser ;

public:
    CarRentalSystem() : loggedInUser (nullptr) {
        // Adding some cars to the rental system
        cars.push_back(Car("Toyota Camry", 50.0));
        cars.push_back(Car("Honda Accord", 55.0));
        cars.push_back(Car("Ford Mustang", 70.0));
        cars.push_back(Car("Chevrolet Malibu", 60.0));
    }

    void signUp() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (users.find(username) != users.end()) {
            cout << "Username already exists. Please try a different one." << endl;
        } else {
            users[username] = User(username, password);
            cout << "Sign up successful!" << endl;
        }
    }

    void login() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (users.find(username) != users.end() && users[username].password == password) {
            loggedInUser  = &users[username];
            cout << "Login successful! Welcome, " << loggedInUser ->username << "!" << endl;
        } else {
            cout << "Invalid username or password." << endl;
        }
    }

    void displayCars() {
        cout << "Available cars for rent:" << endl;
        for (size_t i = 0; i < cars.size(); ++i) {
            cout << i + 1 << ". " << cars[i].model << " - $" << cars[i].pricePerDay << " per day" << endl;
        }
    }

    void rentCar() {
        if (loggedInUser  == nullptr) {
            cout << "You need to log in to rent a car." << endl;
            return;
        }

        displayCars();
        int choice;
        cout << "Select a car to rent (1-" << cars.size() << "): ";
        cin >> choice;

        if (choice < 1 || choice > cars.size()) {
            cout << "Invalid choice." << endl;
            return;
        }

        int days;
        cout << "Enter number of days to rent: ";
        cin >> days;

        double totalCost = cars[choice - 1].pricePerDay * days;
        cout << "You have rented " << cars[choice - 1].model << " for " << days << " days." << endl;
        cout << "Total cost: $" << totalCost << endl;
    }

    void run() {
        int option;
        do {
            cout << "\nCar Rental System" << endl;
            cout << "1. Sign Up" << endl;
            cout << "2. Login" << endl;
            cout << "3. Rent a Car" << endl;
            cout << "4. Exit" << endl;
            cout << "Choose an option: ";
            cin >> option;

            switch (option) {
                case 1:
                    signUp();
                    break;
                case 2:
                    login();
                    break;
                case 3:
                    rentCar();
                    break;
                case 4:
                    cout << "Exiting the system. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid option. Please try again." << endl;
            }
        } while (option != 4);
    }
};

int main() {
    CarRentalSystem system;
    system.run();
    return 0;
}
