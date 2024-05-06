#include <vector>
using namespace std;

vector<int> mergeSort(vector<int> array) {
  // Write your code here.
  
    //if the array size is 1, its already sorted
    if(array.size() == 1) return array;

    //divide array into two
    int mid = array.size()/2;
    vector<int> subarray1(array.begin(), array.begin()+mid);
    vector<int> subarray2(array.begin() + mid, array.end());
    
    //sort two subarrays
    subarray1 = mergeSort(subarray1);
    subarray2 = mergeSort(subarray2);

    //merge two subarrays
    int lo = 0;
    int hi = 0;
    for (int i = 0; i < array.size(); i++){
        if(lo >= subarray1.size()) array[i] = subarray2[hi++];
        else if (hi >= subarray2.size()) array[i] = subarray1[lo++];
        else if(subarray1[lo] <= subarray2[hi]) array[i] = subarray1[lo++];
        else array[i] = subarray2[hi++];
    }
    
    return array;
  
}
