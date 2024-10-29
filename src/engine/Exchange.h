#ifndef EXCHANGE_HPP
#define EXCHANGE_HPP

#include <vector>
#include "OrderBook.h"
#include "Trade.h"

class Exchange {
public:
    Exchange();
    void placeOrder(const std::shared_ptr<Order>& order);
    bool cancelOrder(int orderId);
    void matchOrders();
    void displayTrades() const;

    OrderBook& getOrderBook();

private:
    OrderBook orderBook;
    std::vector<Trade> tradeHistory;
    void recordTrade(const Trade& trade);
};

#endif 
