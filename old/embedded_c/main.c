#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {false, true} bool;

/** \Judge whether num is an even number by bit
 *
 * \param num Short type of input
 * \return true or false
 */
bool isEvenByBit(unsigned short num) {
    short mask = 0x01;
    printf("num & mask = %d\n", num & mask);
    return ((num & mask) == 0);
}

/** \Judge whether num is an even number by mod
 *
 * \param num Short type of input
 * \return true or false
 *
 */
bool isEvenByMod(unsigned short num) {
    bool ret;
    return ((num % 2) == 0);
}

void showbit(unsigned short num) {
    //mask to get every bit value
    unsigned short mask = 1;
    //character array to store every bit in char
    unsigned char arr[sizeof(short) * 9] = {0};

    int step;
    for (step = 0; step < sizeof(short) * 8; step++) {
        //every bit mask is power of 2
        //so bit 0 "&" 1 << 0, bit 1 "&" 1 << 1, bit 2 "&" 1 << 2 to keep the value unchanged.
        if ((num & (mask << step)) >> step == 1) {
            arr[(sizeof(short) * 8 - 1) - step] = '1';
        } else {
            arr[(sizeof(short) * 8 - 1) - step] = '0';
        }

    }

    printf("short type of num in bit format is %sb\n", arr);
}

int main()
{
    float pi = 3.1415926;
    char *str = "X\'Mas!!!";
    int num1, num2, a, b;
    char ch;

    short c = 0x0B;
    short d;
//    printf("Please insert a char for ch:\n");
//    scanf("%c", &ch);
//    printf("ch=%c\n", ch);
//
//    printf("Please enter a char:\n");
//    ch = getchar();
//    putchar(ch);
//    printf("ch=%c\n", ch);
//
//    printf("Sizeof int = %u\n%#x\n%6d\n", sizeof(int), 16, 26);
//    printf("Pi = %f\n", pi);
//    printf("Pi = %10.7f\n", pi);
//    printf("Pi = %e\n", pi);
//    printf("%s\n", str);
//    printf("Please enter a integer for a:\n");
//    num1 = scanf("%d", &a);
//    printf("Please enter a integer for b:\n");
//    num2 = scanf("%d", &b);
//    printf("a = %d, b = %d, num1 = %d, num2 = %d\n", a, b, num1, num2);
//    ch = 4815645645613.52;
//    printf("ch = %c\n", ch);
    //num1 = 4815645645613.52;
    //printf("num1 = %d\n", num1);

    printf("size of short: %d\n", sizeof(short));

    /* extract bit #3 of c
     *
     * design a bit mask d using "&"
     * because c = 0000000000001010b
     *                         3210
     *                         ^
     * "&" mask d should be 0000000000001000b
     * because any bit & 1 will not change, & 0 will always be 0
     */

     d = 0x08;
     printf("The bit 3 of c = %x\n", (c & d) >> 3);

    /* design a bit mask using "|"
     *
     * "|" mask e should be 1111111111110111b
     * because any bit | 0 will not change, | 1 will always be 1
     */

    short e = 0xFFF7;
    printf("The bit #3 of c = %x\n", (c | d) >> 3);

    /*set bit #3 of c to 0*/
    short maskf = 0x07;
    printf("The bit #3 of c = %x\n", (c & maskf) >> 3);

    /*set bit #2 of c to 1*/
    short maskg = 0x04;
    printf("The bit #2 of c = %x\n", ((c | maskg) & maskg)>> 2);
    showbit(65535);

    printf("Is 73846 an even number ?%d\n", isEvenByBit(73846));
    printf("Is 73846 an even number ?%s\n", isEvenByBit(73846) == true ? "true" : "false");


    switch (isEvenByBit(73846)) {
        case true:
            printf("73846 is even\n");
            break;
        case false:
            printf("73846 is odd\n");
            break;
        default:
            break;
    }


    return 0;
}


