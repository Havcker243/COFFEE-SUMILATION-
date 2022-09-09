#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <ctime>
using namespace std;
/////////////////////////////////////////////////////////////////////
// Names : Adegbesan Dolapo, Noah Frost
// Date:  19th/05/2022
// Filename : Group.h
///////////////////////////////////////////////////////////////////

class Group
{
    // Atrributes
private:
    int name;      // the unique number that the party is under
    int number;    // how many people are in the party
    int startWait; // how much time they are assigned to wait

    // Methoods
public:
    // This is default constrcutor
    Group();

    // the main constructor which
    // takes in the namwe of the group
    Group(int name);

    // sets the name of the group
    // input is the new name/number
    void setName(int name);

    // sets the time that the group starts waiting for something
    // input is the start time
    void setStart(int wait);

    // returns the name of the group
    int getName();

    // returns the number of people in the group
    int getNumber();

    // returns the time that the group started waiting
    int getWait();
};

#endif