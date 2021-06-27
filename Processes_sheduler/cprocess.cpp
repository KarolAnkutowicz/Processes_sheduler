/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cprocess.cpp
 */

#include "cprocess.h"

using namespace std;

/*
 * cProcess()
 */
cProcess::cProcess()
{
    vTimeReadiness = vTimeReady = vTimeToReady = vTimeWaiting = vTimeDoing
            = vTimeDone = vTimeToDo = vTimeProcessing = 0; // ustanowienie wszystkisch czasow na'0'
}

/*
 * cProcess(typeTime aTimeDoing)
 */
cProcess::cProcess(typeTime aTimeDoing)
{
    vTimeDoing = vTimeToDo = aTimeDoing; // ustanowienie czasu do wykonania procesu
    vTimeReadiness = vTimeReady = vTimeToReady
            = vTimeWaiting = vTimeDone = vTimeProcessing = 0; // pozostale czasy sa na'0'
}

/*
 * cProcess(typeTime aTimeReadiness, typeTime aTimeDoing)
 */
cProcess::cProcess(typeTime aTimeReadiness, typeTime aTimeDoing)
{
    vTimeReadiness = vTimeToReady = aTimeReadiness; // ustanowienie czasu oczekiwania
    vTimeDoing = vTimeToDo = aTimeDoing; // ustanowienie czasu wykonywania procesu
    vTimeReady = vTimeWaiting = vTimeDone = vTimeProcessing = 0; // ustanowienie pozostalych czasow na'0'
}

/*
 * cProcess(cProcess &P)
 */
cProcess::cProcess(cProcess &P)
{
    vTimeReadiness = P.vTimeReadiness; // przypisanie odpowiednich czasow nowemu obiektowi
    vTimeReady = P.vTimeReady;
    vTimeToReady = vTimeToReady;
    vTimeWaiting = P.vTimeWaiting;
    vTimeDoing = P.vTimeDoing;
    vTimeDone = P.vTimeDone;
    vTimeToDo = P.vTimeToDo;
    vTimeProcessing = P.vTimeProcessing;
}



/*
 * ostream & operator << (ostream & StreamOut, cProcess & P)
 */
ostream & operator << (ostream & StreamOut, cProcess & P)
{
    StreamOut << P.getTimeReadiness() << " " << P.getTimeDoing() << " "; // wypisanie czasow procesu
    return StreamOut; // zwrocenie strumienia
}

/*
 * istream & operator >> (istream & StreamIn, cProcess & P)
 */
istream & operator >> (istream & StreamIn, cProcess & P)
{
    typeTime aTimeReadiness, aTimeDoing; // utworzenie zmiennych
    StreamIn >> skipws >> aTimeReadiness >> aTimeDoing; // wczytanie czasow procesu
    P.setTimeReadiness(aTimeReadiness); // ustanowienie czasu oczekiwania
    P.setTimeDoing(aTimeDoing); // ustanowienie czasu wykonania
    P.vTimeToReady = P.vTimeReadiness;
    P.vTimeToDo = P.vTimeDoing;
    return StreamIn; // zwrocenie strumienia
}



/*
 * void setTimeReadiness(typeTime argTimeReadiness)
 */
void cProcess::setTimeReadiness(typeTime aTimeReadiness)
{
    if (aTimeReadiness > constMaxTime) // sprawdzamy czy podany przez nas czas nie jest sprzeczny z zalozeniami
        vTimeReadiness = aTimeReadiness % constMaxTime; // jesli tak to ustawiamy maksimum
    else
        vTimeReadiness = aTimeReadiness; // jesli jest ok to przypisujemy wartosc z argumentu
    vTimeToReady = vTimeReadiness; // ustanowienie czasu jaki musi uplynac do pelnej gotowosci
}

/*
 * void setTimeDoing(typeTime aTimeDoing)
 */
void cProcess::setTimeDoing(typeTime aTimeDoing)
{
    if (aTimeDoing > constMaxTime) // sprawdzamy czy podany przez nas czas nie jest sprzeczny z zalozeniami
        vTimeDoing = aTimeDoing % constMaxTime; // jesli tak to ustawiamy maksimum
    else
        vTimeDoing = aTimeDoing; // jesli jest ok to przypisujemy wartosc z argumentu
    vTimeToDo = vTimeDoing; // ustanowienie czasu jaki jeszcze mamy do wykonania calego procesu
}



/*
 * void mIncrementTimeReady()
 */
void cProcess::mIncrementTimeReady()
{
    if (vTimeReady < vTimeReadiness) // sprawdzamy czy proces nie jest juz gotowy
    {
        vTimeReady++; // jesli nie to skraca sie czas oczekiwania
        vTimeToReady--;
    }
}

/*
 * void mForwardTimeReady(typeTime aTimeForward)
 */
void cProcess::mForwardTimeReady(typeTime aTimeForward)
{
    if (aTimeForward <= vTimeToReady) // sprawdzamy czy nie przekroczymy czasu gotowosci
    {
        vTimeReady += aTimeForward; // jesli nie to skraca sie czas oczekiwania
        vTimeToReady -= aTimeForward;
    }
}

/*
 * void mIncrementTimeDone()
 */
void cProcess::mIncrementTimeDone()
{
    if (vTimeDone < vTimeDoing) // sprawdzamy czy proces nie jest juz wykonany
    {
        vTimeDone++; // jesli nie to wykonujemy jego fragment
        vTimeToDo--;
    }
}

/*
 * void mForwardTimeDone(typeTime aTimeForward)
 */
void cProcess::mForwardTimeDone(typeTime aTimeForward)
{
    if (aTimeForward <= vTimeToDo) // sprawdzamy czy nie przekroczymy czasu wykonania
    {
        vTimeDone += aTimeForward; // jesli nie to wykonujemy proces przez wskazany czas
        vTimeToDo -= aTimeForward;
    }
}

/*
 * void mResetProcess()
 */
void cProcess::mResetProcess()
{
    vTimeReadiness = vTimeReady = vTimeToReady = vTimeWaiting = vTimeDoing
            = vTimeDone = vTimeToDo = vTimeProcessing = 0; // ustanawiamy wszystkie wartosci na'0'
}


/* cprocess.cpp */
/********** END_OF_FILE **********/
