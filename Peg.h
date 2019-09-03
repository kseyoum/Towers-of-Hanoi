//
//  Peg.h
//  Mac
//
//  Created by Kirubel Seyoum on 2/7/19.
//  Copyright © 2019 Sanjay Madhav. All rights reserved.
//
#include <iostream>
#include <string>
#include "vector.h"
#pragma once
#include "Disk.h"
//Peg class to establish peg objects
class Peg
{
private:
    //peg member variables
    Vector<Disk> diskOnPeg;
    int pegX;
    int pegY;
    int pegWidth;
    int pegHeight;
    std::string pegColor;
    
public:
    //peg class functions
    Peg();
    Peg(int x, int y, int height, int width);
    void draw(GWindow& gw);
    void addDisk(Disk oneDisk);
    Disk removeDisk();
};
    

