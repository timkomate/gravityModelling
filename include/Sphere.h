#ifndef GRAVITYMODELLING_SPHERE_H
#define GRAVITYMODELLING_SPHERE_H

#include<iostream>
#include "./Shape2D.h"

class Sphere: public Shape2D{
    public:
        Sphere();
        Sphere(double,double,double,double);
        void print();
        void setDeltaRho(double);
        void setRadius(double);
        double getDeltaRho();
        double getRadius();
        double forwardModel(double);
    protected:
        double radius;
        double deltaRho;
};

#endif //  GRAVITYMODELLING_SPHERE_H