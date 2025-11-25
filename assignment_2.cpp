#include <iostream>
using namespace std;

int main() {
    // Product Variables
    int p1Id = 1, p2Id = 2, p3Id = 3;
    char p1Name = 'A', p2Name = 'B', p3Name = 'C';
    double p1Price = 25.50, p2Price = 40.00, p3Price = 15.75;
    int p1Qty = 10, p2Qty = 20, p3Qty = 30;
    
    // Customer Variables
    char customerType;
    
    // Order Variables
    int orderId;
    int orderQty;
    double subtotal = 0.0;
    double discount = 0.0;
    double fee = 0.0;
    double total = 0.0;
    
    // Validation Variables
    bool validProduct = false;
    bool validQuantity = false;
    bool confirmedOrder = false;
    char confirmChoice;
    char changeChoice;
    
    // Display Inventory
    cout << "=== SMART INVENTORY & ORDER ASSISTANT ===" << endl;
    cout << "Product ID\tName\tPrice\tStock" << endl;
    cout << p1Id << "\t\t" << p1Name << "\t$" << p1Price << "\t" << p1Qty << endl;
    cout << p2Id << "\t\t" << p2Name << "\t$" << p2Price << "\t" << p2Qty << endl;
    cout << p3Id << "\t\t" << p3Name << "\t$" << p3Price << "\t" << p3Qty << endl;
    cout << "==========================================" << endl;
    
    // Input Customer Type
    cout << "Enter customer type (R for Regular, P for Prime): ";
    cin >> customerType;
    
    if (customerType != 'R' && customerType != 'P' && customerType != 'r' && customerType != 'p') {
        cout << "Invalid customer type! Defaulting to Regular." << endl;
        customerType = 'R';
    }
    
    // Order Input Section
    cout << "\n=== PLACE YOUR ORDER ===" << endl;
    cout << "Enter product ID: ";
    cin >> orderId;
    
    // Validate Product ID
    if (orderId == p1Id) {
        validProduct = true;
        cout << "Product selected: " << p1Name << " - Price: $" << p1Price << " - Available Stock: " << p1Qty << endl;
    } else if (orderId == p2Id) {
        validProduct = true;
        cout << "Product selected: " << p2Name << " - Price: $" << p2Price << " - Available Stock: " << p2Qty << endl;
    } else if (orderId == p3Id) {
        validProduct = true;
        cout << "Product selected: " << p3Name << " - Price: $" << p3Price << " - Available Stock: " << p3Qty << endl;
    } else {
        validProduct = false;
        cout << "Invalid product ID! Please restart the program." << endl;
        return 1;
    }
    
    // Input Quantity
    cout << "Enter quantity: ";
    cin >> orderQty;
    
    // Validate Quantity
    if (orderId == p1Id) {
        if (orderQty > 0 && orderQty <= p1Qty) {
            validQuantity = true;
            subtotal = p1Price * orderQty;
        } else {
            validQuantity = false;
            cout << "Invalid quantity! Available stock: " << p1Qty << endl;
        }
    } else if (orderId == p2Id) {
        if (orderQty > 0 && orderQty <= p2Qty) {
            validQuantity = true;
            subtotal = p2Price * orderQty;
        } else {
            validQuantity = false;
            cout << "Invalid quantity! Available stock: " << p2Qty << endl;
        }
    } else if (orderId == p3Id) {
        if (orderQty > 0 && orderQty <= p3Qty) {
            validQuantity = true;
            subtotal = p3Price * orderQty;
        } else {
            validQuantity = false;
            cout << "Invalid quantity! Available stock: " << p3Qty << endl;
        }
    }
    
    if (!validQuantity) {
        cout << "Order cannot be processed. Please restart the program." << endl;
        return 1;
    }
    
    // Discount Calculation
    double primeDiscount = 0.0;
    double regularDiscount = 0.0;
    double bulkDiscount = 0.0;
    
    // Prime customer discount (15% for orders above $50)
    if ((customerType == 'P' || customerType == 'p') && subtotal > 50.0) {
        primeDiscount = subtotal * 0.15;
    }
    
    // Regular customer discount (10% for orders above $75)
    if ((customerType == 'R' || customerType == 'r') && subtotal > 75.0) {
        regularDiscount = subtotal * 0.10;
    }
    
    // Bulk discount (5% for quantities above 5)
    if (orderQty > 5) {
        bulkDiscount = subtotal * 0.05;
    }
    
    // Apply highest discount
    if (primeDiscount >= regularDiscount && primeDiscount >= bulkDiscount) {
        discount = primeDiscount;
    } else if (regularDiscount >= primeDiscount && regularDiscount >= bulkDiscount) {
        discount = regularDiscount;
    } else {
        discount = bulkDiscount;
    }
    
    // Fee Calculation
    double amountAfterDiscount = subtotal - discount;
    
    if (amountAfterDiscount < 20.0) {
        fee = 2.50; // Small order processing fee
    }
    
    // Total Calculation
    total = amountAfterDiscount + fee;
    
    // Display Order Summary
    cout << "\n=== ORDER SUMMARY ===" << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Discount: $" << discount << endl;
    cout << "Fee: $" << fee << endl;
    cout << "Total: $" << total << endl;
    cout << "=====================" << endl;
    
    // Confirmation
    cout << "Confirm order? (Y/N): ";
    cin >> confirmChoice;
    
    if (confirmChoice == 'Y' || confirmChoice == 'y') {
        confirmedOrder = true;
        cout << "Order confirmed!" << endl;
    } else {
        cout << "Do you want to: " << endl;
        cout << "C - Cancel order" << endl;
        cout << "Enter your choice (C to cancel): ";
        cin >> changeChoice;
        
        if (changeChoice == 'C' || changeChoice == 'c') {
            cout << "Order cancelled. Thank you!" << endl;
            return 0;
        } else {
            cout << "Invalid choice. Order cancelled." << endl;
            return 0;
        }
    }
    
    // Update Inventory if order confirmed
    if (confirmedOrder) {
        // Store original stock for display
        int originalStock = 0;
        char productName;
        
        if (orderId == p1Id) {
            originalStock = p1Qty;
            productName = p1Name;
            p1Qty = p1Qty - orderQty;
        } else if (orderId == p2Id) {
            originalStock = p2Qty;
            productName = p2Name;
            p2Qty = p2Qty - orderQty;
        } else if (orderId == p3Id) {
            originalStock = p3Qty;
            productName = p3Name;
            p3Qty = p3Qty - orderQty;
        }
        
        // Final Invoice
        cout << "\n=== FINAL INVOICE ===" << endl;
        cout << "Product: " << productName << " | Qty: " << orderQty << endl;
        cout << "Customer Type: " << ((customerType == 'P' || customerType == 'p') ? "Prime" : "Regular") << endl;
        cout << "Subtotal: $" << subtotal << endl;
        cout << "Discount: $" << discount << endl;
        cout << "Fee: $" << fee << endl;
        cout << "TOTAL PAYABLE: $" << total << endl;
        
        // Stock Reduction Statement
        cout << "\n=== STOCK UPDATE STATEMENT ===" << endl;
        cout << "Product " << productName << " stock reduced from " << originalStock 
             << " to " << (orderId == p1Id ? p1Qty : (orderId == p2Id ? p2Qty : p3Qty)) 
             << " (Reduced by " << orderQty << " units)" << endl;
        
        cout << "\n=== UPDATED INVENTORY ===" << endl;
        cout << "Product ID\tName\tStock" << endl;
        cout << p1Id << "\t\t" << p1Name << "\t" << p1Qty << endl;
        cout << p2Id << "\t\t" << p2Name << "\t" << p2Qty << endl;
        cout << p3Id << "\t\t" << p3Name << "\t" << p3Qty << endl;
    }
    
    cout << "\nThank you for using Smart Inventory & Order Assistant!" << endl;
    return 0;
}