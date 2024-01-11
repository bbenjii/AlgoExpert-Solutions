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

void nodeDepths(BinaryTree *node, int currentDepth,int &sum){
    //add to sum
    sum += currentDepth;

    if(node->left != nullptr) nodeDepths(node->left, currentDepth+1, sum);
    if(node->right != nullptr) nodeDepths(node->right, currentDepth+1, sum);

}

int nodeDepths(BinaryTree *root) {
    // Write your code here.
    int sum = 0;

    nodeDepths(root,0,sum);

    return sum;
}
