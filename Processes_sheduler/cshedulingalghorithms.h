/********** BEGIN_OF_FILE **********/
/* cshedulingalghorithms.h */

#ifndef CSHEDULINGALGHORITHMS_H
#define CSHEDULINGALGHORITHMS_H

#include "constantsandtypes.h"
#include "cprocess.h"

using namespace std;

class cShedulingAlghorithms
{
    cProcess tableProcesses[constSeries][constProcesses];
    typeTime tableTotalTimesDoing[constSeries];
    double tableAverageTimesDoing[constSeries];
    typeTime tableTotalTimesProcessing[constSeries];
    double tableAverageTimesProcessing[constSeries];
public:
    cShedulingAlghorithms();

    void mSheduling();
    void mRoundRobin();

    inline cProcess getProcess(typeProcess parSeries, typeProcess parProcesses);
    inline typeTime getTotalTimesDoing(typeProcess parSeries);
    inline typeTime getAverageTotalTimesDoing(typeProcess parSeries);
    inline typeTime getTotalTimesProcessing(typeProcess parSeries);
    inline typeTime getAverageTimesProcessing(typeProcess parSeries);

    inline void mClearTotalTimesDoing(typeProcess parSeries);
    void mClearAllTotalTimesDoing();
    inline void mClearAverageTimesDoing(typeProcess parSeries);
    void mClearAllAverageTimesDoing();
    inline void mClearTotalTimesProcessing(typeProcess parSeries);
    void mClearAllTotalTimesProcessing();
    inline void mClearAverageTimesProcessing(typeProcess parSeries);
    void mClearAllAverageTimesProcessing();

    void mCalculateTotalTimesDoing(typeProcess parSeries);
    void mCalculateAverageTotalTimesDoing(typeProcess parSeries);
    void mCalculateTotalTimesProcessing(typeProcess parSeries);
    void mCalculateAverageTimesProcessing(typeProcess parSeries);

    void mSortingSeries(typeProcess parSeries);
    void mSortingAll();
    void mReverseSeries(typeProcess parSeries);
    void mReverseAll();

    void mDrawProcesses();
    void mClearSeries(typeProcess parSeries);
    void mClearAllSeries();

    void mPrintProcessesToFile();
    void mPrintResultsToFile(typeProcess parAlghorithmNumber);
};

#endif // CSHEDULINGALGHORITHMS_H

/* cshedulingalghorithms.h */
/********** END_OF_FILE **********/
