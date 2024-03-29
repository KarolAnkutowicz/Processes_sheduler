/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cshedulingalgorithms.cpp
 */

#include "cshedulingalgorithms.hpp"
#include <iomanip>

/********** PUBLIC: BEGINNING **********/

/*
 * cShedulingAlgorithms()
 */
cShedulingAlgorithms::cShedulingAlgorithms()
{
    mResetAllProcesses(); // wyczyszczenie tablicy procesow
    mDrawProcesses(); // wylosowanie procesow
    mWriteProcessesToFile(); // wypisanie procesow do pliku
    mMakeFCFS(); // wywolanie metody implementujacej dzialanie algorytmu FCFS
    mMakeLCFS(); // wywolanie metody implementujacej dzialanie algorytmu LCFS
    mMakeSJF(); // wywolanie metody implementujacej dzialanie algorytmu SJF
    mMakeRR(); // wywolanie metody implementujacej dzialanie algorytmu Round-Robin
    mMakeSRT(); // wywolanie metody implementujacej dzialanie algorytmu SRT
}

/*
 * cShedulingAlgorithms(enum aAlgorithm)
 */
cShedulingAlgorithms::cShedulingAlgorithms(enumAlgorithms aAlgorithm)
{
    mResetAllProcesses(); // wyczyszczenie tablicy procesow
    mDrawProcesses(); // wylosowanie procesow
    mWriteProcessesToFile(); // wypisanie procesow do pliku
    switch (aAlgorithm) // wywolanie odpowiedniej metody, zgodnie z podanym argumentem
    {
    case fcfs: mMakeFCFS(); break; // wywolanie realizacji algorytmu FCFS
    case lcfs: mMakeLCFS(); break; // wywolanie realizacji algorytmu LCFS
    case sjf: mMakeSJF(); break; // wywolanie realizacji algorytmu SJF
    case rr: mMakeRR(); break; // wywolanie realizacji algorytmu Round-Robin
    case srt: mMakeSRT(); break; // wywolanie realizacji algorytmu SRT
    }
}



/*
 * void mMakeFCFS()
 */
void cShedulingAlgorithms::mMakeFCFS()
{
    mResetAllTotalTimeDoing(); // wyzerowanie wszystkich calkowitych czasow wykonania
    mResetAllAverageTimeDoing(); // wyzerowanie wszystkich srednich czasow wykonania
    mResetAllTotalTimeProcessing(); // wyzerowanie wszystkich calkowitych czasow przetwarzania
    mResetAllAverageTimeProcessing(); // wyzerowanie wszystkich srednich czasow przetwarzania
    mSortingAllSeriesReadiness(); // sortujemy procesu uzyskujac kolejnosc gotowosci do wykonania
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++)// przejscie po wszystkich procesach
        {
            if (mReadyAny(i) == false) // sprawdzamy czy jakikolwiek proces jest gotowy do wykonania
                mForwardReadinessSeries(i, tabProcesses[i][j].getTimeToReady()); // jesli nie to przesuwamy czas oczekiwania na gotowosc wszystkich procesow
            mMakeProcess(i, j); // wykonujemy kolejny proces
        }
        for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach w serii
            tabProcesses[i][j].mCalculateTimeProcessing(); // wyznaczenie czasu calkowitego przetwarzania procesu
    }
    mCalculateAllTotalTimeDoing(); // wywolanie metody obliczajacej sumaryczne czasy wykonywania procesow w kolejnych seriach
    mCalculateAllAverageTimeDoing(); // wywolanie metody obliczajacej srednie czasy wykonywanie procesow w kolejnych seriach
    mCalculateAllTotalTimeProcessing(); // wywolanie metody obliczajacej sumaryczne czasy przetwarzania procesow w kolejnych seriach
    mCalculateAllAverageTimeProcessing(); // wywolanie metody obliczajacej srednie czasy przetwarzania procesow w kolejnych seriach
    mWriteResultsToFile(fcfs); // wypisanie resultatow do pliku
}

/*
 * void mMakeLCFS()
 */
void cShedulingAlgorithms::mMakeLCFS()
{
    mResetAllTotalTimeDoing(); // wyzerowanie wszystkich calkowitych czasow wykonania
    mResetAllAverageTimeDoing(); // wyzerowanie wszystkich srednich czasow wykonania
    mResetAllTotalTimeProcessing(); // wyzerowanie wszystkich calkowitych czasow przetwarzania
    mResetAllAverageTimeProcessing(); // wyzerowanie wszystkich srednich czasow przetwarzania
    mSortingAllSeriesReadiness(); // sortujemy procesu uzyskujac kolejnosc gotowosci do wykonania
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++)// przejscie po wszystkich procesach
        {
            if (mReadyAny(i) == false) // sprawdzamy czy jakikolwiek proces jest gotowy do wykonania
                mForwardReadinessSeries(i, tabProcesses[i][j].getTimeToReady()); // jesli nie to przesuwamy czas oczekiwania na gotowosc wszystkich procesow
            mMakeProcess(i, mGetLast(i)); // wykonujemy kolejny proces
        }
        for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach w serii
            tabProcesses[i][j].mCalculateTimeProcessing(); // wyznaczenie czasu calkowitego przetwarzania procesu
    }
    mCalculateAllTotalTimeDoing(); // wywolanie metody obliczajacej sumaryczne czasy wykonywania procesow w kolejnych seriach
    mCalculateAllAverageTimeDoing(); // wywolanie metody obliczajacej srednie czasy wykonywanie procesow w kolejnych seriach
    mCalculateAllTotalTimeProcessing(); // wywolanie metody obliczajacej sumaryczne czasy przetwarzania procesow w kolejnych seriach
    mCalculateAllAverageTimeProcessing(); // wywolanie metody obliczajacej srednie czasy przetwarzania procesow w kolejnych seriach
    mWriteResultsToFile(lcfs); // wypisanie resultatow do pliku
}

/*
 * void mMakeSJF()
 */
void cShedulingAlgorithms::mMakeSJF()
{
    mResetAllTotalTimeDoing(); // wyzerowanie wszystkich calkowitych czasow wykonania
    mResetAllAverageTimeDoing(); // wyzerowanie wszystkich srednich czasow wykonania
    mResetAllTotalTimeProcessing(); // wyzerowanie wszystkich calkowitych czasow przetwarzania
    mResetAllAverageTimeProcessing(); // wyzerowanie wszystkich srednich czasow przetwarzania
    mSortingAllSeriesReadiness(); // sortujemy procesu uzyskujac kolejnosc gotowosci do wykonania
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++)// przejscie po wszystkich procesach
        {
            if (mReadyAny(i) == false) // sprawdzamy czy jakikolwiek proces jest gotowy do wykonania
                mForwardReadinessSeries(i, tabProcesses[i][j].getTimeToReady()); // jesli nie to przesuwamy czas oczekiwania na gotowosc wszystkich procesow
            mMakeProcess(i, mGetTheShortest(i)); // wykonujemy kolejny proces
        }
        for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach w serii
            tabProcesses[i][j].mCalculateTimeProcessing(); // wyznaczenie czasu calkowitego przetwarzania procesu
    }
    mCalculateAllTotalTimeDoing(); // wywolanie metody obliczajacej sumaryczne czasy wykonywania procesow w kolejnych seriach
    mCalculateAllAverageTimeDoing(); // wywolanie metody obliczajacej srednie czasy wykonywanie procesow w kolejnych seriach
    mCalculateAllTotalTimeProcessing(); // wywolanie metody obliczajacej sumaryczne czasy przetwarzania procesow w kolejnych seriach
    mCalculateAllAverageTimeProcessing(); // wywolanie metody obliczajacej srednie czasy przetwarzania procesow w kolejnych seriach
    mWriteResultsToFile(sjf); // wypisanie resultatow do pliku
}

/*
 * void mMakeRR()
 */
void cShedulingAlgorithms::mMakeRR()
{
    mResetAllTotalTimeDoing(); // wyzerowanie wszystkich calkowitych czasow wykonania
    mResetAllAverageTimeDoing(); // wyzerowanie wszystkich srednich czasow wykonania
    mResetAllTotalTimeProcessing(); // wyzerowanie wszystkich calkowitych czasow przetwarzania
    mResetAllAverageTimeProcessing(); // wyzerowanie wszystkich srednich czasow przetwarzania
    mSortingAllSeriesReadiness(); // sortujemy procesu uzyskujac kolejnosc gotowosci do wykonania
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        do // petla dla kazdej serii
        {
            for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach w serii
            {
                if (mReadyAny(i) == false) // sprawdzamy czy jakikolwiek proces jest gotowy do wykonania
                    mForwardReadinessSeries(i, tabProcesses[i][j].getTimeToReady()); // jesli nie to przesuwamy czas oczekiwania na gotowosc wszystkich procesow
                if (tabProcesses[i][j].getTimeToReady() > 0) // sprawdzamy czy na pewno proces jest gotowy do wykonania
                    continue; // jesli nie to pomijamy go i przechodzimy do kolejnego procesu w serii
                else if (tabProcesses[i][j].getTimeToDo() < constQuantumOfTime) // jesli proces jest gotowy sprawddzamy czy pozostaly czas wykonania jest krotszy niz podstawowy kwant czasu
                    mMakeProcess(i, j, tabProcesses[i][j].getTimeToDo()); // jesli tak to wykonujemy tyle czasu procesu ile zostalo
                else // jesli czas jest bedzie rowny lub wiekszy
                    mMakeProcess(i, j, constQuantumOfTime); // wowczas wykonujemygo  tylko prze okreslony kwant czasu
            }
        } while (mDoneAll(i) == false); // petla kazdej serii konczy sie kiedy zostaja ukonczone wszystkie procesy
        for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach w serii
            tabProcesses[i][j].mCalculateTimeProcessing(); // wyznaczenie czasu calkowitego przetwarzania procesu
    }
    mCalculateAllTotalTimeDoing(); // wywolanie metody obliczajacej sumaryczne czasy wykonywania procesow w kolejnych seriach
    mCalculateAllAverageTimeDoing(); // wywolanie metody obliczajacej srednie czasy wykonywanie procesow w kolejnych seriach
    mCalculateAllTotalTimeProcessing(); // wywolanie metody obliczajacej sumaryczne czasy przetwarzania procesow w kolejnych seriach
    mCalculateAllAverageTimeProcessing(); // wywolanie metody obliczajacej srednie czasy przetwarzania procesow w kolejnych seriach
    mWriteResultsToFile(rr); // wypisanie resultatow do pliku
}

/*
 * void mMakeSRT()
 */
void cShedulingAlgorithms::mMakeSRT()
{
    mResetAllTotalTimeDoing(); // wyzerowanie wszystkich calkowitych czasow wykonania
    mResetAllAverageTimeDoing(); // wyzerowanie wszystkich srednich czasow wykonania
    mResetAllTotalTimeProcessing(); // wyzerowanie wszystkich calkowitych czasow przetwarzania
    mResetAllAverageTimeProcessing(); // wyzerowanie wszystkich srednich czasow przetwarzania
    mSortingAllSeriesReadiness(); // sortujemy procesu uzyskujac kolejnosc gotowosci do wykonania
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        do // petla dla kazdej serii
        {
            for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach w serii
            {
                if (mReadyAny(i) == false) // sprawdzamy czy jakikolwiek proces jest gotowy do wykonania
                    mForwardReadinessSeries(i, tabProcesses[i][j].getTimeToReady()); // jesli nie to przesuwamy czas oczekiwania na gotowosc wszystkich procesow
                if (tabProcesses[i][j].getTimeToReady() > 0) // sprawdzamy czy na pewno proces jest gotowy do wykonania
                    continue; // jesli nie to pomijamy go i przechodzimy do kolejnego procesu w serii
                else // wykonujemy proces ktorego zostalo nam najmniej do wykonania
                    mMakeProcess(i, mGetTheShortest(i), 1); // wowczas wykonujemygo  tylko prze okreslony kwant czasu
            }
        } while (mDoneAll(i) == false); // petla kazdej serii konczy sie kiedy zostaja ukonczone wszystkie procesy
        for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach w serii
            tabProcesses[i][j].mCalculateTimeProcessing(); // wyznaczenie czasu calkowitego przetwarzania procesu
    }
    mCalculateAllTotalTimeDoing(); // wywolanie metody obliczajacej sumaryczne czasy wykonywania procesow w kolejnych seriach
    mCalculateAllAverageTimeDoing(); // wywolanie metody obliczajacej srednie czasy wykonywanie procesow w kolejnych seriach
    mCalculateAllTotalTimeProcessing(); // wywolanie metody obliczajacej sumaryczne czasy przetwarzania procesow w kolejnych seriach
    mCalculateAllAverageTimeProcessing(); // wywolanie metody obliczajacej srednie czasy przetwarzania procesow w kolejnych seriach
    mWriteResultsToFile(srt); // wypisanie resultatow do pliku
}

/*
 * bool mReadyAny(typeNumberProcess aSeries)
 */
bool cShedulingAlgorithms::mReadyAny(typeNumberProcess aSeries)
{
    bool vAny = false; // nadanie wartosci poczatkowej zmiennej okreslajacej wystepowanie gotowego procesu
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach w serii
    {
        if ((tabProcesses[aSeries][i].getTimeToReady() == 0) && (tabProcesses[aSeries][i].getTimeToDo() > 0)) // sprawdzamy czy mamy nieukonczony proces gotowy do wykonywania
        {
            vAny = true; // jesli tak to ustawiamy wartosc zmiennej na "true"
            break; // wychodzimy z petli
        }
        else // wszystkie pozostale przypadki
            continue; // przechodzimy do kolejnego cyklu petli
    }
    return vAny; // zwrocenie wartosci
}

/*
 * void mForwardReadinessSeries(typeNumberProcess aSeries, typeTime aTime)
 */
void cShedulingAlgorithms::mForwardReadinessSeries(typeNumberProcess aSeries, typeTime aTime)
{
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach
    {
        if (tabProcesses[aSeries][i].getTimeToReady() > 0) // sprawdzenie czy proces nie jest jeszcze gotowy do wykonania
            tabProcesses[aSeries][i].mForwardTimeReady(aTime); // przesuniecie czasu oczekiwania na gotowosc
    }
}

/*
 * void mMakeProcess(typeNumberProcess aSeries, typeNumberProcess aIndex, typeTime aTime)
 */
void cShedulingAlgorithms::mMakeProcess(typeNumberProcess aSeries, typeNumberProcess aIndex, typeTime aTime)
{
    typeTime vForward; // zmienna pomocnicza stosowana do przesuwania czasow procesow
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach w serii
    {
        if (i == aIndex) // sprawdzamy czy to jest numer procesu, ktory mamy wykonac
            tabProcesses[aSeries][i].mForwardTimeDone(aTime); // jesli tak to go wykonujemy
        else if ((tabProcesses[aSeries][i].getTimeToReady() == 0) && (tabProcesses[aSeries][i].getTimeToDo() == 0)) // sprawdzamy czy proces juz jest w calosci wykonany
            continue; // kontynuujemy sprawdzanie kolejnych procesow
        else if (tabProcesses[aSeries][i].getTimeToReady() > aTime) // sprawdzamy czy proces nie bedzie nawet gotowy
            tabProcesses[aSeries][i].mForwardTimeReady(aTime); // przesuwamy czas oczekiwania na gotowosc do wykonania
        else if ((tabProcesses[aSeries][i].getTimeToReady() == 0) && (tabProcesses[aSeries][i].getTimeToDo() > 0)) // przypadek kiedy proces jest juz gotowy ale jeszcze nie mozemy go wykonac
            tabProcesses[aSeries][i].mForwardTimeWaiting(aTime); // wydluza sie czas oczekiwanie
        else // ostatni przypadek kiedy proces stanie sie gotowy ale nie bedzie go mozna jeszcze wykonac
        {
            vForward = aTime - tabProcesses[aSeries][i].getTimeToReady(); // ustalamy ile czasu proces bedzie czekal na wykonanie
            tabProcesses[aSeries][i].mForwardTimeReady(tabProcesses[aSeries][i].getTimeToReady()); // konczymy jego czas na oczekiwanie
            tabProcesses[aSeries][i].mForwardTimeWaiting(vForward); // zaczynamy oczekiwac na wykonanie (proces jest juz gotowy
        }
    }
}

/*
 * void mMakeProcess(typeNumberProcess aSeries, typeNumberProcess aIndex)
 */
void cShedulingAlgorithms::mMakeProcess(typeNumberProcess aSeries, typeNumberProcess aIndex)
{
    typeTime vForward, vForwardPart; // zmienne pomocnicze stosowane do przesuwania czasow procesow
    vForward = tabProcesses[aSeries][aIndex].getTimeToDo(); // ustalenie ile czasu zostanie do wykonania wskazanego procesu
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach w serii
    {
        if (i == aIndex) // sprawdzamy czy to jest numer procesu, ktory mamy wykonac
            tabProcesses[aSeries][i].mForwardTimeDone(vForward); // jesli tak to go wykonujemy
        else if ((tabProcesses[aSeries][i].getTimeToReady() == 0) && (tabProcesses[aSeries][i].getTimeToDo() == 0)) // sprawdzamy czy proces juz jest w calosci wykonany
            continue; // kontynuujemy sprawdzanie kolejnych procesow
        else if (tabProcesses[aSeries][i].getTimeToReady() > vForward) // sprawdzamy czy proces nie bedzie nawet gotowy
            tabProcesses[aSeries][i].mForwardTimeReady(vForward); // przesuwamy czas oczekiwania na gotowosc do wykonania
        else if ((tabProcesses[aSeries][i].getTimeToReady() == 0) && (tabProcesses[aSeries][i].getTimeToDo() > 0)) // przypadek kiedy proces jest juz gotowy ale jeszcze nie mozemy go wykonac
            tabProcesses[aSeries][i].mForwardTimeWaiting(vForward); // wydluza sie czas oczekiwanie
        else // ostatni przypadek kiedy proces stanie sie gotowy ale nie bedzie go mozna jeszcze wykonac
        {
            vForwardPart = vForward - tabProcesses[aSeries][i].getTimeToReady(); // ustalamy ile czasu proces bedzie czekal na wykonanie
            tabProcesses[aSeries][i].mForwardTimeReady(tabProcesses[aSeries][i].getTimeToReady()); // konczymy jego czas na oczekiwanie
            tabProcesses[aSeries][i].mForwardTimeWaiting(vForwardPart); // zaczynamy oczekiwac na wykonanie (proces jest juz gotowy
        }
    }
}

/*
 * typeNumberProcess mGetLast(typeNumberProcess aSeries)
 */
typeNumberProcess cShedulingAlgorithms::mGetLast(typeNumberProcess aSeries)
{
    typeNumberProcess vIndex = 0; // nadanie wartosci poczatkowej indeksu
    typeTime vTime = (constMaxTime * (constProcesses + 1)); // nadanie wartosci poczatkowej czasu
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach we wskazanej serii
    {
        if ((tabProcesses[aSeries][i].getTimeToReady() > 0) || (tabProcesses[aSeries][i].getTimeToDo() == 0)) // sprawdzamy czy proces jest w ogole gotowy do wykonania albo jest juz wykonany
            continue; // przechowimy do kolejnego cyklu petli
        else // proces jest gotowy do wykonania
        {
            if (tabProcesses[aSeries][i].getTimeWaiting() <= vTime) // jesli czas oczekiwania jest mniejszy niz aktualnie wskazany
            {
                vTime = tabProcesses[aSeries][i].getTimeWaiting(); // nadajemy nowa wartosc czasu
                vIndex = i; // nadajemy nowy indeks procesu, ktory czeka najkrocej
            }
        }
    }
    return vIndex; // zwrocenie wartosci
}

/*
 * typeNumberProcess mGetTheShortest(typeNumberProcess aSeries)
 */
typeNumberProcess cShedulingAlgorithms::mGetTheShortest(typeNumberProcess aSeries)
{
    typeNumberProcess vIndex = 0; // nadanie wartosci poczatkowej indeksu
    typeTime vTime = (constMaxTime * (constProcesses + 1)); // nadanie wartosci poczatkowej czasu
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach we wskazanej serii
    {
        if ((tabProcesses[aSeries][i].getTimeToReady() > 0) || (tabProcesses[aSeries][i].getTimeToDo() == 0)) // sprawdzamy czy proces jest w ogole gotowy do wykonania albo jest juz wykonany
            continue; // przechowimy do kolejnego cyklu petli
        else // proces jest gotowy do wykonania
        {
            if (tabProcesses[aSeries][i].getTimeToDo() < vTime) // jesli czas oczekiwania jest mniejszy niz aktualnie wskazany
            {
                vTime = tabProcesses[aSeries][i].getTimeToDo(); // nadajemy nowa wartosc czasu
                vIndex = i; // nadajemy nowy indeks procesu, ktory czeka najkrocej
            }
        }
    }
    return vIndex; // zwrocenie indeksu
}

/*
 * bool mDoneAll(typeNumberProcess aSeries)
 */
bool cShedulingAlgorithms::mDoneAll(typeNumberProcess aSeries)
{
    bool vAll = true; // nadanie wartosci poczatkowej zmiennej okreslajacej wykonanie wszystkich procesow
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach w serii
    {
        if (tabProcesses[aSeries][i].getTimeToDo() > 0) // sprawdzamy czy mamy proces, ktory jeszcze nie jest ukoczony
        {
            vAll = false; // jesli tak to ustawiamy wartosc zmiennej na "false"
            break; // wychodzimy z petli
        }
        else // w przypadku kiedy proces jest ukonczony
            continue; // przechodzimy do kolejnego cyklu petli
    }
    return vAll; // zwrocenie wartosci
}



/*
 * void mDrawProcesses()
 */
void cShedulingAlgorithms::mDrawProcesses()
{
    typeTime vTime1, vTime2; // zmienne, ktorych wartosci bedziemy losowac
    mResetAllProcesses(); // wyczyszczenie tablicy procesow
    srand(time_t(NULL)); // ustanowienie zmiennej losowej
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystich seriach
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach
        {
            vTime1 = rand() % constMaxTime + 1; // losowanie czasu oczekiwania na gotowosc
            vTime2 = rand() % constMaxTime + 1; // losowanie czasu wykonania
            tabProcesses[i][j].setTimeReadiness(vTime1); // ustanowienie czasu oczekiwania na gotowosc
            tabProcesses[i][j].setTimeDoing(vTime2); // ustanowienie czasu wykonania
        }
    }
}

/*
 * void mResetSeries(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mResetSeries(typeNumberProcess aSeries)
{
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach
        mResetProcess(aSeries, i); // resetowanie wskazanego procesu
}

/*
 * void mResetAllProcesses()
 */
void cShedulingAlgorithms::mResetAllProcesses()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mResetSeries(i); // resetowanie wskazanej serii
}

/*
 * void mReadProcessesFromFile()
 */
void cShedulingAlgorithms::mReadProcessesFromFile()
{
    using namespace std; // zapowiedz wykorzystania elementow standardowej przestrzeni nazw
    mResetAllProcesses(); // wyczyszczenie aktualnej tablicy procesow
    ifstream StreamIn; // utworzenie wejsciowego strumienia plikowego
    StreamIn.open("processes.txt"); // otwarcie strumienia
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach
        {
            StreamIn >> skipws >> tabProcesses[i][j]; // wczytanie pojedynczego procesu
        }
    }
    StreamIn.close(); // zamkniecie strumienia
}

/*
 * void mWriteProcessesToFile()
 */
void cShedulingAlgorithms::mWriteProcessesToFile()
{
    using namespace std; // zapowiedz wykorzystania elementow standardowej przestrzeni nazw
    ofstream StreamOut; // otwarcie wyjsciowego strumienia plikowego
    StreamOut.open("processes.txt"); // otwarcie strumienia
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystich seriach
    {
        for (typeNumberProcess j = 0; j < constProcesses; j++) // przejscie po wszystkich procesach
            StreamOut << tabProcesses[i][j]; // wypisanie procesu
        StreamOut << endl; // nowa seria - nowa linijka tekstu
    }
    StreamOut.close(); // zamkniecie strumienia
}

/*
 * void mPrintAllTimesProcess(typeNumberProcess aSeries, typeNumberProcess aProcess)
 */
void cShedulingAlgorithms::mPrintAllTimesProcess(typeNumberProcess aSeries, typeNumberProcess aProcess)
{
    using namespace std; // zapowiedz wykorzystania elementow standardowej przestrzeni nazw
    cout << "Proces w serii " << aSeries << " o numerze " << aProcess << " :" << endl // wypisanie informacji o serii i numerze procesu w serii
        << "    TimeReadiness: " << tabProcesses[aSeries][aProcess].getTimeReadiness() << endl // wypisanie calkowitego czasu oczekiwania na gotowosc
        << "    TimeReady: " << tabProcesses[aSeries][aProcess].getTimeReady() << endl // wypisanie aktualnego czasu oczekiwania na gotowosc
        << "    TimeToReady: " << tabProcesses[aSeries][aProcess].getTimeToReady() << endl // wypisanie aktualnego czasu pozostalego do oczekiwania na gotowosc
        << "    TimeWaiting: " << tabProcesses[aSeries][aProcess].getTimeWaiting() << endl // wypisanie calkowitego czasu oczekiwania na wykonanie gotowego do wykonania procesu
        << "    TimeDoing: " << tabProcesses[aSeries][aProcess].getTimeDoing() << endl // wypisanie calkowitego czasu wykonania
        << "    TimeDone: " << tabProcesses[aSeries][aProcess].getTimeDone() << endl // wypisanie aktualnego czasu wykonania
        << "    TimeToDo: " << tabProcesses[aSeries][aProcess].getTimeToDo() << endl // wypisanie aktualnego czasu jaki zostal do wykonania
        << "    TimeProcessing: " << tabProcesses[aSeries][aProcess].getTimeProcessing() << endl; // wypisanie calkowitego czasu przetwarzania
}

/*
 * void mPrintAllTimesSeriesProcesses(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mPrintAllTimesSeriesProcesses(typeNumberProcess aSeries)
{
    using namespace std; // zapowiedz wykorzystania elementow standardowej przestrzeni nazw
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach w serii
        mPrintAllTimesProcess(aSeries, i); // wywolanie metody wypisujacej wszystkie czasy wskazanego  procesu
    cout << endl; // przejscie do nowej linii (dla porzadku)
}



/*
 * void mSortingSeriesReadiness(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mSortingSeriesReadiness(typeNumberProcess aSeries)
{
    cProcess Proc; // utworzenie zmiennej pomocniczej
    for (typeNumberProcess i = 0; i < (constProcesses - 1); i++) // przejscie po wszystkich elementach do przedostatniego
    {
        for (typeNumberProcess j = i + 1; j < constProcesses; j++) // przejscie po dalszych elementach
        {
            if (tabProcesses[aSeries][i].getTimeReadiness() > tabProcesses[aSeries][j].getTimeReadiness()) // sprawdzamy czy pierwszy element jest wiekszy
            {
                Proc = tabProcesses[aSeries][i]; // jesli pierwszy element jest wiekszy to sortujemy z zastosowaniem sortowania babelkowego
                tabProcesses[aSeries][i] = tabProcesses[aSeries][j];
                tabProcesses[aSeries][j] = Proc;
            }
        }
    }
}

/*
 * void mSortingAllSeriesReadiness()
 */
void cShedulingAlgorithms::mSortingAllSeriesReadiness()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mSortingSeriesReadiness(i); // wywolanie metody sortowania wskazanej serii
}

/*
 * void mSortingSeriesReadinessAndDoing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mSortingSeriesReadinessAndDoing(typeNumberProcess aSeries)
{
    mSortingSeriesReadiness(aSeries); // sortujemy czasu wedlug czasu oczekiwania na gotowosc
    cProcess Proc; // utworzenie zmiennej pomocniczej
    for (typeNumberProcess i = 0; i < (constProcesses - 1); i++) // przejscie po wszystkich elementach do przedostatniego
    {
        for (typeNumberProcess j = i + 1; j < constProcesses; j++) // przejscie po dalszych elementach
        {
            if (tabProcesses[aSeries][i].getTimeReadiness() == tabProcesses[aSeries][j].getTimeReadiness()) // sprawdzamy czy czasy oczekiwania na gotowosc sa takie same
            {
                if (tabProcesses[aSeries][i].getTimeDoing() > tabProcesses[aSeries][j].getTimeDoing()) // jesli tak to takie procesy sortujemy rosnaco wzgledem czasu wykonywania
                {
                    Proc = tabProcesses[aSeries][i]; // jesli pierwszy element jest wiekszy to sortujemy z zastosowaniem sortowania babelkowego
                    tabProcesses[aSeries][i] = tabProcesses[aSeries][j];
                    tabProcesses[aSeries][j] = Proc;
                }
            }
        }
    }
}

/*
 * void mSortingAllSeriesReadinessAndDoing()
 */
void cShedulingAlgorithms::mSortingAllSeriesReadinessAndDoing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mSortingSeriesReadinessAndDoing(i); // posortowanie wskazanej serii
}



/*
 * void mResetAllTotalTimeDoing()
 */
void cShedulingAlgorithms::mResetAllTotalTimeDoing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mResetTotalTimeDoing(i); // resetowanie wskazanej serii
}

/*
 * void mCalculateTotalTimeDoing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mCalculateTotalTimeDoing(typeNumberProcess aSeries)
{
    mResetTotalTimeDoing(aSeries); // resetowanie wszystkich calkowitych czasow wykonywania procesow
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie po wszystkich procesach w serii
        tabTotalTimeDoing[aSeries] += tabProcesses[aSeries][i].getTimeDoing(); // dodawanie do sumy kolejnych czasow
}

/*
 * void mCalculateAllTotalTimeDoing()
 */
void cShedulingAlgorithms::mCalculateAllTotalTimeDoing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mCalculateTotalTimeDoing(i); // obliczenie calkowitego czasu dzialanie procesow w danej serii
}



/*
 * void mResetAllAverageTimeDoing()
 */
void cShedulingAlgorithms::mResetAllAverageTimeDoing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mResetAverageTimeDoing(i); // resetowanie wskazanej serii
}

/*
 * void mCalculateAllAverageTimeDoing()
 */
void cShedulingAlgorithms::mCalculateAllAverageTimeDoing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mCalculateAverageTimeDoing(i); // obliczenie sredniego czasu wykonywanie procesow we wskazanej serii
}



/*
 * void mResetAllTotalTimeProcessing()
 */
void cShedulingAlgorithms::mResetAllTotalTimeProcessing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mResetTotalTimeProcessing(i); // resetowanie wskazanego calkowitego czasu przetwarzania
}

/*
 * void mCalculateTotalTimeProcessing(typeNumberProcess aSeries)
 */
void cShedulingAlgorithms::mCalculateTotalTimeProcessing(typeNumberProcess aSeries)
{
    mResetTotalTimeProcessing(aSeries); // resetowanie wskazanego calkowitego czasu przetwarzania
    for (typeNumberProcess i = 0; i < constProcesses; i++) // przejscie  po wszystkich procesach w serii
        tabTotalTimeProcessing[aSeries] += tabProcesses[aSeries][i].getTimeProcessing(); // dodanie do sumy czasu przetwarzanie kolejnego procesu
}

/*
 * void mCalculateAllTotalTimeProcessing()
 */
void cShedulingAlgorithms::mCalculateAllTotalTimeProcessing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mCalculateTotalTimeProcessing(i); // obliczenie calkowitego czasu przetwarzania procesow w danej serii
}



/*
 * void mResetAllAverageTimeProcessing()
 */
void cShedulingAlgorithms::mResetAllAverageTimeProcessing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mResetAverageTimeProcessing(i); // resetowanie sredniego czasu przetwarzania w danej serii
}

/*
 * void mCalculateAllAverageTimeProcessing()
 */
void cShedulingAlgorithms::mCalculateAllAverageTimeProcessing()
{
    for (typeNumberProcess i = 0; i < constSeries; i++) // przejscie po wszystkich seriach
        mCalculateAverageTimeProcessing(i); // obliczenie sredniego czasu przetwarzania procesow we wskazanej serii
}



/*
 * void mWriteResultsToFile(enumAlgorithms aAlgorithm)
 */
void cShedulingAlgorithms::mWriteResultsToFile(enumAlgorithms aAlgorithm)
{
    using namespace std; // zapowiedz wykorzystania elementow standardowej przestrzeni nazw
    // fcfs, lcfs, sjf, rr, srt
    ofstream StreamOut; // zdefiniowanie strumienia
    switch (aAlgorithm) // wybranie odpowiedniego alogorytmu
    {
    case fcfs: StreamOut.open("resultsFCFS.txt"); break; // otwarcie strumienia dla wynikow algorytmu FCFS
    case lcfs: StreamOut.open("resultsLCFS.txt"); break; // otwarcie strumienia dla wynikow algorytmu LCFS
    case sjf: StreamOut.open("resultSJF.txt"); break; // otwarcie strumienia dla wynikow algorytmu SJF
    case rr: StreamOut.open("resultsRR.txt"); break; // otwarcie strumienia dla wynikow algorytmu Round-Robin
    case srt: StreamOut.open("resultsSRT.txt"); break; // otwarcie strumienia dla wynikow algorytmu SRT
    }
    for (typeNumberProcess i = 0; i < constSeries; i++)
    {
        StreamOut << "Average time doing " << setw(4) << i + 1
            << " series: " << tabAverageTimeDoing[i] << "     "
            << "Average time processing " << setw(4) << i + 1
            << " series: " << tabAverageTimeProcessing[i] << endl;
    }
    StreamOut.close();
}

/********** PUBLIC: END **********/

/* cshedulingalgorithms.cpp */
/********** END_OF_FILE **********/
