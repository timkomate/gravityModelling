#ifndef GRAVITYMODELLING_MODEL_H
#define GRAVITYMODELLING_MODEL_H

#include<iostream>
#include "LinSpace1D.h"
#include "ObservedAnomaly1D.h"
#include <fstream>
#include <random>
#include <math.h>

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

        void addNoise(double mean, double deviation){
            std::default_random_engine generator;
            std::normal_distribution<double> distribution(mean,deviation);
            for (int i = 0; i < anomaly.size(); i++){
                double noise = distribution(generator);
                anomaly[i] = anomaly[i] + noise;
            }
        }

        void writeAnomaly(std::string fileName){
            std::ofstream outputFile;
            outputFile.open(fileName);
            for (int i = 0; i < anomaly.size();i++){
                outputFile << linSpace1D->getElement(i) << " " << anomaly[i] << std::endl;
            }
            outputFile.close();
        }

        std::vector<double> getAnomaly(){
            return anomaly;
        }

        T getShape(){
            return shape;
        }

        void addObservation(ObservedAnomaly1D * observedAnomaly1D){
            this-> observedAnomaly1D = observedAnomaly1D;
        }

        void calculateResidual(){
            residual = 0;
            for (int i = 0; i < anomaly.size(); i++){
                residual = residual + (pow(anomaly[i] - observedAnomaly1D->getAnomaly(i),2));
                //std::cout << residual << std::endl;
            }
            residual = sqrt(residual) / anomaly.size();           
        }

    private:
        LinSpace1D * linSpace1D;
        ObservedAnomaly1D * observedAnomaly1D;
        T shape;
        double residual = 0;
        std::vector<double> anomaly;
};

#endif //  GRAVITYMODELLING_MODEL_H