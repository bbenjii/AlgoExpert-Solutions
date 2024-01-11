using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
  // Write your code here.
if (head == nullptr || head->next == nullptr) return head;
    LinkedList * rest = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return rest;}
