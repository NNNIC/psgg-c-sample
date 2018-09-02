#include <stdio.h>
#include <stdbool.h>

extern void testControl_update();
extern void testControl_start();
extern bool testControl_is_end();

void main()
{
    printf("hello!\n");

    testControl_start();

    while(testControl_is_end()==false) {
        testControl_update();
    }

}