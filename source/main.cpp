#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include "Group.h"
#include "Event.h"
using namespace std;
/////////////////////////////////////////////////////////////////////
// Names : Adegbesan Dolapo, Noah Frost
// Date:  19th/05/2022
// Filename : Main.cpp
///////////////////////////////////////////////////////////////////

// puts a list of a random number of events at random times through the day into the list of all events
// input is the vector being filled
// output is the vector as a pass by reference value
void rndmEvents(vector<Event> &list, int size);

// finds which event has the lowest time and returns the index
// input is the vector of events to search
// output is the index of where in the vector the next event is
int findNextEvent(vector<Event> list);

int main()
{
    ofstream timeline("timeline.txt"); // Here  we open the file
    ofstream summary("summary.txt");   // Here open another file
    srand(time(NULL));                 // This is used to for the random fucntion
    vector<Event> list;                // a list of all the events queued to happen
    vector<Group> queue;               // all the people in line1
    int baseEvents = 50;               // the number of base events/people that will walk in throughout the day

    int index;                    // the index of the next event to occur
    int queueTime = 0;            // the total amount of time that people spend in the queue
    int money = (rand() % 6) + 8; // This varaible holds the random number that would generate the amount of money spent per event
    int foodTime = 0;             // this is the average time it took to make the food
    int customers = 0;            // the running amount of customers in the store at a given time
    int maxCustomers = 0;         // holds the max amount of customers that come into restaurant
    int averagetime = 0;          // holds the average of time a person waits in the Que
    int realnumber = 0;           // This holds the total amount of time spent in making the food
    int averagemoney = 0;         // holds the average of time a person waits in the Que
    int realmoney = 0;            // This holds the value of money relased from the doorder function
    int finalmoney = 0;           // This holds the total amount of money made

    rndmEvents(list, baseEvents);

    // the simulation continues until there are no more events to do
    while (list.size() > 0)
    {
        index = findNextEvent(list);                                                                           // the next event that happens is found
        realmoney = list[index].doEvent(queue, list, queueTime, money, customers, "timeline.txt", realnumber); // the event is done
        list.erase(list.begin() + index);                                                                      // the event is removed from the list

        // checks for a new maximum number of people in the restaurant
        if (customers > maxCustomers)
        {
            maxCustomers = customers;
        }
        finalmoney += realmoney;
    }
    // here we calculate the average of money made ,
    // the avearge que time ,
    // the average time it took to make the food
    averagetime = queueTime / (baseEvents * 1.0);
    foodTime = realnumber / (baseEvents * 1.0);
    averagemoney = finalmoney / (baseEvents * 1.0);

    // Here we ouptu into the file the statistics of the simulation
    summary << "Welcome to the coffee shop simulation" << endl;
    summary << "Below is the data which have been collected  during the coffee shop  event based simulation"
            << "\n\n";
    summary << "Average time spent in the Queue:  " << averagetime << "  mins  " << endl; // prints average wait time, 1.0 is so that it calculates as a float
    summary << "The max number of customers in the restaurant at one time:  " << maxCustomers << endl;
    summary << "Average food time:    " << foodTime << "  mins " << endl;
    summary << "Average amount of money made: " << averagemoney << "  Dollars " << endl;
}

void rndmEvents(vector<Event> &list, int size)
{
    Event hold;      // holds each event added to the list
    hold.setType(1); // the type of every base event is 1: someone entering the restaurant

    // adds the specified number of base events
    for (int i = 0; i < size; i++)
    {
        hold.setName(i);            // the name is set to a unique value
        hold.setTime(rand() % 720); // randomly/evenly distributes the event in a span of 12 hours
        list.push_back(hold);       // the evnt is added to the list
    }
}

int findNextEvent(vector<Event> list)
{
    int currMin = list[0].getTime(); // the running minimum time
    int minIndex = 0;                // the index of the minimum time

    // checks the time of every event
    for (int i = 0; i < list.size(); i++)
    {
        // checks the time of the current event to the current minimum
        if (list[i].getTime() < currMin)
        {
            currMin = list[i].getTime(); // new minimum is set
            minIndex = i;                // new index is set
        }
    }
    return minIndex; // the index is returned
}
