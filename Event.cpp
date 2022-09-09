#include <iostream>
#include <vector>
#include <ctime>
#include "Event.h"
using namespace std;

/////////////////////////////////////////////////////////////////////
// Names : Adegbesan Dolapo, Noah Frost
// Date:  19th/05/2022
// Filename : Event.cpp
///////////////////////////////////////////////////////////////////

Event::Event()
{
    time = -1;
    type = -1;
    random = (rand() % 10) + 2; // gives random number between 2 and 11
    moneysaver = 0;
}

Event::Event(int time, int type)
{
    this->time = time;
    this->type = type;
    random = (rand() % 10) + 2; // gives random number between 2 and 11
    moneysaver = 0;
}

void Event::setEvent(int time, int type, Group group)
{
    this->time = time;
    this->type = type;
    this->group = group;
}

void Event::setTime(int time)
{
    this->time = time;
}

void Event::setType(int type)
{
    this->type = type;
}

void Event::setGroup(Group info)
{
    group = info;
}

void Event::setName(int name)
{
    group.setName(name);
}

int Event::getTime()
{
    return time;
}

int Event::getrandom()
{
    return random;
}
int Event::getType()
{
    return type;
}

Group Event::getGroup()
{
    return group;
}

int Event::doEvent(vector<Group> &queue, vector<Event> &list, int &queueTime, int &money, int &customers, string output, int &realnumber)
{
    // here we open the file
    ofstream timeline;
    timeline.open(output, ofstream::out | ofstream::app);

    // Type one is the first event where the costomer  entered the coffe shop
    // then joined the que as they enter  the shop
    // as the enter the information is put in a file
    if (type == 1)
    {
        timeline << "Group " << group.getName() << " entered at " << time << endl;
        doQueue(queue, list, customers);
    }

    // in the second type or second event the customer would order the food
    //  the time at which he/she spent in the queu qould be calculated
    //  the  time at which it takes to make the food would be calculated
    else if (type == 2)
    {
        timeline << "Group " << group.getName() << " ordered at " << time << endl;
        // this fucntion return the money that has been paid when that specific event takes place
        moneysaver = doOrder(queue, list, money, queueTime, realnumber);
    }
    // here the information that the costumer recived thier food would be written in the file
    else if (type == 3)
    {
        timeline << "Group " << group.getName() << " received food at " << time << endl;
    }
    else if (type == 4)
    {
        // Here the customer would be leave the coffee shop
        // as they leave they would be removed from the list
        timeline << "Group " << group.getName() << " left at " << time << endl;
        doLeave(list, customers);
    }
    // here we open the file
    timeline.close();
    // here we return the money paid in the second event
    return moneysaver;
}

void Event::doQueue(vector<Group> &queue, vector<Event> &list, int &customers)
{
    Event newEvent;                 // holding for new event created by being in line
    customers += group.getNumber(); // the number of people that comes into the restaurant is added to the total
    group.setStart(time);           // when they enter, the amount of wait time begins
    queue.push_back(group);         // the person/group enters the queue

    if (queue.size() == 1)
    { // when no one is in line, the person/group goes right to order

        newEvent.setEvent(orderTime(), 2, group); // the person finishes ordering some random time later
        list.push_back(newEvent);                 // the event is put into the vector
    }
}

int Event::doOrder(vector<Group> &queue, vector<Event> &list, int &money, int &queueTime, int &realnumber)
{

    Event newEvent;                        // holding for new event created by ordering food
    newEvent.setEvent(time + 1, 4, group); // the next event that these people will do is leave
    list.push_back(newEvent);              // event is added to the list
    queue.erase(queue.begin());            // the group is removed from the queue

    if (queue.size() != 0)
    {                                                // if there is anyone else in the queue
        newEvent.setEvent(orderTime(), 2, queue[0]); // the next group will be ordering food
        list.push_back(newEvent);                    // the event is added to the list
    }
    // To get the queuetime we have to remove the time at which
    // the costumer entered and the time at which they leave the queue
    queueTime += time - group.getWait();
    // This would be the queuetime + time it takes to order
    realnumber += time - group.getWait() + random;
    // here we return the money that was paid in
    return money;
}

void Event::doLeave(vector<Event> &list, int &customers)
{
    customers -= group.getNumber(); // the number of people in the group leaves the building
}

int Event::orderTime()
{
    int total = time; // the current time plus how much time it will take to order
    // for (int i = 0; i < group.getNumber(); i++) //adds some time per person to order
    // {
    //     total += (rand() % 2) + 1;
    // }
    return total + rand() % 2 + 1;
}
