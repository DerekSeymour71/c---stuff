/* codility problem for max counters, currently has a performance problem on max counters, and large numbers of them */


#include <iostream> /* console stuff */
#include <cstdlib>  /* standard lib */
#include <string>
#include <cstring>
#include <limits>   
#include <vector>  /*when size of array not known, can use push_back, for example */
#include <sstream> /* string streams */
#include <numeric> /* sequences of values */
#include <ctime>   /* time, baby */
#include <cmath>   /* numbers, yo */
#include <assert.h>  /* assertions */
#include <functional>
#include <bits/stdc++.h>

using namespace std;

     /* A[0] = 3      
        A[1] = 4
        A[2] = 4
        A[3] = 6
        A[4] = 1
        A[5] = 4
        A[6] = 4

    */
    
    
    /* n = 5    5 counter array
        (0, 0, 1, 0, 0)   A[i]= 3(-1)     0++   
        (0, 0, 1, 1, 0)   A[i]= 4(-1)     0++ 
        (0, 0, 1, 2, 0)   A[i]= 4(-1)     1++ 
        
        (2, 2, 2, 2, 2)   A[i]= 6         n + 1 so set all counters to current max counter (i.e. 2 current max)
        
        need here to avoid iterating over all counters....to max perf
        
        (3, 2, 2, 2, 2)   A[i]= 1(-1)     2++
        (3, 2, 2, 3, 2)   A[i]= 4(-1)     4++
        (3, 2, 2, 4, 2)   A[i]= 4(-1)     4++

    */


   





   
    

void output(string str){
  cout<<str << endl;
}

vector<int> solution(int N, vector<int> &A){
   vector<int> counters(N,0);  
   
   int n = A.size();

   int max = 0;

   int counteridx = -1;


   if ((n>0) & (N>0)) {  //number of increments/decrements etc
     
     for (int i=0; i<n; i++){
           counteridx = A[i]-1;          
        
            if (A[i] == (N+1)){  //increase all counters to maximum value of any counter
            
              fill(counters.begin(), counters.end(), max);  //this is a performance problem

            }
            else //increment the counter at A[i]
            {
              counters[counteridx]++;  
              if (counters[counteridx] > max) {
                  max = counters[counteridx];
               }
        
            } 

        }

   }

   return counters;
};


int main(){
   vector<int> items = {3,4,4,6,1,4,4};
   vector<int> counters{};


   counters = solution(5,items);
   int n = counters.size();

   for (int i=0; i<n; i++){
     output("Counter " + to_string(i) + ":" + to_string(counters[i]));
   } 
 


   return 0; 

}

 
