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
 * mMakeFCFS()
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
 * mSortingSeriesReadiness(typeNumberProcess aSeries)
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
 * mSortingAllSeriesReadiness()
 */
void cShedulingAlgorithms::mSortingAllSeriesReadiness()
{
    for (typeNumberProcess i = 0; i < constSeries; i++)
        mSortingSeriesReadiness(i);
}

/*
 * mSortingSeriesReadinessAndDoing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mSortingSeriesReadinessAndDoing(typeNumberProcess aSeries)
{

}

/*
 * mSortingAllSeriesReadinessAndDoind()
 */
void cShedulingAlgorithms::mSortingAllSeriesReadinessAndDoind()
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
