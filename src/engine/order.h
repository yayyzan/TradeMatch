#ifndef ORDER_H
#define ORDER_H

enum class OrderStatus{
    Pending,
    Matched, 
    Partial, 
    Cancelled
};

class Order {
public:
    Order(int id, double price, int quantity);

    int getId() const;
    int getQuantity() const; 
    double getPrice() const;
    OrderStatus getStatus() const;

    void setStatus(OrderStatus status);

    void display() const;

    void revisePrice(double newPrice);
    void reviseQuantity(int newQuantity);

private:
    int id; 
    double price; 
    int quantity;
    OrderStatus status;
};

#endif