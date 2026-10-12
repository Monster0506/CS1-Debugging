// Singly linked list of ints.
// Expected output:
//   1 2 3
//   1 3
//   3
//   remove 9: not found
//   (empty)

#include <iostream>

struct Node {
  int value;
  Node *next;
};

void pushFront(Node *head, int v);
void printList(const Node *head);
bool removeValue(Node *&head, int v);
void freeList(Node *&head);

int main() {
  Node *head = nullptr;
  pushFront(head, 3);
  pushFront(head, 2);
  pushFront(head, 1);
  printList(head);

  removeValue(head, 2);
  printList(head);

  removeValue(head, 1);
  printList(head);

  std::cout << "remove 9: " << (removeValue(head, 9) ? "removed" : "not found")
            << std::endl;

  freeList(head);
  printList(head);
}

void pushFront(Node *head, int v) {
  Node *n = new Node;
  n->value = v;
  n->next = head;
  head = n;
}

void printList(const Node *head) {
  if (head == nullptr) {
    std::cout << "(empty)" << std::endl;
    return;
  }
  while (head->next != nullptr) {
    std::cout << head->value << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

bool removeValue(Node *&head, int v) {
  if (head == nullptr) {
    return false;
  }
  Node *cur = head;
  while (cur->next != nullptr && cur->next->value != v) {
    cur = cur->next;
  }
  if (cur->next == nullptr) {
    return false;
  }
  Node *doomed = cur->next;
  cur->next = doomed->next;
  delete doomed;
  return true;
}

void freeList(Node *&head) {
  while (head != nullptr) {
    delete head;
    head = head->next;
  }
}
