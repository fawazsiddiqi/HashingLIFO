//METHOD 1

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const int arraySize =4000037;
long long arrayMain[arraySize];

long checkNum(long num){
    
    num = abs(num % arraySize);
    
    return num;
}

int main() {
    long long temporary = 0;
    long long position;
    int counter = 0;
    ifstream in;
    
    in.open("progr3-data-set.txt");
    
    clock_t begin = clock();
    for (int i=0; i<arraySize; i++) {
        arrayMain[i] = 0;
    }
    
    for (int i = 0; i < 1000000; i++) {
        in >> temporary;
        
        position = checkNum(temporary);
        
        if (arrayMain[position] == 0)
        {
            arrayMain[position] = temporary;
        }
        else if (arrayMain[position] != 0)
        {
            for (long j = position; j < arraySize ;j++)
            {
                if (arrayMain[j] == 0) {
                     arrayMain[j] = arrayMain[position];
                    arrayMain[position] = temporary;
                    break;
                }
               
            }
        }
    }
    clock_t end = clock();
    
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout <<"Time Taken: " << elapsed_secs << " Seconds" <<endl;
    for (int i=0; i<arraySize; i++) {
      if (arrayMain[i] != 0)
      {
          counter ++;
      }
    }
    cout << counter << " values stored" << endl;
    
    in.close();
    
    return 0;
}
