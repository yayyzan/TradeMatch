#include "Exchange.h"
#include "Logger.h"
#include <iostream>

Exchange::Exchange() : orderBook() {}

void Exchange::placeOrder(const std::shared_ptr<Order>& order) {
    orderBook.addOrder(order);
    Logger::logOrder(*order);
}

bool Exchange::cancelOrder(int orderId) {
    bool result = orderBook.cancelOrder(orderId);
    if (!result) {
        Logger::logError("Failed to cancel order with ID: " + std::to_string(orderId));
    }
    return result;
}

void Exchange::recordTrade(const Trade& trade) {
    tradeHistory.push_back(trade);
    Logger::logTrade(trade);
}

void Exchange::matchOrders() {
    auto trades = orderBook.matchOrders();
    for (const auto& trade : trades) {
        recordTrade(trade);
    }
}

void Exchange::displayTrades() const {
    for (const auto& trade : tradeHistory) {
        trade.display();
    }
}

OrderBook& Exchange::getOrderBook() {
    return orderBook;
}
