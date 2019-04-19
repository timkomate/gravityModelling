#ifndef GRAVITYMODELLING_LINSPACE_H
#define GRAVITYMODELLING_LINSPACE_H

#include<iostream>
#include<vector>
class LinSpace1D{
    public:
        LinSpace1D();
        LinSpace1D(double, double);
        LinSpace1D(double, double, double);
        void print();
        double getElement(int);
        double getStepSize();
        double getBegin();
        double getEnd();
        unsigned int getSize(); 
        std::vector<double> getContainer();
        void setContainer(std::vector<double>);
        void print(bool);
    private:
        double begin;
        double end;
        double stepSize;
        unsigned int size;
        std::vector<double> container;
        void initContainer();
};

#endif //  GRAVITYMODELLING_LINSPACE_H