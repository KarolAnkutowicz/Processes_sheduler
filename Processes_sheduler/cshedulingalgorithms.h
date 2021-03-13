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
     * cShedulingAlgorithms(enum aAlgorithm) -
     * PRE:
     * - ;
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
     * mDrawProcesses() -
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mDrawProcesses();
    /*
     * mResetProcesses(typeNumberProcess aSeries, typeNumberProcess aProcesses) -
     * PRE:
     * - ;
     * POST:
     * - brak.
     */
    inline void mResetProcesses(typeNumberProcess aSeries, typeNumberProcess aProcesses)
    {
        tabProcesses[aSeries][aProcesses].mResetProcess();
    }

    /*
     * mResetAllProcesses() -
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllProcesses();

    /*
     * mReadProcessesFromFile() -
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mReadProcessesFromFile();

    /*
     * mWriteProcessesToFile() -
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mWriteProcessesToFile();



    /*
     * mSortingProcesses(typeNumberProcess aSeries, bool aAscendingWaiting, bool aAscendingDoing) -
     * PRE:
     * - ;
     * POST:
     * - brak.
     */
    void mSortingProcesses(typeNumberProcess aSeries, bool aAscendingWaiting, bool aAscendingDoing);

    /*
     * mSortingAllProcesses(bool aAscendingWaiting, bool aAscendingDoing) -
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mSortingAllProcesses(bool aAscendingWaiting, bool aAscendingDoing);



    /*
     * mResetTotalTimeDoing(typeNumberProcess aSeries) -
     * PRE:
     * - ;
     * POST:
     * - brak.
     */
    inline void mResetTotalTimeDoing(typeNumberProcess aSeries)
    {
        tabTotalTimeDoing[aSeries] = 0;
    }

    /*
     * mResetAllTotalTimeDoing() -
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllTotalTimeDoing();

    /*
     * mCalculateTotalTimeDoing(typeNumberProcess aSeries) -
     * PRE:
     * - ;
     * POST:
     * - brak.
     */
    void mCalculateTotalTimeDoing(typeNumberProcess aSeries);

    /*
     * getTotalTimeDoing(typeNumberProcess aSeries) -
     * PRE:
     * - ;
     * POST:
     * - .
     */
    inline typeTime getTotalTimeDoing(typeNumberProcess aSeries)
    {
        return tabTotalTimeDoing[aSeries];
    }



    /*
     * mResetAverageTimeDoing(typeNumberProcess aSeries) -
     * PRE:
     * - ;
     * POST:
     * - brak.
     */
    inline void mResetAverageTimeDoing(typeNumberProcess aSeries)
    {
        tabAverageTimeDoing[aSeries] = 0;
    }

    /*
     * mResetAllAverageTimeDoing() -
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllAverageTimeDoing();

    /*
     * mCalculateAverageTimeDoing(typeNumberProcess aSeries) -
     * PRE:
     * - ;
     * POST:
     * - brak.
     */
    void mCalculateAverageTimeDoing(typeNumberProcess aSeries);

    /*
     * getAverageTimeDoing(typeNumberProcess aSeries) -
     * PRE:
     * - ;
     * POST:
     * - .
     */
    inline typeTime getAverageTimeDoing(typeNumberProcess aSeries)
    {
        return tabAverageTimeDoing[aSeries] = 0;
    }



    /*
     * mResetTotalTimeProcessing(typeNumberProcess aSeries) -
     * PRE:
     * - ;
     * POST:
     * - brak.
     */
    inline void mResetTotalTimeProcessing(typeNumberProcess aSeries)
    {
        tabTotalTimeProcessing[aSeries] = 0;
    }

    /*
     * mResetAllTotalTimeProcessing() -
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllTotalTimeProcessing();

    /*
     * mCalculateTotalTimeProcessing(typeNumberProcess aSeries) -
     * PRE:
     * - ;
     * POST:
     * - brak.
     */
    void mCalculateTotalTimeProcessing(typeNumberProcess aSeries);

    /*
     * getTotalTimeProcessing(typeNumberProcess aSeries) -
     * PRE:
     * - ;
     * POST:
     * - .
     */
    inline typeTime getTotalTimeProcessing(typeNumberProcess aSeries)
    {
        return tabTotalTimeProcessing[aSeries] = 0;
    }



    /*
     * mResetAverageTimeProcessing(typeNumberProcess aSeries) -
     * PRE:
     * - ;
     * POST:
     * - brak.
     */
    inline void mResetAverageTimeProcessing(typeNumberProcess aSeries)
    {
        tabAverageTimeProcessing[aSeries] = 0;
    }

    /*
     * mResetAllAverageTimeProcessing() -
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetAllAverageTimeProcessing();

    /*
     * mCalculateAverageTimeProcessing(typeNumberProcess aSeries) -
     * PRE:
     * - ;
     * POST:
     * - brak.
     */
    void mCalculateAverageTimeProcessing(typeNumberProcess aSeries);

    /*
     * getAverageTimeProcessing(typeNumberProcess aSeries) -
     * PRE:
     * - ;
     * POST:
     * - .
     */
    inline typeTime getAverageTimeProcessing(typeNumberProcess aSeries)
    {
        return tabAverageTimeProcessing[aSeries];
    }



    /*
     * mWriteResultsToFile(enumAlgorithms parAlgorithm) -
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mWriteResultsToFile(enumAlgorithms parAlgorithm);
};

#endif // CSHEDULINGALGORITHMS_H

/* cshedulingalgorithms.h */
/********** END_OF_FILE **********/
