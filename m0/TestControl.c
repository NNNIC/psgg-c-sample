#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

static bool m_bYesNo = false;
	
static void br_YES(void *st)
{
	if (!HasNextState())
	{
		if (m_bYesNo)
		{
			SetNextState(st);
		}
	}
}

static void br_NO(void *st)
{
	if (!HasNextState())
	{
		if (!m_bYesNo)
		{
			SetNextState(st);
		}
	}
}

// write your code here!
static void set_yes_or_no()
{
	srand((unsigned)time(NULL));
	int r = rand();
	printf("rand = %d\n",r );
	m_bYesNo = ((r % 2) == 0);
}