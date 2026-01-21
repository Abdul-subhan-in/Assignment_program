#include <iostream>
using namespace std;

int main() {
    char choice;
    
    cout << "===== VENDING MACHINE =====\n";
    cout << "A: Coffee ($2)\n";
    cout << "B: Tea ($1)\n";
    cout << "C: Water ($0.5)\n";
    cout << "Enter your choice (A/B/C): ";
    
    cin >> choice;  // User inputs a single character
    
    cout << "\n";
    
    // Process the character input
    if (choice == 'A' || choice == 'a') {
        cout << "Dispensing Coffee... Enjoy!\n";
    } 
    else if (choice == 'B' || choice == 'b') {
        cout << "Dispensing Tea... Enjoy!\n";
    } 
    else if (choice == 'C' || choice == 'c') {
        cout << "Dispensing Water... Enjoy!\n";
    } 
    else {
        cout << "Invalid selection! Please try again.\n";
    }
    
    return 0;
}