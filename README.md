# TradeMatch

TradeMatch is an in-memory order matching engine designed to simulate an exchange. It allows users to place buy and sell orders, view the order book, and see executed trades.

## Features

- **Order Placement**: Users can place buy and sell orders with specified prices and quantities.
- **Order Matching**: Automatically matches buy and sell orders based on price and quantity.
- **Order Book**: View the current state of the order book, including open orders.
- **Trade Execution**: Displays executed trades after orders are placed or matched.
- **Order Cancellation**: Allows users to cancel existing orders.

## Structure

The project consists of the following key components:

- **Order**: Represents individual buy or sell orders.
- **Trade**: Represents executed trades between buy and sell orders.
- **OrderBook**: Manages the collection of active orders and handles matching logic.
- **Exchange**: Orchestrates order placement, cancellation, and trade execution.
- **ClientInterface**: Provides a user interface for interacting with the exchange.

## Getting Started

### Prerequisites

- C++11 or later
- CMake
- A C++ compiler (e.g., g++, clang++)

### Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/yayyzan/TradeMatch.git
   cd TradeMatch
   ```

2. Run the script
    ```bash
    ./build.sh
    ```


