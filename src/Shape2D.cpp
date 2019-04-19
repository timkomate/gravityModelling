#include "../include/Shape2D.h"
#include <iostream>
Shape2D::Shape2D(){
    this->coordX = 0;
    this->coordZ = 1000;
}

Shape2D::Shape2D(double coordX, double coordZ){
    this->coordX = coordX;
    this->coordZ = coordZ;
}

void Shape2D::print(){
    std::cout << "Shape2D:" << std::endl;
    std::cout << "X coordinate: " << coordX << std::endl;
    std::cout << "Z coordinate: " << coordZ << std::endl;
}

void Shape2D::setCoordX(double coordX){
    this->coordX = coordX;
}

void Shape2D::setCoordZ(double coordZ){
    this->coordZ = coordZ;
}

double Shape2D::getCoordX(){
    return coordX;
}

double Shape2D::getCoordZ(){
    return coordZ;
}