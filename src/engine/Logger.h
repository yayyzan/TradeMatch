#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include "Order.h"
#include "Trade.h"

class Logger {
public:
    static void logOrder(const Order& order);
    static void logTrade(const Trade& trade);
    static void logError(const std::string& message);
};

#endif 
