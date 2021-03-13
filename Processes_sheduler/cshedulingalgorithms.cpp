/********** BEGIN_OF_FILE **********/
/* cshedulingalgorithms.cpp */

#include "cshedulingalgorithms.h"

using namespace std;

/*
 * cShedulingAlgorithms()
 */
cShedulingAlgorithms::cShedulingAlgorithms()
{
}

/*
 * cShedulingAlgorithms(enum aAlgorithm)
 */
cShedulingAlgorithms::cShedulingAlgorithms(enumAlgorithms aAlgorithm)
{
}



/*
 * mMakeFCFS()
 */
void cShedulingAlgorithms::mMakeFCFS()
{
}

/*
 * mMakeLCFS()
 */
void cShedulingAlgorithms::mMakeLCFS()
{
}

/*
 * mMakeSJF()
 */
void cShedulingAlgorithms::mMakeSJF()
{
}

/*
 * mMakeRR()
 */
void cShedulingAlgorithms::mMakeRR()
{
}

/*
 * mMakeSRT()
 */
void cShedulingAlgorithms::mMakeSRT()
{
}



/*
 * mDrawProcesses()
 */
void cShedulingAlgorithms::mDrawProcesses()
{

}

/*
 * mResetAllProcesses()
 */
void cShedulingAlgorithms::mResetAllProcesses()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        for (typeNumberProcess j = 0; j < constProcesses; j++)
            mResetProcesses(i, j);
}

/*
 * mReadProcessesFromFile()
 */
void cShedulingAlgorithms::mReadProcessesFromFile()
{
}

/*
 * mWriteProcessesToFile()
 */
void cShedulingAlgorithms::mWriteProcessesToFile()
{
}



/*
 * mSortingProcesses(typeNumberProcess aSeries, bool aAscendingWaiting, bool aAscendingDoing)
 */
void cShedulingAlgorithms::mSortingProcesses(typeNumberProcess aSeries, bool aAscendingWaiting, bool aAscendingDoing)
{
}

/*
 * mSortingAllProcesses(bool aAscendingWaiting, bool aAscendingDoing)
 */
void cShedulingAlgorithms::mSortingAllProcesses(bool aAscendingWaiting, bool aAscendingDoing)
{
}



/*
 * mResetAllTotalTimeDoing()
 */
void cShedulingAlgorithms::mResetAllTotalTimeDoing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mResetTotalTimeDoing(i);
}

/*
 * mCalculateTotalTimeDoing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mCalculateTotalTimeDoing(typeNumberProcess aSeries)
{
}



/*
 * mResetAllAverageTimeDoing()
 */
void cShedulingAlgorithms::mResetAllAverageTimeDoing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mResetAverageTimeDoing(i);
}

/*
 * mCalculateAverageTimeDoing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mCalculateAverageTimeDoing(typeNumberProcess aSeries)
{
}



/*
 * mResetAllTotalTimeProcessing()
 */
void cShedulingAlgorithms::mResetAllTotalTimeProcessing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mResetTotalTimeProcessing(i);
}

/*
 * mCalculateTotalTimeProcessing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mCalculateTotalTimeProcessing(typeNumberProcess aSeries)
{
}



/*
 * mResetAllAverageTimeProcessing()
 */
void cShedulingAlgorithms::mResetAllAverageTimeProcessing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mResetAverageTimeProcessing(i);
}

/*
 * mCalculateAverageTimeProcessing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mCalculateAverageTimeProcessing(typeNumberProcess aSeries)
{
}



/*
 * mWriteResultsToFile(enumAlgorithms parAlgorithm)
 */
void cShedulingAlgorithms::mWriteResultsToFile(enumAlgorithms parAlgorithm)
{
    // fcfs, lcfs, sjf, rr, srt
    ofstream StreamOut;
    switch(parAlgorithm)
    {
        case fcfs: StreamOut.open("ResultsFCFS.txt"); break;
        case lcfs: StreamOut.open("ResultsLCFS.txt"); break;
        case sjf: StreamOut.open("ResultSJF.txt"); break;
        case rr: StreamOut.open("ResultsRR.txt"); break;
        case srt: StreamOut.open("ResultsSRT.txt"); break;
    }
    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
        StreamOut << "Average time doing " << setw(4) << i+1
                  << " series: " << tabAverageTimeDoing[i] << "     "
                  <<  "Average time processing " << setw(4) << i+1
                  << " series: " << tabAverageTimeProcessing[i] << endl;
    }
}


/* cshedulingalgorithms.cpp */
/********** END_OF_FILE **********/
