#include <iostream>
#include "constants.h"

using namespace std;

double getTowerHeight();
void calculateAndPrintHeight(double towerHeight, int second);
void printHeight(double height, int second);
double calculateHeight(double towerHeight, int second);

int main()
{
    int i = 0;
    const double towerHeight = getTowerHeight();
    while (i < 5)
    {
        calculateAndPrintHeight(towerHeight, i);
        i++;
    }

    return 0;
}

// Get height from user and returns it
double getTowerHeight()
{
    cout << "Enter the height of the tower in meters: ";
    double t_height;
    cin >> t_height;
    return t_height;
}

void calculateAndPrintHeight(double towerHeight, int second)
{
    double height = calculateHeight(towerHeight, second);
    printHeight(height, second);
}

void printHeight(double height, int second)
{
    if (height > 0.0)
		std::cout << "At " << second << " seconds, the ball is at height: " << height << " meters\n";
	else
		std::cout << "At " << second << " seconds, the ball is on the ground.\n";
}

// Return height from the gnd after "seconds" seconds
double calculateHeight(double towerHeight, int second)
{
    /// Using formula: [ s = u * t + (a * t^2) / 2 ], here u(initial velocity) = 0
    double distanceFallen = (myConstants::gravity * (second * second)) / 2;
    double currentHeight = towerHeight - distanceFallen;

    return currentHeight;
}
