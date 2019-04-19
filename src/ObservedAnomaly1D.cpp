#include "../include/ObservedAnomaly1D.h"
#include <random>


ObservedAnomaly1D::ObservedAnomaly1D(std::vector<double> anomaly, std::vector<double> position){
    this->anomaly = anomaly;
    this->position = position;
}

/*ObservedAnomaly1D::ObservedAnomaly1D(){

}*/

double ObservedAnomaly1D::getPosition(int i){
    return position[i];
}

double ObservedAnomaly1D::getAnomaly(int i){
    return anomaly[i];
}

void ObservedAnomaly1D::addNoise(double mean, double deviation){
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(mean,deviation);
    for (int i = 0; i < anomaly.size(); i++){
        double noise = distribution(generator);
        anomaly[i] = anomaly[i] + noise;
    }
}