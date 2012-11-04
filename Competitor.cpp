//
//  Competitor.cpp
//  competitor
//
//  Created by Anders Akesson on 10/17/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#include "Competitor.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

Competitor::Competitor(string newName)
{
    this -> name = newName;
}

Competitor::Competitor(string newName, int newnrOfMarkings = 0)
{
    this -> name = newName;
}

Competitor::Competitor(string newName, char newCurrentDirection, int newNrOfMarkings)
{
    this -> name = newName;
    this -> currentDirection = newCurrentDirection;
    this -> nrOfMarkings = newNrOfMarkings;
}


bool Competitor::getNrOfMarkings(int newNrOfTwistPlaces) const
{
    return(nrOfMarkings == newNrOfTwistPlaces);
}

int Competitor::nrOfMarkingsCounter() const
{
    return this -> nrOfMarkings;
}

char Competitor::makeTwist() 
{
        int r = rand() % 2;
        if(r == 0)
            currentDirection = FORWARD;
        else
            currentDirection = BACKWARD;
    
    return currentDirection;
}

void Competitor::makeMove() 
{
    if(currentDirection == FORWARD)
    {
        nrOfMarkings++;
    }
    else if(currentDirection == BACKWARD && nrOfMarkings >= 1)
    {
        nrOfMarkings--;
    }
       
}

void Competitor::setName(string newName)
{
    this -> name = newName;
}

string Competitor::getName() const
{
    return this -> name;
}

string Competitor::toString() const
{
    stringstream strStream; //object
    strStream << this -> name << " is going " << this -> currentDirection << " and has " << this -> nrOfMarkings << " markings." << endl;
    return strStream.str();
}


Competitor::~Competitor(){}






