//  psggConverterLib.dll converted from TestControl.xlsx. 
#include <stdio.h>
#include <stdbool.h>

//== Declear externals  ==

extern void TestControl_update();
extern void TestControl_start();
extern bool TestControl_is_end();

//== Declear States  ==

static void S_START(bool bFirst);
static void S_END(bool bFirst);
static void S_0001(bool bFirst);
static void S_0002(bool bFirst);
static void S_0003(bool bFirst);
static void S_0004(bool bFirst);


// == manager ==

static void *m_curfunc = NULL;
static void *m_nextfunc= NULL;
static void *m_tempfunc = NULL;
static bool  m_bNoWait = false;

extern void TestControl_update() {
    while(true) {
        bool bFirst = false;
        if (m_nextfunc!=NULL) {
            m_curfunc = m_nextfunc;
            m_nextfunc = NULL;
            bFirst = true;
        }

        m_bNoWait = false;
        if (m_curfunc!=NULL) {
            void (*func)(bool);
            func = m_curfunc;
            (*func)(bFirst);
        }
        if (m_bNoWait == false) break;
    }
}

static void Goto(void *st) {
    m_nextfunc = st;
}

static bool CheckState(void *st) {
    return m_curfunc == st;
}

static void SetNextState(void *st) {
    m_tempfunc = st;
}

static void GoNextState() {
    m_nextfunc = m_tempfunc;
    m_tempfunc  = NULL;
}

static bool HasNextState() {
    return m_tempfunc != NULL;
}

static void NoWait()
{
    m_bNoWait = true;
}

//== Include User source ==
#include "TestControl.c"


//== States ==


/*
    S_START
*/
void S_START(bool bFirst)
{
    if (bFirst)
    {
    }
    if (!HasNextState())
    {
        SetNextState(S_0001);
    }
    if (HasNextState())
    {
        GoNextState();
    }
}
/*
    S_END
*/
void S_END(bool bFirst)
{
    if (bFirst)
    {
    }
    if (HasNextState())
    {
        GoNextState();
    }
}
/*
    S_0001
    new state
*/
void S_0001(bool bFirst)
{
    if (bFirst)
    {
        printf("Hello Again!\n");
    }
    if (!HasNextState())
    {
        SetNextState(S_0002);
    }
    if (HasNextState())
    {
        GoNextState();
    }
}
/*
    S_0002
    new state
*/
void S_0002(bool bFirst)
{
    if (bFirst)
    {
        set_yes_or_no();
    }
    br_YES(S_0003);
    br_NO(S_0004);
    if (HasNextState())
    {
        GoNextState();
    }
}
/*
    S_0003
    new state
*/
void S_0003(bool bFirst)
{
    if (bFirst)
    {
        printf("YES\n");
    }
    if (!HasNextState())
    {
        SetNextState(S_END);
    }
    if (HasNextState())
    {
        GoNextState();
    }
}
/*
    S_0004
    new state
*/
void S_0004(bool bFirst)
{
    if (bFirst)
    {
        printf("NO\n");
    }
    if (!HasNextState())
    {
        SetNextState(S_END);
    }
    if (HasNextState())
    {
        GoNextState();
    }
}


// start and check end
extern void TestControl_start()
{
    Goto(S_START);
}
extern bool TestControl_is_end()
{
    return CheckState(S_END);
}

