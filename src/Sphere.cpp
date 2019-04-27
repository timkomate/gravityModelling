#include "../include/Sphere.h"
#include "../include/Shape2D.h"
#include <math.h>
#include <random>

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


Sphere Sphere::makeShape(){
    double minCoordX = -100;
    double maxCoordX = 100;
    double minCoordZ = 50;
    double maxCoordZ = 1000;
    double minDeltaRho = 100;
    double maxDeltaRho = 5000;
    double minRadius = 5;
    double maxRadius = 100;
    std::random_device re;

    std::uniform_real_distribution<double> X(minCoordX,maxCoordX);
    std::uniform_real_distribution<double> Z(minCoordZ,maxCoordZ);
    std::uniform_real_distribution<double> DR(minDeltaRho,maxDeltaRho);
    std::uniform_real_distribution<double> R(minRadius,maxRadius);

    Sphere sp(X(re), Z(re), DR(re), R(re));
    return sp;
}

Sphere Sphere::breedShape(Sphere * s1, Sphere * s2, double mutationFactor){
    double x, z, dr, r;
    std::random_device re;
    std::uniform_real_distribution<double> R(0,1);
    std::uniform_int_distribution<int> X(1,2);
    if (R(re) <=  mutationFactor){
        return Sphere::makeShape();
    }
    if (X(re) == 1)
        x = s1->getCoordX();
    else
        x = s2->getCoordX();
    
    if (X(re) == 1)
        z = s1->getCoordZ();
    else
        z = s2->getCoordZ();
    
    if (X(re) == 1)
        dr = s1->getDeltaRho();
    else
        dr = s2->getDeltaRho();

    if (X(re) == 1)
        r = s1->getRadius();
    else
        r = s2->getRadius();
    return Sphere(x,z,dr,r);
}

/*
Sphere * Sphere::makeSphere(){
    double minCoordX = -100;
    double maxCoordX = 100;
    double minCoordZ = 50;
    double maxCoordZ = 1000;
    double minDeltaRho = 100;
    double maxDeltaRho = 5000;
    double minRadius = 5;
    double maxRadius = 100;
    std::random_device re;

    std::uniform_real_distribution<double> X(minCoordX,maxCoordX);
    std::uniform_real_distribution<double> Z(minCoordZ,maxCoordZ);
    std::uniform_real_distribution<double> DR(minDeltaRho,maxDeltaRho);
    std::uniform_real_distribution<double> R(minRadius,maxRadius);

    Sphere * sp = new Sphere(X(re), Z(re), DR(re), R(re));
    return sp;
}*/