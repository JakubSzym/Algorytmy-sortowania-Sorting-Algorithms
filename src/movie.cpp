#include "movie.hh"

#include<cmath>
using namespace std;



fstream& operator>>(fstream& file, Movie& movie){
  bool end = false;
  string word;
  char sign;
  if(file.good()){
    while(sign!=','){file>>sign;}
    file>>sign;
    word.append(1,sign);
    if(sign=='"'){
      while(!end){
        file>>sign;
        word.append(1,sign);
        while(sign!='"'){
	  file>>sign;
	  word.append(1,sign);
        }
        file>>sign;
	if(sign == ','){
          movie.setTitle(word);
          file>>movie.getRating();
	  end = true;
	}
      }
    }else{
       while(sign!=','){
         file>>sign;
         word.append(1,sign);
      }
      movie.setTitle(word);
    
      file>>movie.getRating();
    }
  }
  return  file;
}


ostream& operator <<(ostream& screen, Movie& movie){
  screen<<movie.getTitle()<<" "<<movie.getRating();
  return screen;
}

void Movie::operator=(Movie movie){
  this->setRating(movie.getRating());
  this->setTitle(movie.getTitle());
}

double average(Movie* array, int count){
  long double sum=0;;
  for(int i=0;i<count;i++){
    sum += array[i].getRating();
  }
  double result = sum/count;
  return result;
}

int partition(Movie* array, int p, int r){
  Movie x = array[p];
  int i = p, j = r;
  Movie w;
  //podzial struktury
  while(true){
    while(array[j].getRating() > x.getRating()){
      j--;
    }
    while(array[i].getRating() < x.getRating()){
      i++;
    }
    //jezeli cos zostalo po niewlasciwej stronie piwota - zamien
    if(i<j){
      w = array[i];
      array[i]=array[j];
      array[j]=w;
      i++;
      j--;
    }else{
      return j; //zwraca punkt podzialu
    }
  }
}


void quickSort(Movie* array, int p, int r){
  int q;
  if(p < r){
    q=partition(array, p,r); //podzial na dwie czesci
    quickSort(array, p,q); //wywolanie quick sort dla pierwszej czesci
    quickSort(array, q+1,r); //wywolanie dla drugiej czesci
  }
}


 void merge(Movie *array, int low, int high, int mid){
   int i, j, k;
   Movie *help = new Movie[(high-low+1)]; //utworzenie tablicy pomocniczej
   //zmienne pomocnicze
   i=low;
  k=0;
  j=mid+1;
  //podzial struktury 
  while(i<=mid && j<=high){
    if(array[j].getRating() < array[i].getRating()){
      help[k]=array[j];
      j++;
    }else{
      help[k]=array[i];
      i++;
    }
    k++;
  }
  //przeniesienie odpowiednio pozostalych elementow
  if(i<=mid){
    while(i<=mid){
      help[k]=array[i];
      k++;
      i++;
    }
  }else{
    while(j<=high){
      help[k]=array[j];
      k++;
      j++;
    }
  }
  //Odpowiednie przepisanie wartosci z tablicy pomocniczej
  for(i=0; i<high-low; i++){
    array[low+i]=help[i];
  }
  delete[] help; //zwolnienie pamieci
   
}

 void mergeSort(Movie* array, int low, int high){
   int mid; //srodek przedzialu sortowania
  if(low<high){
    mid=(low+high)/2;
    mergeSort(array,low,mid); //wywolanie od poczatku do srodka
    mergeSort(array,mid+1,high); //wywolanie od srodka do konca
    merge(array,low,high,mid);  //podzial struktury
  }
}

 void heapify(Movie* array, int heapSize, int index){
  int leftSide = (index+1)*2-1;
  int rightSide = (index+1)*2;
  int largest=0;

  //tworzenie zaleznosci w kopcu
  
  if(leftSide<heapSize && array[leftSide].getRating() > array[index].getRating())
    largest = leftSide;
  else
    largest = index;

  if(rightSide<heapSize && array[rightSide].getRating() > array[largest].getRating())
    largest = rightSide;

  if(largest != index){
    Movie t = array[index];
    array[index] = array[largest];
    array[largest] = t;

    heapify(array, heapSize, largest); //wywolanie rekurencyjne
  }
}


 void heapSort(Movie* array, int count){
   int heapSize = count; //rozmiar kopca
  //budowanie kopca
  for(int i=(heapSize-1)/2;i>=0;--i){
    heapify(array, heapSize, i);
  }
  //wlasciwe sortowanie
  for(int i = count-1;i>0;--i){
    Movie t = array[i];
    array[i] = array[0];
    array[0]=t;

    //tworzenie mniejszego kopca
    --heapSize;
    heapify(array,heapSize,0);
  }
}

 void insertionSort(Movie* array, int count){
  int j;
  Movie k;
  for(int i=1;i<count;i++){
    k = array[i];
    j=i;
    while(j>0 && array[j-1].getRating() > k.getRating()){
      array[j] = array[j-1];
      j--;
    }
    array[j] = k;
  }
}

 void introSort(Movie *array, int count){
   int partSize = partition(array, 0, count-1);
  if(partSize < 16){
    insertionSort(array, count);
  }
  else if(partSize > 2*log(count)){
    heapSort(array, count);
  }
  else{
    quickSort(array, 0, count-1);
  }
}



 

 
