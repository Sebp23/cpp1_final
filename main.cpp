#include <iostream>
#include <vector>
#include <string>

struct Hopper {

    int remainingBeans;
    int maxAmountOfBeans;
    int beansNeeded;

    //create the hopper and fill it up
    Hopper() {
        maxAmountOfBeans = 200;
        remainingBeans = 0;

        AddBeans();
    }

    //in the cup struct, check how many beans are left in the hopper before making the cup
    int CheckHopper() {
        int beansInHopper = remainingBeans;

        std::cout << "There are " << beansInHopper << " grams of beans in the hopper." << std::endl;

        return beansInHopper;
    }

    //in the cup struct, add beans to the hopper if there are less than 50
    void AddBeans() {
        beansNeeded = maxAmountOfBeans - remainingBeans;

        std::cout << "Adding " << beansNeeded << " grams of beans." << std::endl;
        remainingBeans += beansNeeded;
    }

    void RemoveBeans(int beansToRemove) {
        remainingBeans -= remainingBeans - beansToRemove;
    }

};

struct HeatSource {

    int currentWaterTemp;
    int maxTemp;

    //create the heatsource and heat up the water
    HeatSource(int newWaterTemp) {
        this->currentWaterTemp = newWaterTemp;
        maxTemp = 100;

        std::cout << "The water resevoir has " << currentWaterTemp << " degree celsius water" << std::endl;
    }

    //Check the temperature of the water when making the cup
    int CheckTemp() {
        std::cout << "The water is " << currentWaterTemp << " degrees celsius" << std::endl;

        return currentWaterTemp;
    }

    //Heat up the water if the temp is less than 100
    void HeatWater() {
        std::cout << "Heating water to " << maxTemp << " degrees celsius." << std::endl;
        currentWaterTemp = maxTemp;
    }

};

struct WaterResevoir {

    double waterRemaining;
    double maxWater;
    double waterNeeded;
    int newWaterTemp;

    WaterResevoir() {
        waterRemaining = 0;
        maxWater = 1;
        newWaterTemp = 30;

        waterRemaining = maxWater;

        std::cout << "The resevoir has been made and filled with " << waterRemaining << "L of water" << std::endl;
    }

    double CheckWater() {
        std::cout << "There is currently " << waterRemaining << "L of water left in the resevoir" << std::endl;

        return waterRemaining;
    }

    void AddWater() {
        waterNeeded = maxWater - waterRemaining;
        std::cout << "Filling resevoir with " << waterNeeded << "L of water" << std::endl;
    }

};

struct Grinder {
    int beansToGrind;

    Grinder() {
        beansToGrind = 50;
    }

    void GrindBeans(Hopper hopperToGrindFrom) {
        std::cout << "Grinding " << beansToGrind << " from hopper." << std::endl;
        hopperToGrindFrom.RemoveBeans(beansToGrind);
    }

};

struct CupReceptacle {

    int beansRequried;
    double waterRequired;
    
    CupReceptacle(Hopper m_hopper, WaterResevoir m_resevoir, HeatSource m_heatSource, Grinder m_grinder) {
        // beansRequried = 50;
        // waterRequired = 0.25;
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

    Hopper *hopper = new Hopper();
    WaterResevoir *resevoir = new WaterResevoir();
    HeatSource *heater = new HeatSource(resevoir->newWaterTemp);
    Grinder *grinder = new Grinder();

    std::cout << "TEST: Objects instantiated" << std::endl;
}
