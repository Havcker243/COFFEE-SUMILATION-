#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Group.h"
using namespace std;
/////////////////////////////////////////////////////////////////////
// Names : Adegbesan Dolapo, Noah Frost
// Instructor : Qian Mao
// Filename : Event.h
///////////////////////////////////////////////////////////////////

class Event
{
    // ATRRIBUTES
private:
    int time;    // the time that the event will occur
    int type;    // the type of event where 1=entering, 2=ordering food, 3=getting food, 4=leaving
    Group group; // this is the group that is doing some event

    // This is the varaible which gives random number
    // That would be added to the queueTime which would later be used to get the foodtime
    int random;
    int moneysaver; // This is the fucntion that would be used to calculator

    // METHODS
public:
    // This is the default constuctor for the event class
    Event();

    // This is the main constructor
    // It takes in the time for the events and the type for the events
    Event(int time, int type);

    // sets the characteristics of an event which is used for creating the list of base events
    // input is the time and type of event, and the group that is doing the event
    // no output since it is just setting information
    void setEvent(int time, int type, Group group);

    // This is the fucntion that set the time for which each
    // events starts
    // It takes in the time at which each events strats
    void setTime(int time);

    // This the fucntion that sets the
    // type of event that would take place
    void setType(int type);

    // sets the group of an event to a new group
    // input is the new group
    void setGroup(Group info);

    // This is the fucntion that
    // sets the name of the group
    void setName(int name);

    // returns the time of the event
    int getTime();

    // returns the type of event
    int getType();

    // returns the group of the event
    Group getGroup();

    // performs the action that an event will create
    // input is the queue of people waiting to order, the list of events, the total amount of time that people have waited, the total money spent, how many customers are in the store, which file is being outputted into, and each groups total time waited
    // the output is these variables that are pass by reference, and the amount of money spent by the customer
    int doEvent(vector<Group> &queue, vector<Event> &list, int &queueTime, int &money, int &customers, string output, int &realnumber);

    // does the action of someone entering a queue: they are put in the queue, and if they are first in line, they order
    // input is the queue, the list of events, the number of customers in the restaurant
    // output is each of these variables as pass by reference
    void doQueue(vector<Group> &queue, vector<Event> &list, int &customers);

    // does the action of someone ordering: they finish waiting, spend money, and wait for food
    // input is the queue, the list of events, the total money spent, the total wait time, and the total wait time + random time
    // ouput is how much money was spent
    int doOrder(vector<Group> &queue, vector<Event> &list, int &money, int &queueTime, int &realnumber);

    // does the action of someone receiving food: stop waiting for food, and either sit down or leave
    // input is the queue for food, the list of events, and the number of customers in the restaurant
    // ouput is
    int doFood(vector<Group> &foodQueue, vector<Event> &list, int &customers);

    // does the event of someone leaving: they are removed from the number of customers in the restaurant
    // input is the list of events, and the number of customers
    // no output
    void doLeave(vector<Event> &list, int &customers);

    // decides a random amount of time it takes to order based on how many people are in the group ordering
    // no input
    // output is the time that they will finish ordering
    int orderTime();

    // returns the random number between 2 and 11 associated with the event
    int getrandom();
};

#endif