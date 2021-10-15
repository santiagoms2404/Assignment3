/*
Programmer : Santiago Marin Suarez
*Course : CPTR 212
*Description : Class car, assignment 3
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

int main()
{
    //Declare the two car objects and set the values using the six parameter contructor.
    Car car1("Hyundai", "Accent", 2021, 15000, 11.9, 40), car2("Seat", "Ibiza", 2020, 20000, 10.6, 35);

    cout << "Details of the car 1: \n";
    car1.output(cout);

    cout << endl;

    cout << "Details of the car 2: \n";
    car2.output(cout);

    cout << endl;

    cout << "Comparison between car 1 and car 2: \n" << Compare(car1, car2) << endl;

    return 0;


}

Car::Car(string makeOfCar, string modelOfCar, int yearOfCar, double odometer, float capacity, float latestDistance)
{
    make = makeOfCar;
    model = modelOfCar;
    year = yearOfCar;
    odometerReading = odometer;
    fuelCapacity = capacity;
    latestTripDistanceTravelled = latestDistance;  
}

Car::Car() : latestTripDistanceTravelled(0), fuelCapacity(0), odometerReading(0)
{

}

string Car::getMake()
{    
    return (make);
}

string Car::getModel()
{
    return (model);
}

int Car::getYear()
{
    return(year);
}

double Car::getOdometer()
{
    return(odometerReading);
}

float Car::getCapacity()
{
    return(fuelCapacity);
}

float Car::getLatestDistance()
{
    return(latestTripDistanceTravelled);
}

void Car::set(string makeOfCar, string modelOfCar, int yearOfCar, double odometer, float capacity, float latestDistance)
{
    make = makeOfCar;
    model = modelOfCar;
    year = yearOfCar;
    odometerReading = odometer;
    fuelCapacity = capacity;
    latestTripDistanceTravelled = latestDistance;
}

//Return miles per galon.
float Car::fuelEconomyCalculation(float cCapacity, float cLatestDistance)
{
    fuelCapacity = cCapacity;
    latestTripDistanceTravelled = cLatestDistance;

    return (latestTripDistanceTravelled /= fuelCapacity);
}

//Make a comparison with all possibillities from the two car objects using year and the odometer.
bool Compare(Car car1, Car car2)
{
    if ((car1.getYear() > car2.getYear()) && (car1.getOdometer() < car2.getOdometer()))
    {
        cout << "Car 1 is a better option" << endl;
    }
    else if ((car1.getYear() > car2.getYear()) && (car1.getOdometer() > car2.getOdometer()))
    {
        cout << "Car 1 is newer, but it has more miles in the odometer " << endl;
    }
    else if ((car1.getYear() < car2.getYear()) && (car1.getOdometer() < car2.getOdometer()))
    {
        cout << "Car 2 is newer, but it has more miles in the odometer " << endl;
    }
    else if ((car1.getYear() < car2.getYear()) && (car1.getOdometer() > car2.getOdometer()))
    {
        cout << "Car 2 is a better option" << endl;
    }
    else if ((car1.getYear() == car2.getYear()) && (car1.getOdometer() > car2.getOdometer()))
    {
        cout << "Both cars are from the same year, but car 2 has less miles in the odometer" << endl;
    }
    else if ((car1.getYear() == car2.getYear()) && (car1.getOdometer() < car2.getOdometer()))
    {
        cout << "Both cars are from the same year, but car 1 has less miles in the odometer" << endl;
    }
    else if ((car1.getYear() < car2.getYear()) && (car1.getOdometer() == car2.getOdometer()))
    {
        cout << "Car 2 is newer, but both have the same miles in the odometer" << endl;
    }
    else if ((car1.getYear() > car2.getYear()) && (car1.getOdometer() == car2.getOdometer()))
    {
        cout << "Car 1 is newer, but both have the same miles in the odometer" << endl;
    }
    else if ((car1.getYear() == car2.getYear()) && (car1.getOdometer() == car2.getOdometer()))
    {
        cout << "You can buy any car between the two" << endl;
    }
    return 0;
}

//Display all the information to the screen.
void Car::output(ostream& outs)
{
    outs << "Make of the car: " << getMake() << endl;
    outs << "Model of the car: " << getModel() << endl;
    outs << "year of the car: " << getYear() << endl;
    outs << "The odometer reading of the car is: " << getOdometer() << endl;
    outs << "The fuel capacity of the car is: " << getCapacity() << endl;
    outs << "The fuel economy calculation is: " << fuelEconomyCalculation(getCapacity(), getLatestDistance()) << " miles per galon " << endl;
}
