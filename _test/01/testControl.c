#include <stdio.h>
#include <stdbool.h>

// mananager
static void *m_curfunc = NULL;
static void *m_nextfunc= NULL;
static void *m_tempfunc = NULL;
static bool  m_bNoWait = false;

extern void testControl_update() {
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

// Decrlear
static void S_START(bool);
static void S_END(bool);
static void S_0001(bool);

// states
static void S_START(bool bFirst) {
    if (bFirst) {
        printf("S_START\n");
    }
    Goto(S_0001);
}
static void S_END(bool bFirst) {
    if (bFirst) {
        printf("S_END\n");
    }
}
static int m_cnt = 0;
static void S_0001(bool bFirst) {
    if (bFirst) {
        printf("S_0001\n");
        SetNextState(S_END);
    }
    printf("%d\n",m_cnt);
    if (m_cnt++ < 10) return;
    GoNextState();
}

// start and check end
extern void testControl_start()
{
    Goto(S_START);
}
extern bool testControl_is_end()
{
    return CheckState(S_END);
}