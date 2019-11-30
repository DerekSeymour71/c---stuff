//solution to codility binary gap problem, which passed 100% of test cases.


//note: a learning unit...I'm not recommending using classes here for simple things, I just want to know how classes work in C++
//how to have events, etc, and using a bit array seemed like a nice way to keep me interested.





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


/* reminder C++ is case sensitive */

using namespace std;

void output(string str){
  cout<<str << endl;
}

//typedef void bitloop(bool bit, int idx);
 
typedef const std::function<void(bool, int)> bitloop;




class BitArray{
   
   private:
      int fValue;
      int fCount;
      int fMask;


   protected:
     bool checkIdx(int idx){
       return (idx <= this->fCount); 
     }

     

   public:


   //set mask  

   void setMask(int mask){
       fMask = mask;
   }



   void forEach(const bitloop loop){
     for (int i = 0; i<=fCount-1;i++){
        loop(this->isSet(i),i);  
     }   
   }


   void setValue(int value){
        fValue = value;
        fCount = floor(log2(this->fValue))+1; //return the number of bits
   }

   int getValue(){
       return this->fValue;
   }

   BitArray(int value){
     this->setValue(value);
   }


   int getCount(){
      return fCount; //return the number of bits
      //output("numb bits" + to_string(numBits));
    }

   bool isSet(int idx){
     if (this->checkIdx(idx)){  //check the idx....raise exception
         return this->fValue & (1<<idx);  
     }
     else
     {
         throw "idx out of bounds";
     }
   }
    
    

 };
 
 

int solution(int N) {
    BitArray bits(N);
   int score = 0;
   int runningTotal = 0;
   bool startbit = false;
   
   bits.forEach([&](bool on, int i){ 
         // output("index" + to_string(i) + ':' + to_string(on));
          
          
         if(!startbit){(startbit = on);}; 
         //output("start bit :" + to_string(startbit));
         
         if((!on) && (startbit)){
                      
           runningTotal++; 
           
         }
         else{
            
           if(runningTotal>0) { 
              if (runningTotal > score)
              {
                score = runningTotal;
              }
           runningTotal = 0;} 

         }
         
         //output("score :" + to_string(score));
      });
    
    return score;

}
