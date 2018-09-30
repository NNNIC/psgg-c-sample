#include <stdio.h>
#include <stdbool.h>

extern void TestControl_update();
extern void TestControl_start();
extern bool TestControl_is_end();

void main()
{
    printf("hello!\n");

    TestControl_start();

    while(TestControl_is_end()==false) {
        TestControl_update();
    }

}