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

/* cprocess.cpp */
/********** END_OF_FILE **********/
