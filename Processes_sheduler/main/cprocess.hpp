/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cprocess.hpp
 */

#pragma once

#include "constantsandtypes.hpp"
#include <iomanip>
#include <iostream>

/*
 * cProcess - klasa modelujaca pojedynczy proces
 */
class cProcess
{
/********** PUBLIC: BEGINNING **********/

public:

    /*
     * cProcess() - konstruktor wywolywany bez argumentow.
     * PRE:
     * - brak;
     * POST:
     * - tworzenie obiektu klasy cProcess.
     */
    cProcess();

    /*
     * cProcess(typeTime aTimeDoing) - konstruktor wywolywany
     * z jednym argumentem - czasem trwania procesu.
     * PRE:
     * - czas trwania prcesu (typ: typeTime);
     * POST:
     * - tworzenie obiektu klasy cProcess.
     */
    cProcess(typeTime aTimeDoing);

    /*
     * cProcess(typeTime aTimeReadiness, typeTime aTimeDoing) -
     * konstruktor wywolywany z dwoma argumentami - czas trwania
     * procesu oraz czas potrzebny do gotowosci procesu.
     * PRE:
     * - czas trwania procesu (typ: typeTime), czas
     * oczekiwania na gotowosc procesu (typ: typeTime);
     * POST:
     * - tworzenie obiektu klasy cProcess.
     */
    cProcess(typeTime aTimeReadiness, typeTime aTimeDoing);

    /*
     * cProcess(cProcess &P) - konstruktor kopiujacy klasy cProcess.
     * PRE:
     * - podanie referencji do obiektu (typ: cProcess);
     * POST:
     * - tworzenie obiektu - kopii obiektu podanego jako argument.
     */
    cProcess(cProcess& P);



    /*
     * ostream & operator << (ostream & StreamOut, cProcess & P) -
     * przeladowanie operatora wyjscia (wypisanie obiektu).
     * PRE:
     * - referencja obiektu klasy ostream, obiekt klasy cProcess;
     * POST:
     * - referencja do obiektu klasy ostream.
     */
    friend std::ostream& operator << (std::ostream& StreamOut, cProcess& P);

    /*
     * istream & operator >> (istream & StreamIn, cProcess & P) -
     * przeladowanie operatora wejscia (wczytanie obiektu).
     * PRE:
     * - referencja obiektu klasy istream, obiekt klasy cProcess;
     * POST:
     * - referencja do obiektu klasy istream.
     */
    friend std::istream& operator >> (std::istream& StreamIn, cProcess& P);



    /*
     * typeTime getTimeReadiness() - metoda zwracajaca uplywajacy
     * czas od momentu rozpoczecia przetwarzania procesow do momentu
     * rozpoczecia gotowosci procesu do wykonania.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vTimeReadiness (typ: typeTime).
     */
    inline typeTime getTimeReadiness()
    {
        return vTimeReadiness;
    }

    /*
     * typeTime getTimeReady() - metoda zwracajaca czas do gotowosci
     * wykonania procesu jaki juz uplynal.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vTimeReady (typ: typeTime).
     */
    inline typeTime getTimeReady()
    {
        return vTimeReady;
    }

    /*
     * typeTime getTimeToReady() - metoda zwracajaca czas jaki
     * pozostal do gotowosci procesu.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vTimeToReady (typ: typeTime).
     */
    inline typeTime getTimeToReady()
    {
        return vTimeToReady;
    }

    /*
     * typeTime getTimeWaiting() - metoda zwracajaca czas
     * oczekiwania na wykonanie procesu.
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
     * typeTime getTimeWaiting() - metoda zwracajaca czas
     * wykonywania procesu.
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
     * typeTime getTimeDone() - metoda zwracajaca czas procesu
     * jaki zostal juz wykonany.
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
     * typeTime getTimeToDo() - metoda zwracajaca czas jaki
     * zostal do wykonania.
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
     * typeTime getTimeProcessing() - metoda zwracajaca calkowity
     * czas przetwarzania procesu.
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
     * void setTimeReadiness(typeTime argTimeReadiness) - metoda
     * ustawiajaca czas uplywajacy od momentu rozpoczecia przetwarzania
     * procesow do momentu rozpoczecia gotowosci procesu do wykonania.
     * PRE:
     * - podanie wartosci czasu (typ: typeTime);
     * POST:
     * - brak.
     */
    void setTimeReadiness(typeTime aTimeReadiness);

    /*
     * void setTimeDoing(typeTime aTimeDoing) - metoda ustawiajaca
     * czas wykonywania procesu.
     * PRE:
     * - podanie wartosci czasu (typ: typeTime);
     * POST:
     * - brak.
     */
    void setTimeDoing(typeTime aTimeDoing);



    /*
     * void mIncrementTimeReady() - metoda inkrementujaca czas
     * oczekiwania na gotowosc procesu do wykonania.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mIncrementTimeReady();

    /*
     * void mForwardTimeReady(typeTime aTimeForward) - metoda
     * zwiekszajaca czas jaki uplynal od momentu rozpoczecia
     * oczekiwania na gotowosc procesu do wykonania.
     * PRE:
     * - podanie wartosci czasu (typ: typeTime);
     * POST:
     * - brak.
     */
    void mForwardTimeReady(typeTime aTimeForward);

    /*
     * void mIncrementTimeWaiting() - metoda inkrementujaca czas
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
     * void mForwardTimeWaiting(typeTime aTimeForward) - metoda
     * zwiekszajaca czas jaki proces jest w stanie gotowosci
     * do wykonania.
     * PRE:
     * - podanie wartosci czasu (typ: typeTime);
     * POST:
     * - brak.
     */
    inline void mForwardTimeWaiting(typeTime aTimeForward)
    {
        vTimeWaiting += aTimeForward;
    }

    /*
     * void mIncrementTimeDone() - metoda inkrementujaca czas procesu
     * jaki zostal juz wykonany.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mIncrementTimeDone();

    /*
     * void mForwardTimeDone(typeTime aTimeForward) - metoda
     * zwiekszajaca czas wykonania pracesu.
     * PRE:
     * - podanie wartosci czasu (typ: typeTime);
     * POST:
     * - brak.
     */
    void mForwardTimeDone(typeTime aTimeForward);

    /*
     * void mCalculateTimeProcessing() - metoda obliczajaca
     * calkowity czas przetwarzania procesu.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void mCalculateTimeProcessing()
    {
        vTimeProcessing = vTimeDoing + vTimeWaiting;
    }

    /*
     * void mResetProcess() - metoda zerujaca wszystkie czasy procesu.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void mResetProcess();

 /********** PUBLIC: END **********/

 /********** PRIVATE: BEGINNING **********/
 
private:

    /*
     * typeTime vTimeReadiness - czas uplywajacy od momentu
     * rozpoczecie przetwarzania procesow do momentu gotowosci
     * procesu do wykonywania.
     */
    typeTime vTimeReadiness;

    /*
     * typeTime vTimeReady - czas do momentu gotowosci jaki
     * juz uplynal.
     */
    typeTime vTimeReady;

    /*
     * typeTime vTimeToReady - czas do momentu gotowosci jaki
     * jeszcze pozostal.
     */
    typeTime vTimeToReady;

    /*
     * typeTime vTimeWaiting - czas oczekiwania na wykonanie
     * procesu.
     */
    typeTime vTimeWaiting;

    /*
     * typeTime vTimeDoing - czas wykonywania procesu.
     */
    typeTime vTimeDoing;

    /*
     * typeTime vTimeDone - czas procesu jaki zostal juz wykonany.
     */
    typeTime vTimeDone;

    /*
     * typeTime vTimeToDo - czas jaki pozostal do calkowitego
     * wykonania procesu.
     */
    typeTime vTimeToDo;

    /*
     * typeTime vTimeProcessing - calkowity czas przetwarzania
     * procesu (oczekiwanie + wykonywanie).
     */
    typeTime vTimeProcessing;

/********** PRIVATE: END **********/
};

/* cprocess.hpp */
/********** END_OF_FILE **********/
