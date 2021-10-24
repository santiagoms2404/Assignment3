/*
Programmer : Santiago Marin Suarez
*Course : CPTR 212
*Description : Class car implementation, assignment 3
* Date : September 20, 2021
*Last update : October 14, 2021
*/


#include "SantiagoMarinCarComparison.h"


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
