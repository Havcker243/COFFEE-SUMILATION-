#include <iostream>
#include <ctime>
#include "Group.h"
using namespace std;
/////////////////////////////////////////////////////////////////////
// Names : Adegbesan Dolapo, Noah Frost
// Date:  19th/05/2022
// Filename : Group.cpp
///////////////////////////////////////////////////////////////////

Group::Group()
{
    name = -1;                 // sets to -1 so we know if the name never got set properly
    number = (rand() % 2) + 1; // randomly decides a group has 1 or 2 people
    startWait = 0;
}

Group::Group(int name)
{
    this->name = name;
    number = (rand() % 2) + 1;
    startWait = 0;
}

void Group::setName(int name)
{
    this->name = name;
}

void Group::setStart(int wait)
{
    startWait = wait;
}

int Group::getName()
{
    return name;
}

int Group::getNumber()
{
    return number;
}

int Group::getWait()
{
    return startWait;
}