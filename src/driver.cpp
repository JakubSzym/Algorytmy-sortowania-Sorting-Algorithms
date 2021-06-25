#include "driver.hh"

using namespace std;
using namespace chrono;

void driver(fstream& file, int set){
  Movie movie;
    if(set!=0){
    cout<<"Number of elements:"<<set<<endl;

    file.open("projekt2_dane.csv",ios::in);
  
    Movie* q_1 = new Movie[set];
    for(int i=0; i<set; i++){
      file>>movie;
      q_1[i] = movie;
    }
    cout<<"________________________________________"<<endl;
    auto begin = high_resolution_clock::now();
    quickSort(q_1, 0, set-1);
    auto end = high_resolution_clock::now();
    auto elapsed = duration_cast<milliseconds>(end-begin);
    cout<<"Quick Sort"<<endl;
    cout<<"Time of sorting: "<< elapsed.count()<<" milliseconds"<<endl;
    cout<<"Average rating: "<<average(q_1, set)<<endl;
    cout<<"Median: "<<q_1[set/2].getRating()<<endl;
    file.close();
    delete[] q_1;

    file.open("projekt2_dane.csv", ios::in);
    
    Movie *q_2 = new Movie[set];

    for(int i=0;i<set;i++){
      file>>movie;
      q_2[i] = movie;
    }
    cout<<"__________________________________________"<<endl;
    begin = high_resolution_clock::now();
    introSort(q_2, set);
    end = high_resolution_clock::now();
    elapsed = duration_cast<milliseconds>(end-begin);
    cout<<"Intro Sort"<<endl;
    cout<<"Time of sorting: "<< elapsed.count()<<" milliseconds"<<endl;
    cout<<"____________________________________________"<<endl;
    file.close();
    delete[] q_2;
      
    file.open("projekt2_dane.csv", ios::in);
    
    Movie *q_3 = new Movie[set];
    
    for(int i=0;i<set;i++){
      file>>movie;
      q_3[i] = movie;
    }
    cout<<"__________________________________________"<<endl;
    begin = high_resolution_clock::now();
    heapSort(q_3, set);
    end = high_resolution_clock::now();
    elapsed = duration_cast<milliseconds>(end-begin);
    cout<<"Heap Sort"<<endl;
    cout<<"Time of sorting: "<< elapsed.count()<<" milliseconds"<<endl;
    cout<<"____________________________________________"<<endl;
    file.close();
    delete[] q_3;

    }else{
     set = 962903;
     string help;
     file.open("projekt2_dane.csv", ios::in);
     Movie* q_1 = new Movie[set];
    for(int i=0;i<set;i++){
          file>>movie;
          q_1[i] = movie;
     }
    cout<<"Number of elements: "<<set<<endl;
    cout<<"________________________________________"<<endl;
    auto begin = high_resolution_clock::now();
    quickSort(q_1, 0, set-1);
    auto end = high_resolution_clock::now();
    auto elapsed = duration_cast<milliseconds>(end-begin);
    cout<<"Quick Sort"<<endl;
    cout<<"Time of sorting: "<< elapsed.count()<<" milliseconds"<<endl;
    cout<<"Average rating: "<<average(q_1, set)<<endl;
    cout<<"Median: "<<q_1[set/2].getRating()<<endl;
    file.close();
    delete[] q_1;

    file.open("projekt2_dane.csv", ios::in);
    
    Movie *q_2 = new Movie[set];
    
    for(int i=0;i<set;i++){
      file>>movie;
      q_2[i] = movie;
    }
    cout<<"__________________________________________"<<endl;
    begin = high_resolution_clock::now();
    introSort(q_2, set);
    end = high_resolution_clock::now();
    elapsed = duration_cast<milliseconds>(end-begin);
    cout<<"Intro Sort"<<endl;
    cout<<"Time of sorting: "<< elapsed.count()<<" milliseconds"<<endl;
    cout<<"____________________________________________"<<endl;
    file.close();
    delete[] q_2;
      
    file.open("projekt2_dane.csv", ios::in);
    
    Movie *q_3 = new Movie[set];
    
    for(int i=0;i<set;i++){
      file>>movie;
      q_3[i] = movie;
    }
    cout<<"__________________________________________"<<endl;
    begin = high_resolution_clock::now();
    heapSort(q_3, set);
    end = high_resolution_clock::now();
    elapsed = duration_cast<milliseconds>(end-begin);
    cout<<"Heap Sort"<<endl;
    cout<<"Time of sorting: "<< elapsed.count()<<" milliseconds"<<endl;
    cout<<"____________________________________________"<<endl;
    file.close();
    delete[] q_3;
    }
}
