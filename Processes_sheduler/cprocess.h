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
     * przetwarzania procesow do momentu gotowsci procesu
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

};

#endif // CPROCESS_H

/* cprocess.h */
/********** END_OF_FILE **********/
