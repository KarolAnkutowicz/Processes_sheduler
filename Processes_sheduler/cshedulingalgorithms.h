/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cshedulingalgorithms.h
 */

#ifndef CSHEDULINGALGORITHMS_H
#define CSHEDULINGALGORITHMS_H

#include "constantsandtypes.h"
#include "cprocess.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

/*
 * cShedulingAlgorithms - klasa modelujaca algorytmy szeregowania
 * procesow. Zawiera pola i metody realizujace docelowo 5 roznych
 * algorytmow: FCFS, LCFS, SJF, Round-Robin i SRT
 */
class cShedulingAlgorithms
{
    /*
     * cProcess tabProcesses[constSeries][constProcesses] - tablica
     * procesow, ktore sa przetwarzane przez kolejne algorytmy. Zebrane
     * w okreslonej liczbie ciagow.
     */
    cProcess tabProcesses[constSeries][constProcesses];

    /*
     * typeTime tabTotalTimeDoing[constSeries] - tablica sumarycznych
     * czasow dzialanie procesow.
     */
    typeTime tabTotalTimeDoing[constSeries];

    /*
     * double tabAverageTimeDoing[constSeries] - tablica srednich czasow
     * dzialanie procesow.
     */
    double tabAverageTimeDoing[constSeries];

    /*
     * typeTime tabTotalTimeProcessing[constSeries] - tablica sumarycznych
     * czasow przetwarzania procesow.
     */
    typeTime tabTotalTimeProcessing[constSeries];

    /*
     * double tabAverageTimeProcessing[constSeries] - tablica srednich
     * czasow przetwarzania procesow.
     */
    double tabAverageTimeProcessing[constSeries];

public:
    /*
     * cShedulingAlgorithms() - konstruktor wywolywany bez
     * argumentow.
     * PRE:
     * - brak;
     * POST:
     * - utworzenie obiektu klasy cShedulingAlgorithms.
     */
    cShedulingAlgorithms();

    /*
     * cShedulingAlgorithms(enum aAlgorithm) - konstruktor wywolywany
     * z jednym argumentem.
     * PRE:
     * - podanie wykorzystywanego algorytmu;
     * POST:
     * - utworzenie obiektu klasy cShedulingAlgorithms.
     */
    cShedulingAlgorithms(enumAlgorithms aAlgorithm);



    /*
     * void mMakeFCFS() - metoda realizujaca niewywlaszczajacy algorytm
     * FCFS (First Come First Served - pierwszy zgloszony, pierwszy
     * obsluzony).
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeFCFS();

    /*
     * void mMakeLCFS() - metoda realizujaca niewywlaszczajacy algorytm
     * FCFS (First Come First Served - pierwszy zgloszony, pierwszy
     * obsluzony).
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeLCFS();

    /*
     * void mMakeSJF() - metoda realizujaca niewywlaszczajacy algorytm
     * SJF (SJN, SPF, SPN, Shortest Job/Process First/Next - najpierw
     * najkrotsze zadanie).
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeSJF();

    /*
     * void mMakeRR() - metoda realizujaca wywlaszczajacy algorytm
     * RR (Round Robin - rotacyjne obslugiwanie kolejnych procesow
     * przez ustalony kwant czasu).
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeRR();

    /*
     * void mMakeSRT() - metoda realizujaca wywlaszczajacy algorytm
     * SRT (Shortest Remaining Time - w pierwszej kolejnosci
     * obslugiwane jest zadanie z najkrotszym czasem zakonczenia).
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeSRT();

    /*
     * bool mReadyAny(typeNumberProcess aSeries) - metoda pomocnicza
     * sprawdzajaca czy istnieje aktualnie proces ktory mozemy wykonywac
     * (tzn. nieukonczony proces ktory jest w stanie gotowosci).
     * PRE:
     * - podanie numeru serii (typ: typeNumberProcess;
     * POST:
     * - zwrocenie wartosci logicznej.
     */
    bool mReadyAny(typeNumberProcess aSeries);

    /*
     * void mForwardReadinessSeries(typeNumberProcess aSeries, typeTime aTime) -
     * metoda przesuwajaca czas oczekiwania na gotowosc we wskazanej serii
     * procesow o wskazana ilosc czasu.
     * PRE:
     * - podanie numeru serii (typ: typeNumberProcess), podanie czasu
     * (typ: typeTime);
     * POST:
     * - brak.
     */
    void mForwardReadinessSeries(typeNumberProcess aSeries, typeTime aTime);

    /*
     * void mMakeProcess(typeNumberProcess aSeries, typeNumberProcess aIndex, typeTime aTime) -
     * metoda wykonujaca wskazany proces przez wskazana ilosc czasu. Przy
     * okazji obsluguje reszte procesow w serii (przesuwa czasy oczekiwania
     * na gotowosc i oczekiwania na wykonanie)
     * PRE:
     * - podanie numeru serii (typ: typeNumberProcess), podanie numeru
     * procesu w serii (typ: typeNumberProcess), podanie czasu
     * (typ: typeTime);
     * POST:
     * - brak.
     */
    void mMakeProcess(typeNumberProcess aSeries, typeNumberProcess aIndex, typeTime aTime);

    /*
     * void mMakeProcess(typeNumberProcess aSeries, typeNumberProcess aIndex) -
     * metoda wykonujaca wskazany proces az do jego konca wykonywania. Przy
     * okazji obsluguje reszte procesow w serii (przesuwa czasy oczekiwania
     * na gotowosc i oczekiwania na wykonanie)
     * PRE:
     * - podanie numeru serii (typ: typeNumberProcess), podanie numeru
     * procesu w serii (typ: typeNumberProcess), podanie czasu;
     * POST:
     * - brak.
     */
    void mMakeProcess(typeNumberProcess aSeries, typeNumberProcess aIndex);

    /*
     * typeNumberProcess mGetLast(typeNumberProcess aSeries) - metoda
     * pomocnicza do algorytmu LCFS, wyznaczajaca numer indeksu procesu, ktory
     * mamy wykonac.
     * PRE:
     * - podanie numeru serii (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    typeNumberProcess mGetLast(typeNumberProcess aSeries);

    /*
     * typeNumberProcess mGetTheShortest(typeNumberProcess aSeries) - metoda
     * pomocnicza do algorytmu SJF, wyznaczajaca nimer indeksu jeszcze
     * nieukonczonego procesu, ktoremu zostalo najmniej do wykonania.
     * PRE:
     * - podanie numeru serii (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    typeNumberProcess mGetTheShortest(typeNumberProcess aSeries);

    /*
     * bool mDoneAll(typeNumberProcess aSeries) - metoda pomocnicza
     * wykorzystywana w procesach wywlaszczajacych sprawdzajaca
     * czy wszystkie procesy zostaly juz wykonane.
     * PRE:
     * - podanie numeru serii (typ: typeNumberProcess);
     * POST:
     * - zwrocenie wartosci logicznej.
     */
    bool mDoneAll(typeNumberProcess aSeries);



    /*
     * void mDrawProcesses() - metoda losujaca procesy, nastepnie umieszcza
     * je w tablicy procesow.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mDrawProcesses();

    /*
     * void mResetProcess(typeNumberProcess aSeries, typeNumberProcess aProcess) -
     * metoda resetujaca konkretny proces.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess), podanie numeru
     * procesu w serii (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    inline void mResetProcess(typeNumberProcess aSeries, typeNumberProcess aProcess)
    {
        tabProcesses[aSeries][aProcess].mResetProcess();
    }

    /*
     * void mResetSeries(typeNumberProcess aSeries) - metoda resetujaca
     * wskazana serie procesow.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    void mResetSeries(typeNumberProcess aSeries);

    /*
     * void mResetAllProcesses() - metoda resetujaca wszystkie procesy.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllProcesses();

    /*
     * void mReadProcessesFromFile() - metoda wczytujaca procesy
     * z pliku.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mReadProcessesFromFile();

    /*
     * void mWriteProcessesToFile() - metoda zapisujaca procesy
     * do pliku.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mWriteProcessesToFile();

    /*
     * void mPrintAllTimesProcess(typeNumberProcess aSeries, typeNumberProcess aProcess) -
     * metoda wypisujaca wszystkie czasy wskazanego procesu.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess), podanie numeru procesu
     * (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    void mPrintAllTimesProcess(typeNumberProcess aSeries, typeNumberProcess aProcess);

    /*
     * void mPrintAllTimesSeriesProcesses(typeNumberProcess aSeries) - metoda
     * wypisujaca wszystkie czasy procesow wskazanej serii.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    void mPrintAllTimesSeriesProcesses(typeNumberProcess aSeries);



    /*
     * void mSortingSeries(typeNumberProcess aSeries) - metoda
     * sortujaca procesy rosnaco wg czasow gotowosci do wykonywania.
     * PRE:
     * - podanie numeru serii procesow (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    void mSortingSeriesReadiness(typeNumberProcess aSeries);

    /*
     * void mSortingAllSeriesReadiness() - metoda sortujaca wszystkie
     * serie procesow rosnoca wg czasow gotowosci do wykonywania.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mSortingAllSeriesReadiness();

    /*
     * void mSortingSeriesReadinessAndDoing(typeNumberProcess aSeries) -
     * metoda sortujaca procesy rosnaco wg czasu gotowosci do
     * wykonywania a nastepnie rosnaco wg czasu wykonywania w danej
     * serii.
     * PRE:
     * - podanie numeru serii procesow (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    void mSortingSeriesReadinessAndDoing(typeNumberProcess aSeries);

    /*
     * void mSortingAllSeriesReadinessAndDoing() - metoda sortujaca
     * procesy rosnaco wg czasu gotowosci do wykonywania a nastepnie
     * rosnaco wg czasu wykonywania we wszystkich seriach procesow.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mSortingAllSeriesReadinessAndDoing();



    /*
     * void mResetTotalTimeDoing(typeNumberProcess aSeries) - metoda
     * resetujaca sumaryczny czas wykonania wskazanej serii
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    inline void mResetTotalTimeDoing(typeNumberProcess aSeries)
    {
        tabTotalTimeDoing[aSeries] = 0;
    }

    /*
     * void mResetAllTotalTimeDoing() - metoda resetujaca wszystkie
     * sumaryczne czasy wykonywania procesow.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllTotalTimeDoing();

    /*
     * void mCalculateTotalTimeDoing(typeNumberProcess aSeries) -
     * metoda obliczajaca sumaryczny czas wykonywania procesow
     * we wskazanej serii.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    void mCalculateTotalTimeDoing(typeNumberProcess aSeries);

    /*
     * void mCalculateAllTotalTimeDoing() - metoda obliczajaca
     * sumaryczne czasy wykonywanie procesow we wszystkich seriach
     * - brak;
     * POST:
     * - brak.
     */
    void mCalculateAllTotalTimeDoing();

    /*
     * typeTime getTotalTimeDoing(typeNumberProcess aSeries) -
     * metoda zwracajaca sumaryczny czas wykonywania procesow
     * wskazanej serii.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - zwrocenie sumarycznej wartosci czasow wykonywania procesow
     * danej serii (typ: typeTime).
     */
    inline typeTime getTotalTimeDoing(typeNumberProcess aSeries)
    {
        return tabTotalTimeDoing[aSeries];
    }



    /*
     * void mResetAverageTimeDoing(typeNumberProcess aSeries) - metoda
     * resetujaca sredni czas wykonywania procesow wskazanej serii.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    inline void mResetAverageTimeDoing(typeNumberProcess aSeries)
    {
        tabAverageTimeDoing[aSeries] = 0;
    }

    /*
     * void mResetAllAverageTimeDoing() - metoda resetujaca srednie
     * czasy wykonywania procesow wszystkich serii.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllAverageTimeDoing();

    /*
     * void mCalculateAverageTimeDoing(typeNumberProcess aSeries) -
     * metoda obliczajaca sredni czas wykonywania procesow
     * we wskazanej serii.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    inline void mCalculateAverageTimeDoing(typeNumberProcess aSeries)
    {
        tabAverageTimeDoing[aSeries] = getTotalTimeDoing(aSeries) / constProcesses;
    }

    /*
     * void mCalculateAllAverageTimeDoing() - metoda obliczajaca sredni
     * czas wykonywania procesow dla wszystkich serii.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mCalculateAllAverageTimeDoing();

    /*
     * typeTime getAverageTimeDoing(typeNumberProcess aSeries) -
     * zwrocenie wartosci sredniego czasu wykonywania procesu
     * we wskazanej serii.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - zwrocenie srednego czasu wykonywania procesow wskazanej serii
     * (typ: typeTime).
     */
    inline typeTime getAverageTimeDoing(typeNumberProcess aSeries)
    {
        return tabAverageTimeDoing[aSeries] = 0;
    }



    /*
     * void mResetTotalTimeProcessing(typeNumberProcess aSeries) -
     * metoda resetujaca sumaryczny czas przetwarzania procesow
     * wskazanej serii.
     * PRE:
     * - wskazanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    inline void mResetTotalTimeProcessing(typeNumberProcess aSeries)
    {
        tabTotalTimeProcessing[aSeries] = 0;
    }

    /*
     * void mResetAllTotalTimeProcessing() - metoda resetujaca
     * sumaryczne czasy przetwarzania procesow wszystkich serii.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllTotalTimeProcessing();

    /*
     * void mCalculateTotalTimeProcessing(typeNumberProcess aSeries) -
     * metoda obliczajaca sredni czas przetwarzania procesow
     * we wskazanej serii.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    void mCalculateTotalTimeProcessing(typeNumberProcess aSeries);

    /*
     * void mCalculateAllTotalTimeProcessing() - metoda obliczajaca
     * calkowite czasy przetwarzania we wszystkich seriach.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mCalculateAllTotalTimeProcessing();

    /*
     * typeTime getTotalTimeProcessing(typeNumberProcess aSeries) -
     * metoda zwracajaca sumaryczny czas przetwarzania procesow
     * wskazanej serii.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - zwrocenie sumarycznego czasu przetwarzania wskazanej serii
     * (typ: typeTime).
     */
    inline typeTime getTotalTimeProcessing(typeNumberProcess aSeries)
    {
        return tabTotalTimeProcessing[aSeries];
    }



    /*
     * void mResetAverageTimeProcessing(typeNumberProcess aSeries) -
     * metoda resetujaca sredni czas przetwarzania procesow wskazanej
     * serii.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    inline void mResetAverageTimeProcessing(typeNumberProcess aSeries)
    {
        tabAverageTimeProcessing[aSeries] = 0;
    }

    /*
     *  void mResetAllAverageTimeProcessing() - metoda resetujaca
     * srednie czasy przetwarzania wszystkich serii procesow.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllAverageTimeProcessing();

    /*
     * void mCalculateAverageTimeProcessing(typeNumberProcess aSeries) -
     * metoda obliczajaca sredni czas przetwarzania procesow wskazanej
     * serii
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - brak.
     */
    inline void mCalculateAverageTimeProcessing(typeNumberProcess aSeries)
    {
        tabAverageTimeProcessing[aSeries] = getTotalTimeProcessing(aSeries) / constProcesses;
    }

    /*
     * void mCalculateAllAverageTimeProcessing() - metoda obliczajaca
     * sredni czas przetwarzania procesow we wszystkich seriach.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mCalculateAllAverageTimeProcessing();

    /*
     * typeTime getAverageTimeProcessing(typeNumberProcess aSeries) -
     * metoda zwracajaca sredni czas przetwarzania wskazanej serii.
     * PRE:
     * - podanie serii procesow (typ: typeNumberProcess);
     * POST:
     * - zwrocenie wartosci sredniej czasu przetwarzania wskazanej
     * serii (typ: typeTime).
     */
    inline typeTime getAverageTimeProcessing(typeNumberProcess aSeries)
    {
        return tabAverageTimeProcessing[aSeries];
    }



    /*
     * void mWriteResultsToFile(enumAlgorithms parAlgorithm) - metoda
     * wypisujaca wyniki dzialania wskazanego algorytmu.
     * PRE:
     * - podanie algorytmuc(typ: enumAlgorithm);
     * POST:
     * - brak.
     */
    void mWriteResultsToFile(enumAlgorithms aAlgorithm);
};

#endif // CSHEDULINGALGORITHMS_H

/* cshedulingalgorithms.h */
/********** END_OF_FILE **********/
