#include<iostream>
#include<fstream>
#include<string>
#include<chrono>

using namespace std;
using namespace chrono;
fstream filter(fstream& originalFile, string name){
  fstream newFile;
  newFile.open(name, ios::out);
  string row;
  while(originalFile.good()){
    getline(originalFile, row);
    if(row[row.length()-1]=='0' || row[row.length()-1]=='2' || row[row.length()-1]=='3' || row[row.length()-1]=='1' || row[row.length()-1]=='4' || row[row.length()-1]=='5' || row[row.length()-1]=='6' || row[row.length()-1]=='7' || row[row.length()-1]=='8' || row[row.length()-1]=='9'){
      newFile<<row<<endl;
    }
  }
  return newFile;
}

int main(){
  fstream file;
  string name1, name2;
  cin>>name1>>name2;
  file.open(name1, ios::in);
  auto begin = high_resolution_clock::now();
  file = filter(file, name2);
  auto end = high_resolution_clock::now();
  auto elapsed = duration_cast<milliseconds>(end-begin);
  cout<<"Time of operation: "<<elapsed.count()<<" miliseconds"<<endl;
}
