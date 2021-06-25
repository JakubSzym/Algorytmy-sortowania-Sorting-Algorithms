#include "driver.hh"

using namespace std;
using namespace chrono;

#define SET_1 10000
#define SET_2 100000
#define SET_3 500000
#define ALL 0

int main(){
    fstream file;
    
    driver(file, SET_1);
    driver(file, SET_2);
    driver(file, SET_3);
    driver(file, ALL);
}
