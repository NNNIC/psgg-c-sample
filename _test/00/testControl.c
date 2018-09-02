#include <stdio.h>
#include <stdbool.h>

// mananager
void *testControl_curfunc = NULL;
void *testControl_nextfunc= NULL;

extern void testControl_update() {
    bool bFirst = false;
    if (testControl_nextfunc!=NULL) {
        testControl_curfunc = testControl_nextfunc;
        testControl_nextfunc = NULL;
        bFirst = true;
    }
    if (testControl_curfunc!=NULL) {
        void (*func)(bool);
        func = testControl_curfunc;
        (*func)(bFirst);
    }
}

void testControl_goto(void *st) {
    testControl_nextfunc = st;
}

bool testControl_checkState(void *st) {
    return testControl_curfunc == st;
}

// Decrlear
void testControl_S_START(bool);
void testControl_S_END(bool);
void testControl_S_0001(bool);

void testControl_S_START(bool bFirst) {
    if (bFirst) {
        printf("S_START\n");
    }
    testControl_goto(testControl_S_END);
}
void testControl_S_END(bool bFirst) {
    if (bFirst) {
        printf("S_END\n");
    }
}

//
extern void testControl_start()
{
    testControl_goto(testControl_S_START);
}
extern bool testControl_is_end()
{
    return testControl_checkState(testControl_S_END);
}