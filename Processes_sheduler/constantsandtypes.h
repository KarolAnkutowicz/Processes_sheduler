/********** BEGIN_OF_FILE **********/
/* constantsandtypes.h */

#ifndef CONSTANTSANDTYPES_H
#define CONSTANTSANDTYPES_H

using namespace std;

/*
 * unsigned short typeTime - zdefiniowanie synonimu typu dla czasu
 */
typedef unsigned short typeTime;
/*
 * unsigned int typeProcess - zdefiniowanie synonimu typu dla numeracji procesow
 */
typedef unsigned int typeProcess;

/*
 * typeTime constMaxTime - podanie zakresu do losowanie czasu trwania procesu
 */
const typeTime constMaxTime = 20;
/*
 * typeTime constQuantumOfTime - staly kwant czasu
 */
const typeTime constQuantumOfTime = 2;
/*
 * typeProcess constProcesses - liczba procesow w jednym ciagu
 */
const typeProcess constProcesses = 100;
/*
 * typeProcess constSeries - liczba ciagow procesow
 */
const typeProcess constSeries = 100;

#endif // CONSTANTSANDTYPES_H

/* constantsandtypes.h */
/********** END_OF_FILE **********/
