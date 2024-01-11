using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next;

    LinkedList(int value) {
        this->value = value;
        next = nullptr;
    }
};

LinkedList *rearrangeLinkedList(LinkedList *head, int k) {
    // Write your code here.

      if(head == nullptr) return head;


    LinkedList *smaller = nullptr;
    LinkedList *value = nullptr;
    LinkedList *bigger = nullptr;

    LinkedList *current = head;

    //create the three different lists
    while (current != nullptr){
        LinkedList * next = current->next;
        current->next = nullptr;

        if(current->value < k){
            if(smaller == nullptr) smaller = current;
            else {
                LinkedList * i = smaller;
                while(i->next != nullptr){
                    i = i->next;
                }
                i->next = current;
            }
        }
        else if(current->value > k){
            if(bigger == nullptr) bigger = current;
            else {
                LinkedList * i = bigger;
                while(i->next != nullptr){
                    i = i->next;
                }
                i->next = current;
            }        }
        else if(current->value == k){
            if(value == nullptr) value = current;
            else {
                LinkedList * i = value;
                while(i->next != nullptr){
                    i = i->next;
                }
                i->next = current;
            }        }

        current = next;
    }
    LinkedList * newHead = nullptr;
    //merge three lists
    if(smaller != nullptr){
        newHead = smaller;

        current = newHead;

        //find end of smaller list
        while(current->next != nullptr){
            current = current->next;
        }

        //connect end of smaller with beginning of "same" list or bigger list
        if(value != nullptr){
            current->next = value;

            //find end of same value list
            while(current->next != nullptr){
                current = current->next;
            }
            if(bigger != nullptr) current->next = bigger;

        }
        else if (bigger != nullptr) current->next = bigger;

    }
    else if(value != nullptr){
        newHead = value;

        current = newHead;

        //find end of same value list
        while(current->next != nullptr){
            current = current->next;
        }

        if(bigger != nullptr) current->next = bigger;

    }
    else if(bigger != nullptr) newHead = bigger;


    return newHead;
}
