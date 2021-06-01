/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cprocess.h
 */

#ifndef CPROCESS_H
#define CPROCESS_H

#include "constantsandtypes.h"
#include <iomanip>
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
     * vTimeReady - czas do momentu gotowosci jaki juz uplynal.
     */
    typeTime vTimeReady;

    /*
     * vTimeToReady - czas do momentu gotowosci jaki jeszcze
     * pozostal.
     */
    typeTime vTimeToReady;

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
     * cProcess(typeTime aTimeReadiness, typeTime aTimeDoing) -
     * konstruktor wywolywany z dwoma argumentami - czas trwania
     * procesu oraz czas potrzebny do gotowosci procesu.
     * PRE:
     * - czas trwania procesu (argument: aTimeDoing), czas
     * oczekiwania na gotowosc procesu (argument: aTimeReadiness);
     * POST:
     * - tworzenie obiektu.
     */
    cProcess(typeTime aTimeReadiness, typeTime aTimeDoing);

    /*
     * cProcess(cProcess &P) - konstruktor kopiujacy klasy cProcess.
     * PRE:
     * - podanie referencji do obiektu (typ: cProcess);
     * POST:
     * - tworzenie obiektu - kopii obiektu podanego jako argument.
     */
    cProcess(cProcess &P);



    /*
     * ostream & operator << (ostream & StreamOut, cProcess & P) -
     * PRE:
     * - referencja obiektu klasy ostream, obiekt klasy cProcess;
     * POST:
     * - referencja do obiektu klasy ostream.
     */
    friend ostream & operator << (ostream & StreamOut, cProcess & P);

    /*
     * istream & operator >> (istream & StreamIn, cProcess & P) -
     * PRE:
     * - referencja obiektu klasy istream, obiekt klasy cProcess;
     * POST:
     * - referencja do obiektu klasy istream.
     */
    friend istream & operator >> (istream & StreamIn, cProcess & P);

    /*
     * operator = (cProcess & P) -
     * PRE:
     * -
     * POST:
     * -
     */
    void operator = (cProcess & P);



    /*
     * getTimeReadiness() - metoda zwracajaca uplywajacy czas
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
     * getTimeReady() - metoda zwracajaca czas do gotowosci
     * wykonania procesu jaki juz uplynal.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vTimeReady (typeTime).
     */
    inline typeTime getTimeReady()
    {
        return vTimeReady;
    }

    /*
     * getTimeToReady() - metoda zwracajaca czas jaki pozostal
     * do gotowosci procesu.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vTimeToReady (typeTime).
     */
    inline typeTime getTimeToReady()
    {
        return vTimeToReady;
    }

    /*
     * getTimeWaiting() - metoda zwracajaca czas oczekiwania
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
     * getTimeWaiting() - metoda zwracajaca czas wykonywania procesu.
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
     * getTimeDone() - metoda zwracajaca czas procesu jaki zostal
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
     * getTimeToDo() - metoda zwracajaca czas jaki zostal do wykonania.
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
     * getTimeProcessing() - metoda zwracajaca calkowity czas
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
     * mIncrementTimeReady() - metoda inkrementujaca czas
     * oczekiwania na gotowosc procesu do wykonania.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mIncrementTimeReady();

    /*
     * mDecrementTimeToReady() - metoda dekrementujaca czas
     * jaki pozostal do gotowosci do wykonywania procesu.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mDecrementTimeToReady();

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

    /*
     * mResetProcess() - metoda zerujaca wszystkie czasy procesu.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetProcess();
};

#endif // CPROCESS_H

/* cprocess.h */
/********** END_OF_FILE **********/
