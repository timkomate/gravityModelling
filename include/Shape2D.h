
#ifndef GRAVITYMODELLING_SHAPE2D_H
#define GRAVITYMODELLING_SHAPE2D_H

#include<iostream>

class Shape2D{
    public:
        Shape2D();
        Shape2D(double,double);
        virtual void print();
        virtual void setCoordX(double);
        virtual void setCoordZ(double);
        virtual double getCoordX();
        virtual double getCoordZ();
        virtual double forwardModel(double) = 0;
    protected:
        double coordX;
        double coordZ;
};

#endif //  GRAVITYMODELLING_SHAPE2D_H