/********** BEGIN_OF_FILE **********/
/* cprocess.cpp */

#include "cprocess.h"

using namespace std;

/*
 * cProcess()
 */
cProcess::cProcess()
{
    vTime = 0; // nadanie wartosci poczatkowych
    vTimeDone = 0;
    vTimeWillDo = 0;
}

/*
 * cProcess(typeTime parTime)
 */
cProcess::cProcess(typeTime parTime)
{
    vTime = parTime; // nadanie wartosci poczatkowych
    vTimeDone = 0;
    vTimeWillDo = parTime;
}

/*
 * ostream &operator << (ostream &streamOut, cProcess &P)
 */
ostream &operator << (ostream &streamOut, cProcess &P)
{
    streamOut << P.getVTime();
    return streamOut;
}

/*
 * void setVTime(typeTime parTime)
 */
void cProcess::setVTime(typeTime parTime)
{
    vTime = parTime; // zmiana wartosci czasu trwania procesu
    vTimeDone = 0;
    vTimeWillDo = parTime;
}
/*
 * void mDoProcess()
 */
void cProcess::mDoProcess()
{
    vTimeDone = vTime; // mija caly czas wykonania procesu
    vTimeWillDo = 0;
}
/*
 * mIncrementProcessingTime()
 */
void cProcess::mIncrementProcessingTime()
{
    if (vTimeWillDo > 0) // sprawdzamy czy proces nie jest juz w calosci
    {                    // wykonany
        vTimeDone++;
        vTimeWillDo--;
    }
}
/*
 * mDoQuantumOfTime(typeTime parTime)
 */
void cProcess::mDoQuantumOfTime(typeTime parTime)
{
    if (parTime >= vTimeWillDo) // sprawdzamy czy staly kwant czasu nie przekracza
        mDoProcess();           // wartosci czasu jaka zostala do konca
    else
    {
        vTimeDone += parTime;
        vTimeWillDo -= parTime;
    }
}

/*
 * void mClearProcess()
 */
void cProcess::mClearProcess()
{
    vTime = 0; // zerowanie wszystkich wartosci
    vTimeStartOfProcessing = 0;
    vTimeEndOfProcessing = 0;
    vTimeProcessing = 0;
    vTimeDone = 0;
    vTimeWillDo = 0;
}

/* cprocess.cpp */
/********** END_OF_FILE **********/
