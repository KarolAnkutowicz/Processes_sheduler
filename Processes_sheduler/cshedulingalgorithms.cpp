/********** BEGIN_OF_FILE **********/
/* cshedulingalgorithms.cpp */

#include "cshedulingalgorithms.h"

using namespace std;

/*
 * cShedulingAlgorithms()
 */
cShedulingAlgorithms::cShedulingAlgorithms()
{
    mMakeFCFS();
    mMakeLCFS();
    mMakeSJF();
    mMakeRR();
    mMakeSRT();
}

/*
 * cShedulingAlgorithms(enum aAlgorithm)
 */
cShedulingAlgorithms::cShedulingAlgorithms(enumAlgorithms aAlgorithm)
{
    switch (aAlgorithm)
    {
        case fcfs: mMakeFCFS(); break;
        case lcfs: mMakeLCFS(); break;
        case sjf: mMakeSJF(); break;
        case rr: mMakeRR(); break;
        case srt: mMakeSRT(); break;
    }
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
    typeTime vTime1, vTime2;
    mResetAllProcesses();
    srand(time_t(NULL) + (unsigned int)&constProcesses);
    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++)
        {
            vTime1 = rand() % constMaxTime + 1;
            vTime2 = rand() % constMaxTime + 1;
            tabProcesses[i][j].setTimeReadiness(vTime1);
            tabProcesses[i][j].setTimeDoing(vTime2);
        }
    }
}

/*
 * mResetSeries(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mResetSeries(typeNumberProcess aSeries)
{
    for (typeNumberProcess i = 0; i < constProcesses; i++)
        mResetProcess(aSeries, i);
}

/*
 * mResetAllProcesses()
 */
void cShedulingAlgorithms::mResetAllProcesses()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mResetSeries(i);
}

/*
 * mReadProcessesFromFile()
 */
void cShedulingAlgorithms::mReadProcessesFromFile()
{
    mResetAllProcesses();
    ifstream StreamIn;
    StreamIn.open("procesy.txt");
    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++)
        {
            StreamIn >> tabProcesses[i][j];
        }
    }
    StreamIn.close();
}

/*
 * mWriteProcessesToFile()
 */
void cShedulingAlgorithms::mWriteProcessesToFile()
{
    ofstream StreamOut;
    StreamOut.open("procesy.txt");
    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++)
            StreamOut << tabProcesses[i][j];
        StreamOut << "   ";
    }
    StreamOut.close();
}



/*
 * mSortingSeries(typeNumberProcess aSeries, bool aAscendingReadiness, bool aAscendingDoing, bool aReadinessFirst)
 */
void cShedulingAlgorithms::mSortingSeries(typeNumberProcess aSeries, bool aAscendingReadiness, bool aAscendingDoing, bool aReadinessFirst)
{
    if (aReadinessFirst)
    {
        if (aAscendingReadiness)
        {
            if (aAscendingDoing)
            {

            }
            else
            {

            }
        }
        else
        {
            if (aAscendingDoing)
            {

            }
            else
            {

            }
        }
    }
    else
    {
        if (aAscendingReadiness)
        {
            if (aAscendingDoing)
            {

            }
            else
            {

            }
        }
        else
        {
            if (aAscendingDoing)
            {

            }
            else
            {

            }
        }
    }
}

/*
 * mSortingAllSeries(bool aAscendingReadiness, bool aAscendingDoing, bool aReadinessFirst)
 */
void cShedulingAlgorithms::mSortingAllProcesses(bool aAscendingReadiness, bool aAscendingDoing, bool aReadinessFirst)
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
        if (aReadinessFirst)
        {
            if (aAscendingReadiness)
            {
                if (aAscendingDoing)
                    mSortingSeries(i, true, true, true);
                else
                    mSortingSeries(i, true, false, true);
            }
            else
            {
                if (aAscendingDoing)
                    mSortingSeries(i, false, true, true);
                else
                    mSortingSeries(i, false, false, true);
            }
        }
        else
        {
            if (aAscendingReadiness)
            {
                if (aAscendingDoing)
                    mSortingSeries(i, true, true, false);
                else
                    mSortingSeries(i, true, false, false);
            }
            else
            {
                if (aAscendingDoing)
                    mSortingSeries(i, false, true, false);
                else
                    mSortingSeries(i, false, false, false);
            }
        }
    }
}

/*
 * void mReverseOrderSeries(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mReverseOrderSeries(typeNumberProcess aSeries)
{
    cProcess vProc;
    for (typeNumberProcess i = 0; i < (constProcesses / 2); i++)
    {
        vProc = tabProcesses[aSeries][i];
        tabProcesses[aSeries][i] = tabProcesses[aSeries][constProcesses - i - 1];
        tabProcesses[aSeries][constProcesses - i - 1] = vProc;
    }
}

/*
 * mReverseOrderAllSeries()
 */
void cShedulingAlgorithms::mReverseOrderAllSeries()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mReverseOrderSeries(i);
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
    mResetTotalTimeDoing(aSeries);
    for (typeNumberProcess i = 0; i < constProcesses; i++)
        tabTotalTimeDoing[aSeries] += tabProcesses[aSeries][i].getTimeDoing();
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
    tabAverageTimeDoing[aSeries] = getTotalTimeDoing(aSeries) / constProcesses;
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
    mResetTotalTimeProcessing(aSeries);
    for (typeNumberProcess i = 0; i < constProcesses; i++)
        tabTotalTimeProcessing[aSeries] += tabProcesses[aSeries][i].getTimeProcessing();
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
    tabAverageTimeProcessing[aSeries] = getTotalTimeProcessing(aSeries) / constProcesses;
}



/*
 * mWriteResultsToFile(enumAlgorithms aAlgorithm)
 */
void cShedulingAlgorithms::mWriteResultsToFile(enumAlgorithms aAlgorithm)
{
    // fcfs, lcfs, sjf, rr, srt
    ofstream StreamOut;
    switch(aAlgorithm)
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
