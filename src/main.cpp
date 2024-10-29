#include <iostream>
#include "engine/Exchange.h"
#include "client/ClientInterface.h"

int main() {
    Exchange exchange; 
    ClientInterface client(exchange); 

    client.run(); 

    return 0; 
}
