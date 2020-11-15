/********** BEGIN_OF_FILE **********/
/* cprocess.h */

#ifndef CPROCESS_H
#define CPROCESS_H

#include "constantsandtypes.h"
#include <iostream>

using namespace std;

class cProcess
{
    typeTime vTime;
    typeTime vTimeStartOfProcessing;
    typeTime vTimeEndOfProcessing;
    typeTime vTimeProcessing;
    typeTime vTimeDone;
    typeTime vTimeWillDo;
public:
    cProcess();
    cProcess(typeTime parTime);

    friend ostream &operator << (ostream &streamOut, cProcess &P);

    typeTime getVTime();
    typeTime getVTimeStartOfProcessing();
    typeTime getVTimeEndOfProcessing();
    typeTime getVTimeProcessing();
    typeTime getVTimeDone();
    typeTime getVTimeWillDo();

    void setVTime(typeTime parTime);
    void setVTimeStartOfProcessing(typeTime parTime);

    void mDoProcess();
    inline void mIncrementProcessingTime();
    inline void mDoQuantumOfTime(typeTime parTime);
    void mClearProcess();

    typeProcess mCalculateProcessing();
};

#endif // CPROCESS_H

/* cprocess.h */
/********** END_OF_FILE **********/
