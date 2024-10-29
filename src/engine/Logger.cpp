#include "Logger.h"
#include <iostream>

void Logger::logOrder(const Order& order) {
    std::cout << "Order placed - ID: " << order.getId()
              << ", Price: " << order.getPrice()
              << ", Quantity: " << order.getQuantity()
              << ", Type: " << (order.isBuyOrder() ? "Buy" : "Sell") << std::endl;
}

void Logger::logTrade(const Trade& trade) {
    std::cout << "Trade executed - Buy Order ID: " << trade.getBuyOrderId()
              << ", Sell Order ID: " << trade.getSellOrderId()
              << ", Price: " << trade.getPrice()
              << ", Quantity: " << trade.getQuantity() << std::endl;
}

void Logger::logError(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
}
