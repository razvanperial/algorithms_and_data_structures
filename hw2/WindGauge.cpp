#include "WindGauge.h"
#include <climits>
#include <iostream>

WindGauge::WindGauge(int period){
    maxPeriod = period;
    maxSpeed = INT_MIN;
    minSpeed = INT_MAX;
    sumSpeeds = 0;
    currentPeriod = 0;
}

void WindGauge::currentWindSpeed(int speed){
    //push the speed given at the end of the deque
    speeds.push_back(speed);

    //if it is higher than the maxi or smaller than the min, update accordingly
    maxSpeed = std::max(maxSpeed, speed);
    minSpeed = std::min(minSpeed, speed);

    //check if the current no. of elements before adding was equal to max
    if(currentPeriod == maxPeriod){
        //if so, update the sum of speeds by substracting the first element
        //and adding the last one 
        sumSpeeds = sumSpeeds - speeds.front() + speed;

        //if the maxspeed or minspeed will have to be popped of the deque, 
        //they have to be recalculated by iterating throw the elements,
        //not taking the first one into consideration (which was the 
        //previous max or min)
        if(speeds.front() == maxSpeed || speeds.front() == minSpeed){
            maxSpeed = INT_MIN;
            minSpeed = INT_MAX;
            std::deque<int>::iterator i;
            i++;
            for(i = speeds.begin() + 1; i < speeds.end(); i++){
                maxSpeed = std::max(maxSpeed, *i);
                minSpeed = std::min(minSpeed, *i);
            }
        }

        //finally, pop the first elemennt off the beginning of the deque
        speeds.pop_front();
    }
    else{
        currentPeriod++;
        sumSpeeds = sumSpeeds + speed;
    }
}

int WindGauge::highest() const{
    return maxSpeed;
}

int WindGauge::lowest() const{
    return minSpeed;
}

int WindGauge::average() const{
    return sumSpeeds/currentPeriod;
}

void WindGauge::dump() {
    std::cout<<"Highest speed: "<<maxSpeed<<std::endl;
    std::cout<<"Lowest speed: "<<minSpeed<<std::endl;
    std::cout<<"Average speed: "<<sumSpeeds/currentPeriod<<std::endl;
}