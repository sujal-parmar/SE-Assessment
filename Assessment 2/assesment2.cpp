#include <iostream>
#include <cmath>
using namespace std;

const double CostPerHour = 3000;
const double CostPerMinute = 50;
const double CostOfDinner = 500;

int calculateServers(int guests)
{
    return ceil(guests / 20.0);
}

double calculateServerCost(int minutes)
{
    double cost1 = (minutes / 60) * CostPerHour;
    double cost2 = (minutes % 60) * CostPerMinute;
    return cost1 + cost2;
}

double calculateFoodCost(int guests)
{
    return guests * CostOfDinner;
}

double calculateAvgCostPerPerson(double totalFoodCost, int guests)
{
    return totalFoodCost / guests;
}

double calculateDeposit(double totalCost)
{
    return totalCost * 0.25;
}

class Event
{
private:
    string eventName;
    string firstName, lastName;
    int guests;
    int minutes;

public:
    void getDetails()
    {
        cout << "Enter the name of the Event: ";
        getline(cin, eventName);
        cout << "Enter your First Name: ";
        cin >> firstName;
        cout << "Enter your Last Name: ";
        cin >> lastName;
        cout << "Enter Number of Guests: ";
        cin >> guests;
        cout << "Enter Number of Minutes: ";
        cin >> minutes;
    }

    void displayCostEstimation()
    {
        int numServers = calculateServers(guests);
        double costPerServer = calculateServerCost(minutes);
        double totalFoodCost = calculateFoodCost(guests);
        double avgCostPerPerson = calculateAvgCostPerPerson(totalFoodCost, guests);
        double totalCost = totalFoodCost + (costPerServer * numServers);
        double deposit = calculateDeposit(totalCost);

        cout << "\n---------- Event Summary ----------\n";
        cout << "Event Name           : " << eventName << endl;
        cout << "Organizer Name       : " << firstName << " " << lastName << endl;
        cout << "Number of Guests     : " << guests << endl;
        cout << "Event Duration       : " << minutes << " minutes\n";
        cout << "Number of Servers    : " << numServers << endl;
        cout << "Cost for One Server  : rs." << costPerServer << endl;
        cout << "Total Food Cost      : rs." << totalFoodCost << endl;
        cout << "Average Cost/Person  : rs." << avgCostPerPerson << endl;
        cout << "Total Event Cost     : rs." << totalCost << endl;
        cout << "Deposit (25%)        : rs." << deposit << endl;
        cout << "-----------------------------------\n";
    }
};

int main()
{
    Event myEvent;
    myEvent.getDetails();
    myEvent.displayCostEstimation();

    return 0;
}