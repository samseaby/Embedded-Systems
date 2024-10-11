#include "mbed.h"
#include "Rectangle.hpp"

Rectangle::Rectangle(float length, float width){
    this->_length = length;
    this->_width = width;
}
void Rectangle::area(){
    this->_area = this->_length * this->_width;
    printf("\nLength: %f, Width: %f, Area: %f",_length, _width, _area);
}
void Rectangle::perimeter(){
    this->_perimeter = this->_length + this->_length + this->_width + this->_width;
    printf(" Perimeter: %f",_perimeter);
}