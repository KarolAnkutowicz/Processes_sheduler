/********** BEGIN_OF_FILE **********/
/* cshedulingalgorithms.cpp */

#include "cshedulingalgorithms.h"

using namespace std;

/*
 * cShedulingAlgorithms()
 */
cShedulingAlgorithms::cShedulingAlgorithms()
{
    mClearAllSeries(); // wyczyszczenie ewentualnych pozostalosci po wczesniejszych dzialaniach
    mDrawProcesses(); // losowanie procesow
    mPrintProcessesToFile(); // wypisanie procesow do pliku
    for (typeProcess i = 0; i < 4; i++) // przejscie po wszystkich dostepnych algorytmach
    {
        mClearAllTotalTimesDoing(); // wyczyszczenie tabel wynikow obliczen
        mClearAllAverageTimesDoing();
        mClearAllTotalTimesProcessing();
        mClearAllAverageTimesProcessing();
        switch(i)
        {
            case 1: mSheduling(); // algorytm FCFS
                    break;
            case 2: mReverseAll(); // algorytm LCSF
                    mSheduling();
                    break;
            case 3: mSortingAll(); // algorytm SJF
                    mSheduling();
                    break;
            //case 4: mRoundRobin(); // Algorytm Round Robin
                   // break;
        }
        mPrintResultsToFile(i); // wypisanie wynikow do pliku
    }
}

/*
 * void mSheduling()
 */
void cShedulingAlgorithms::mSheduling()
{
    for (typeProcess i = 0; i < constSeries; i++) // przejscie po wszystkich ciagach
    {
        typeTime vSumProcessing = 0; // ustanowienie poczatkowej sumy
        for (typeProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach
        {
            tableProcesses[i][j].setVTimeStartOfProcessing(0); // ustawienie poczatkowego czasu przetwarzania
            vSumProcessing += tableProcesses[i][j].getVTime(); // obliczenie koncowego czasu przetwarzania
            tableProcesses[i][j].setVTimeEndOfProcessing(vSumProcessing); // ustawienie koncowego czasu przetwarzania
            tableProcesses[i][j].mCalculateProcessing(); // obliczenie calkowitego czasu przetwarzania
        }
        mCalculateTotalTimesDoing(i); // wywolanie metody obliczajacej calkowity czas wykonywania
        mCalculateAverageTotalTimesDoing(i); // wywolanie metody obliczajacej sredni czas wykonywania
        mCalculateTotalTimesProcessing(i); // wywolywanie metody obliczajacej calkowity czas przetwarzania
        mCalculateAverageTimesProcessing(i); // wywolanie metody obliczajacej sredni czas przetwarzania
    }
}
/*
 * void mRoundRobin()
 */
/*void cShedulingAlgorithms::mRoundRobin()
{
    //
}*/

/*
 * void mClearAllTotalTimesDoing()
 */
void cShedulingAlgorithms::mClearAllTotalTimesDoing()
{
    for (typeProcess i = 0; i < constSeries; i++) // przejscie po wszystkich ciagach
        mClearTotalTimesDoing(i); // wywolanie metody zerujacej wskazany calkowity czas wykonywania
}
/*
 * void mClearAllAverageTimesDoing()
 */
void cShedulingAlgorithms::mClearAllAverageTimesDoing()
{
    for (typeProcess i = 0; i < constSeries; i++) // przejscie po wszystkich ciagach
        mClearAverageTimesDoing(i); // wywolanie metody zerujacej wskazany sredni czas wykonywania
}
/*
 * void mClearAllTotalTimesProcessing()
 */
void cShedulingAlgorithms::mClearAllTotalTimesProcessing()
{
    for (typeProcess i = 0; i < constSeries; i++) // przejscie po wszystkich ciagach
        mClearTotalTimesProcessing(i); // wywolanie metody zerujacej wskazany calkowity czas przetwarzania
}
/*
 * void mClearAllAverageTimesProcessing()
 */
void cShedulingAlgorithms::mClearAllAverageTimesProcessing()
{
    for (typeProcess i = 0; i < constSeries; i++) // przejscie po wszystkich ciagach
        mClearAverageTimesProcessing(i); // wywolanie metody zerujacej wskazany sredni czas przetwarzania
}

/*
 * void mCalculateTotalTimesDoing(typeProcess parSeries)
 */
void cShedulingAlgorithms::mCalculateTotalTimesDoing(typeProcess parSeries)
{
    typeTime vSum = 0; // nadanie sumy poczatkowej
    for (typeProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach
        vSum += tableProcesses[parSeries][i].getVTime(); // zwrocenie i dodanie czasu wykonywania
    tableTotalTimesDoing[parSeries] = vSum; // przypisanie sumy
}
/*
 * void mCalculateAverageTotalTimesDoing(typeProcess parSeries)
 */
void cShedulingAlgorithms::mCalculateAverageTotalTimesDoing(typeProcess parSeries)
{
    tableAverageTimesDoing[parSeries] = tableTotalTimesDoing[parSeries] / constProcesses;
}
/*
 * void mCalculateTotalTimesProcessing(typeProcess parSeries)
 */
void cShedulingAlgorithms::mCalculateTotalTimesProcessing(typeProcess parSeries)
{
    typeTime vSum = 0; // nadanie sumy poczatkowej
    for (typeProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach
        vSum += tableProcesses[parSeries][i].getVTimeProcessing(); // zwrocenie i dodanie czasu przetwarzania
    tableTotalTimesProcessing[parSeries] = vSum; // przypisanie sumy
}
/*
 * void mCalculateAverageTimesProcessing(typeProcess parSeries)
 */
void cShedulingAlgorithms::mCalculateAverageTimesProcessing(typeProcess parSeries)
{
    tableAverageTimesProcessing[parSeries] = tableTotalTimesProcessing[parSeries] / constProcesses;
}

/*
 * void mSortingSeries(typeProcess parSeries)
 */
void cShedulingAlgorithms::mSortingSeries(typeProcess parSeries)
{
    cProcess vPom; // zmienna pomocnicza
    for (typeProcess i = 0; i < (constProcesses - 1); i++) // przejscie po wszystkich elementaach poza ostatnim
    {
        for (typeProcess j = i + 1; j < constProcesses; j++) // przejscie po wszystkich elementach poza poczatkowym
        {
            if (tableProcesses[parSeries][i].getVTime() > tableProcesses[parSeries][j].getVTime()) // sprawdzeni warunku
            {
                vPom = tableProcesses[parSeries][i]; // zamiana zgodnie z algorytmem sortowania babelkowego
                tableProcesses[parSeries][i] = tableProcesses[parSeries][j];
                tableProcesses[parSeries][j] = vPom;
            }
        }
    }
}
/*
 * void mSortingAll()
 */
void cShedulingAlgorithms::mSortingAll()
{
    for (typeProcess i = 0; i < constSeries; i++) // przejscie po wszystkich ciagach
        mSortingSeries(i); // wywolanie metody sortujacej dany ciag
}
/*
 * void mReverseSeries(typeProcess parSeries)
 */
void cShedulingAlgorithms::mReverseSeries(typeProcess parSeries)
{
    cProcess vPom; // zmienna pomocnicza
    for (typeProcess i = 0; i < (constSeries / 2); i++)
    {
        vPom = tableProcesses[parSeries][i]; // zamiana elementow miejscami
        tableProcesses[parSeries][i] = tableProcesses[parSeries][constSeries - i - 1];
        tableProcesses[parSeries][constSeries - i - 1] = vPom;
    }
}
/*
 * void mReverseAll()
 */
void cShedulingAlgorithms::mReverseAll()
{
    for (typeProcess i = 0; i < constSeries; i++) // przejscie po wszystkich procesach
        mReverseSeries(i); // odwracanie kolejnosci
}
/*
 * void mDrawProcesses()
 */
void cShedulingAlgorithms::mDrawProcesses()
{
    typeTime vT;
    mClearAllSeries(); // czyszczeni tablicy
    srand(time_t(NULL) + (typeTime)&constProcesses); // generowanie liczb losowych
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
                  << tableAverageTimesProcessing[i] << endl; // wykonywanie sredniego czasu calego przetwarzania
    }
}

/* cshedulingalgorithms.cpp */
/********** END_OF_FILE **********/
