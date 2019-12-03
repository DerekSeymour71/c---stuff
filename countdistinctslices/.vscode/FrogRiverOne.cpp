
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

int solution(int X, vector<int> &A) {
    output("Solution called"); 
    int result = -1;
    
    if (X > 0){ 
      vector<bool> leafs(X,false);  
      int n = A.size();
      int leafTotal = 0;

      for (int i=0; i<n; i++){
          if (((A[i] > 0) & (A[i] <= X)) & (!leafs[A[i]])){
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



