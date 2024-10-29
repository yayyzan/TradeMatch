#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include "Trade.h"
#include <map>
#include <memory>
#include <vector>

class OrderBook {
public:
    void addOrder(const std::shared_ptr<Order>& order);
    bool cancelOrder(int orderId);  
    std::vector<Trade> matchOrders(); 
    void display() const;

private:
    std::multimap<double, std::shared_ptr<Order>, std::greater<double>> buyOrders; 
    std::multimap<double, std::shared_ptr<Order>> sellOrders; 
};

#endif 
