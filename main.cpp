#include <iostream>
#include <vector>
#include <string>

struct Hopper {

    int remainingBeans;

    Hopper() {
        remainingBeans = 0;
    }

};

struct HeatSource {

    int waterTemp;

    HeatSource() {
        waterTemp = 30;
    }

};

struct WaterResevoir {

    double waterRemaining;

    WaterResevoir() {
        waterRemaining = 0;
    }

};

struct Grinder {

    Grinder() {

    }

};

struct CupReceptacle {

    int beansRequried = 50;
    double waterRequired = 0.25;

    CupReceptacle() {

    }

};

int main() {
    
    // A hopper can hold at most 200 grams of beans
    // Each cup of coffee takes 50 grams of beans to make
    // The Water Reservoir Can Hold 1 Liter of Water
    // Each cup of coffee takes .25 liters to make
    // Water enters the reservoir at 30 degrees Celsius
    // To brew coffee the water needs to be at 100 degrees Celsius
    // A user should be able to request n cups of coffee where n > 0 and n <= 4
    // you must print out every step of the process
    // this is an OOP assignment, use objects
    // I should be able to build your project with make

}
