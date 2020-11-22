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
 * void mSheduling()
 */
void cShedulingAlgorithms::mSheduling()
{

}
/*
 * void mRoundRobin()
 */
void cShedulingAlgorithms::mRoundRobin()
{

}

/*
 * void mClearAllTotalTimesDoing()
 */
void cShedulingAlgorithms::mClearAllTotalTimesDoing()
{

}
/*
 * void mClearAllAverageTimesDoing()
 */
void cShedulingAlgorithms::mClearAllAverageTimesDoing()
{

}
/*
 * void mClearAllTotalTimesProcessing()
 */
void cShedulingAlgorithms::mClearAllTotalTimesProcessing()
{

}
/*
 * void mClearAllAverageTimesProcessing()
 */
void cShedulingAlgorithms::mClearAllAverageTimesProcessing()
{

}

/*
 * void mCalculateTotalTimesDoing(typeProcess parSeries)
 */
void cShedulingAlgorithms::mCalculateTotalTimesDoing(typeProcess parSeries)
{

}
/*
 * void mCalculateAverageTotalTimesDoing(typeProcess parSeries)
 */
void cShedulingAlgorithms::mCalculateAverageTotalTimesDoing(typeProcess parSeries)
{

}
/*
 * void mCalculateTotalTimesProcessing(typeProcess parSeries)
 */
void cShedulingAlgorithms::mCalculateTotalTimesProcessing(typeProcess parSeries)
{

}
/*
 * void mCalculateAverageTimesProcessing(typeProcess parSeries)
 */
void cShedulingAlgorithms::mCalculateAverageTimesProcessing(typeProcess parSeries)
{

}

/*
 * void mSortingSeries(typeProcess parSeries)
 */
void cShedulingAlgorithms::mSortingSeries(typeProcess parSeries)
{

}
/*
 * void mSortingAll()
 */
void cShedulingAlgorithms::mSortingAll()
{

}
/*
 * void mReverseSeries(typeProcess parSeries)
 */
void cShedulingAlgorithms::mReverseSeries(typeProcess parSeries)
{

}
/*
 * void mReverseAll()
 */
void cShedulingAlgorithms::mReverseAll()
{

}
/*
 * void mDrawProcesses()
 */
void cShedulingAlgorithms::mDrawProcesses()
{
    typeTime vT;
    mClearAllSeries(); // czyszczeni tablicy
    srand(time_t(NULL) + (typeProcess)&constProcesses); // generowanie liczb losowych
    for (typeProcess i = 0; i < constSeries; i++) // przejscie po wszystkich ciagach
    {
        for (typeProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach
        {
            vT = rand() % constMaxTime + 1; // losowanie czasu wykonywania procesu
            tableProcesses[i][j].setVTime(vT); // przypisanie wylosowanego czasu
        }
    }
}
/*
 * void mClearSeries(typeProcess parSeries)
 */
void cShedulingAlgorithms::mClearSeries(typeProcess parSeries)
{
    for (typeProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach
        tableProcesses[parSeries][i].mClearProcess(); // czyszczenie wskazanego procesu
}
/*
 * void mClearAllSeries()
 */
void cShedulingAlgorithms::mClearAllSeries()
{
    for (typeProcess i = 0; i < constSeries; i++) // przejscie po wszystkich ciagach
        mClearSeries(i); // czyszczenie wskazanego ciagu
}

/*
 * void mPrintProcessesToFile()
 */
void cShedulingAlgorithms::mPrintProcessesToFile()
{
    ofstream streamOut; // tworzenie strumienia wyjsciowego pliku
    streamOut.open("Processes.txt"); // otwarcie pliku
    for (typeProcess i = 0; i < constSeries; i++) // przejscie po wszystkich ciagach
    {
        for (typeProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach
            streamOut << setw(3) << tableProcesses[i][j]; // wypisanie czasu wykonywania procesu
        streamOut << endl;
    }
    streamOut.close(); // zamkniecie strumienia
}
/*
 * void mPrintResultsToFile(typeProcess parAlghorithmNumber)
 */
void cShedulingAlgorithms::mPrintResultsToFile(typeProcess parAlgorithmNumber)
{
    ofstream streamOut; // utworzenie strumienia wyjsciowego pliku
    switch(parAlgorithmNumber) // wybor odpowiedniego algorytmu
    {
        case 1: streamOut.open("ResultFCFS.txt"); break;
        case 2: streamOut.open("ResultLCFS.txt"); break;
        case 3: streamOut.open("ResultSJF.txt"); break;
        //case 4: streamOut.open("ResultRoundRobin.txt"); break;
    }
    for (typeProcess i = 0; i < constSeries; i++) // przejscie po wszystkich ciagach
    {
        streamOut << tableAverageTimesDoing[i] << "   " // wypisanie sredniego czasu wykonywania procesu
                  << tableAverageTimesProcessing << endl; // wykonywanie sredniego czasu calego przetwarzania
    }
}

/* cshedulingalgorithms.cpp */
/********** END_OF_FILE **********/
