/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cshedulingalgorithms.cpp
 */

#include "cshedulingalgorithms.h"
#include <iomanip>

using namespace std;

/*
 * cShedulingAlgorithms()
 */
cShedulingAlgorithms::cShedulingAlgorithms()
{
    mResetAllProcesses(); // wyczyszczenie tablicy procesow
    mDrawProcesses(); // wylosowanie procesow
    mWriteProcessesToFile(); // wypisanie procesow do pliku
    mMakeFCFS(); // wywolanie metody implementujacej dzialanie algorytmu FCFS
    mMakeLCFS(); // wywolanie metody implementujacej dzialanie algorytmu LCFS
    mMakeSJF(); // wywolanie metody implementujacej dzialanie algorytmu SJF
    mMakeRR(); // wywolanie metody implementujacej dzialanie algorytmu Round-Robin
    mMakeSRT(); // wywolanie metody implementujacej dzialanie algorytmu SRT
}

/*
 * cShedulingAlgorithms(enum aAlgorithm)
 */
cShedulingAlgorithms::cShedulingAlgorithms(enumAlgorithms aAlgorithm)
{
    mResetAllProcesses(); // wyczyszczenie tablicy procesow
    mDrawProcesses(); // wylosowanie procesow
    mWriteProcessesToFile(); // wypisanie procesow do pliku
    switch (aAlgorithm) // wywolanie odpowiedniej metody, zgodnie z podanym argumentem
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
    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++)
            cout << tabProcesses[i][j] << "   ";
        cout << endl;
    }
    cout << endl;
    mSortingAllSeriesReadiness();
    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++)
            cout << tabProcesses[i][j] << "   ";
        cout << endl;
    }

    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
    }

    /*
     * - pojawil sie pierwszy proces
     * - wykonujemy go
     * - pojawiaja sie nowe procesy
     * - sa obslugiwane w kolejnosci pojawienia sie bez wzgledu na dlugosc
     */
}

/*
 * void mMakeLCFS()
 */
void cShedulingAlgorithms::mMakeLCFS()
{
    /*
     * - pojawil sie pierwszy proces
     * - wykonujemy go
     * - pojawiaja sie nowe procesy
     * - ostatni ktory przyszedl jest obslugiwany jako pierwszy
     * - pojawiaja sie nowe procesy
     * - ostatni ktory przyszedl jest obslugowany jako pierwszy
     * - itd...
     */
}

/*
 * void mMakeSJF()
 */
void cShedulingAlgorithms::mMakeSJF()
{
    /*
     * - pojawil sie pierwszy proces
     * - wykonujemy go
     * - pojawiaja sie nowe procesy
     * - proces, ktory zakonczylby sie najszybciej jest wykonywany
     * - itd...
     */
}

/*
 * void mMakeRR()
 */
void cShedulingAlgorithms::mMakeRR()
{
    /*
     * - pojawil sie pierwszy proces
     * - wykonujemy go przez kwant czasu
     * - przechodzimy na kolejny proces
     * - wykonujemy go przez kwant czasu
     * - itd...
     */
}

/*
 * void mMakeSRT()
 */
void cShedulingAlgorithms::mMakeSRT()
{
    /*
     * - pojawil sie pierwszy proces
     * - wykonujemy go...
     * - do momentu kiedy pojawi sie proces, ktory moglby sie zakonczyc szybciej
     * - itd...
     */
}



/*
 * void mDrawProcesses()
 */
void cShedulingAlgorithms::mDrawProcesses()
{
    typeTime vTime1, vTime2; // zmienne, ktorych wartosci bedziemy losowac
    mResetAllProcesses(); // wyczyszczenie tablicy procesow
    srand(time_t(NULL)); // ustanowienie zmiennej losowej
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystich seriach
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach
        {
            vTime1 = rand() % constMaxTime + 1; // losowanie czasu oczekiwania na gotowosc
            vTime2 = rand() % constMaxTime + 1; // losowanie czasu wykonania
            tabProcesses[i][j].setTimeReadiness(vTime1); // ustanowienie czasu oczekiwania na gotowosc
            tabProcesses[i][j].setTimeDoing(vTime2); // ustanowienie czasu wykonania
        }
    }
}

/*
 * void mResetSeries(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mResetSeries(typeNumberProcess aSeries)
{
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach
        mResetProcess(aSeries, i); // resetowanie wskazanego procesu
}

/*
 * void mResetAllProcesses()
 */
void cShedulingAlgorithms::mResetAllProcesses()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mResetSeries(i); // resetowanie wskazanej serii
}

/*
 * void mReadProcessesFromFile()
 */
void cShedulingAlgorithms::mReadProcessesFromFile()
{
    mResetAllProcesses(); // wyczyszczenie aktualnej tablicy procesow
    ifstream StreamIn; // utworzenie wejsciowego strumienia plikowego
    StreamIn.open("procesy.txt"); // otwarcie strumienia
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach
        {
            StreamIn >> skipws >> tabProcesses[i][j]; // wczytanie pojedynczego procesu
        }
    }
    StreamIn.close(); // zamkniecie strumienia
}

/*
 * void mWriteProcessesToFile()
 */
void cShedulingAlgorithms::mWriteProcessesToFile()
{
    ofstream StreamOut; // otwarcie wyjsciowego strumienia plikowego
    StreamOut.open("processes.txt"); // otwarcie strumienia
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystich seriach
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach
            StreamOut << tabProcesses[i][j]; // wypisanie procesu
        StreamOut << endl; // nowa seria - nowa linijka tekstu
    }
    StreamOut.close(); // zamkniecie strumienia
}



/*
 * void mSortingSeriesReadiness(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mSortingSeriesReadiness(typeNumberProcess aSeries)
{
    cProcess Proc; // utworzenie zmiennej pomocniczej
    for (typeNumberProcess i = 0; i < (constProcesses - 1); i++) // przejscie po wszystkich elementach do przedostatniego
    {
        for (typeNumberProcess j = i + 1; j < constProcesses; j++) // przejscie po dalszych elementach
        {
            if (tabProcesses[aSeries][i].getTimeReadiness() > tabProcesses[aSeries][j].getTimeReadiness()) // sprawdzamy czy pierwszy element jest wiekszy
            {
                Proc = tabProcesses[aSeries][i]; // jesli pierwszy element jest wiekszy to sortujemy z zastosowaniem sortowania babelkowego
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
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mSortingSeriesReadiness(i); // wywolanie metody sortowania wskazanej serii
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
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mResetTotalTimeDoing(i); // resetowanie wskazanej serii
}

/*
 * void mCalculateTotalTimeDoing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mCalculateTotalTimeDoing(typeNumberProcess aSeries)
{
    mResetTotalTimeDoing(aSeries); // resetowanie wszystkich calkowitych czasow wykonywania procesow
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach w serii
        tabTotalTimeDoing[aSeries] += tabProcesses[aSeries][i].getTimeDoing(); // dodawanie do sumy kolejnych czasow
}

/*
 * void mCalculateAllTotalTimeDoing()
 */
void cShedulingAlgorithms::mCalculateAllTotalTimeDoing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mCalculateTotalTimeDoing(i); // obliczenie calkowitego czasu dzialanie procesow w danej serii
}



/*
 * void mResetAllAverageTimeDoing()
 */
void cShedulingAlgorithms::mResetAllAverageTimeDoing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mResetAverageTimeDoing(i); // resetowanie wskazanej serii
}

/*
 * void mCalculateAllAverageTimeDoing()
 */
void cShedulingAlgorithms::mCalculateAllAverageTimeDoing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mCalculateAverageTimeDoing(i); // obliczenie sredniego czasu wykonywanie procesow we wskazanej serii
}



/*
 * void mResetAllTotalTimeProcessing()
 */
void cShedulingAlgorithms::mResetAllTotalTimeProcessing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mResetTotalTimeProcessing(i); // resetowanie wskazanego calkowitego czasu przetwarzania
}

/*
 * void mCalculateTotalTimeProcessing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mCalculateTotalTimeProcessing(typeNumberProcess aSeries)
{
    mResetTotalTimeProcessing(aSeries); // resetowanie wskazanego calkowitego czasu przetwarzania
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie  po wszystkich procesach w serii
        tabTotalTimeProcessing[aSeries] += tabProcesses[aSeries][i].getTimeProcessing(); // dodanie do sumy czasu przetwarzanie kolejnego procesu
}



/*
 * void mResetAllAverageTimeProcessing()
 */
void cShedulingAlgorithms::mResetAllAverageTimeProcessing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mResetAverageTimeProcessing(i); // resetowanie sredniego czasu przetwarzania w danej serii
}



/*
 * void mWriteResultsToFile(enumAlgorithms aAlgorithm)
 */
void cShedulingAlgorithms::mWriteResultsToFile(enumAlgorithms aAlgorithm)
{
    // fcfs, lcfs, sjf, rr, srt
    ofstream StreamOut; // zdefiniowanie strumienia
    switch(aAlgorithm) // wybranie odpowiedniego alogorytmu
    {
        case fcfs: StreamOut.open("resultsFCFS.txt"); break; // otwarcie strumienia dla wynikow algorytmu FCFS
        case lcfs: StreamOut.open("resultsLCFS.txt"); break; // otwarcie strumienia dla wynikow algorytmu LCFS
        case sjf: StreamOut.open("resultSJF.txt"); break; // otwarcie strumienia dla wynikow algorytmu SJF
        case rr: StreamOut.open("resultsRR.txt"); break; // otwarcie strumienia dla wynikow algorytmu Round-Robin
        case srt: StreamOut.open("resultsSRT.txt"); break; // otwarcie strumienia dla wynikow algorytmu SRT
    }
    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
        StreamOut << "Average time doing " << setw(4) << i+1
                  << " series: " << tabAverageTimeDoing[i] << "     "
                  <<  "Average time processing " << setw(4) << i+1
                  << " series: " << tabAverageTimeProcessing[i] << endl;
    }
    StreamOut.close();
}


/* cshedulingalgorithms.cpp */
/********** END_OF_FILE **********/
