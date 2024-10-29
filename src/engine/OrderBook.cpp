#include "OrderBook.h"

void OrderBook::addOrder(const std::shared_ptr<Order>& order) {
    if (order->isBuyOrder()) {
        buyOrders.insert({order->getPrice(), order});
    } else {
        sellOrders.insert({order->getPrice(), order});
    }
}

bool OrderBook::cancelOrder(int orderId) {
    for (auto it = buyOrders.begin(); it != buyOrders.end(); ++it) {
        if (it->second->getId() == orderId) {
            buyOrders.erase(it);
            return true; 
        }
    }
    
    for (auto it = sellOrders.begin(); it != sellOrders.end(); ++it) {
        if (it->second->getId() == orderId) {
            sellOrders.erase(it);
            return true; 
        }
    }

    return false; 
}

std::vector<Trade> OrderBook::matchOrders() {
    std::vector<Trade> trades;

    while (!buyOrders.empty() && !sellOrders.empty()) {
        auto buyIt = buyOrders.begin();
        auto sellIt = sellOrders.begin();

        double buyPrice = buyIt->first;
        double sellPrice = sellIt->first;

        if (buyPrice >= sellPrice) {
            int buyQuantity = buyIt->second->getQuantity();
            int sellQuantity = sellIt->second->getQuantity();
            int matchQuantity = std::min(buyQuantity, sellQuantity);

            Trade trade(buyIt->second->getId(), sellIt->second->getId(), sellPrice, matchQuantity);
            trades.push_back(trade);

            buyIt->second->reviseQuantity(buyQuantity - matchQuantity);
            sellIt->second->reviseQuantity(sellQuantity - matchQuantity);

            if (buyIt->second->getQuantity() == 0) {
                buyOrders.erase(buyIt);
                sellIt->second->setStatus(OrderStatus::Partial);
            }
            if (sellIt->second->getQuantity() == 0) {
                sellOrders.erase(sellIt);
                buyIt->second->setStatus(OrderStatus::Partial);
            }
        } else {
            break; 
        }
    }

    return trades;
}

void OrderBook::display() const {
    std::cout << "Buy Orders:" << std::endl;
    for (const auto& order : buyOrders) {
        order.second->display();
    }
    std::cout << "Sell Orders:" << std::endl;
    for (const auto& order : sellOrders) {
        order.second->display();
    }
}

