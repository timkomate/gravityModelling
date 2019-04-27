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
    LinSpace1D lp(-100,100);
    Model<Sphere> trueModel(&lp,sp);
    trueModel.calculateAnomaly();
    ObservedAnomaly1D oa(trueModel.getAnomaly(),lp.getContainer());
    oa.addNoise(0,0.002);
    trueModel.print();
    //Population<Sphere, 10> p(&lp,&oa);
    Population<Sphere, 10> p;
    for (int i = 0; i < 10000; i++){
        Model<Sphere> randomModel(&lp, &oa);
        //randomModel.print();
        p.addModel(randomModel);
    }
    p.top().print();
    trueModel.writeAnomaly("anomaly.xy");
    return 0;
}