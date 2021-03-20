/********** BEGIN_OF_FILE **********/
/* cshedulingalgorithms.h */

#ifndef CSHEDULINGALGORITHMS_H
#define CSHEDULINGALGORITHMS_H

#include "constantsandtypes.h"
#include "cprocess.h"
#include <cstdlib>
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
     * tabProcesses[constSeries][constProcesses] - tablica procesow,
     * ktore sa przetwarzane przez kolejne algorytmy. Zebrane
     * w okreslonej liczbie ciagow.
     */
    cProcess tabProcesses[constSeries][constProcesses];

    /*
     * tabTotalTimeDoing[constSeries] - tablica sumarycznych czasow
     * dzialanie procesow.
     */
    typeTime tabTotalTimeDoing[constSeries];

    /*
     * tabAverageTimeDoing[constSeries] - tablica srednich czasow
     * dzialanie procesow.
     */
    double tabAverageTimeDoing[constSeries];

    /*
     * tabTotalTimeProcessing[constSeries] - tablica sumarycznych
     * czasow przetwarzania procesow.
     */
    typeTime tabTotalTimeProcessing[constSeries];

    /*
     * tabAverageTimeProcessing[constSeries] - tablica srednich
     * czasow przetwarzania procesow.
     */
    double tabAverageTimeProcessing[constSeries];

public:
    /*
     * cShedulingAlgorithms() - konstruktor wywolywany bez
     * parametrow.
     * PRE:
     * - brak;
     * POST:
     * - utworzenie obiektu.
     */
    cShedulingAlgorithms();

    /*
     * cShedulingAlgorithms(enum aAlgorithm) - konstruktor wywolywany
     * z jednym argumentem.
     * PRE:
     * - podanie wykorzystywanego algorytmu;
     * POST:
     * - utworzenie obiektu.
     */
    cShedulingAlgorithms(enumAlgorithms aAlgorithm);


    /*
     * mMakeFCFS() - metoda realizujaca niewywlaszczajacy algorytm
     * FCFS (First Come First Served - pierwszy zgloszony, pierwszy
     * obsluzony).
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeFCFS();

    /*
     * mMakeLCFS() - metoda realizujaca niewywlaszczajacy algorytm
     * FCFS (First Come First Served - pierwszy zgloszony, pierwszy
     * obsluzony).
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeLCFS();

    /*
     * mMakeSJF() - metoda realizujaca niewywlaszczajacy algorytm
     * SJF (SJN, SPF, SPN, Shortest Job/Process First/Next - najpierw
     * najkrotsze zadanie).
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeSJF();

    /*
     * mMakeRR() - metoda realizujaca wywlaszczajacy algorytm
     * RR (Round Robin - rotacyjne obslugiwanie kolejnych procesow
     * przez ustalony kwant czasu).
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeRR();

    /*
     * mMakeSRT() - metoda realizujaca wywlaszczajacy algorytm
     * SRT (Shortest Remaining Time - w pierwszej kolejnosci
     * obslugiwane jest zadanie z najkrotszym czasem zakonczenia).
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mMakeSRT();



    /*
     * mDrawProcesses() - metoda losujaca procesy, nastepnie umieszcza
     * je w tablicy procesow.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mDrawProcesses();

    /*
     * mResetProcess(typeNumberProcess aSeries, typeNumberProcess aProcess) -
     * metoda resetujaca konkretny proces.
     * PRE:
     * - podanie serii procesow (argument: aSeries), podanie numeru
     * procesu w serii (argument: aProcess);
     * POST:
     * - brak.
     */
    inline void mResetProcess(typeNumberProcess aSeries, typeNumberProcess aProcess)
    {
        tabProcesses[aSeries][aProcess].mResetProcess();
    }

    /*
     * mResetSeries(typeNumberProcess aSeries) - metoda resetujaca
     * wskazana serie procesow.
     * PRE:
     * - podanie serii procesow (argument: aSeries);
     * POST:
     * - brak.
     */
    void mResetSeries(typeNumberProcess aSeries);

    /*
     * mResetAllProcesses() - metoda resetujaca wszystkie procesy.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllProcesses();

    /*
     * mReadProcessesFromFile() - metoda wczytujaca procesy
     * z pliku.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mReadProcessesFromFile();

    /*
     * mWriteProcessesToFile() - metoda zapisujaca procesy
     * do pliku.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mWriteProcessesToFile();



    /*
     * mSortingSeries(typeNumberProcess aSeries, bool aAscendingReadiness, bool aAscendingDoing, bool aReadinessFirst) -
     * metoda sortujaca wskazana serie procesow wedlug wskazanych
     * kryteriow.
     * PRE:
     * - podanie serii procesow (argument: aSeries), podanie czy mamy
     * sortowac czasy gotowosci rosnaco (argument: aAscendingReadiness),
     * podanie czy mamy sortowac czasy wykonywania rosnaco
     * (argument: aAscendingDoing), podanie czy priorytetem sa czasy
     * gotowosci (argument: aReadinessFirst);
     * POST:
     * - brak.
     */
    void mSortingSeries(typeNumberProcess aSeries, bool aAscendingReadiness, bool aAscendingDoing, bool aReadinessFirst);

    /*
     * mSortingAllProcesses(bool aAscendingReadiness, bool aAscendingDoing, bool aReadinessFirst) -
     * metoda sortujaca wszystkie procesy w seriach wedlug wskazanych
     * kryteriow.
     * PRE:
     * - podanie czy mamy sortowac czasy gotowosci rosnaco
     * (argument: aAscendingReadiness), podanie czy mamy sortowac
     * czasy wykonywania rosnaco (argument: aAscendingDoing),
     * podanie czy priorytetem sa czasy gotowosci
     * (argument: aReadinessFirst);
     * POST:
     * - brak.
     */
    void mSortingAllProcesses(bool aAscendingReadiness, bool aAscendingDoing, bool aReadinessFirst);

    /*
     * mReverseOrderSeries(typeNumberProcess aSeries) - metoda
     * odwracajaca kolejnosc procesow w danej serii.
     * PRE:
     * - podanie serii (argument: aSeries);
     * POST:
     * - brak.
     */
    void mReverseOrderSeries(typeNumberProcess aSeries);

    /*
     * mReverseOrderAllSeries() - metoda odwracajaca kolejnosc
     * procesow we wszystkich seriach.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mReverseOrderAllSeries();



    /*
     * mResetTotalTimeDoing(typeNumberProcess aSeries) - metoda
     * resetujaca sumaryczny czas wykonania wskazanej serii
     * PRE:
     * - podanie serii procesow (argument: aSeries);
     * POST:
     * - brak.
     */
    inline void mResetTotalTimeDoing(typeNumberProcess aSeries)
    {
        tabTotalTimeDoing[aSeries] = 0;
    }

    /*
     * mResetAllTotalTimeDoing() - metoda resetujaca wszystkie
     * sumaryczne czasy wykonywania procesow.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllTotalTimeDoing();

    /*
     * mCalculateTotalTimeDoing(typeNumberProcess aSeries) - metoda
     * obliczajaca symaryczny czas wykonywania procesow we wskazanej
     * serii.
     * PRE:
     * - podanie serii procesow (argument: aSeries);
     * POST:
     * - brak.
     */
    void mCalculateTotalTimeDoing(typeNumberProcess aSeries);

    /*
     * getTotalTimeDoing(typeNumberProcess aSeries) - metoda zwracajaca
     * sumaryczny czas wykonywania procesow wskazanej serii.
     * PRE:
     * - podanie serii procesow (argument: aSeries);
     * POST:
     * - zwrocenie sumarycznej wartosci czasow wykonywania procesow
     * danej serii (typ: typeTime).
     */
    inline typeTime getTotalTimeDoing(typeNumberProcess aSeries)
    {
        return tabTotalTimeDoing[aSeries];
    }



    /*
     * mResetAverageTimeDoing(typeNumberProcess aSeries) - metoda
     * resetujaca sredni czas wykonywania procesow wskazanej serii.
     * PRE:
     * - podanie serii procesow (argument: aSeries);
     * POST:
     * - brak.
     */
    inline void mResetAverageTimeDoing(typeNumberProcess aSeries)
    {
        tabAverageTimeDoing[aSeries] = 0;
    }

    /*
     * mResetAllAverageTimeDoing() - metoda resetujaca srednie czasy
     * wykonywania procesow wszystkich serii.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllAverageTimeDoing();

    /*
     * mCalculateAverageTimeDoing(typeNumberProcess aSeries) - metoda
     * obliczajaca sredni czas wykonywania procesow we wskazanej serii.
     * PRE:
     * - podanie serii procesow (argument: aSeries);
     * POST:
     * - brak.
     */
    void mCalculateAverageTimeDoing(typeNumberProcess aSeries);

    /*
     * getAverageTimeDoing(typeNumberProcess aSeries) - zwrocenie
     * wartosci sredniego czasu wykonywania procesu we wskazanej serii.
     * PRE:
     * - podanie serii procesow (argument: aSeries);
     * POST:
     * - zwrocenie srednego czasu wykonywania procesow wskazanej serii
     * (typ: typeTime).
     */
    inline typeTime getAverageTimeDoing(typeNumberProcess aSeries)
    {
        return tabAverageTimeDoing[aSeries] = 0;
    }



    /*
     * mResetTotalTimeProcessing(typeNumberProcess aSeries) - metoda
     * resetujaca sumaryczny czas przetwarzania procesow wskazanej
     * serii.
     * PRE:
     * - wskazanie serii procesow (argument: aSeries);
     * POST:
     * - brak.
     */
    inline void mResetTotalTimeProcessing(typeNumberProcess aSeries)
    {
        tabTotalTimeProcessing[aSeries] = 0;
    }

    /*
     * mResetAllTotalTimeProcessing() - metoda resetujaca sumaryczne
     * czasy przetwarzania procesow wszystkich serii.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllTotalTimeProcessing();

    /*
     * mCalculateTotalTimeProcessing(typeNumberProcess aSeries) -
     * metoda obliczajaca sredni czas przetwarzania procesow
     * we wskazanej serii.
     * PRE:
     * - podanie serii procesow (argument: aSeries);
     * POST:
     * - brak.
     */
    void mCalculateTotalTimeProcessing(typeNumberProcess aSeries);

    /*
     * getTotalTimeProcessing(typeNumberProcess aSeries) - metoda
     * zwracajaca sumaryczny czas przetwarzania procesow wskazanej
     * serii.
     * PRE:
     * - podanie serii procesow (argument: aSeries);
     * POST:
     * - zwrocenie sumarycznego czasu przetwarzania wskazanej serii
     * (typ: typeNumberProcess).
     */
    inline typeTime getTotalTimeProcessing(typeNumberProcess aSeries)
    {
        return tabTotalTimeProcessing[aSeries] = 0;
    }



    /*
     * mResetAverageTimeProcessing(typeNumberProcess aSeries) -
     * metoda resetujaca sredni czas przetwarzania procesow wskazanej
     * serii.
     * PRE:
     * - podanie serii procesow (argument: aSeries);
     * POST:
     * - brak.
     */
    inline void mResetAverageTimeProcessing(typeNumberProcess aSeries)
    {
        tabAverageTimeProcessing[aSeries] = 0;
    }

    /*
     * mResetAllAverageTimeProcessing() - metoda resetujaca srednie
     * czasy przetwarzania wszystkich serii procesow.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllAverageTimeProcessing();

    /*
     * mCalculateAverageTimeProcessing(typeNumberProcess aSeries) -
     * metoda obliczajaca sredni czas przetwarzania procesow wskazanej
     * serii
     * PRE:
     * - podanie serii procesow (argument: aSeries);
     * POST:
     * - brak.
     */
    void mCalculateAverageTimeProcessing(typeNumberProcess aSeries);

    /*
     * getAverageTimeProcessing(typeNumberProcess aSeries) - metoda
     * zwracajaca sredni czas przetwarzania wskazanej serii.
     * PRE:
     * - podanie serii procesow (argumenr: aSeries);
     * POST:
     * - zwrocenie wartosci sredniej czasu przetwarzania wskazanej
     * serii (typ: typeTime).
     */
    inline typeTime getAverageTimeProcessing(typeNumberProcess aSeries)
    {
        return tabAverageTimeProcessing[aSeries];
    }



    /*
     * mWriteResultsToFile(enumAlgorithms parAlgorithm) - metoda
     * wypisujaca wyniki dzialania wskazanego algorytmu.
     * PRE:
     * - podanie algorytmuc(argument: aAlgorithm;
     * POST:
     * - brak.
     */
    void mWriteResultsToFile(enumAlgorithms aAlgorithm);
};

#endif // CSHEDULINGALGORITHMS_H

/* cshedulingalgorithms.h */
/********** END_OF_FILE **********/
