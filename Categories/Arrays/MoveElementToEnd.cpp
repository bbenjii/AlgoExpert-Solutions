#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  // Write your code here.

    int lo = 0, hi = array.size()-1;
    
    while(lo < hi){
       if(array[lo]==toMove && array[hi]!= toMove){
            array[lo] = array[hi];
            array[hi] = toMove;
        }
      
        if(array[lo] != toMove) lo++; //if low pointer is not integer keep noving forwards
        if (array[hi] == toMove) hi--; //if hi pointr is integer keeping moving backwards
           
    }
    
    return array;}
