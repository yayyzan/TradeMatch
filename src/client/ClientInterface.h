#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include "../engine/Exchange.h"

class ClientInterface {
public:
    ClientInterface(Exchange& exchange);
    void run();

private:
    Exchange& exchange;

    void displayMenu();
    void handleOrder();
    void handleCancel();
    void viewOrderBook() const;
    void matchOrders();
};

#endif 
