#include "AD.h"

float adc(int ad_value[], int data_num)
{
    // sorting
    sort(ad_value, data_num);

    // calculate average except for max and min
    int i = 0, total = 0;
    float avg = 0;
    int v = 0;
    for(i = 1; i < data_num - 2; i++)
    {
        total = total + ad_value[i];
    }
    avg = total / (data_num - 2);
    v = avg * 10 / MAX_VOLTAGE;

    return v;
}

void sort(int ad_value[], int data_num)
{
    int i;
    int newArr[data_num - 2];
    for(i = 0; i < data_num; i++)
    {
        int j;
        for(j = 0; j < data_num; j++)
        {
            if (ad_value[i] > ad_value[j])
            {
                int swap = ad_value[i];
                ad_value[i] =  ad_value[j];
                ad_value[j] = swap;
            }
        }
    }
}
