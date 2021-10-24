/*
Programmer : Santiago Marin Suarez
*Course : CPTR 212
*Description : Class car interface, assignment 3
* Date : September 20, 2021
*Last update : October 14, 2021
*/


#include <iostream>
#include <string>
using namespace std;

class Car
{
    public:

        //Constructors 
        Car(string makeOfCar, string modelOfCar, int yearOfCar, double odometer, float capacity, float latestDistance);
        //The specs of the car.

        Car(); //Default constructor
       
        //Mutator functions
        void set(string makeOfCar, string modelOfCar, int yearOfCar, double odometer, float capacity, float latestDistance);
       
        //Accessor functions
        string getMake();             // get the make of the car.
        string getModel();            // get the model of the car.
        int getYear();                // get the year of the car.
        double getOdometer();          // get the odometer reading of the car.
        float getCapacity();          // get fuel capacity of the car.
        float getLatestDistance();    // get the latest distance travelled of the car.

        //Friend function
        friend bool Compare(Car car1, Car car2);
        //Compares the two cars using year and odometer reading. Return the best car from the two.  

        //Member functions
        float fuelEconomyCalculation(float cCapacity, float cLatestDistance);
        //Return the miles per galon according to the capacity of the tank and the latest distance travelled. 

        void output(ostream& outs);
        //Display the information about the cars.

    private:
        // member variables
        string make;
        string model;
        int year;
        double odometerReading;
        float fuelCapacity;
        float latestTripDistanceTravelled;
        

};