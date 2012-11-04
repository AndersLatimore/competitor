//
//  Competitor.h
//  competitor
//
//  Created by Anders Akesson on 10/17/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#ifndef __competitor__Competitor__
#define __competitor__Competitor__

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

class Competitor
{
private:
    string name;
    char currentDirection;
    int nrOfMarkings;
    
    static const char FORWARD = 'F';
    static const char BACKWARD = 'B';

public:
    Competitor(){};
    Competitor(string);
    Competitor(string, int);
    Competitor(string, char, int);
    string getName() const;
    void setName(string);
    bool getNrOfMarkings(int) const;
    int nrOfMarkingsCounter() const;
    char getCurrentDirection() const {return this -> currentDirection;}
    char makeTwist();
    void makeMove();
    string toString() const;
    ~Competitor();
};

#endif /* defined(__competitor__Competitor__) */
