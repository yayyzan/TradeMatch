#include "ClientInterface.h"
#include <iostream>
#include <memory>

ClientInterface::ClientInterface(Exchange& exchange) : exchange(exchange) {}

void ClientInterface::run() {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleOrder();
                break;
            case 2:
                handleCancel();
                break;
            case 3:
                viewOrderBook();
                break;
            case 4: 
                exchange.displayTrades(); 
                break;
            case 0:
                std::cout << "Exiting client interface." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 0);
}

void ClientInterface::displayMenu() {
    std::cout << "\n--- Order Matching Client ---\n";
    std::cout << "1. Place Order\n";
    std::cout << "2. Cancel Order\n";
    std::cout << "3. View Order Book\n";
    std::cout << "4. View Trade History\n"; 
    std::cout << "0. Exit\n";
}

void ClientInterface::handleOrder() {
    int id, quantity;
    double price;
    char type;
    
    std::cout << "Enter Order ID: ";
    std::cin >> id;
    std::cout << "Enter Price: ";
    std::cin >> price;
    std::cout << "Enter Quantity: ";
    std::cin >> quantity;
    std::cout << "Enter Order Type (B for Buy, S for Sell): ";
    std::cin >> type;

    OrderType orderType = (type == 'B' || type == 'b') ? OrderType::Buy : OrderType::Sell;
    auto order = std::make_shared<Order>(id, price, quantity, orderType);

    exchange.placeOrder(order);
    std::cout << "Order placed successfully!\n";

    matchOrders(); 
}


void ClientInterface::handleCancel() {
    int orderId;
    std::cout << "Enter Order ID to cancel: ";
    std::cin >> orderId;

    if (exchange.cancelOrder(orderId)) {
        std::cout << "Order canceled successfully." << std::endl;
    } else {
        std::cout << "Order not found." << std::endl;
    }
}

void ClientInterface::viewOrderBook() const {
    std::cout << "\nCurrent Order Book:\n";
    exchange.getOrderBook().display(); 
}

void ClientInterface::matchOrders() {
    exchange.matchOrders();
}
