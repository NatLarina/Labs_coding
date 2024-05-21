#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

struct Product {
    std::string name;
    std::string category;
    double price;
    int quantity;
    std::string description;
};

std::vector<Product> products;
std::string filename = "products.txt";

void saveToFile() {
    std::ofstream file(filename);
    for (const auto& product : products) {
        file << product.name << "," << product.category << "," << product.price << "," << product.quantity << "," << product.description << "\n";
    }
    file.close();
    std::cout << "Data saved to file." << std::endl;
}

void loadFromFile() {
    products.clear();
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        Product product;
        std::getline(ss, product.name, ',');
        std::getline(ss, product.category, ',');
        ss >> product.price;
        ss.ignore();
        ss >> product.quantity;
        ss.ignore();
        std::getline(ss, product.description, '\n');
        products.push_back(product);
    }
    file.close();
    std::cout << "Data loaded from file." << std::endl;
}

void addProduct() {
    Product product;
    std::cout << "Enter product name: ";
    std::getline(std::cin, product.name);
    std::cout << "Enter product category: ";
    std::getline(std::cin, product.category);
    std::cout << "Enter product price: ";
    std::cin >> product.price;
    std::cout << "Enter product quantity: ";
    std::cin >> product.quantity;
    std::cin.ignore();
    std::cout << "Enter product description: ";
    std::getline(std::cin, product.description);
    products.push_back(product);
    std::cout << "Product added successfully." << std::endl;
}

void editProduct() {
    int index;
    std::cout << "Enter index of product to edit: ";
    std::cin >> index;
    if (index >= 0 && index < products.size()) {
        Product& product = products[index];
        std::cout << "Enter new product name (" << product.name << "): ";
        std::cin.ignore();
        std::getline(std::cin, product.name);
        std::cout << "Enter new product category (" << product.category << "): ";
        std::getline(std::cin, product.category);
        std::cout << "Enter new product price (" << product.price << "): ";
        std::cin >> product.price;
        std::cout << "Enter new product quantity (" << product.quantity << "): ";
        std::cin >> product.quantity;
        std::cin.ignore();
        std::cout << "Enter new product description (" << product.description << "): ";
        std::getline(std::cin, product.description);
        std::cout << "Product edited successfully." << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

void deleteProduct() {
    int index;
    std::cout << "Enter index of product to delete: ";
    std::cin >> index;
    if (index >= 0 && index < products.size()) {
        products.erase(products.begin() + index);
        std::cout << "Product deleted successfully." << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

void searchProduct() {
    std::string query;
    std::cout << "Enter search query: ";
    std::cin.ignore();
    std::getline(std::cin, query);
    bool found = false;
    for (const auto& product : products) {
        if (product.name.find(query) != std::string::npos ||
            product.category.find(query) != std::string::npos ||
            product.description.find(query) != std::string::npos) {
            std::cout << "Name: " << product.name << ", Category: " << product.category << ", Price: " << product.price << ", Quantity: " << product.quantity << ", Description: " << product.description << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No products found." << std::endl;
    }
}

void printProducts() {
    for (const auto& product : products) {
        std::cout << "Name: " << product.name << ", Category: " << product.category << ", Price: " << product.price << ", Quantity: " << product.quantity << ", Description: " << product.description << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nProduct Database Menu" << std::endl;
        std::cout << "1. Load data from file" << std::endl;
        std::cout << "2. Save data to file" << std::endl;
        std::cout << "3. Add product" << std::endl;
        std::cout << "4. Edit product" << std::endl;
        std::cout << "5. Delete product" << std::endl;
        std::cout << "6. Search product" << std::endl;
        std::cout << "7. Print all products" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                loadFromFile();
                break;
            case 2:
                saveToFile();
                break;
            case 3:
                addProduct();
                break;
            case 4:
                editProduct();
                break;
            case 5:
                deleteProduct();
                break;
            case 6:
                searchProduct();
                break;
            case 7:
                printProducts();
                break;
            case 8:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 8);

    return 0;
}
