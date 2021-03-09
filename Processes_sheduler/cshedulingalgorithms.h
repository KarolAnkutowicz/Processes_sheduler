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
     * - brak.
     * POST:
     * - utworzenie obiektu.
     */
    cShedulingAlgorithms();



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
     *
     */
    void mDrawProcesses();
    /*
     *
     */
    void mResetProcesses(typeNumberProcess aSeries, typeNumberProcess aProcesses);
    /*
     *
     */
    void mResetAllProcesses();
    /*
     *
     */
    void mReadProcessesFromFile();
    /*
     *
     */
    void mWriteProcessesToFile();



    /*
     *
     */
    void mSortingAscendingProcesses(typeNumberProcess aSeries);
    /*
     *
     */
    void mSortingAscendingAllProcesses();
    /*
     *
     */
    void mSortingDescendingProcesses(typeNumberProcess aSeries);
    /*
     *
     */
    void mSortingDescendingAllProcesses();



    /*
     *
     */
    void mResetTotalTimeDoing(typeNumberProcess aSeries);
    /*
     *
     */
    void mResetAllTotalTimeDoing();
    /*
     *
     */
    void mCalculateTotalTimeDoing(typeNumberProcess aSeries);
    /*
     *
     */
    typeTime getTotalTimeDoing(typeNumberProcess aSeries);



    /*
     *
     */
    void mResetAverageTimeDoing(typeNumberProcess aSeries);
    /*
     *
     */
    void mResetAllAverageTimeDoing();
    /*
     *
     */
    void mCalculateAverageTimeDoing(typeNumberProcess aSeries);
    /*
     *
     */
    typeTime getAverageTimeDoing(typeNumberProcess aSeries);



    /*
     *
     */
    void mResetTotalTimeProcessing(typeNumberProcess aSeries);
    /*
     *
     */
    void mResetAllTotalTimeProcessing();
    /*
     *
     */
    void mCalculateTotalTimeProcessing(typeNumberProcess aSeries);
    /*
     *
     */
    typeTime getTotalTimeProcessing(typeNumberProcess aSeries);



    /*
     *
     */
    void mResetAverageTimeProcessing(typeNumberProcess aSeries);
    /*
     *
     */
    void mResetAllAverageTimeProcessing();
    /*
     *
     */
    void mCalculateAverageTimeProcessing(typeNumberProcess aSeries);
    /*
     *
     */
    typeTime getAverageTimeProcessing(typeNumberProcess aSeries);



    /*
     *
     */
    void mWriteResultsToFile();
};

#endif // CSHEDULINGALGORITHMS_H

/* cshedulingalgorithms.h */
/********** END_OF_FILE **********/
