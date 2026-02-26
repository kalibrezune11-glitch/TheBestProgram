#include <iostream>
#include <string> // for std::stoi

int main(int argc, char* argv[]) {
    // 1. Check if the user provided exactly two arguments
    // argc counts the program name as the first argument, so we need argc == 3
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <num1> <num2>" << std::endl;
        return 1; 
    }

    try {
        // 2. Convert strings from argv to integers
        int a = std::stoi(argv[1]);
        int b = std::stoi(argv[2]);

        // 3. Perform and print operations
        std::cout << "Results for " << a << " and " << b << ":" << std::endl;
        std::cout << "Addition:       " << a << " + " << b << " = " << (a + b) << std::endl;
        std::cout << "Subtraction:    " << a << " - " << b << " = " << (a - b) << std::endl;
        std::cout << "Multiplication: " << a << " * " << b << " = " << (a * b) << std::endl;

        // 4. Handle division with a safety check
        if (b != 0) {
            // Cast to double for precise division results
            double quotient = static_cast<double>(a) / b;
            std::cout << "Division:       " << a << " / " << b << " = " << quotient << std::endl;
        } else {
            std::cout << "Division:       Undefined (cannot divide by zero)" << std::endl;
        }

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Please provide valid integers." << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: One of the numbers is too large for an int." << std::endl;
        return 1;
    }

    return 0;
}
