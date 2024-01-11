using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
  // Write your code here.
  int rows = matrix.size();
  int cols = matrix[0].size(); 
  
  
  vector<vector<int>> transpose(cols, vector<int>(rows));
  
  for(int i = 0; i < rows; i++){
      for(int z = 0; z < cols; z++){
          transpose[z][i] = matrix[i][z];
      }
      
  }
  return transpose;
}
