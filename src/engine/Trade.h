#ifndef TRADE_HPP
#define TRADE_HPP

#include <iostream>

class Trade {
public:

    Trade(int buyOrderId, int sellOrderId, double price, int quantity);

    int getBuyOrderId() const;
    int getSellOrderId() const;
    double getPrice() const;
    int getQuantity() const;

    void display() const;

private:
    int tradeId;
    int buyOrderId;
    int sellOrderId;
    double price;
    int quantity;
};

#endif 