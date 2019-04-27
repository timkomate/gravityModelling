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
        static int ID;
        Model(LinSpace1D * linSpace1D, T shape){
            this->linSpace1D = linSpace1D;
            this->shape = shape;
            modelID = ++ID;
        }

        Model(LinSpace1D * linSpace1D){
            this->linSpace1D = linSpace1D;
            this->shape = T::makeShape();
            modelID = ++ID;
        }

        Model(LinSpace1D * linSpace1D, ObservedAnomaly1D * observedAnomaly1D){
            this->linSpace1D = linSpace1D;
            this->shape = T::makeShape();
            calculateAnomaly();
            addObservation(observedAnomaly1D);
            calculateResidual();
            modelID = ++ID;
        }

        Model(LinSpace1D * linSpace1D, ObservedAnomaly1D * observedAnomaly1D, T shape){
            this->linSpace1D = linSpace1D;
            this->shape = shape;
            calculateAnomaly();
            addObservation(observedAnomaly1D);
            calculateResidual();
            modelID = ++ID;
        }


        void print(){
            shape.print();
            linSpace1D->print(false);
            std::cout << "Residual: " << residual << std::endl;
            std::cout << "ID: " << modelID << std::endl;
            std::cout << std::endl;
        }

        void calculateAnomaly(){
            anomaly.clear();
            for (int i = 0; i<linSpace1D->getSize();i++){
                anomaly.push_back(shape.forwardModel(linSpace1D->getElement(i)));
                //std::cout << anomaly[i] << std::endl;
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

        T* getShapePointer(){
            return &shape;
        }

        void addObservation(ObservedAnomaly1D * observedAnomaly1D){
            this->observedAnomaly1D = observedAnomaly1D;
        }

        void calculateResidual(){
            residual = 0;
            for (int i = 0; i < anomaly.size(); i++){
                residual = residual + (pow(anomaly[i] - observedAnomaly1D->getAnomaly(i),2));
                //std::cout << residual << std::endl;
            }
            residual = sqrt(residual) / anomaly.size();           
        }

        double getResidual(){
            return residual;
        }

        static Model<T> pairModels(Model<T> m1, Model<T> m2, LinSpace1D * linSpace1D, ObservedAnomaly1D * observedAnomaly1D, double mutationFactor){
            T shape = T::breedShape(m1.getShapePointer(),m2.getShapePointer(), mutationFactor);
            return Model(linSpace1D, observedAnomaly1D, shape);
        }

    private:
        LinSpace1D * linSpace1D;
        ObservedAnomaly1D * observedAnomaly1D;
        T shape;
        double residual = 0;
        std::vector<double> anomaly;
        unsigned int modelID;
        friend bool operator<(const Model<T>& p1, const Model<T>& p2){
            return p1.residual < p2.residual;
        }
        friend bool operator>(const Model<T>& p1, const Model<T>& p2){
            return p1.residual > p2.residual;
        }
};

/*
template <class T>
struct cca {
    bool operator()(Model<T>& a, Model<T>& b) const {
        return a.getResidual() < b.getResidual();
    }
};*/



#endif //  GRAVITYMODELLING_MODEL_H