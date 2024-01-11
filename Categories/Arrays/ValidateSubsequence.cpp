using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
  
    if(array.size() < sequence.size()) return false;
    int pos = -1;
    for(int i = 0; i < sequence.size(); i++){
        bool found = false;
        for (int z = pos+1; z < array.size(); z++) {
            if (sequence[i] == array[z]) {
                pos = z;
                found = true;
                break;
            }
        }
        if(found == false) return false; 
    }
    return true;
}
