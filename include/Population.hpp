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
//using namespace std;

template<class T, size_t popSize, size_t generationSize >
class Population{
    public:
        Population(LinSpace1D * linSpace1D, ObservedAnomaly1D * observedAnomaly1D){
            this->linSpace1D = linSpace1D;
            this->observedAnomaly1D = observedAnomaly1D;
            for (int i = 0; i < popSize; i++){
                //std::cout << i << std::endl;
                addModel(Model<T>(linSpace1D, observedAnomaly1D));
            }
        }

        Population(){}

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

        void makePool(){
            pool.clear();
            for (int i = 0; i < popSize / 10; i++){
                pool.push_back(pq.top());
                pq.pop();
            }
            pq = std::priority_queue<Model<T>, std::vector<Model<T>>, std::greater<Model<T>>>();
        }

        void nextGeneration(double mutationFactor){
            int p1 = 0;
            int p2 = 0;
            //Model<T> child;
            makePool();
            std::random_device re;
            std::uniform_int_distribution<int> X(0,pool.size()-1);
            while (pq.size() != popSize){
                while (p1 == p2){
                    p1 = X(re);
                    p2 = X(re);
                }
                //std::cout << p1 << " " << p2 << " " << pool.size() <<  std::endl;
                Model<T> child = Model<T>::pairModels(pool[p1], pool[p2],linSpace1D,observedAnomaly1D,mutationFactor);
                child.calculateAnomaly();
                child.calculateResidual();
                addModel(child);

                p1 = 0;
                p2 = 0;
            }
        }

        void doEvolution(double mutationFactor){
            for (int i = 0; i<generationSize; i++){
                //std::cout << "Generation: " << i+1 << std::endl;
                nextGeneration(mutationFactor);
                Model<T> v = pq.top();
                std::cout << "Min-Residual: " << v.getResidual() << std::endl;
                //v.print();
            }
        }


        void printPool(){
            for (int i = 0; i < pool.size(); i++){
                std::cout << "Pool:" << std::endl;
                pool[i].print();
            }
        }
    private:
        std::priority_queue<Model<T>, std::vector<Model<T>>, std::greater<Model<T>>> pq;
        std::vector<Model<T>> pool;
        LinSpace1D * linSpace1D;
        ObservedAnomaly1D * observedAnomaly1D;
};

#endif //  GRAVITYMODELLING_POPULATION_H