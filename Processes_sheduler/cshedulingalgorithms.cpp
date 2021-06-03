/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cshedulingalgorithms.cpp
 */

#include "cshedulingalgorithms.h"

using namespace std;

/*
 * cShedulingAlgorithms()
 */
cShedulingAlgorithms::cShedulingAlgorithms()
{
    mResetAllProcesses();
    mDrawProcesses();
    mWriteProcessesToFile();
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
    mResetAllProcesses();
    mDrawProcesses();
    mWriteProcessesToFile();
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
 * void mMakeFCFS()
 */
void cShedulingAlgorithms::mMakeFCFS()
{
    mReadProcessesFromFile();
    mSortingAllSeriesReadiness();
    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++)
            cout << tabProcesses[i][j] << "   ";
        cout << endl;
    }

    /*for (typeNumberProcess i = 0; i < constSeries; i++)
    {

    }*/

}

/*
 * void mMakeLCFS()
 */
void cShedulingAlgorithms::mMakeLCFS()
{
}

/*
 * void mMakeSJF()
 */
void cShedulingAlgorithms::mMakeSJF()
{
}

/*
 * void mMakeRR()
 */
void cShedulingAlgorithms::mMakeRR()
{
}

/*
 * void mMakeSRT()
 */
void cShedulingAlgorithms::mMakeSRT()
{
}



/*
 * void mDrawProcesses()
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
 * void mResetSeries(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mResetSeries(typeNumberProcess aSeries)
{
    for (typeNumberProcess i = 0; i < constProcesses; i++)
        mResetProcess(aSeries, i);
}

/*
 * void mResetAllProcesses()
 */
void cShedulingAlgorithms::mResetAllProcesses()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mResetSeries(i);
}

/*
 * void mReadProcessesFromFile()
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
 * void mWriteProcessesToFile()
 */
void cShedulingAlgorithms::mWriteProcessesToFile()
{
    ofstream StreamOut;
    StreamOut.open("processes.txt");
    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++)
            StreamOut << tabProcesses[i][j];
        StreamOut << endl;
    }
    StreamOut.close();
}



/*
 * void mSortingSeriesReadiness(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mSortingSeriesReadiness(typeNumberProcess aSeries)
{
    cProcess Proc;
    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
        for (typeNumberProcess j = i + 1; j < constProcesses; j++)
        {
            if (tabProcesses[aSeries][i].getTimeReadiness() > tabProcesses[aSeries][j].getTimeProcessing())
            {
                Proc = tabProcesses[aSeries][i];
                tabProcesses[aSeries][i] = tabProcesses[aSeries][j];
                tabProcesses[aSeries][j] = Proc;
            }
        }
    }
}

/*
 * void mSortingAllSeriesReadiness()
 */
void cShedulingAlgorithms::mSortingAllSeriesReadiness()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mSortingSeriesReadiness(i);
}

/*
 * void mSortingSeriesReadinessAndDoing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mSortingSeriesReadinessAndDoing(typeNumberProcess aSeries)
{

}

/*
 * void mSortingAllSeriesReadinessAndDoind()
 */
void cShedulingAlgorithms::mSortingAllSeriesReadinessAndDoind()
{

}



/*
 * void mResetAllTotalTimeDoing()
 */
void cShedulingAlgorithms::mResetAllTotalTimeDoing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mResetTotalTimeDoing(i);
}

/*
 * void mCalculateTotalTimeDoing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mCalculateTotalTimeDoing(typeNumberProcess aSeries)
{
    mResetTotalTimeDoing(aSeries);
    for (typeNumberProcess i = 0; i < constProcesses; i++)
        tabTotalTimeDoing[aSeries] += tabProcesses[aSeries][i].getTimeDoing();
}



/*
 * void mResetAllAverageTimeDoing()
 */
void cShedulingAlgorithms::mResetAllAverageTimeDoing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mResetAverageTimeDoing(i);
}

/*
 * void mCalculateAverageTimeDoing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mCalculateAverageTimeDoing(typeNumberProcess aSeries)
{
    tabAverageTimeDoing[aSeries] = getTotalTimeDoing(aSeries) / constProcesses;
}



/*
 * void mResetAllTotalTimeProcessing()
 */
void cShedulingAlgorithms::mResetAllTotalTimeProcessing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mResetTotalTimeProcessing(i);
}

/*
 * void mCalculateTotalTimeProcessing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mCalculateTotalTimeProcessing(typeNumberProcess aSeries)
{
    mResetTotalTimeProcessing(aSeries);
    for (typeNumberProcess i = 0; i < constProcesses; i++)
        tabTotalTimeProcessing[aSeries] += tabProcesses[aSeries][i].getTimeProcessing();
}



/*
 * void mResetAllAverageTimeProcessing()
 */
void cShedulingAlgorithms::mResetAllAverageTimeProcessing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mResetAverageTimeProcessing(i);
}

/*
 * void mCalculateAverageTimeProcessing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mCalculateAverageTimeProcessing(typeNumberProcess aSeries)
{
    tabAverageTimeProcessing[aSeries] = getTotalTimeProcessing(aSeries) / constProcesses;
}



/*
 * void mWriteResultsToFile(enumAlgorithms aAlgorithm)
 */
void cShedulingAlgorithms::mWriteResultsToFile(enumAlgorithms aAlgorithm)
{
    // fcfs, lcfs, sjf, rr, srt
    ofstream StreamOut;
    switch(aAlgorithm)
    {
        case fcfs: StreamOut.open("resultsFCFS.txt"); break;
        case lcfs: StreamOut.open("resultsLCFS.txt"); break;
        case sjf: StreamOut.open("resultSJF.txt"); break;
        case rr: StreamOut.open("resultsRR.txt"); break;
        case srt: StreamOut.open("resultsSRT.txt"); break;
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
