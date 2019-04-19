#include <iostream>
#include "./include/Shape2D.h"
#include "./include/Sphere.h"
#include "./include/LinSpace1D.h"
#include "./include/Model.hpp"
#include "./include/ObservedAnomaly1D.h"

int main(int args, char ** argv){
    Sphere sp(0,100,1000,10);
    LinSpace1D lp(-100,100);
    Model<Sphere> m(&lp,sp);
    m.print();
    m.calculateAnomaly();
    //m.addNoise(0,0.002);
    ObservedAnomaly1D oa(m.getAnomaly(),lp.getContainer());
    oa.addNoise(0,0.002);
    m.addObservation(& oa);
    m.calculateResidual();
    m.print();
    m.writeAnomaly("anomaly.xy");
    return 0;
}