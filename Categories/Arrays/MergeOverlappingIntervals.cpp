#include <vector>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  // Write your code here.
    int start = intervals[0][0], end = intervals[0][1];
    vector<vector<int>> mergedIntervals;

    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i][0] <= end) end = intervals[i][1]; //if it overlaps
        else{
            mergedIntervals.push_back(vector<int>{start,end});
            start = intervals[i][0];
            end = intervals[i][1];

        }
        if(i == intervals.size()-1){
            mergedIntervals.push_back(vector<int>{start,end});
        }

    }
    return mergedIntervals;
}
