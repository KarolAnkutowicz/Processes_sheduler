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
};

#endif // CSHEDULINGALGORITHMS_H

/* cshedulingalgorithms.h */
/********** END_OF_FILE **********/
