#include "../include/LinSpace1D.h"

LinSpace1D::LinSpace1D(){
    this->begin = 0;
    this->end = 100;
    this->stepSize = 1;
    initContainer();
}

LinSpace1D::LinSpace1D(double begin, double end){
    this->begin = begin;
    this->end = end;
    this->stepSize = 1;
    initContainer();
}

LinSpace1D::LinSpace1D(double begin, double end, double stepSize){
    this->begin = begin;
    this->end = end;
    this->stepSize = stepSize;
    initContainer();
}

void LinSpace1D::initContainer(){
    for (int i = begin; i <= end; i = i + stepSize){
        container.push_back(i);
    }
    size = container.size();
}

double LinSpace1D::getElement(int i){
    return container[i];
}

double LinSpace1D::getBegin(){
    return begin;
}

double LinSpace1D::getEnd(){
    return end;
}

unsigned int LinSpace1D::getSize(){
    return size;
}

std::vector<double> LinSpace1D::getContainer(){
    return container;
}

void LinSpace1D::setContainer(std::vector<double> container){
    this->container = container;
}

void LinSpace1D::print(bool cond){
    std::cout << "LinSpace1D:" << std::endl;
    std::cout << "Begin: " << begin << std::endl;
    std::cout << "End: " << end << std::endl;
    std::cout << "Step size: " << stepSize << std::endl;
    std::cout << "Container size: " << size << std::endl; 
    if (cond){
        for (int i = 0; i < container.size(); i++)
            std::cout << container[i] << std::endl;
    }
    std::cout << std::endl;
}