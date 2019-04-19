#include <iostream>
#include "./include/Shape2D.h"
#include "./include/Sphere.h"
#include "./include/LinSpace1D.h"
#include "./include/Model.hpp"
int main(int args, char ** argv){
    Sphere sp;
    LinSpace1D lp(-10,100);
    Model<Sphere> m(&lp,sp);
    m.print();
    return 0;
}