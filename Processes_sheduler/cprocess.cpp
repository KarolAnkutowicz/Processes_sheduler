/********** BEGIN_OF_FILE **********/
/* cprocess.cpp */

#include "cprocess.h"

using namespace std;

/*
typeTime vTimeReadiness;
typeTime vTimeWaiting;
typeTime vTimeDoing;
typeTime vTimeDone;
typeTime vTimeToDo;
typeTime vTimeProcessing;
*/


/*
 * cProcess()
 */
cProcess::cProcess()
{
    vTimeReadiness = vTimeWaiting = vTimeDoing = vTimeDone
            = vTimeToDo = vTimeProcessing = 0;
}

/*
 * cProcess(typeTime aTimeDoing)
 */
cProcess::cProcess(typeTime aTimeDoing)
{
    vTimeDoing = vTimeToDo = aTimeDoing;
    vTimeReadiness = vTimeWaiting = vTimeDone = vTimeProcessing = 0;
}

/*
 * cProcess(typeTime aTimeDoing, typeTime aTimeReadiness)
 */
cProcess::cProcess(typeTime aTimeDoing, typeTime aTimeReadiness)
{
    vTimeDoing = vTimeToDo = aTimeDoing;
    vTimeReadiness = aTimeReadiness;
    vTimeWaiting = vTimeDone = vTimeProcessing = 0;
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
