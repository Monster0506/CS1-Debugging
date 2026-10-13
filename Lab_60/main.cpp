// Coffee Shack with the Observer pattern. Three customers each order a drink
// (a decorated coffee). The barista (chain of responsibility) is recorded with
// the order. After taking an order, the shack randomly either takes a new
// order or finishes a random pending order and notifies ALL customers; only
// the customer whose drink it is reacts.
//
// Run:  ./coffeeshack < input.txt
// For every customer exactly one pair of lines like this appears (the order
// of customers is random):
//   Alex, your medium coffee with sugar is ready. It is prepared by a Senior Barista. It will be $8, please.
//   This is Alex, I got my coffee, thank you!
//   Bea ... large coffee with cream, honey ... Manager ... $15
//   Cy  ... small coffee ... Junior Barista ... $5

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "coffee.hpp"
#include "barista.hpp"
#include "coffeeshack.hpp"
#include "customer.hpp"

Drink* buildDrink() {
    char   choice;
    Drink* order = nullptr;

    std::cout << "hi, l, m, s? ";
    std::cin >> choice;

    switch (choice) {
        case 'l': order = new LargeCoffee();  break;
        case 'm': order = new MediumCoffee(); break;
        default:  order = new SmallCoffee();  break;
    }
    

    do {
        std::cout << "s, c, h, or d? ";
        std::cin >> choice;
        switch (choice) {
            case 's': order = new Sugar(order); break;
            case 'c': order = new Cream(order); break;
            case 'h': order = new Honey(order); break;
            default: break;
        }
    } while (choice != 'd');

    return order;
}


int main() {
    std::srand(std::time(nullptr));
    JuniorBarista junior;
    SeniorBarista senior;
    Manager manager;
    junior.setNext(&senior);
    senior.setNext(&manager);

    CoffeeShack shack;

    std::vector<Customer*> customers;

    const int CUSTOMERS = 3;
    int ordersPlaced   = 0;

    while (ordersPlaced < CUSTOMERS || shack.hasPending()) {

        bool takeOrder =
            (ordersPlaced < CUSTOMERS) &&
            (!shack.hasPending() || rand() % 2 == 0);

        if (takeOrder) {
            Drink* drink = buildDrink();

            std::string name;
            std::cout << "name? ";
            std::cin >> name;

            std::string barista = junior.handle(drink);

            Customer* customer = new Customer(name);
            customers.push_back(customer);
            shack.attach(customer);

            delete drink;
            shack.addOrder(name, drink->getName(), drink->getPrice(), barista); 

            std::cout << "Please wait, " << name << ".\n\n";
            ++ordersPlaced;
        } else {
            shack.serveRandom();
        }
    }

    for (auto* c : customers) delete c;

    return 0;
}
