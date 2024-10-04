#include "mbed.h"
#include <iostream>
#include <complex> 

// Function declarations
double absOfImaginary(double real, double imag);
void bin2hex(std::string binString);

int main()
{
    // Variable declarations
    double real;
    double imag;
    std::string binString;

    // Take user inputs for real and imaginary numbers 
    std::cout << "Please enter your real number: ";
    std::cin >> real;

    std::cout << "\nPlease enter your imaginary number: ";
    std::cin >> imag;

    // Save result of function and display
    double converted = absOfImaginary(real, imag);
    std::cout << '\n' << "Your absolute value is: " << converted << std::endl;

    // Record custom binary string and input to conversion function
    std::cout << "Input binary string to be converted: ";
    std::cin >> binString;
    bin2hex(binString);
}

double absOfImaginary(double real, double imag) {
    std::complex<double> complexNum(real, imag);    // Create complexNum of type double, similar to struct, just does the heavy lifting for you
    double converted = std::abs(complexNum);        // Take absolute of complex number
    return converted;
}

void bin2hex(std::string binString) {
    // Both functions part of std library 
    // c_str takes user input and outputs as c style string to be compatible with printf
    // stoi converts string to integer of base 2 to allow easy hex conversion, nullptr is output location of converted string
    printf("\n%s is %x in hex\n", binString.c_str(), std::stoi(binString,nullptr,2));

}


