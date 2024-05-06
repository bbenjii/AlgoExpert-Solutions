/*
Write a function that takes in an array of integers and returns the number of inversions in the array. An inversion occurs if for any valid indices and j, i<j and array[i] > array[j].
For example, given array = [3, 4, 1, 2], there are 4 inversions. The following pairs of indices
represent inversions: Lo, 21, LO, 31, 11, 21, 11, 31.
Intuitively, the number of inversions is a measure of how unsorted the array
*/

#include <vector>
using namespace std;


void mergeSort(int &inversionCount, vector<int> &array, vector<int> &aux, int lo, int hi){
    if(hi <= lo) {
        return;
    }

    //find mid
    int mid = (lo+hi)/2;

    //sort each subarray
    mergeSort(inversionCount,array,aux,lo, mid);
    mergeSort(inversionCount, array,aux, mid+1, hi);

    //copy array
    for(int i = lo; i <= hi; i++){
        aux[i] = array[i];
    }

    //pointers
    int i = lo, j = mid+1;

    //merge
    for (int k = lo; k <=hi;k++){
       if(i > mid) array[k] = aux[j++];
       else if(j > hi) array[k] = aux[i++];
       else if(aux[i] <= aux[j]) array[k] = aux[i++];
       else {
           array[k] = aux[j++];
           int inversions = 1+mid-i;
            inversionCount += inversions;}
    }

}


int countInversions(vector<int> &array) {
    // Write your code here.
    vector<int> aux(array.size());

    int inversionCount= 0;

    mergeSort(inversionCount, array, aux, 0, array.size()-1);

    return inversionCount;
}
