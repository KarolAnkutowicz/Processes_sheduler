/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: constantsandtypes.hpp
 */

#ifndef CONSTANTSANDTYPES_HPP
#define CONSTANTSANDTYPES_HPP

/*
 * enum enumAlgorithms - zdefiniowany typ wyliczeniowy
 * do znormalizowania argumentow potrzebnych do wywolywania
 * wskazanych metod.
 */
enum enumAlgorithms { fcfs, lcfs, sjf, rr, srt };

/*
 * unsigned int typeTime - zdefiniowany synonim typu
 * dla czasu trwania procesu.
 */
typedef unsigned int typeTime;

/*
 * unsigned short typeNumberProcess - zdefiniowany synonim typu
 * dla numeracji procesow.
 */
typedef unsigned short typeNumberProcess;



/*
 * typeTime constMaxTime - zdefiniowany maksymalny czas gotowosci
 * oraz maksymalmny czas trwania procesu.
 */
const typeTime constMaxTime = 20;

/*
 * typeTime constQuantumOfTime - zdefiniowany kwant czasu
 * wykorzystywany w algorytmach wywlaszczeniowych.
 */
const typeTime constQuantumOfTime = 2;

/*
 * typeNumberProcess constProcesses - zdefiniowana liczba procesow
 * w ciagu.
 */
const typeNumberProcess constProcesses = 5;

/*
 * typeNumberProcess constSeries - zdefiniowana liczba ciagow procesow.
 */
const typeNumberProcess constSeries = 5;

#endif // CONSTANTSANDTYPES_HPP

/* constantsandtypes.hpp */
/********** END_OF_FILE **********/
