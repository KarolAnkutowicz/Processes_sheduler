/********** BEGIN_OF_FILE **********/
/* cprocess.cpp */

#include "cprocess.h"

using namespace std;

/*
 * cProcess()
 */
cProcess::cProcess()
{
}

/*
 * cProcess(typeTime aTimeDoing)
 */
cProcess::cProcess(typeTime aTimeDoing)
{
}

/*
 * cProcess(typeTime aTimeDoing, typeTime aTimeReadiness)
 */
cProcess::cProcess(typeTime aTimeDoing, typeTime aTimeReadiness)
{
}



/*
 * setTimeReadiness(typeTime argTimeReadiness)
 */
void cProcess::setTimeReadiness(typeTime aTimeReadiness)
{
    if (aTimeReadiness > constMaxTime)
        vTimeReadiness = constMaxTime;
    else
        vTimeReadiness = aTimeReadiness;
}

/*
 * setTimeDoing(typeTime aTimeDoing)
 */
void cProcess::setTimeDoing(typeTime aTimeDoing)
{
    if (aTimeDoing > constMaxTime)
        vTimeDoing = constMaxTime;
    else
        vTimeDoing = aTimeDoing;
}



/*
 * mIncrementTimeDone()
 */
void cProcess::mIncrementTimeDone()
{
    if (vTimeDone < vTimeDoing)
        vTimeDone++;
}

/*
 * mDecrementTimeToDo()
 */
void cProcess::mDecrementTimeToDo()
{
    if (vTimeToDo > 0)
        vTimeToDo--;
}

/* cprocess.cpp */
/********** END_OF_FILE **********/
