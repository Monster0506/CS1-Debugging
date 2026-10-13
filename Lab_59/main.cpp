// Coffee Shack: Decorator (ingredients) + Chain of Responsibility (baristas).
// Prices: large $10, medium $7, small $5; sugar $1, cream $2, honey $3.
// Junior barista: only plain coffee. Senior: anything without honey.
// Manager: everything.
//
// Input (one character per prompt):   m s h h d Alex
// Expected output:
//   I, Manager have prepared your drink
//   Alex, your medium coffee with sugar, honey, honey is ready. It will be $14
//
// Input:  s d Bo
//   I, Junior Barista have prepared your drink
//   Bo, your small coffee is ready. It will be $5
//
// Input:  l c d Cy
//   I, Senior Barista have prepared your drink
//   Cy, your large coffee with cream is ready. It will be $12
//
// Run with, e.g.:  printf 'm\ns\nh\nh\nd\nAlex\n' | ./coffee

#include <iostream>
#include <string>

#include "coffee.hpp"
#include "barista.hpp"


int main() {
    char choice;
    Drink* order = nullptr; 
    JuniorBarista junior;
    SeniorBarista senior;
    Manager       manager;    

    junior.setNext(&senior);
    senior.setNext(&manager);

    std::cout<<"hi, l,m,s? ";
    std::cin >> choice; 

    switch (choice){
        case 'l': order = new LargeCoffee(); break;
        case 'm': order = new MediumCoffee(); break;
        default: order = new SmallCoffee(); break;
    }
    do {
        std::cout << "s, c, h, or d? ";
        std::cin >> choice;

        switch (choice){
            case 's': order = new Sugar(order); break;
            case 'c': order = new Cream(order); break;
            case 'h': order = new Honey(order); break;
            default: break;
        }
    } while (choice != 'd');


    std::string name;
    std::cout << "name? ";
    std::cin >> name;
    
    junior.handle(order, name);

    delete order; 
}