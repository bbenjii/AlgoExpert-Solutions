#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
  vector<int> square= ;
  for(int i = 0; i < array.size(); i++){
    square.push_back(array[i]*array[i]);
  }
  return square;
}
