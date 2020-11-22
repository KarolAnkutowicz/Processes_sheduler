/********** BEGIN_OF_FILE **********/
/* cprocess.h */

#ifndef CPROCESS_H
#define CPROCESS_H

#include "constantsandtypes.h"
#include <iostream>

using namespace std;

/*
 * cProcess - klasa modelujaca pojedynczy proces
 */
class cProcess
{
    /*
     * typeTime vTime - czas wykonywania procesu
     */
    typeTime vTime;
    /*
     * typeTime vTimeStartOfProcessing - moment rozpoczecia przetwarzanai procesu
     */
    typeTime vTimeStartOfProcessing;
    /*
     * typeTime vTimeEndOfProcessing - moment zakonczenia przetwarzania procesu
     */
    typeTime vTimeEndOfProcessing;
    /*
     * typeTime vTimeProcessing - calkowity czas przetwarzania
     */
    typeTime vTimeProcessing;
    /*
     * typeTime vTimeDone - czesc czasu wykonania
     */
    typeTime vTimeDone;
    /*
     * typeTime vTimeWillDo - czesc czasu pozostala do wykonania
     */
    typeTime vTimeWillDo;

public:
    /*
     * cProcess() - konstruktor wywolywany bez argumentow
     * PRE:
     * - brak.
     * POST:
     * - tworzenie obiektu.
     */
    cProcess();
    /*
     * cProcess(typeTime parTime) - konstruktor wywolywany z jednym
     * argumentem typu parTime (jest to czas trwania procesu).
     * PRE:
     * - podanie czasu trwania procesu.
     * POST:
     * - tworzenie obiektu.
     */
    cProcess(typeTime parTime);

    /*
     * ostream &operator << (ostream &streamOut, cProcess &P) - prze³adowanie
     * operatora wyjœcia.
     * PRE:
     * - obiekt klasy ostream;
     * - obiekt klasy cProcess.
     * POST:
     * - zwrocenie strumienia wyjsciowego.
     */
    friend ostream &operator << (ostream &streamOut, cProcess &P);

    /*
     * getVTime() - metoda zwracajaca wartosc pola vTime.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vTime.
     */
    inline typeTime getVTime()
    {
        return vTime;
    }
    /*
     * setVTime(typeTime parTime) - metoda ustawiajaca wartosc pola vTime.
     * PRE:
     * - podanie nowej wartosci vTime.
     * POST:
     * - brak.
     */
    void setVTime(typeTime parTime);
    /*
     * getVTimeStartOfProcessing() - metoda zwracajaca wartosc pola
     * vtimeStartOfProcessing.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vtimeStartOfProcessing.
     */
    inline typeTime getVTimeStartOfProcessing()
    {
        return vTimeStartOfProcessing;
    }
    /*
     * void setVTimeStartOfProcessing(typeTime parTime) - metoda ustawiajaca
     * wartosc pola vTimeStartOfProcessing.
     * PRE:
     * - podanie nowej wartosci pola vTimeStartOfProcessing.
     * POST:
     * - brak.
     */
    inline void setVTimeStartOfProcessing(typeTime parTime)
    {
        vTimeStartOfProcessing = parTime;
    }
    /*
     * getVTimeEndOfProcessing() - metoda zwracajaca wartosc pola
     * vTimeEndOfProcessing.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vTimeEndOfProcessing.
     */
    inline typeTime getVTimeEndOfProcessing()
    {
        return vTimeEndOfProcessing;
    }
    /*
     * getVTimeProcessing() - metoda zwracajaca wartosc pola
     * vTimeProcessing
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vTimeProcessing.
     */
    inline typeTime getVTimeProcessing()
    {
        return vTimeProcessing;
    }
    /*
     * getVTimeDone() - metoda zwracajaca wartosc pola vTimeDone.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vTimeDone.
     */
    inline typeTime getVTimeDone()
    {
        return vTimeDone;
    }
    /*
     * getVTimeWillDo() - metoda zwracajaca wartosc pola vTimeWillDo.
     * PRE:
     * - brak.
     * POST:
     * - zwrocenie wartosci pola vTimeWillDo.
     */
    inline typeTime getVTimeWillDo()
    {
        return vTimeWillDo;
    }

    /*
     * mDoProcess() - metoda zwiekszajaca czas wykonania procesu do
     * wartosci maksymalnej.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mDoProcess();
    /*
     * mIncrementProcessingTime() - metoda zwiekszajaca czas wykonania
     * procesu o jedna jednostke.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mIncrementProcessingTime();
    /*
     * mDoQuantumOfTime(typeTime parTime) - metoda zwiekszajaca czas
     * wykonania procesu o staly kwant czasu. W przypadku gdy do konca
     * zostalo mniej czasu to proces jest wykonywany do konca.
     * PRE:
     * - podanie kwantu czasu.
     * POST:
     * - brak.
     */
    void mDoQuantumOfTime(typeTime parTime);
    /*
     * mClearProcess() - metoda "czyszczaca" proces.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    void mClearProcess();

    /*
     * mCalculateProcessing() - metoda obliczajaca calkowity czas
     * trwania procesu.
     * PRE:
     * - brak.
     * POST:
     * - brak.
     */
    inline void mCalculateProcessing()
    {
        vTimeProcessing = vTimeEndOfProcessing - vTimeStartOfProcessing;
    }
};

#endif // CPROCESS_H

/* cprocess.h */
/********** END_OF_FILE **********/
