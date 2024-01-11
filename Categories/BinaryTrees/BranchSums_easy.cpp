using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

void branchSums(BinaryTree *node, int currentSum, vector<int> &sums){

    //add to current sum
    currentSum += node->value;

    //if node is a leaf add current sum to the list
    if(node->left == nullptr && node->right == nullptr){
        sums.push_back(currentSum);
        return;
    }
    if(node->left != nullptr){
        branchSums(node->left, currentSum, sums);
    }
    if(node->right != nullptr){
        branchSums(node->right, currentSum, sums);
    }
}

vector<int> branchSums(BinaryTree *root) {
    // Write your code here.
    vector<int> sums;
    int currentSum = 0;
    branchSums(root, currentSum, sums);
    
    return sums;
}

