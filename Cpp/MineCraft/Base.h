#ifndef BASE_H
#define BASE_H

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<cmath>

#define ubuntu
#ifdef ubuntu
    #define clear system("clear")
#endif
#ifdef windows
    #define clear system("cls")
#endif

using namespace std;

const int TSoil = 0;
const char CSoil = ' ';
const int TWater = 1;
const char CWater = '~';
const int TDes = -1;
const char CDes = '*';
const int THill = 2;
const char CHill = '^';
const int TRabbit = 3;
const char CRabbit = '@';
const int TWolf = 4;
const char CWolf = '!';
const int TGlass = 5;
const char CGlass = '$';

int TotalDay = 0, TotalRabbit, TotalWolf;
int StD, WeR, ReG, DW, DR;
#endif