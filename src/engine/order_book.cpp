#include "order_book.h"

void OrderBook::addOrder(std::shared_ptr<Order> order) {
    if (order->getStatus() == OrderStatus::Pending) {
        if (order->getQuantity() > 0) {
            if (order->getPrice() < 0) {
                buyOrders.emplace(order->getPrice(), order);
            } else {
                sellOrders.emplace(order->getPrice(), order);
            }
        }
    }
}

void OrderBook::removeOrder(int orderId) {
    for (auto it = buyOrders.begin(); it != buyOrders.end(); ) {
        if (it->second->getId() == orderId) {
            it = buyOrders.erase(it); 
        } else {
            ++it; 
        }
    }

    for (auto it = sellOrders.begin(); it != sellOrders.end(); ) {
        if (it->second->getId() == orderId) {
            it = sellOrders.erase(it); 
        } else {
            ++it; 
        }
    }
}

void OrderBook::matchOrders() {
    while (!buyOrders.empty() && !sellOrders.empty()) {
        auto buyIt = buyOrders.rbegin(); 
        auto sellIt = sellOrders.begin(); 

        if (buyIt->first >= sellIt->first) {
            std::cout << "Matching Order: " 
                      << "Buy Order ID: " << buyIt->second->getId() 
                      << " with Sell Order ID: " << sellIt->second->getId() 
                      << " at Price: " << sellIt->first << std::endl;

            int matchedQuantity = std::min(buyIt->second->getQuantity(), sellIt->second->getQuantity());
            buyIt->second->reviseQuantity(buyIt->second->getQuantity() - matchedQuantity);
            sellIt->second->reviseQuantity(sellIt->second->getQuantity() - matchedQuantity);

            if (buyIt->second->getQuantity() == 0) {
                buyOrders.erase(--buyIt.base()); 
            }
            if (sellIt->second->getQuantity() == 0) {
                sellOrders.erase(sellIt); 
            }
        } else {
            break; 
        }
    }
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
