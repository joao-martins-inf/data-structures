#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *head;
  int value;
  struct node *next;
};

void printLinkedList(struct node *p) {
  while (p != NULL) {
    printf("%d", p->value);
    p = p->next;
  }
}

// bool findOne(struct node *headRef, int value) {
// }
