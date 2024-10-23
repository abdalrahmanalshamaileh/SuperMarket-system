# Super Market Management System

This is a simple Super Market Management System developed in C++. The system provides two types of users: the **Administrator** and the **Buyer**. Administrators can manage the inventory by adding, editing, or removing products, while buyers can purchase products and receive a receipt showing their total order cost, including discounts.

#Features

- **Admin**
  - Login system for admin
  - Add new products to the inventory
  - Modify existing products
  - Delete products from the inventory
  - View the list of available products

- **Buyer**
  - View available products
  - Buy products by entering their code and quantity
  - Receive a receipt with a breakdown of the product prices, discounts, and the total cost

#Project Structure

The project contains a single class `shopping` that handles all the functionalities of the supermarket management system.

- menu(): Displays the main menu and allows users to choose between admin or buyer mode.
- admin(): Displays admin-specific options such as adding, editing, or removing products.
- buyer(): Handles the purchasing process for buyers, allowing them to select products and generate receipts.
- add(): Allows the admin to add new products to the inventory.
- edit(): Allows the admin to modify details of existing products.
- rem(): Allows the admin to delete products from the inventory.
- list(): Displays all available products in the inventory.
- receipt(): Generates a receipt for the buyer after purchasing products, showing the total cost, including discounts.




