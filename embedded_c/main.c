#include <stdio.h>
#include <stdlib.h>
#include "AD.h"
#include "tree.h"

int a = 3, *p1, *p2, *p3;

void pt(int x, int y)
{
    printf("x + y = %d\n", x + y);
}

void analogToDigitalConverter()
{
    int v[VSAMPLE] = {432,543,63,464,325,675,324,1004,464,198};
    printf("Voltage is:[%f]\n", adc(v, VSAMPLE));
}

void envTest()
{
    printf("Hello world!\n");
    pt(5, 6);
}

void pointerTestPrint()
{
    printf("a = %d, *p1 = %d, *p2 = %d, *p3 = %d\n", a, *p1, *p2, *p3);
}

void pointerTest()
{
    p1 = p2 = p3 = &a;
    pointerTestPrint();

    (*p1) = (*p1)++;
    pointerTestPrint();

    int b = 5;
    p1 = &b;
    pointerTestPrint();

    //illegal
    //p1 = 3;
    //pointerTestPrint();

    int arr[10] = {0};
    printf("arr = 0x%x\n", arr);
    //illegal
    //arr++;
    //printf("arr = %d\n", arr);

    p1 = arr;
    printf("p1's address=0x%x, P1's pointing address=0x%x", &p1, p1);

    //illegal assignment of value before pointing to a address
    //int *p4;
    //*p4 = 4;
    //printf("p4 address = 0x%x, *p4 = %d\n", &p4, *p4);
}

void main()
{
    //envTest());
    //pointerTest();
    //analogToDigitalConverter();
    treeDemo();
    return;
}


