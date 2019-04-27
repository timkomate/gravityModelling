#ifndef GRAVITYMODELLING_POPULATION_H
#define GRAVITYMODELLING_POPULATION_H

#include<iostream>
#include "LinSpace1D.h"
#include "ObservedAnomaly1D.h"
#include "Model.hpp"
#include <fstream>
#include <random>
#include <math.h>
#include <queue> 
#include <vector>
using namespace std;

template<class T, size_t popSize >
class Population{
    public:
        /*Population(LinSpace1D * linSpace1D, ObservedAnomaly1D * observedAnomaly1D){
            for (int i = 0; i < popSize; i++){
                pq.push(Model<T>(linSpace1D, observedAnomaly1D));
            }
        }*/
        Population(){

        }
        void addModel(Model<T> model){
            pq.push(model);
        }

        void printModels(){
            while(!pq.empty()){
                Model<T> model = pq.top();
                pq.pop();
                model.print();
            }
        }

        Model<T> top(){
            return pq.top();
        }

    private:
        priority_queue<Model<T>, vector<Model<T>>, greater<Model<T>>> pq;


};



#endif //  GRAVITYMODELLING_POPULATION_H