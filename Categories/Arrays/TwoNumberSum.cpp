#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here
 vector<int> sums;
    for(int i = 0; i< array.size()-1; i++)
        for(int z = i+1; z<array.size(); z++){
            if (array[i] + array[z] == targetSum){
                //if item not found
                if (!(find(sums.begin(), sums.end(), array[i]) != sums.end())) sums.push_back(array[i]);
                if (!(find(sums.begin(), sums.end(), array[z]) != sums.end())) sums.push_back(array[z]);
            }
        }

        return sums;
}
