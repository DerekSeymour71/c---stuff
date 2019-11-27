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


/* reminder C++ is case sensitive */

using namespace std;

void output(string str){
  cout<<str << endl;
}

typedef bitloop(bool bit);


class BitArray{
   
   private:
      int fValue;
      int fCount;


   protected:
     bool checkIdx(int idx){
       return (idx <= this->fCount); 
     }

   public:

   void forEach(const bitloop loop){
     for (int i = 0; i<=fCount;i++){
        loop(this->isSet(i));  
     }   
   }


   void setValue(int value){
        fValue = value;
        fCount = floor(log2(this->fValue))+1; //return the number of bits
   }

   int getValue(){
       return this->fValue;
   }
  
   void setMask(int mask){
       fMask = mask;
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
 
 
//using a class instead of this solution. (to help me with classes and bitshifting)
int binarygap(int N) {

    
    /*int numBits = bitCount(N); //return the number of bits
    
     

    bool foundOne = false;
    int maximumGap = 0;
    int possibleGap = 0;
     
    
    for (int i=0; i<numBits; i++) {
        // find a 0
        bit = getBit(N,i);
        
        if ( foundOne && ! (isZero(N,i))) {
            possibleGap++;
        } else if ((N & (1<<i))) {
            // If we found a one, set the gap length and reset the
            // current counter
            if (foundOne) {
                if (possibleGap > maximumGap) {
                    maximumGap = possibleGap;
                }
                possibleGap = 0;
            }
            foundOne = true;
        }
    }
    
    return maximumGap; */
}
 
 


//          16  8  4  2  1 
//           1  1  1  1  1 
int main()
{
   //output("binary gap:" + to_string(binarygap(10)));   
   try
   {
      BitArray bits(20);
      output("Count:" + to_string(bits.getCount()));
      output("Value:" + to_string(bits.getValue()));
      output("bit 4:" + to_string(bits.isSet(4)));   
      output("bit 2:" + to_string(bits.isSet(2))); 
      output("bit 3:" + to_string(bits.isSet(3))); 


     /* bits.forEach([](bool on) {   --stuck here with lamba i can't get my head around the syntax
         
        }); */


      //output("bit 6:" + to_string(bits.getOn(6)));  exception idx out of bound
       
      
   }
   catch(const char* msg)
   {
       std::cerr << msg << '\n';
   }
   
    

}  


 



