#include "order.h"
#include <stdexcept>
#include <iostream>

Order::Order(int id, double price, int quantity)
    : id(id), price(price), quantity(quantity) {
        
        if (quantity <= 0){
            throw std::invalid_argument("Quantity cannot be less than zero");
        }

        if (price < 0){
            throw std::invalid_argument("Price must be greater than zero");
        }

        std::cout << "Order placed -> ID: " << id << ", Price: " << price << ", Quantity: " << quantity << std::endl;
}

int Order::getID() const {
    return id;
}

int Order::getQuantity() const {
    return quantity;
}

double Order::getPrice() const {
    return price;
}

OrderStatus Order::getStatus() const {
    return status;
}

void Order::setStatus(OrderStatus status) {
    this->status = status;
}

void Order::display() const {
    std::cout << "Order ID: " << id 
              << ", Price: " << price 
              << ", Quantity: " << quantity 
              << ", Status: " << static_cast<int>(status) // You might want to implement a better way to print status
    << std::endl;
}

void Order::revisePrice(double newPrice){
    if (newPrice < 0) {
        throw std::invalid_argument("Price must be non-negative.");
    }
    price = newPrice;
}

void Order::reviseQuantity(int newQuantity){
    if (newQuantity <= 0) {
        throw std::invalid_argument("Quantity must be greater than zero.");
    }
    quantity = newQuantity;
}
