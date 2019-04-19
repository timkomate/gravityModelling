#ifndef GRAVITYMODELLING_OBSERVEDANOMALY1D_H
#define GRAVITYMODELLING_OBSERVEDANOMALY1D_H

#include<iostream>
#include<vector>

class ObservedAnomaly1D{
    public:
        //ObservedAnomaly1D();
        ObservedAnomaly1D(std::vector<double>,std::vector<double>);
        void addNoise(double,double);
        double getPosition(int);
        double getAnomaly(int);
    private:
        std::vector<double> position;
        std::vector<double> anomaly;
};

#endif //  GRAVITYMODELLING_OBSERVEDANOMALY1D_H