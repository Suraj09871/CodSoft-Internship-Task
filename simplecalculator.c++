#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "Welcome to the calculator program!" << std::endl;
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    switch (operation) {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2!= 0) {
                std::cout << "Result: " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error: Division by zero!" << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operation!" << std::endl;
            break;
    }

    return 0;
}