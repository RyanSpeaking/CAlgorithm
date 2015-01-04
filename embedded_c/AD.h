#ifndef AD_H_INCLUDED
#define AD_H_INCLUDED

#include <stdio.h>

#define MAX_VOLTAGE 3.3f
#define MAX_VOLTAGE_AD 1024
#define VSAMPLE 10

//===============
// PUBLIC
//===============
// analog to digital converter of voltage
float adc(int ad_value[], int data_num);

//===============
// PRIVATE
//===============
void sort(int ad_value[], int data_num);

#endif // AD_H_INCLUDED


