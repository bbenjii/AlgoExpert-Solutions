#include <vector>

using namespace std;

vector<int> zigzagTraverse(vector<vector<int>> array) {
  // Write your code here.
    vector<int> elements;

    int x_max = array.size(), y_max = array[0].size();
    int x = 0, y = 0;
    bool down = true;

    while(x < x_max && y < y_max){
        elements.push_back(array[x][y]);

        if(down){

            if(x == x_max-1){
                y +=1;
                down = false;
            }
           else if (y == 0){
                x += 1;
                down = false;
            }
            else{
                x +=1;
                y -=1;
            }
        }
        else if (!down){
            if(y == y_max-1){
                x +=1;
                down = true;
            }
            else if(x == 0){
                y +=1;
                down = true;
            }
            else{
                x -=1;
                y +=1;
            }
        }
    }

    return elements;
}
