#include <stdio.h>
#include <stdlib.h>

struct linkedListNode {
  int value;
  struct linkedListNode *next;
};

void printLinkedList(struct linkedListNode *p) {
  while (p != NULL) {
    printf("%d", p->value);
    p = p->next;
  }
}

struct linkedListNode createHead(int value) {
  struct linkedListNode *head = NULL;
  head = malloc(sizeof(struct linkedListNode));

  head->value = value;
  head->next = NULL;

  return *head;
}

// void test() {
//   struct linkedListNode *head = createHead(40);
//   printLinkedList(head);
// }
// bool findOne(struct node *headRef, int value) {
// }
