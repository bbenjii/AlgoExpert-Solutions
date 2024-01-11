using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};


LinkedList *zipLinkedList(LinkedList *linkedList) {
    // Write your code here.
    LinkedList * cur = linkedList;
    //divide linked list and reverse second half
    int length = 0;
    while(cur != nullptr){
        length++;
        cur = cur->next;
    }
    int mid = length/2;
    LinkedList *linkedlist2;

    cur = linkedList;
    for(int i = 1; i < mid; i++){
        cur = cur->next;
    }
    // linkedlist2 = reverse(cur->next);
    cur->next = nullptr;
    cur = linkedList;
    int i = 1;

    while(linkedlist2 != nullptr){
        linkedlist2->next = cur->next;
        cur->next = linkedlist2;

        cur = cur->next->next;
        linkedlist2 = linkedlist2->next;
        }

    return linkedList;
    
