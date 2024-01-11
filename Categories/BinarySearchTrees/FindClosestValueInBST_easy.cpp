class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
  // Write your code here.
 BST *current = tree;
    while(current != NULL){
        if(target < current->value){
            if(current->left == NULL) return current->value;
            else current = current->left;
        }
        else if(target == current->value){
            return current->value;
        } else{
            if(current->right == NULL) return current->value;
            else current = current->right;
        }

    }
    return 0;
  
}
