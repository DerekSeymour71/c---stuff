/* this problem is a bit like bingo, waiting for all your numbers to come out - when you have crossed them all off, you win */
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

  


void output(string str){
  cout<<str << endl;
}

//probably a few other checks you can perform, but runs in 0(n)
int solution(int X, vector<int> &A) {
    output("Solution called"); 
    int result = -1;
    
    if (X > 0){  //X is the target leaf to jump to, if it's 0 there is no jump 
      vector<bool> leafs(X,false);  //set all the leafs to false (i.e no leafs have fallen across the river)
      int n = A.size();
      int leafTotal = 0;  //tracking how many distinct leafs in any sequence up to X have falled so far

      for (int i=0; i<n; i++){
          if (((A[i] > 0) & (A[i] <= X)) & (!leafs[A[i]])){  //this line is about testing the array idx, and whether the leaf array value is previously set true
              leafs[A[i]] = true;
              
               output("Marked true : " + to_string(i) + ":" + to_string(A[i])); 
              
              leafTotal ++;
          } 
          
          if(leafTotal ==X){
              result = i;
              break;
          }
          
      }
    }  
    return result;
}


int main(){

   vector<int> items = {1,3,1,4,2,3,5,4};
  // vector<int> items = {2, 2, 2, 2, 2};
    
   

 output("frog cross :" + to_string(solution(5,items)));
}



