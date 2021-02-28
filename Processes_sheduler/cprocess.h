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
     * cProcess(typeTime aTimeDoing) - konstruktor wywolywany
     * z jednym argumentem - czasem trwania procesu.
     * PRE:
     * - czas trwania prcesu (argument: aTimeDoing;
     * POST:
     * - tworzenie obiektu.
     */
    cProcess(typeTime aTimeDoing);

    /*
     * cProcess(typeTime aTimeDoing, typeTime aTimeReadiness) -
     * konstruktor wywolywany z dwoma argumentami - czas trwania
     * procesu oraz czas potrzebny do gotowosci procesu.
     * PRE:
     * - czas trwania procesu (argument: aTimeDoing), czas
     * oczekiwania na gotowosc procesu (argument: aTimeReadiness);
     * POST:
     * - tworzenie obiektu.
     */
    cProcess(typeTime aTimeDoing, typeTime aTimeReadiness);



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



    /*
     * mIncrementTimeWaiting() - metoda inkrementujaca czas
     * oczekiwania procesu na wykonannie.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void mIncrementTimeWaiting()
    {
        vTimeWaiting++;
    }

    /*
     * mIncrementTimeDone() - metoda inkrementujaca czas procesu
     * jaki zostal juz wykonany.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mIncrementTimeDone();

    /*
     * mDecrementTimeToDo() - metoda dekrememntujaca czas procesu
     * jaki zostal do wykonania.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mDecrementTimeToDo();

    /*
     * mIncrementTimeProcessing() - metoda inkrementujaca czas
     * calkowitego przetwarzania procesu.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void mIncrementTimeProcessing()
    {
        vTimeProcessing++;
    }
};

#endif // CPROCESS_H

/* cprocess.h */
/********** END_OF_FILE **********/
