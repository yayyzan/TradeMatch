#ifndef ORDER_H
#define ORDER_H

enum class OrderStatus{
    Pending,
    Matched, 
    Partial, 
    Cancelled
};

enum class OrderType{
    Buy,
    Sell
};

class Order {
public:
    Order(int id, double price, int quantity, OrderType type);

    int getId() const;
    int getQuantity() const; 
    double getPrice() const;
    OrderStatus getStatus() const;
    OrderType getType() const;
    bool isBuyOrder() const;

    void setStatus(OrderStatus status);

    void display() const;

    void revisePrice(double newPrice);
    void reviseQuantity(int newQuantity);

private:
    int id; 
    double price; 
    int quantity;
    OrderStatus status;
    OrderType type;
};

#endif