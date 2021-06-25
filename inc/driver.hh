#ifndef DRIVER_HH_INCLUDED
#define DRIVER_HH_INCLUDED

#include "movie.hh"
#include<fstream>
#include<iostream>
#include<chrono>

/*
 *Funkcja wykonuje sortowanie konkretnej ilosci danych z pliku
 *Argumenty:
 *  fstream& file - uchwyt do pliku (przez referencje)
 *  int set - liczba danych do posortowania
 */
void driver(std::fstream& file, int set);

#endif //DRIVER_HH_INCLUDED
