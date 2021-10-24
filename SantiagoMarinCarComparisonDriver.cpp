/*
Programmer : Santiago Marin Suarez
*Course : CPTR 212
*Description : Class car driver, assignment 3
* Date : September 20, 2021
*Last update : October 14, 2021
*/

#include "SantiagoMarinCarComparison.cpp"

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