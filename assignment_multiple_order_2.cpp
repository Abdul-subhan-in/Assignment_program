#include <iostream>
using namespace std;

int main() {
    // Product Variables - Initial Stock
    int p1Id = 101, p2Id = 102, p3Id = 103;
    char p1Name = 'A', p2Name = 'B', p3Name = 'C';
    double p1Price = 25.50, p2Price = 40.00, p3Price = 15.75;
    int p1Qty = 10, p2Qty = 5, p3Qty = 20;
    
    // Variables for multiple orders
    char continueOrder;
    int orderCount = 0;
    
    cout << "=== SMART INVENTORY & ORDER ASSISTANT ===" << endl;
    cout << "=== MULTIPLE ORDERS SUPPORT ===" << endl << endl;

    // FIRST ORDER
    cout << "--- PROCESSING ORDER #1 ---" << endl;
    
    // Display Current Inventory
    cout << "Current Inventory:" << endl;
    cout << "Product ID\tName\tPrice\tStock" << endl;
    cout << p1Id << "\t\t" << p1Name << "\t$" << p1Price << "\t" << p1Qty << endl;
    cout << p2Id << "\t\t" << p2Name << "\t$" << p2Price << "\t" << p2Qty << endl;
    cout << p3Id << "\t\t" << p3Name << "\t$" << p3Price << "\t" << p3Qty << endl;
    
    // Order Variables for Order 1
    char customerType1;
    int orderId1, orderQty1;
    double subtotal1 = 0.0, discount1 = 0.0, fee1 = 0.0, total1 = 0.0;
    bool validProduct1 = false, validQuantity1 = false;
    char confirmChoice1;
    
    // Customer Type for Order 1
    cout << "\nEnter customer type for Order #1 (R for Regular, P for Prime): ";
    cin >> customerType1;
    
    if (customerType1 != 'R' && customerType1 != 'P' && customerType1 != 'r' && customerType1 != 'p') {
        cout << "Invalid customer type! Defaulting to Regular." << endl;
        customerType1 = 'R';
    }
    
    // Order Input for Order 1
    cout << "Enter product ID for Order #1: ";
    cin >> orderId1;
    
    // Validate Product ID for Order 1
    if (orderId1 == p1Id) {
        validProduct1 = true;
        cout << "Product selected: " << p1Name << " - Price: $" << p1Price << " - Available: " << p1Qty << endl;
    } else if (orderId1 == p2Id) {
        validProduct1 = true;
        cout << "Product selected: " << p2Name << " - Price: $" << p2Price << " - Available: " << p2Qty << endl;
    } else if (orderId1 == p3Id) {
        validProduct1 = true;
        cout << "Product selected: " << p3Name << " - Price: $" << p3Price << " - Available: " << p3Qty << endl;
    } else {
        cout << "Invalid product ID! Skipping Order #1." << endl;
        validProduct1 = false;
    }
    
    if (validProduct1) {
        // Quantity for Order 1
        cout << "Enter quantity for Order #1: ";
        cin >> orderQty1;
        
        // Validate Quantity for Order 1
        if (orderId1 == p1Id && orderQty1 > 0 && orderQty1 <= p1Qty) {
            validQuantity1 = true;
            subtotal1 = p1Price * orderQty1;
        } else if (orderId1 == p2Id && orderQty1 > 0 && orderQty1 <= p2Qty) {
            validQuantity1 = true;
            subtotal1 = p2Price * orderQty1;
        } else if (orderId1 == p3Id && orderQty1 > 0 && orderQty1 <= p3Qty) {
            validQuantity1 = true;
            subtotal1 = p3Price * orderQty1;
        } else {
            cout << "Invalid quantity! Available stock: ";
            if (orderId1 == p1Id) cout << p1Qty;
            else if (orderId1 == p2Id) cout << p2Qty;
            else if (orderId1 == p3Id) cout << p3Qty;
            cout << endl;
            validQuantity1 = false;
        }
        
        if (validQuantity1) {
            // Discount Calculation for Order 1
            double primeDiscount1 = 0.0, regularDiscount1 = 0.0, bulkDiscount1 = 0.0;
            
            if ((customerType1 == 'P' || customerType1 == 'p') && subtotal1 > 50.0) {
                primeDiscount1 = subtotal1 * 0.15;
            }
            if ((customerType1 == 'R' || customerType1 == 'r') && subtotal1 > 75.0) {
                regularDiscount1 = subtotal1 * 0.10;
            }
            if (orderQty1 > 5) {
                bulkDiscount1 = subtotal1 * 0.05;
            }
            
            // Apply highest discount
            if (primeDiscount1 >= regularDiscount1 && primeDiscount1 >= bulkDiscount1) {
                discount1 = primeDiscount1;
            } else if (regularDiscount1 >= primeDiscount1 && regularDiscount1 >= bulkDiscount1) {
                discount1 = regularDiscount1;
            } else {
                discount1 = bulkDiscount1;
            }
            
            // Fee Calculation for Order 1
            double amountAfterDiscount1 = subtotal1 - discount1;
            if (amountAfterDiscount1 < 20.0) {
                fee1 = 2.50;
            }
            
            total1 = amountAfterDiscount1 + fee1;
            
            // Display Order Summary for Order 1
            cout << "\n=== ORDER #1 SUMMARY ===" << endl;
            cout << "Subtotal: $" << subtotal1 << endl;
            cout << "Discount: $" << discount1 << endl;
            cout << "Fee: $" << fee1 << endl;
            cout << "Total: $" << total1 << endl;
            
            // Confirmation for Order 1
            cout << "Confirm Order #1? (Y/N): ";
            cin >> confirmChoice1;
            
            if (confirmChoice1 == 'Y' || confirmChoice1 == 'y') {
                // Update Inventory for Order 1
                if (orderId1 == p1Id) {
                    p1Qty = p1Qty - orderQty1;
                } else if (orderId1 == p2Id) {
                    p2Qty = p2Qty - orderQty1;
                } else if (orderId1 == p3Id) {
                    p3Qty = p3Qty - orderQty1;
                }
                orderCount++;
                cout << "Order #1 confirmed and inventory updated!" << endl;
            } else {
                cout << "Order #1 cancelled." << endl;
            }
        }
    }
    
    // Display Stock Status after Order 1
    cout << "\n=== STOCK STATUS AFTER ORDER #1 ===" << endl;
    cout << "Product ID\tName\tRemaining Stock" << endl;
    cout << p1Id << "\t\t" << p1Name << "\t" << p1Qty << endl;
    cout << p2Id << "\t\t" << p2Name << "\t" << p2Qty << endl;
    cout << p3Id << "\t\t" << p3Name << "\t" << p3Qty << endl;
    
    // SECOND ORDER
    cout << "\nDo you want to place Order #2? (Y/N): ";
    cin >> continueOrder;
    
    if (continueOrder == 'Y' || continueOrder == 'y') {
        cout << "\n--- PROCESSING ORDER #2 ---" << endl;
        
        // Display Current Inventory for Order 2
        cout << "Current Inventory:" << endl;
        cout << "Product ID\tName\tPrice\tStock" << endl;
        cout << p1Id << "\t\t" << p1Name << "\t$" << p1Price << "\t" << p1Qty << endl;
        cout << p2Id << "\t\t" << p2Name << "\t$" << p2Price << "\t" << p2Qty << endl;
        cout << p3Id << "\t\t" << p3Name << "\t$" << p3Price << "\t" << p3Qty << endl;
        
        // Order Variables for Order 2
        char customerType2;
        int orderId2, orderQty2;
        double subtotal2 = 0.0, discount2 = 0.0, fee2 = 0.0, total2 = 0.0;
        bool validProduct2 = false, validQuantity2 = false;
        char confirmChoice2;
        
        // Customer Type for Order 2
        cout << "\nEnter customer type for Order #2 (R for Regular, P for Prime): ";
        cin >> customerType2;
        
        if (customerType2 != 'R' && customerType2 != 'P' && customerType2 != 'r' && customerType2 != 'p') {
            cout << "Invalid customer type! Defaulting to Regular." << endl;
            customerType2 = 'R';
        }
        
        // Order Input for Order 2
        cout << "Enter product ID for Order #2: ";
        cin >> orderId2;
        
        // Validate Product ID for Order 2
        if (orderId2 == p1Id) {
            validProduct2 = true;
            cout << "Product selected: " << p1Name << " - Price: $" << p1Price << " - Available: " << p1Qty << endl;
        } else if (orderId2 == p2Id) {
            validProduct2 = true;
            cout << "Product selected: " << p2Name << " - Price: $" << p2Price << " - Available: " << p2Qty << endl;
        } else if (orderId2 == p3Id) {
            validProduct2 = true;
            cout << "Product selected: " << p3Name << " - Price: $" << p3Price << " - Available: " << p3Qty << endl;
        } else {
            cout << "Invalid product ID! Skipping Order #2." << endl;
            validProduct2 = false;
        }
        
        if (validProduct2) {
            // Quantity for Order 2
            cout << "Enter quantity for Order #2: ";
            cin >> orderQty2;
            
            // Validate Quantity for Order 2
            if (orderId2 == p1Id && orderQty2 > 0 && orderQty2 <= p1Qty) {
                validQuantity2 = true;
                subtotal2 = p1Price * orderQty2;
            } else if (orderId2 == p2Id && orderQty2 > 0 && orderQty2 <= p2Qty) {
                validQuantity2 = true;
                subtotal2 = p2Price * orderQty2;
            } else if (orderId2 == p3Id && orderQty2 > 0 && orderQty2 <= p3Qty) {
                validQuantity2 = true;
                subtotal2 = p3Price * orderQty2;
            } else {
                cout << "Invalid quantity! Available stock: ";
                if (orderId2 == p1Id) cout << p1Qty;
                else if (orderId2 == p2Id) cout << p2Qty;
                else if (orderId2 == p3Id) cout << p3Qty;
                cout << endl;
                validQuantity2 = false;
            }
            
            if (validQuantity2) {
                // Discount Calculation for Order 2
                double primeDiscount2 = 0.0, regularDiscount2 = 0.0, bulkDiscount2 = 0.0;
                
                if ((customerType2 == 'P' || customerType2 == 'p') && subtotal2 > 50.0) {
                    primeDiscount2 = subtotal2 * 0.15;
                }
                if ((customerType2 == 'R' || customerType2 == 'r') && subtotal2 > 75.0) {
                    regularDiscount2 = subtotal2 * 0.10;
                }
                if (orderQty2 > 5) {
                    bulkDiscount2 = subtotal2 * 0.05;
                }
                
                // Apply highest discount
                if (primeDiscount2 >= regularDiscount2 && primeDiscount2 >= bulkDiscount2) {
                    discount2 = primeDiscount2;
                } else if (regularDiscount2 >= primeDiscount2 && regularDiscount2 >= bulkDiscount2) {
                    discount2 = regularDiscount2;
                } else {
                    discount2 = bulkDiscount2;
                }
                
                // Fee Calculation for Order 2
                double amountAfterDiscount2 = subtotal2 - discount2;
                if (amountAfterDiscount2 < 20.0) {
                    fee2 = 2.50;
                }
                
                total2 = amountAfterDiscount2 + fee2;
                
                // Display Order Summary for Order 2
                cout << "\n=== ORDER #2 SUMMARY ===" << endl;
                cout << "Subtotal: $" << subtotal2 << endl;
                cout << "Discount: $" << discount2 << endl;
                cout << "Fee: $" << fee2 << endl;
                cout << "Total: $" << total2 << endl;
                
                // Confirmation for Order 2
                cout << "Confirm Order #2? (Y/N): ";
                cin >> confirmChoice2;
                
                if (confirmChoice2 == 'Y' || confirmChoice2 == 'y') {
                    // Update Inventory for Order 2
                    if (orderId2 == p1Id) {
                        p1Qty = p1Qty - orderQty2;
                    } else if (orderId2 == p2Id) {
                        p2Qty = p2Qty - orderQty2;
                    } else if (orderId2 == p3Id) {
                        p3Qty = p3Qty - orderQty2;
                    }
                    orderCount++;
                    cout << "Order #2 confirmed and inventory updated!" << endl;
                } else {
                    cout << "Order #2 cancelled." << endl;
                }
            }
        }
        
        // Display Stock Status after Order 2
        cout << "\n=== STOCK STATUS AFTER ORDER #2 ===" << endl;
        cout << "Product ID\tName\tRemaining Stock" << endl;
        cout << p1Id << "\t\t" << p1Name << "\t" << p1Qty << endl;
        cout << p2Id << "\t\t" << p2Name << "\t" << p2Qty << endl;
        cout << p3Id << "\t\t" << p3Name << "\t" << p3Qty << endl;
        
        // THIRD ORDER
        cout << "\nDo you want to place Order #3? (Y/N): ";
        cin >> continueOrder;
        
        if (continueOrder == 'Y' || continueOrder == 'y') {
            cout << "\n--- PROCESSING ORDER #3 ---" << endl;
            
            // Display Current Inventory for Order 3
            cout << "Current Inventory:" << endl;
            cout << "Product ID\tName\tPrice\tStock" << endl;
            cout << p1Id << "\t\t" << p1Name << "\t$" << p1Price << "\t" << p1Qty << endl;
            cout << p2Id << "\t\t" << p2Name << "\t$" << p2Price << "\t" << p2Qty << endl;
            cout << p3Id << "\t\t" << p3Name << "\t$" << p3Price << "\t" << p3Qty << endl;
            
            // Order Variables for Order 3
            char customerType3;
            int orderId3, orderQty3;
            double subtotal3 = 0.0, discount3 = 0.0, fee3 = 0.0, total3 = 0.0;
            bool validProduct3 = false, validQuantity3 = false;
            char confirmChoice3;
            
            // Customer Type for Order 3
            cout << "\nEnter customer type for Order #3 (R for Regular, P for Prime): ";
            cin >> customerType3;
            
            if (customerType3 != 'R' && customerType3 != 'P' && customerType3 != 'r' && customerType3 != 'p') {
                cout << "Invalid customer type! Defaulting to Regular." << endl;
                customerType3 = 'R';
            }
            
            // Order Input for Order 3
            cout << "Enter product ID for Order #3: ";
            cin >> orderId3;
            
            // Validate Product ID for Order 3
            if (orderId3 == p1Id) {
                validProduct3 = true;
                cout << "Product selected: " << p1Name << " - Price: $" << p1Price << " - Available: " << p1Qty << endl;
            } else if (orderId3 == p2Id) {
                validProduct3 = true;
                cout << "Product selected: " << p2Name << " - Price: $" << p2Price << " - Available: " << p2Qty << endl;
            } else if (orderId3 == p3Id) {
                validProduct3 = true;
                cout << "Product selected: " << p3Name << " - Price: $" << p3Price << " - Available: " << p3Qty << endl;
            } else {
                cout << "Invalid product ID! Skipping Order #3." << endl;
                validProduct3 = false;
            }
            
            if (validProduct3) {
                // Quantity for Order 3
                cout << "Enter quantity for Order #3: ";
                cin >> orderQty3;
                
                // Validate Quantity for Order 3
                if (orderId3 == p1Id && orderQty3 > 0 && orderQty3 <= p1Qty) {
                    validQuantity3 = true;
                    subtotal3 = p1Price * orderQty3;
                } else if (orderId3 == p2Id && orderQty3 > 0 && orderQty3 <= p2Qty) {
                    validQuantity3 = true;
                    subtotal3 = p2Price * orderQty3;
                } else if (orderId3 == p3Id && orderQty3 > 0 && orderQty3 <= p3Qty) {
                    validQuantity3 = true;
                    subtotal3 = p3Price * orderQty3;
                } else {
                    cout << "Invalid quantity! Available stock: ";
                    if (orderId3 == p1Id) cout << p1Qty;
                    else if (orderId3 == p2Id) cout << p2Qty;
                    else if (orderId3 == p3Id) cout << p3Qty;
                    cout << endl;
                    validQuantity3 = false;
                }
                
                if (validQuantity3) {
                    // Discount Calculation for Order 3
                    double primeDiscount3 = 0.0, regularDiscount3 = 0.0, bulkDiscount3 = 0.0;
                    
                    if ((customerType3 == 'P' || customerType3 == 'p') && subtotal3 > 50.0) {
                        primeDiscount3 = subtotal3 * 0.15;
                    }
                    if ((customerType3 == 'R' || customerType3 == 'r') && subtotal3 > 75.0) {
                        regularDiscount3 = subtotal3 * 0.10;
                    }
                    if (orderQty3 > 5) {
                        bulkDiscount3 = subtotal3 * 0.05;
                    }
                    
                    // Apply highest discount
                    if (primeDiscount3 >= regularDiscount3 && primeDiscount3 >= bulkDiscount3) {
                        discount3 = primeDiscount3;
                    } else if (regularDiscount3 >= primeDiscount3 && regularDiscount3 >= bulkDiscount3) {
                        discount3 = regularDiscount3;
                    } else {
                        discount3 = bulkDiscount3;
                    }
                    
                    // Fee Calculation for Order 3
                    double amountAfterDiscount3 = subtotal3 - discount3;
                    if (amountAfterDiscount3 < 20.0) {
                        fee3 = 2.50;
                    }
                    
                    total3 = amountAfterDiscount3 + fee3;
                    
                    // Display Order Summary for Order 3
                    cout << "\n=== ORDER #3 SUMMARY ===" << endl;
                    cout << "Subtotal: $" << subtotal3 << endl;
                    cout << "Discount: $" << discount3 << endl;
                    cout << "Fee: $" << fee3 << endl;
                    cout << "Total: $" << total3 << endl;
                    
                    // Confirmation for Order 3
                    cout << "Confirm Order #3? (Y/N): ";
                    cin >> confirmChoice3;
                    
                    if (confirmChoice3 == 'Y' || confirmChoice3 == 'y') {
                        // Update Inventory for Order 3
                        if (orderId3 == p1Id) {
                            p1Qty = p1Qty - orderQty3;
                        } else if (orderId3 == p2Id) {
                            p2Qty = p2Qty - orderQty3;
                        } else if (orderId3 == p3Id) {
                            p3Qty = p3Qty - orderQty3;
                        }
                        orderCount++;
                        cout << "Order #3 confirmed and inventory updated!" << endl;
                    } else {
                        cout << "Order #3 cancelled." << endl;
                    }
                }
            }
            
            // Display Final Stock Status
            cout << "\n=== FINAL STOCK STATUS ===" << endl;
            cout << "Product ID\tName\tRemaining Stock" << endl;
            cout << p1Id << "\t\t" << p1Name << "\t" << p1Qty << endl;
            cout << p2Id << "\t\t" << p2Name << "\t" << p2Qty << endl;
            cout << p3Id << "\t\t" << p3Name << "\t" << p3Qty << endl;
        }
    }
    
    // Final Summary
    cout << "\n=== ORDER SESSION COMPLETE ===" << endl;
    cout << "Total orders placed: " << orderCount << endl;
    cout << "Final inventory levels:" << endl;
    cout << "Product A: " << p1Qty << " units" << endl;
    cout << "Product B: " << p2Qty << " units" << endl;
    cout << "Product C: " << p3Qty << " units" << endl;
    
    cout << "\nThank you for using Smart Inventory & Order Assistant!" << endl;
    return 0;
}