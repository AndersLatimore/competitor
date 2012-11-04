//
//  main.cpp
//  competitor
//
//  This program is a game where the players walk forward(hopefully) and collect markings.
//  The twist determines if a player is walking forwards or backwards. If a player is walking
//  forward, the player collects one marking. If a player is walking backwards,
//  one marking is removed from the total.
//  In the game, F represents going forward, B represents going backwards.
//
//
//  Created by Anders Akesson on 10/17/12.
//  Copyright (c) 2012 Anders Akesson. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Competitor.h"

using namespace std;

void inputAndSetNames(Competitor comps[], int nrOfComps);
void makeTwistForAll(Competitor comps[], int nrOfComps);
void makeMoveForAll(Competitor comps[], int nrOfComps);
void showAll(Competitor comps[], int nrOfComps);
int winner(Competitor comps[], int nrOfComps, int nrOfTwistPlaces);
int enterNrOfComps();
int enterNrOfTwistPlaces();

int main()
{

    Competitor *comps = NULL;
    int nrOfTwistPlaces = 0;
    int nrOfComps = 0;
    int twistCount = 0;
    int goal = -1;
    
    nrOfTwistPlaces = enterNrOfTwistPlaces();
    
    nrOfComps = enterNrOfComps();
    
    comps = new Competitor[nrOfComps];
    inputAndSetNames(comps, nrOfComps);
    
    for(int l = 0; l < nrOfComps; l++)
    {
        cout << comps[l].getName() << "\t" << endl;
    }
    
    while(goal == -1)  //Calling the functions until a winner is declared.
    {
        twistCount++;
        cout << "Twist " << twistCount << endl;
        makeTwistForAll(comps, nrOfComps);
        makeMoveForAll(comps, nrOfComps);
        showAll(comps, nrOfComps);
            
        goal = winner(comps, nrOfComps, nrOfTwistPlaces); //Validate the return of winner. If -1, continue.
        cout << "Press enter to continue.";
        cin.get();
        cin.get();
    }
    cout << twistCount << " twists. ";
    
    delete [] comps;
    comps = NULL;
    return 0;
}

int enterNrOfTwistPlaces()//Function to enter and validate twistplaces.
{
    int newNrOfTwistPlaces;
    cout << "How many twistplaces are there? ";
    cin >> newNrOfTwistPlaces;
    while(newNrOfTwistPlaces <= 0)
    {
        if(newNrOfTwistPlaces <= 0)
        cout << "Not a valid input. " << endl;
        return enterNrOfTwistPlaces();
    }
    return newNrOfTwistPlaces;
}

int enterNrOfComps()//Function to enter and validate the number of players.
{
    int newNrOfComps;
    cout << "How many players are there? ";
    cin >> newNrOfComps;
    while(newNrOfComps < 2)
    {
        if(newNrOfComps < 2)
        cout << "You need at least 2 players. " << endl;
        return enterNrOfComps();
    }
    return newNrOfComps;
}

void inputAndSetNames(Competitor comps[], int nrOfComps) //Function to input names to objects.
{
    string name;
   
    cout << "Enter the names for the players:";
    for(int count = 0; count < nrOfComps; count++)
    {
        cout << "Enter name " << count + 1 << ":";
        if(count < 1){
            cin.ignore(1, '\n');}
        getline(cin,name);
        comps[count] = Competitor(name); //Enter name into the object.
            
    }
}

void makeTwistForAll(Competitor comps[], int nrOfComps) //Function to simulate a twist for all players.
{
    for(int i = 0; i < nrOfComps; i++)
    {        
        comps[i].makeTwist(); 
    }

}

void makeMoveForAll(Competitor comps[], int nrOfComps) //Function to move all players.
{
    for (int i = 0; i < nrOfComps; i++)
    {
        comps[i].makeMove();
    }
}

void showAll(Competitor comps[], int nrOfComps)//Function to show where all players are at.
{
    for (int i = 0; i < nrOfComps; i++)
    {
        cout << comps[i].toString() << endl;
    }
}

int winner(Competitor comps[], int nrOfComps, int nrOfTwistPlaces)//Determine the winner.
{
    int index = 0;
    int position = -1;
    bool found = false;
    
    while(index < nrOfComps && !found)
    {
        if(comps[index].getNrOfMarkings(nrOfTwistPlaces))
        {
            found = true;
            position = index;
            cout << comps[position].getName() << " is the winner! " << endl;
        }
        index++;
        
    }
    return position;
}

