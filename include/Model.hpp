#ifndef GRAVITYMODELLING_MODEL_H
#define GRAVITYMODELLING_MODEL_H

#include<iostream>
#include"LinSpace1D.h"

template<class T>
class Model{
    public:
        Model(LinSpace1D * linSpace1D, T shape){
            this->linSpace1D = linSpace1D;
            this->shape = shape;
        }

        void print(){
            shape.print();
            linSpace1D->print(false);
            std::cout << "Residual: " << residual << std::endl;
        }

        void calculateAnomaly(){
            for (int i = 0; i<linSpace1D->getSize();i++){
                anomaly.push_back(shape.forwardModel(linSpace1D->getElement(i)));
            }
        }
    private:
        LinSpace1D * linSpace1D;
        T shape;
        double residual = 0;
        std::vector<double> anomaly;
};

#endif //  GRAVITYMODELLING_MODEL_H