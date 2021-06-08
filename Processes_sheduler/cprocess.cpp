/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cprocess.cpp
 */

#include "cprocess.h"

using namespace std;

/*
 * cProcess()
 */
cProcess::cProcess()
{
    vTimeReadiness = vTimeReady = vTimeToReady = vTimeWaiting = vTimeDoing
            = vTimeDone = vTimeToDo = vTimeProcessing = 0;
}

/*
 * cProcess(typeTime aTimeDoing)
 */
cProcess::cProcess(typeTime aTimeDoing)
{
    vTimeDoing = vTimeToReady = vTimeToDo = aTimeDoing;
    vTimeReadiness = vTimeReady = vTimeWaiting = vTimeDone
            = vTimeProcessing = 0;
}

/*
 * cProcess(typeTime aTimeReadiness, typeTime aTimeDoing)
 */
cProcess::cProcess(typeTime aTimeReadiness, typeTime aTimeDoing)
{
    vTimeReadiness = vTimeToReady = aTimeReadiness;
    vTimeDoing = vTimeToDo = aTimeDoing;
    vTimeReady = vTimeWaiting = vTimeDone = vTimeProcessing = 0;
}

/*
 * cProcess(cProcess &P)
 */
cProcess::cProcess(cProcess &P)
{
    vTimeReadiness = P.vTimeReadiness;
    vTimeReady = P.vTimeReady;
    vTimeToReady = vTimeToReady;
    vTimeWaiting = P.vTimeWaiting;
    vTimeDoing = P.vTimeDoing;
    vTimeDone = P.vTimeDone;
    vTimeToDo = P.vTimeToDo;
    vTimeProcessing = P.vTimeProcessing;
}



/*
 * ostream & operator << (ostream & StreamOut, cProcess & P)
 */
ostream & operator << (ostream & StreamOut, cProcess & P)
{
    StreamOut << P.getTimeReadiness() << " " << P.getTimeDoing();
    return StreamOut;
}

/*
 * istream & operator >> (istream & StreamIn, cProcess & P)
 */
istream & operator >> (istream & StreamIn, cProcess & P)
{
    typeTime aTimeReadiness, aTimeDoing;
    StreamIn >> skipws >> aTimeReadiness >> aTimeDoing;
    P.setTimeReadiness(aTimeReadiness);
    P.setTimeDoing(aTimeDoing);
    return StreamIn;
}

/*
 * void operator = (cProcess & P)
 */
void cProcess::operator = (cProcess & P)
{
    vTimeReadiness = P.getTimeReadiness();
    vTimeDoing = P.getTimeDoing();
}



/*
 * void setTimeReadiness(typeTime argTimeReadiness)
 */
void cProcess::setTimeReadiness(typeTime aTimeReadiness)
{
    if (aTimeReadiness > constMaxTime)
        vTimeReadiness = constMaxTime;
    else
        vTimeReadiness = aTimeReadiness;
}

/*
 * void setTimeDoing(typeTime aTimeDoing)
 */
void cProcess::setTimeDoing(typeTime aTimeDoing)
{
    if (aTimeDoing > constMaxTime)
        vTimeDoing = constMaxTime;
    else
        vTimeDoing = aTimeDoing;
}



/*
 * void mIncrementTimeReady()
 */
void cProcess::mIncrementTimeReady()
{
    if (vTimeReady < vTimeReadiness)
        vTimeReady++;
}

/*
 * void mDecrementTimeToReady()
 */
void cProcess::mDecrementTimeToReady()
{
    if (vTimeToReady > 0 )
        vTimeToReady--;
}

/*
 * void mIncrementTimeDone()
 */
void cProcess::mIncrementTimeDone()
{
    if (vTimeDone < vTimeDoing)
        vTimeDone++;
}

/*
 * void mDecrementTimeToDo()
 */
void cProcess::mDecrementTimeToDo()
{
    if (vTimeToDo > 0)
        vTimeToDo--;
}

/*
 * void mResetProcess()
 */
void cProcess::mResetProcess()
{
    vTimeReadiness = vTimeWaiting = vTimeDoing = vTimeDone
    = vTimeToDo = vTimeProcessing = 0;
}


/* cprocess.cpp */
/********** END_OF_FILE **********/
