#include "mbed.h"

// Declare class Rectangle 
class Rectangle{

    // Initialise private variables to be accessed by class
    private:
        float _length;
        float _width;
        float _area;
        float _perimeter;

    // Declare public member functions
    public:
        // Constuctor to assign user inputs to private class variables
        Rectangle(float length, float width){
            _length = length;
            _width = width;
        }

        // Returns value of length
        float Length(){
            return _length;
        }

        // Returns value of Width
        float Width(){
            return _width;
        }

        // Calculates and returns area
        float area(){
            _area = _length * _width;
            return _area;
        }

        // Calculates and returns perimeter
        float perimeter(){
            _perimeter = _length + _length + _width + _width;
            return _perimeter;
        }
};

int main(){

    // Create object of Rectangle class with length and width values
    Rectangle rectangle1(3, 2);

    // Print values for length, width, area and perimeter using class member functions
    printf("\nLength: %f, Width: %f, Area: %f, Perimeter: %f", rectangle1.Length(), rectangle1.Width(), rectangle1.area(), rectangle1.perimeter());
}