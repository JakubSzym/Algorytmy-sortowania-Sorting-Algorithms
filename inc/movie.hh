#ifndef MOVIE_HH_INCLUDED
#define MOVIE_HH_INCLUDED

#include<iostream>
#include<fstream>
#include<string>

/*
 *Plik zawiera klase Movie, ktora jest implementacja filmu z bazy danych
 *Ponadto w pliku znajduja sie prototypy algorytmow sortowania, ktore
 *mozna stosowac na tablicach obiektow klasy Movie
 */

class Movie{
private:
  std::string title; //tytul filmu
  double rating; //ranking
public:
  std::string getTitle(){ return title;} //metoda zwracająca tytul
  double& getRating(){return rating;}    //metoda zwracajaca ranking

  void setTitle(std::string newT){title = newT;} //metoda ustawia nowy tytul
  void setRating(double newR){ rating = newR;}   //metoda ustawia nowy ranking

  /*
   *Przeciazenie operatora przypisania dla klasy Movie
   */
  void operator=(Movie movie);
};

/*
 *Przeciazenie operatora czytania z pliku dla klasy Movie
 *Argumenty:
 *  fstream& file - uchwyt do pliku (przez referencje)
 *  Movie& movie - obiekt klasy Movie przekazany przez referencje
 *Zwraca:
 *  obiekt typu fstream przez referencje
 */
std::fstream& operator>>(std::fstream& file, Movie& movie);

/*
 *Przeciazenie operatora pisania na ekran dla klasy Movie
 *Argumenty:
 *  ostream& screen - strumien wyjsciowy
 *  Movie& movie - obiekt klasy Movie przekazany przez referencje
 *Zwraca:
 *  strumien wyjsciowy (przez referencje)
 */
std::ostream& operator<<(std::ostream& screen, Movie& movie);

/*
 *Funkcja liczy srednia arytmetyczna rankigow zawartych w tablicy obiektow klasy Movie
 *Argumenty:
 *  Movie* array - wskaznik na tablice obiektow klasy Movie
 *  int count - liczba danych do liczenia sredniej
 */
double average(Movie* array, int count);

/*
   *partition - sluzy do podzialu struktury w ramach sortowania Quick Sort
   *Argumenty;
   *  Movie* array - wskaznik na tablice obiektow klasy Movie
   * int p - piwot
   * int r - liczba elementow do podzialu
*/
int partition(Movie* array, int p, int r);
 /*
   *merge - sluzy do scalania struktury sortowanej algorytmem Merge Sort
   *Argumenty:
   *  Movie* array - wskaznik na tablice obiektow klasy Movie
   *  int low - poczatek przedzialu sortowania
   *  int mid - srodek przedzialu sortowania
   *  int high - koniec przedzialu sortowania
   */
void merge(Movie* array, int low, int high, int mid);
/*
 *Funkcja pomocnicza przy budowaniu kopca
 *int heapSize - rozmiar kopca
 *int index - indeks wezla
 */
void heapify(Movie* array, int heapSize, int index);

 /*
   *quickSort - algorytm sortowania szybkiego
   *Argumenty:
   *  Movie* array - wskaznik na tablice obiektow klasy Movie
   *  int p - piwot
   *  int r - koniec przedzialu sortowania
*/
void quickSort(Movie* array, int p, int r);
  /*
   *mergeSort - algorytm sortowania przez scalanie
   *Argumenty:
   *  Movie* array - wskaznik na tablice obiektow klasy Movie
   *  int low - poczatek przedzialu sortowania
   *  int high - koniec przedzialu sortowania
*/
void mergeSort(Movie* array, int low, int high);
  /*
   *heapSort - algorytm sortowania przez kopcowanie
   *Argumenty:
   *  Movie* array - wskaznik na tablice obiektow klasy Movie
   *  int count - liczba elementow do posortowania
   */
void heapSort(Movie* array, int count);
  /*
   *insertionSort - algorytm sortowania przez wstawianie
   *Argumenty:
   *  Movie* array - wskaznik na tablice obiektow klasy Movie
   *  int count - liczba elementow do posortowania
   */
void insertionSort(Movie* array, int count);
  /*
   *introSort - algorytm sortowania introspektywnego
   *Argumenty:
   *  Movie* array - wskaznik na tablice obiektow klasy Movie
   *  int count - liczba elementow do posortowania
   */
void introSort(Movie* array, int count);
#endif //MOVIE_HH_INCLUDED
