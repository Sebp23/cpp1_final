#include <iostream>
#include <vector>
#include <string>

//Where the number of beans is stored and manipulated
struct Hopper {

    int remainingBeans;
    int maxAmountOfBeans;
    int beansNeeded;

    //create the hopper and fill it up
    Hopper() {
        maxAmountOfBeans = 200;
        remainingBeans = maxAmountOfBeans;

        std::cout << "The hopper has been filled with " << remainingBeans << " grams of beans" << std::endl;
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
        remainingBeans -= beansToRemove;
    }

};

//Where the water temperature is stored and manipulated
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
    int CheckTempFromSource() {
        std::cout << "The water is " << currentWaterTemp << " degrees celsius" << std::endl;

        return currentWaterTemp;
    }

    //Heat up the water if the temp is less than 100
    void HeatWater() {
        std::cout << "Heating water to " << maxTemp << " degrees celsius." << std::endl;
        currentWaterTemp = maxTemp;
    }

};

//Where the water volume is stored
struct WaterResevoir {

    double waterRemaining;
    double maxWater;
    double waterNeeded;
    int newWaterTemp;

    //create the resevoir and fill it up
    WaterResevoir() {
        waterRemaining = 0;
        maxWater = 1;
        newWaterTemp = 30;

        waterRemaining = maxWater;

        std::cout << "The resevoir has been made and filled with " << waterRemaining << "L of water" << std::endl;
    }

    //check the amount of water remaining
    double CheckWater() {
        std::cout << "There is currently " << waterRemaining << "L of water left in the resevoir" << std::endl;

        return waterRemaining;
    }

    //add water when necessary
    void AddWater(HeatSource *m_heatSource) {
        waterNeeded = maxWater - waterRemaining;
        std::cout << "Filling resevoir with " << waterNeeded << "L of water" << std::endl;
        waterRemaining += waterNeeded;

        m_heatSource->currentWaterTemp = newWaterTemp;
    }

    //pour water when necessary
    void PourWaterFromResevoir(double waterToPour) {
        waterRemaining -= waterToPour;
        std::cout << "Pouring " << waterToPour << "L of water..." << std::endl;
    }

};

//Grinder object
struct Grinder {
    int beansToGrind;

    //declare how many beans the grinder will grind from the hopper
    Grinder() {
        beansToGrind = 50;
    }

    //grind the beans when necessary
    void GrindBeansFromHopper(Hopper *hopperToGrindFrom) {
        std::cout << "Grinding " << beansToGrind << " grams from hopper." << std::endl;
        hopperToGrindFrom->RemoveBeans(beansToGrind);
    }

};

//This is where all the cups are made
struct CupReceptacle {

    int beansRequried;
    double waterRequired;
    int waterTempRequired;
    
    //make the coffee using a consistent hopper, resevoir, heater, and grinder.
    CupReceptacle(Hopper *m_hopper, WaterResevoir *m_resevoir, HeatSource *m_heatSource, Grinder *m_grinder, int m_cupNumber) {
        beansRequried = 50;
        waterRequired = 0.25;
        waterTempRequired = 100;

        std::cout << "Making cup " << m_cupNumber << "..." << std::endl;

        std::cout << "Checking to make sure there are enough beans in the hopper to grind..." << std::endl;
        GrindBeans(m_hopper, m_grinder);

        std::cout << "Checking to make sure there is enough water in the resevoir..." << std::endl;
        PourWater(m_resevoir, m_heatSource);

        std::cout << "Coffe #" << m_cupNumber << " is now ready. Enjoy!" << std::endl;
        

    }

    //grind the beans for Nth cup of coffee, using a consistent hopper and grinder
    void GrindBeans(Hopper *m_hopper, Grinder *m_grinder) {
        int beansRemaining = m_hopper->CheckHopper();

        //if there are enough beans in the hopper, grind the beans
        if (beansRemaining >= beansRequried) {
            std::cout << "There are enough beans..." << std::endl;
            m_grinder->GrindBeansFromHopper(m_hopper);
            std::cout << "Ground " << beansRequried << " grams of beans." << std::endl;
            std::cout << "There are now " << m_hopper->remainingBeans << " grams of beans left in the hopper..." << std::endl;
        }
        else if (beansRemaining < beansRequried) {
            std::cout << "There are not enough beans. Refilling hopper..." << std::endl;
            m_hopper->AddBeans();
            GrindBeans(m_hopper, m_grinder);
        }
    }

    //check the temperature and pour water using a consistent resevoir and heat source
    void PourWater(WaterResevoir *m_resevoir, HeatSource *m_heatSource) {
        double waterRemaining = m_resevoir->CheckWater();

        if (waterRemaining >= waterRequired) {
           std::cout << "There is enough water for 1 cup..." << std::endl;
           //make sure water is hot enough before pouring
           CheckTemp(m_heatSource);
           m_resevoir->PourWaterFromResevoir(waterRequired);
           std::cout << "There is now " << waterRemaining - waterRequired << "L remaining in the resevoir" << std::endl; 
        }
        else if (waterRemaining < waterRequired) {
            std::cout << "There is not enough water. Refilling resevoir..." << std::endl;
            m_resevoir->AddWater(m_heatSource);
            PourWater(m_resevoir, m_heatSource);
        }
    }

    //check the water temperature
    void CheckTemp(HeatSource *m_heatSource) {
        int waterTemp = m_heatSource->CheckTempFromSource();

        if (waterTemp >= waterTempRequired) {
            std::cout << "Water is the proper temperature. Now pouring..." << std::endl;
        }
        else if (waterTemp < waterTempRequired) {
            std::cout << "Water is too cold. Now heating..." << std::endl;
            m_heatSource->HeatWater();
            CheckTemp(m_heatSource);
        }
    }
};

int main() {
    //number of cups to make
    int numberOfCups = 5;

    //make the hopper, resevoir, heat source, and grinder. Use pointers to make sure its always the same object for every coffee cup
    Hopper *hopper = new Hopper();
    WaterResevoir *resevoir = new WaterResevoir();
    HeatSource *heater = new HeatSource(resevoir->newWaterTemp);
    Grinder *grinder = new Grinder();

    //make a specific amount of cups of coffee using the above objects
    for(int i = 0; i < numberOfCups; i++) {
        std::cout << "----------------------------------------------------------------" << std::endl;
        int cupNumber = i + 1;
        CupReceptacle *cup = new CupReceptacle(hopper, resevoir, heater, grinder, cupNumber);
    }

    std::cout << "=======END=======" << std::endl;
}