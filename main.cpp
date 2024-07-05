#include <iostream>
#include <math.h>
#include <tuple>

int operate();


int failOperator(){
    std::cout << "Sorry, the operator you entered is invalid. Please try again." << "\n";
    return operate();
}


bool checkOp(char op) {

    switch (op) {
        case '+':
        case '-':
        case '*':
        case 'x':
        case 'X':
        case '/':
            return true; 
        default:
            return false;
    }
}

std::tuple<int, int, char> getInputs() {
    int numA {};
    int numB {};
    char arithmeticOperator {};
    
    std::cout << "Please enter your operation (e.g., 1 + 1): ";
    std::cin >> numA >> arithmeticOperator >> numB;
    
    // Return a tuple containing numA, numB, and arithmeticOperator
    return std::make_tuple(numA, numB, arithmeticOperator);
}

int operation(int numA, int numB, char op){
    int result {};
    switch (op) {
        case '+':
            result = numA + numB;
            break;
        case '-':
            result = numA - numB;
            break;
        case '*':
        case 'x':
        case 'X':
            result = numA * numB;
            break;
        case '/':
            // Check for division by zero
            if (numB == 0) {
                std::cout << "Error: Division by zero is not allowed." << "\n";
                return operate();  // Restart the operation
            }
            result = numA / numB;
            break;
        default:
            std::cerr << "Unexpected error occurred." << "\n";
            return 1;
    }

    return result;
}

int operate(){
    auto inputs = getInputs();

    int numA {std::get<0>(inputs)};
    int numB {std::get<1>(inputs)};
    char arithmeticOperator {std::get<2>(inputs)};

    bool operatorValidation {checkOp(arithmeticOperator)};

    if(!operatorValidation) {
        return failOperator();
    }

    int result = operation(numA, numB, arithmeticOperator);

    std::cout << result << "\n";

    return operate();
}

int main()
{
    operate();
    return 0;
}