#include "../include/Sphere.h"
#include "../include/Shape2D.h"
#include <math.h>

Sphere::Sphere():Shape2D(){
    this->deltaRho = 1000;
    this->radius = 100;
}

Sphere::Sphere(double coordX,double coordZ ,double deltaRho, double radius)
:Shape2D(coordX, coordZ){
    this->deltaRho = deltaRho;
    this->radius = radius;
}

void Sphere::print(){
    std::cout << "Sphere:" << std::endl;
    std::cout << "X coordinate: " << coordX << std::endl;
    std::cout << "Z coordinate: " << coordZ << std::endl;
    std::cout << "Delta rho: " << deltaRho << std::endl;
    std::cout << "Radius: " << radius << std::endl;
    std::cout << std::endl;
}

void Sphere::setDeltaRho(double deltaRho){
    this->deltaRho = deltaRho;
}

void Sphere::setRadius(double radius){
    this->radius = radius;
}

double Sphere::getDeltaRho(){
    return deltaRho;
}
double Sphere::getRadius(){
    return radius;
}

double Sphere::forwardModel(double x){
    double G=6.67e-11; //gravitational constant
    return 4.0/3.0*M_PI*G*deltaRho*1.0e5*radius*radius*radius*
            1/(pow(x-coordX,2)+pow(coordZ,2))*
            coordZ/(pow((pow(x-coordX,2) + pow(coordZ,2)),(2/3))); //mgal
}