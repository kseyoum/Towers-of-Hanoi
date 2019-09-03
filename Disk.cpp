//
//  Disk.cpp
//  Mac
//
//  Created by Kirubel Seyoum on 2/7/19.
//  Copyright © 2019 Sanjay Madhav. All rights reserved.
//

#include "Disk.h"
// Function: Disk
// Purpose: default constructor that sets the values of the disks member varaibles
// Input: nothing no parameters
// Output: constructor returns nothing
Disk::Disk()
{
    setDiskX(0);
    setDiskY(0);
    diskWidth=0;
    diskHeight=0;
    diskColor= "Green";
}

// Function: Disk
// Purpose: Constructor that uses setter functions to set the values for the disk
// Input: int of disks x cordinate, int of disks y cordinate, int of disks width, int of disks height
// Output: constructor returns nothing
Disk::Disk(int x, int y, int width, int height)
{
    setDiskX(x);
    setDiskY(y);
    diskHeight=height;
    diskWidth=width;
    diskColor= "Green";
}

// Function: setDiskX
// Purpose: setter funciton that sets the x coordinate of the disk
// Input: parameter consists of only an int to rep x coordinate
// Output: void returns nothing
void Disk::setDiskX(int x)
{
    diskX=x;
}

// Function: setDiskY
// Purpose: setter funciton that sets the y coordinate of the disk
// Input: parameter consists of only an int to rep y coordinate
// Output: void returns nothing
void Disk::setDiskY(int y)
{
    diskY=y;
}

// Function: getDiskHeight
// Purpose: Return the disk Height for any disk
// Input: nothing
// Output: returns an int that reps disk height
int Disk::getDiskHeight()
{
    
    return diskHeight;
    
}

// Function: draw
// Purpose: to draw the disk based on the member variables placed
// Input: A gwindow to draw the disk in
// Output: void returns nothing
void Disk::draw (GWindow& gw)
{
    //create rectangle
    gw.setColor(diskColor);
    gw.fillRect(diskX-diskWidth/2,diskY-diskHeight,diskWidth,diskHeight);
    //create outline around rectangle
    gw.setColor("black");
    gw.drawRect(diskX-diskWidth/2,diskY-diskHeight,diskWidth,diskHeight);
    
}
