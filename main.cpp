#include <iostream>
#include "./include/Shape2D.h"
#include "./include/Sphere.h"
#include "./include/LinSpace1D.h"
#include "./include/Model.hpp"
#include "./include/ObservedAnomaly1D.h"
#include "./include/Population.hpp"

template<class T>
int Model<T>::ID = 0;

int main(int args, char ** argv){
    Sphere sp(0,100,1000,10);
    Sphere sp2(-100,50,500,5);
    LinSpace1D lp(-100,100,1);
    Model<Sphere> trueModel(&lp,sp);
    trueModel.calculateAnomaly();
    trueModel.addNoise(0,0.0035);
    trueModel.writeAnomaly("anomaly.xy");
    ObservedAnomaly1D oa(trueModel.getAnomaly(),lp.getContainer());
    //oa.addNoise(0,0.1);
    trueModel.print();
    Population<Sphere, 10000, 20> p(&lp,&oa);
    //p.top().print();
    p.doEvolution(0.15);
    p.top().print();
    p.top().writeAnomaly("modelAnomaly.xy");
    
    return 0;
}