//
//  Peg.cpp
//  Mac
//
//  Created by Kirubel Seyoum on 2/7/19.
//  Copyright © 2019 Sanjay Madhav. All rights reserved.
//
#include "Peg.h"

// Function: Peg
// Purpose: default Constructor to set the values of each peg
// Input: nothing
// Output: constructor returns nothing
Peg::Peg()
{
    //empty
}

// Function: Peg
// Purpose: Constructor to set the values of each peg
// Input: int that reps x coordinate, int that reps y coordinate, int that reps height of peg, and int that reps width of peg
// Output: constructor returns nothing
Peg::Peg(int x, int y, int height, int width)
{
    pegX=x;
    pegY=y;
    pegHeight=height;
    pegWidth=width;
}

// Function: draw
// Purpose: draws the peg and all of the disks that are on that peg
// Input: A gwindow by reference to create with all the pegs
// Output: void returns nothing
void Peg::draw(GWindow& gw)
{
    gw.setColor("black");
    gw.fillRect(pegX-pegWidth/2,pegY-pegHeight,pegWidth,pegHeight);
    for (int i=0; i<diskOnPeg.size(); i++)
    {
        diskOnPeg[i].draw(gw);
    }
}

// Function: addDisk
// Purpose: This function adds a disk to a peg
// Input: takes a disk object as input
// Output: void returns nothing
void Peg::addDisk(Disk oneDisk)
{
    
    oneDisk.setDiskX(pegX);
    oneDisk.setDiskY(pegY-oneDisk.getDiskHeight()*diskOnPeg.size());
    //place vect
    diskOnPeg.push_back(oneDisk);
}

// Function: removeDisk
// Purpose: removes the last disk on that peg and returns it
// Input: nothing
// Output: returns the last disk removed from peg
Disk Peg::removeDisk()
{
    //save a the last disk on the peg
    //remove vector default vector function
    //return it
    Disk temp =diskOnPeg[diskOnPeg.size()-1];
    diskOnPeg.remove(diskOnPeg.size()-1);
    
    return temp;
}
