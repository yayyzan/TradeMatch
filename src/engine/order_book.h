#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "order.h"

class OrderBook{
public:
    OrderBook() = default;

    void addOrder(std::shared_ptr<Order> order);

    void removeOrder(int orderId);

    void matchOrders();

    void display() const;

private:
    std::multimap<double, std::shared_ptr<Order>> buyOrders; 
    std::multimap<double, std::shared_ptr<Order>> sellOrders;
};

#endif