/********** BEGIN_OF_FILE **********/
/* cshedulingalgorithms.h */

#ifndef CSHEDULINGALGORITHMS_H
#define CSHEDULINGALGORITHMS_H

#include "constantsandtypes.h"
#include "cprocess.h"

using namespace std;

/*
 *
 */
class cShedulingAlgorithms
{
    /*
     * cProcess tableProcesses[constSeries][constProcesses] -
     */
    cProcess tableProcesses[constSeries][constProcesses];
    /*
     * typeTime tableTotalTimesDoing[constSeries] -
     */
    typeTime tableTotalTimesDoing[constSeries];
    /*
     * double tableAverageTimesDoing[constSeries] -
     */
    double tableAverageTimesDoing[constSeries];
    /*
     * typeTime tableTotalTimesProcessing[constSeries] -
     */
    typeTime tableTotalTimesProcessing[constSeries];
    /*
     * double tableAverageTimesProcessing[constSeries] -
     */
    double tableAverageTimesProcessing[constSeries];

public:
    /*
     * cShedulingAlgorithms() -
     */
    cShedulingAlgorithms();

    /*
     * void mSheduling() -
     */
    void mSheduling();
    /*
     * void mRoundRobin() -
     */
    void mRoundRobin();

    /*
     * getProcess(typeProcess parSeries, typeProcess parProcesses) -
     */
    inline cProcess getProcess(typeProcess parSeries, typeProcess parProcesses)
    {
        return tableProcesses[parSeries][parProcesses];
    }
    /*
     * getTotalTimesDoing(typeProcess parSeries) -
     */
    inline typeTime getTotalTimesDoing(typeProcess parSeries)
    {
        return tableTotalTimesDoing[parSeries];
    }
    /*
     * getAverageTotalTimesDoing(typeProcess parSeries) -
     */
    inline typeTime getAverageTotalTimesDoing(typeProcess parSeries)
    {
        return tableAverageTimesDoing[parSeries];
    }
    /*
     * getTotalTimesProcessing(typeProcess parSeries) -
     */
    inline typeTime getTotalTimesProcessing(typeProcess parSeries)
    {
        return tableTotalTimesProcessing[parSeries];
    }
    /*
     * getAverageTimesProcessing(typeProcess parSeries) -
     */
    inline typeTime getAverageTimesProcessing(typeProcess parSeries)
    {
        return tableAverageTimesProcessing[parSeries];
    }

    /*
     * mClearTotalTimesDoing(typeProcess parSeries) -
     */
    inline void mClearTotalTimesDoing(typeProcess parSeries)
    {
        tableTotalTimesDoing[parSeries] = 0;
    }
    /*
     * mClearAllTotalTimesDoing() -
     */
    void mClearAllTotalTimesDoing();
    /*
     * mClearAverageTimesDoing(typeProcess parSeries) -
     */
    inline void mClearAverageTimesDoing(typeProcess parSeries)
    {
        tableAverageTimesDoing[parSeries] = 0;
    }
    /*
     * mClearAllAverageTimesDoing() -
     */
    void mClearAllAverageTimesDoing();
    /*
     * mClearTotalTimesProcessing(typeProcess parSeries) -
     */
    inline void mClearTotalTimesProcessing(typeProcess parSeries)
    {
        tableTotalTimesProcessing[parSeries] = 0;
    }
    /*
     * mClearAllTotalTimesProcessing() -
     */
    void mClearAllTotalTimesProcessing();
    /*
     * mClearAverageTimesProcessing(typeProcess parSeries) -
     */
    inline void mClearAverageTimesProcessing(typeProcess parSeries)
    {
        tableAverageTimesProcessing[parSeries] = 0;
    }
    /*
     * mClearAllAverageTimesProcessing() -
     */
    void mClearAllAverageTimesProcessing();

    /*
     * mCalculateTotalTimesDoing(typeProcess parSeries) -
     */
    void mCalculateTotalTimesDoing(typeProcess parSeries);
    /*
     * mCalculateAverageTotalTimesDoing(typeProcess parSeries) -
     */
    void mCalculateAverageTotalTimesDoing(typeProcess parSeries);
    /*
     * mCalculateTotalTimesProcessing(typeProcess parSeries) -
     */
    void mCalculateTotalTimesProcessing(typeProcess parSeries);
    /*
     * mCalculateAverageTimesProcessing(typeProcess parSeries) -
     */
    void mCalculateAverageTimesProcessing(typeProcess parSeries);

    /*
     * mSortingSeries(typeProcess parSeries) -
     */
    void mSortingSeries(typeProcess parSeries);
    /*
     * mSortingAll() -
     */
    void mSortingAll();
    /*
     * mReverseSeries(typeProcess parSeries) -
     */
    void mReverseSeries(typeProcess parSeries);
    /*
     * mReverseAll() -
     */
    void mReverseAll();

    /*
     * mDrawProcesses() -
     */
    void mDrawProcesses();
    /*
     * mClearSeries(typeProcess parSeries) -
     */
    void mClearSeries(typeProcess parSeries);
    /*
     * mClearAllSeries() -
     */
    void mClearAllSeries();

    /*
     * mPrintProcessesToFile() -
     */
    void mPrintProcessesToFile();
    /*
     * mPrintResultsToFile(typeProcess parAlgorithmNumber) -
     */
    void mPrintResultsToFile(typeProcess parAlgorithmNumber);
};

#endif // CSHEDULINGALGORITHMS_H

/* cshedulingalgorithms.h */
/********** END_OF_FILE **********/
