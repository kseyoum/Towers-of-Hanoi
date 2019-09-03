//
//  Disk.h
//  Mac
//
//  Created by Kirubel Seyoum on 2/7/19.
//  Copyright © 2019 Sanjay Madhav. All rights reserved.
//
#include <gwindow.h>
#include <iostream>
#include <string>
#pragma once

//Disk class to establish disk objects
class Disk
{
private:
//Establish Disk member variables
    int diskX;
    int diskY;
    int diskWidth;
    int diskHeight;
    std::string diskColor;
    
    


public:
    //constructor
    Disk();
    //paramartized constructor
    Disk(int x, int y, int width, int height);
    //setter function for X
    void setDiskX(int x);
    //setter function for Y
    void setDiskY(int y);
    //getter function for disk height
    int getDiskHeight();
    //draw function for disk
    void draw (GWindow& gw);
};

