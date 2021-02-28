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
     * vTimeReadiness - czas uplywajacy od momentu rozpoczecie
     * przetwarzania procesow do momentu gotowosci procesu
     * do wykonywania.
     */
    typeTime vTimeReadiness;

    /*
     * vTimeWaiting - czas oczekiwania na wykonanie procesu.
     */
    typeTime vTimeWaiting;

    /*
     * vTimeDoing - czas wykonywania procesu.
     */
    typeTime vTimeDoing;

    /*
     * vTimeDone - czas procesu jaki zostal juz wykonany.
     */
    typeTime vTimeDone;

    /*
     * vTimeToDo - czas jaki pozostal do calkowitego wykonania
     * procesu.
     */
    typeTime vTimeToDo;

    /*
     * vTimeProcessing - calkowity czas przetwarzania procesu
     * (oczekiwanie + wykonywanie).
     */
    typeTime vTimeProcessing;
public:
    /*
     * cProcess() - konstruktor wywolywany bez argumentow.
     * PRE:
     * - brak;
     * POST:
     * - tworzenie obiektu.
     */
    cProcess();



    /*
     * getTimeReadiness - metoda zwracajaca czas uplywajacy czas
     * od momentu rozpoczecia przetwarzania procesow do momentu
     * rozpoczecia gotowosci procesu do wykonania.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vTimeReadiness (typeTime).
     */
    inline typeTime getTimeReadiness()
    {
        return vTimeReadiness;
    }

    /*
     * getTimeWaiting - metoda zwracajaca czas oczekiwania
     * na wykonanie procesu.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vTimeWaiting (typ: typeTime).
     */
    inline typeTime getTimeWaiting()
    {
        return vTimeWaiting;
    }

    /*
     * getTimeWaiting - metoda zwracajaca czas wykonywania procesu.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vTimeDoing (typ: typeTime).
     */
    inline typeTime getTimeDoing()
    {
        return vTimeDoing;
    }

    /*
     * getTimeDone - metoda zwracajaca czas procesu jaki zostal
     * juz wykonany.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vTimeDone (typ: typeTime).
     */
    inline typeTime getTimeDone()
    {
        return vTimeDone;
    }

    /*
     * getTimeToDo - metoda zwracajaca czas jaki zostal do wykonania.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vTimeToDo (typ: typeTime).
     */
    inline typeTime getTimeToDo()
    {
        return vTimeToDo;
    }

    /*
     * getTimeProcessing - metoda zwracajaca calkowity czas
     * przetwarzania procesu.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vTimeProcessing (typ: typeTime).
     */
    inline typeTime getTimeProcessing()
    {
        return vTimeProcessing;
    }



    /*
     * setTimeReadiness(typeTime argTimeReadiness) - metoda ustawiajaca
     * czas uplywajacy od momentu rozpoczecia przetwarzania procesow do
     * momentu rozpoczecia gotowosci procesu do wykonania.
     * PRE:
     * - podanie wartosci czasu (argument: aTimeReadiness);
     * POST:
     * - brak.
     */
    void setTimeReadiness(typeTime aTimeReadiness);

    /*
     * setTimeDoing(typeTime aTimeDoing) - metoda ustawiajaca
     * czas wykonywania procesu.
     * PRE:
     * - podanie wartosci czasu (argument: aTimeDoing);
     * POST:
     * - brak.
     */
    void setTimeDoing(typeTime aTimeDoing);
};

#endif // CPROCESS_H

/* cprocess.h */
/********** END_OF_FILE **********/
