using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

BST *minHeightBst(vector<int> array) {
    // Write your code here.
   if(array.empty()) return nullptr;

    int median = (array.size()-1)/2;
    BST * node = new BST(array[median]);
//    BST node(array[median]) ;


    //make left and right sub array
    vector<int> leftArray;
    vector<int> rightArray;

    for (int i = 0; i < median; i++)leftArray.push_back(array[i]);
    for (int i = median+1; i < array.size(); i++)rightArray.push_back(array[i]);

    node->left = minHeightBst(leftArray);
    node->right = minHeightBst(rightArray);

    return node;
}
