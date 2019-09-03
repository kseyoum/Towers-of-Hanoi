// ITP 365 Spring 2019
// HW3 Towers of Hannoi
// Name: Kirubel Seyoum
// Email: kseyoum@usc.edu
// Platform: Mac

#include "gwindow.h"
#include <iostream>
#include <string>
#include <vector>
#include "Peg.h"
#include "Disk.h"

// Function: promptForDisks
// Purpose: prompts the user for the number of disks to start with
// Input: nothing
// Output: integer of the number of disks that user has asked for
int promptForDisks()
{
    int diskAsk=0;
    //do while loop to assure user answer is in between 2-10
    do
    {
        std::cout<< "How many disks do you want? Only select from 2-10: ";
        std::cin>>diskAsk;
        if (diskAsk>=2 && diskAsk<=10)
        {
            return diskAsk;
        }
    } while (diskAsk<2 || diskAsk>10);
    return 0;
}

// Function: promptForPegs
// Purpose: prompt the user for a starting Peg and endng Peg numbers
// Input: integers that reps the starting peg number anad the ending peg number
// Output: void returns nothing
void promptForPegs(int& startPeg, int& endPeg)
{
    int userSAnswer;
    int userEAnswer;
    //do while loops to assure that users answers follow the requirements
    do
    {
        std::cout<< "Which peg will be your starting peg? (1, 2, or 3): ";
        std::cin>> userSAnswer;
        if(userSAnswer>=1 && userSAnswer<=3)
        {
            startPeg=userSAnswer;
        }
    } while (userSAnswer<1 || userSAnswer>3);
    
    do
    {
        std::cout<< "Which peg will be your ending peg? (1, 2, or 3): ";
        std::cin>>userEAnswer;
        if(userEAnswer>=1 && userEAnswer<=3 &&  userEAnswer!=startPeg)
        {
            endPeg=userEAnswer;
        }
    } while ((userEAnswer<1 && userEAnswer>3) || userEAnswer==userSAnswer);
}

// Function: draw
// Purpose: draw all the pegs (and therefore all the disks on the pegs)
// Input: gwindow to draw in, a vector of pegs
// Output: void returns nothing

void draw (GWindow gw, Vector<Peg> myPeg)
{
    gw.clear();
    
   // for (int i=0; i < myPeg.size(); i++)
   // {
    //    myPeg[i].draw(gw);
   // }
    
    //range based loop to loop through the vector of pegs
    for (Peg peg: myPeg)
    {
        peg.draw(gw);
    }
    pause(1000);
}

// Function: moveDisk
// Purpose: removes the top most Dsk from the start Peg, add it to the destination Peg
// Input: gwindow to draw in, a vector of pegs, int that reps starting peg, int that reps ending peg
// Output: void returns nothing

void moveDisk (GWindow& gw, Vector<Peg>& myPeg, int startPeg, int endPeg)
{
    Disk temp;
    temp=myPeg[startPeg].removeDisk();
    myPeg[endPeg].addDisk(temp);
    draw(gw, myPeg);
}

//1.1. Label the Pegs “start”, “temp”, “end” — these labels may change at different steps
//1.2. Let N be the total number of Disks
//1.3. Number the Disks from N-1 (smallest, topmost) to 0 (largest, bottommost)
//call move 1.4. Move N Disks from “start” to “end”:
//recursive call 1 1.4.1. Transfer N−1 Disks from “start” to “temp”. This leaves Disk 0 alone on “start”
//1.4.2. Move Disk 0 from “start” to “end”
//recursive call 2 1.4.3. Transfer N−1 Disks from “temp” to “end” so they sit on Disk 0

// Function: towerSolver
// Purpose: Uses recursion to move all the Disks from the source Peg to the target Peg
// Input: gwindow to draw in, a vector of pegs, int that reps starting peg, int that reps ending peg, int that reps the number of disks
// Output: void returns nothing
void towerSolver (GWindow& gw, Vector<Peg>& myPeg, int startPeg, int endPeg, int diskNum)
{
    
    //2 recursive calls
    //call move disk
    //when thinking recusively
    //assume that you've written everything and tower solver works works
    //start peg to temp peg to end peg
    //base case 1.3
    //each recusive call do n-1
    //when n=0 stop
    int tempPeg;
     tempPeg=3-(startPeg+endPeg);
    if (diskNum==0)
    {
        return;
    }
    else
    {
        towerSolver(gw, myPeg,startPeg, tempPeg, diskNum-1);
        moveDisk(gw, myPeg, startPeg, endPeg);
        towerSolver(gw, myPeg, tempPeg, endPeg, diskNum-1);
    }
}




int main(int argc, char** argv)
{
    // Create a window
    GWindow gw(800, 500);
    //establish vector of pegs
    Vector<Peg> vectorsPeg;
    int startPeg;
    int endPeg;
    int numDisks = promptForDisks();
    promptForPegs(startPeg, endPeg);
    //Changes values to indicies
    startPeg--;
    endPeg--;
    //for (int i=0; i<3; i++)
    //{
    // vectorsPeg.push_back(i);
    //  vectorsPe
    //}
    
    //Creation of Three pegs
    Peg pegOne(150,500,450,30);
    pegOne.draw(gw);
    Peg pegTwo(400,500,450,30);
    pegTwo.draw(gw);
    Peg pegThree(650,500,450,30);
    pegThree.draw(gw);
    //store all three pegs in the vector
    vectorsPeg.push_back(pegOne);
    vectorsPeg.push_back(pegTwo);
    vectorsPeg.push_back(pegThree);
    //loop that adds the correct number of disks onto pegs
    for (int i=0; i < numDisks; i++)
    {
        vectorsPeg[startPeg].addDisk(Disk(0,0,(200-15*i),30));
    }
    draw(gw, vectorsPeg);
    //call the tower solver function once pegs and disks are drawn
    towerSolver (gw, vectorsPeg, startPeg,endPeg, numDisks);

  
    
    return 0;
}
