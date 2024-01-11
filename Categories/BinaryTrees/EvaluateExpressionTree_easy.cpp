using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

int operation(BinaryTree *node){
    //check if leaf
    if(node->left== nullptr && node->right == nullptr) return node->value;

    switch (node->value) {
        case -1:
            return (operation(node->left) + operation(node->right));
            break;

        case -2:
            return (operation(node->left) - operation(node->right));

        case -3:
            return (operation(node->left) / operation(node->right));

        case -4:
            return (operation(node->left) * operation(node->right));
            
    }

}

int evaluateExpressionTree(BinaryTree *tree) {
    // Write your code here.
//check if leaf
    int sum = operation(tree);
    
    return sum;
}
