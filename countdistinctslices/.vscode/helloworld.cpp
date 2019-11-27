#include <iostream> /* console stuff */
#include <cstdlib>  /* standard lib */
#include <string>   
#include <limits>   
#include <vector>  /*when size of array not known, can use push_back, for example */
#include <sstream> /* string streams */
#include <numeric> /* sequences of values */
#include <ctime>   /* time, baby */
#include <cmath>   /* numbers, yo */
#include <assert.h>  /* assertions */


/* reminder C++ is case sensitive */

using namespace std;


 

int solution(int N) {

    int numBits = floor(std::log2(N))+1;

    bool foundOne = false;
    int maximumGap = 0;
    int possibleGap = 0;
    
    for (int i=0; i<numBits; i++) {
        // find a 0
        if ( foundOne && !(N & (1<<i))) {
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
    
    return maximumGap;
}
 



   
int main()
{


}  


 



