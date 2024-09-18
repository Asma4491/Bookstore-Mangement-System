# Bookstore Management System

This is a simple C++ project that simulates a bookstore management system. It allows users to view available books, add books to their cart, remove books from the cart, and complete the checkout process. The system manages the bookstore's inventory, ensuring that books added to the cart are updated with the correct stock quantities.

## Features

- **Inventory Management:** View all available books in the store with their details, including ISBN, title, author, price, and stock.
- **Cart Functionality:** 
  - Add books to the cart with a specified quantity.
  - Remove books from the cart.
  - Total cost calculation for items in the cart.
- **Checkout System:** 
  - Deduct purchased books from the inventory.
  - Clear the cart and reset total cost upon successful checkout.
- **Search Functionality:** Search books by ISBN, title, or author.

## Classes

- `Book`: Represents a book in the store, holding its ISBN, title, author, price, and stock count.
- `Cart`: Manages the user's shopping cart, including adding, removing, and tracking the total cost of books.
- `Store`: Manages the bookstore's inventory and supports searching for books.

## Getting Started

### Prerequisites

- You need a C++ compiler to run this project.
- Basic knowledge of C++ and object-oriented programming concepts.

### Running the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/Asma4491/bookstore-management-system.git

2. Navigate to the project directory:

```bash
cd bookstore-management-system
```
3. Compile the code:

```bash
g++ -o bookstore main.cpp
```
4. Run the executable:

```bash
./bookstore
```
## Usage

Once you run the program, you can interact with the system using the provided menu:

1. View All Books: Displays the list of available books with their details.
2. Add Book to Cart: Adds a book to your shopping cart by entering its ISBN and quantity.
3. Remove Book from Cart: Removes a book from your shopping cart by entering its ISBN.
4. Checkout: Finalizes the purchase, deducts the items from inventory, and clears your cart.
5. Exit: Exits the program.


## Sample Output

1. View all books
2. Add book to cart
3. Remove book from cart
4. Checkout
5. Exit
Enter your choice: 1

ISBN       Title                         Author              Price    Quantity
--------------------------------------------------------------------------------
ISBN123    Book 1                        Author 1            19.99        10
ISBN456    Book 2                        Author 2            24.99         5

## Customization
You can easily extend the system by:

1. Adding more books to the inventory.
2. Enhancing the search functionality with additional filters.
3. Implementing features like book categorization or user authentication.
