#include <vector>
using namespace std;

vector<int> sortStack(vector<int> &stack, int &element){
    if (stack.empty()) stack.push_back(element);
    else if (element < stack.back()){
        int top = stack.back();
        stack.pop_back();
        sortStack(stack, element);
        stack.push_back(top);
    }
    else {
        stack.push_back(element);
    }

    return stack;

}
vector<int> sortStack(vector<int> &stack) {
    // Write your code here.
    if (stack.empty()) {
        return stack;
    }
    //store last element and pop it stack
    int element = stack.back();
    stack.pop_back();

    if (stack.empty()) {
        stack.push_back(element);
        return stack;
    }
    sortStack(stack);
    sortStack(stack, element);

    return stack;

}
