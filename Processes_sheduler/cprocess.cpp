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
 * ostream & operator << (ostream & StreamOut, cProcess P)
 */
ostream & operator << (ostream & StreamOut, cProcess P)
{
    StreamOut << P.getTimeReadiness() << " " << P.getTimeDoing();
    return StreamOut;
}

/*
 * istream & operator >> (istream & StreamIn, cProcess P)
 */
istream & operator >> (istream & StreamIn, cProcess P)
{
    typeTime aTimeReadiness, aTimeDoing;
    StreamIn >> skipws >> aTimeReadiness >> aTimeDoing;
    P.setTimeReadiness(aTimeReadiness);
    P.setTimeDoing(aTimeDoing);
    return StreamIn;
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
