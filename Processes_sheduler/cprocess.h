/********** BEGIN_OF_FILE **********/
/* cprocess.h */

#ifndef CPROCESS_H
#define CPROCESS_H

#include "constantsandtypes.h"
#include <iostream>

using namespace std;

class cProcess
{
    /*
     * typeTime vTime -
     */
    typeTime vTime;
    /*
     * typeTime vTimeStartOfProcessing -
     */
    typeTime vTimeStartOfProcessing;
    /*
     * typeTime vTimeEndOfProcessing -
     */
    typeTime vTimeEndOfProcessing;
    /*
     * typeTime vTimeProcessing -
     */
    typeTime vTimeProcessing;
    /*
     * typeTime vTimeDone -
     */
    typeTime vTimeDone;
    /*
     * typeTime vTimeWillDo -
     */
    typeTime vTimeWillDo;

public:
    /*
     * cProcess() -
     */
    cProcess();
    /*
     * cProcess(typeTime parTime) -
     */
    cProcess(typeTime parTime);

    /*
     * ostream &operator << (ostream &streamOut, cProcess &P) -
     */
    friend ostream &operator << (ostream &streamOut, cProcess &P);

    /*
     * getVTime() -
     */
    inline typeTime getVTime()
    {
        return vTime;
    }
    /*
     * getVTimeStartOfProcessing() -
     */
    inline typeTime getVTimeStartOfProcessing()
    {
        return vTimeStartOfProcessing;
    }
    /*
     * getVTimeEndOfProcessing() -
     */
    inline typeTime getVTimeEndOfProcessing()
    {
        return vTimeEndOfProcessing;
    }
    /*
     * getVTimeProcessing() -
     */
    inline typeTime getVTimeProcessing()
    {
        return vTimeProcessing;
    }
    /*
     * getVTimeDone() -
     */
    inline typeTime getVTimeDone()
    {
        return vTimeDone;
    }
    /*
     * getVTimeWillDo() -
     */
    inline typeTime getVTimeWillDo()
    {
        return vTimeWillDo;
    }

    /*
     * setVTime(typeTime parTime) -
     */
    void setVTime(typeTime parTime);
    /*
     * setVTimeStartOfProcessing(typeTime parTime) -
     */
    void setVTimeStartOfProcessing(typeTime parTime);

    /*
     * mDoProcess() -
     */
    void mDoProcess();
    /*
     * mIncrementProcessingTime() -
     */
    inline void mIncrementProcessingTime()
    {
        vTimeDone++;
    }
    /*
     * mDoQuantumOfTime(typeTime parTime) -
     */
    inline void mDoQuantumOfTime(typeTime parTime)
    {
        vTimeDone += parTime;
    }
    /*
     * mClearProcess() -
     */
    void mClearProcess();

    /*
     * mCalculateProcessing() -
     */
    typeProcess mCalculateProcessing();
};

#endif // CPROCESS_H

/* cprocess.h */
/********** END_OF_FILE **********/
