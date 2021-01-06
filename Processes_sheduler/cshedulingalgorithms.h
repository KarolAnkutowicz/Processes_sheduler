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
 * procesow. Zawiera pola i metody realizujace docelowo 4 rozne
 * algorytmy: FCFS, LCFS, SJF i Round-Robin.
 */
class cShedulingAlgorithms
{
    /*
     * cProcess tableProcesses[constSeries][constProcesses] -
     * tablica przechowujaca czasy trwania procesow zebrane
     * w kolejnych seriach (wierszach).
     */
    cProcess tableProcesses[constSeries][constProcesses];
    /*
     * typeTime tableTotalTimesDoing[constSeries] -
     * tablica przechowujaca calkowite czasy wykonywania
     * serii procesow.
     */
    typeTime tableTotalTimesDoing[constSeries];
    /*
     * double tableAverageTimesDoing[constSeries] -
     * tablica przechowujaca srednie czasy wykonywania serii
     * procesow.
     */
    double tableAverageTimesDoing[constSeries];
    /*
     * typeTime tableTotalTimesProcessing[constSeries] -
     * tablica przechowujaaca calkowite czasy przetwarzania
     * serii procesow.
     */
    typeTime tableTotalTimesProcessing[constSeries];
    /*
     * double tableAverageTimesProcessing[constSeries] -
     * tablica przechowujaca srednie czasy przetwarzania serii
     * procesow.
     */
    double tableAverageTimesProcessing[constSeries];

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
     * void mSheduling() - metoda obliczajaca czasy calkowite
     * i srednie wykonywania oraz przetwarzania serii procesow.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mSheduling();
    /*
     * void mRoundRobin() - metoda realizujaca wykonywanie
     * szeregowania procesow algorytmem Round-Robin.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    //void mRoundRobin();

    /*
     * getProcess(typeProcess parSeries, typeProcess parProcesses) -
     * metoda zwracajaca czas trwania wskazanego procesu.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries);
     * - podanie numeru procesu w serii (argument: parProcesses).
     * POST:
     * - zwrocenie czasu trwania procesu (typ: cProcess).
     */
    inline cProcess getProcess(typeProcess parSeries, typeProcess parProcesses)
    {
        return tableProcesses[parSeries][parProcesses];
    }
    /*
     * getTotalTimesDoing(typeProcess parSeries) - metoda zwracajaca
     * calkowity czas wykonywania wskazanej serii procesow.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - zwrocenie calkowitego czasu wykonywania serii procesow
     * (typ: typeTime).
     */
    inline typeTime getTotalTimesDoing(typeProcess parSeries)
    {
        return tableTotalTimesDoing[parSeries];
    }
    /*
     * getAverageTotalTimesDoing(typeProcess parSeries) - metoda
     * zwracajaca sredni czas wykonywania wskazanej serii procesow.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - zwrocenie sredniego czasu wykonywania serii procesow
     * (typ: double).
     */
    inline double getAverageTotalTimesDoing(typeProcess parSeries)
    {
        return tableAverageTimesDoing[parSeries];
    }
    /*
     * getTotalTimesProcessing(typeProcess parSeries) - metoda
     * zwracajaca calkowity czas przetwarzania wskazanej serii
     * procesow.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - zwrocenie calkowitego czasu przetwarzania serii procesow
     * (typ: typeTime).
     */
    inline typeTime getTotalTimesProcessing(typeProcess parSeries)
    {
        return tableTotalTimesProcessing[parSeries];
    }
    /*
     * getAverageTimesProcessing(typeProcess parSeries) - metoda
     * zwracajaca sredni czas przetwarzania wskazanej serii procesow.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - zwrocenie sredniego czasu przetwarzania serii procesow
     * (typ: double).
     */
    inline double getAverageTimesProcessing(typeProcess parSeries)
    {
        return tableAverageTimesProcessing[parSeries];
    }

    /*
     * mClearTotalTimesDoing(typeProcess parSeries) - metoda
     * "zerujaca" calkowity czas wykonywania wskazanej serii procesow.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - brak.
     */
    inline void mClearTotalTimesDoing(typeProcess parSeries)
    {
        tableTotalTimesDoing[parSeries] = 0;
    }
    /*
     * mClearAllTotalTimesDoing() - metoda "zerujaca" calkowite czasy
     * wykonywania wszystkich serii procesow.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mClearAllTotalTimesDoing();
    /*
     * mClearAverageTimesDoing(typeProcess parSeries) - metoda
     * "zerujaca" sredni czas wykonywania wskazanej serii procesow.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - brak.
     */
    inline void mClearAverageTimesDoing(typeProcess parSeries)
    {
        tableAverageTimesDoing[parSeries] = 0;
    }
    /*
     * mClearAllAverageTimesDoing() - metoda "zerujaca" srednie czasy
     * wykonywania wszystich serii procesow.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mClearAllAverageTimesDoing();
    /*
     * mClearTotalTimesProcessing(typeProcess parSeries) - metoda
     * "zerujaca" calkowity czas przetwarzania wskazanej serii
     * procesow.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - brak.
     */
    inline void mClearTotalTimesProcessing(typeProcess parSeries)
    {
        tableTotalTimesProcessing[parSeries] = 0;
    }
    /*
     * mClearAllTotalTimesProcessing() - metoda "zerujaca" calkowite
     * czasy przetwarzania wszystkich serii procesow.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mClearAllTotalTimesProcessing();
    /*
     * mClearAverageTimesProcessing(typeProcess parSeries) -
     * metoda "zerujaca" sredni czas przetwarzania wskazanej serii
     * procesow.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - brak.
     */
    inline void mClearAverageTimesProcessing(typeProcess parSeries)
    {
        tableAverageTimesProcessing[parSeries] = 0;
    }
    /*
     * mClearAllAverageTimesProcessing() - metoda "zerujaca" srednie
     * czasy przetwarzania wszystkich serii procesow.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mClearAllAverageTimesProcessing();

    /*
     * mCalculateTotalTimesDoing(typeProcess parSeries) - metoda
     * obliczajaca calkowity czas wykonywania procesow wskazanej serii.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - brak.
     */
    void mCalculateTotalTimesDoing(typeProcess parSeries);
    /*
     * mCalculateAverageTotalTimesDoing(typeProcess parSeries) -
     * metoda obliczajaca sredni czas wykonywania procesow wskazanej
     * serii.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - brak.
     */
    void mCalculateAverageTotalTimesDoing(typeProcess parSeries);
    /*
     * mCalculateTotalTimesProcessing(typeProcess parSeries) -
     * metoda obliczajaca calkowity czas przetwarzania procesow
     * wskazanej serii.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - brak.
     */
    void mCalculateTotalTimesProcessing(typeProcess parSeries);
    /*
     * mCalculateAverageTimesProcessing(typeProcess parSeries) -
     * metoda obliczajaca sredni czas przetwarzania procesow wskazanej
     * serii.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - brak.
     */
    void mCalculateAverageTimesProcessing(typeProcess parSeries);

    /*
     * mSortingSeries(typeProcess parSeries) - metoda sortujaca
     * niemalejaco procesy wskazanej serii. Wykorzystano algorytm
     * sortowania babelkowego.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - brak.
     */
    void mSortingSeries(typeProcess parSeries);
    /*
     * mSortingAll() - metoda sortujaca niemalejaco procesy
     * we wszystkich seriach.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mSortingAll();
    /*
     * mReverseSeries(typeProcess parSeries) - metoda odwracajaca
     * kolejnosc procesow wskazanej serii.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - brak.
     */
    void mReverseSeries(typeProcess parSeries);
    /*
     * mReverseAll() - metoda odwracajaca kolejnosc procesow
     * we wszystkich seriach.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mReverseAll();

    /*
     * mDrawProcesses() - metoda losujaca czas trwania procesu.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mDrawProcesses();
    /*
     * mClearSeries(typeProcess parSeries) - metoda "zerujaca"
     * wskazana serie procesow.
     * PRE:
     * - podanie numeru serii procesow (argument: parSeries).
     * POST:
     * - brak.
     */
    void mClearSeries(typeProcess parSeries);
    /*
     * mClearAllSeries() - metoda "zerujaca" wszystkie serie
     * procesow.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mClearAllSeries();

    /*
     * mPrintProcessesToFile() - metoda tworzaca plik tekstowy
     * i wypisujaca do niego wygenerowane losowo czasy trwania
     * procesow.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mPrintProcessesToFile();
    /*
     * mPrintResultsToFile(typeProcess parAlgorithmNumber) -
     * metoda tworzaca plik tekstowy i wypisujaca do niego
     * obliczone wynikowe czasy dla wskazanego algorytmu.
     * metoda
     * PRE:
     * - podanie numeru algorytmu (argument: parAlgorithmNumber).
     * POST:
     * - brak.
     */
    void mPrintResultsToFile(typeProcess parAlgorithmNumber);
};

#endif // CSHEDULINGALGORITHMS_H

/* cshedulingalgorithms.h */
/********** END_OF_FILE **********/
