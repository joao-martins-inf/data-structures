#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct listImpl {
  int *elements;
  unsigned int size;
  unsigned int capacity;
} ListImpl;

PtList listCreate(unsigned int initialCapacity) {
  PtList newList = (PtList)malloc(sizeof(ListImpl));
  if (newList == NULL)
    return NULL;

  newList->elements = (int *)calloc(initialCapacity, sizeof(int));
  if (newList->elements == NULL) {
    free(newList); // prevent memory leak
    return NULL;
  }

  newList->size = 0;
  newList->capacity = initialCapacity;

  return newList;
}

int listAdd(PtList list, int index, int elem) {
  if (list == NULL)
    return LIST_NULL;
  if (index < 0 || index > list->size)
    return LIST_INVALID_RANK;

  if (list->size == list->capacity) {
    int *newElements =
        (int *)realloc(list->elements, (list->capacity + 1) * sizeof(int));

    if (newElements == NULL)
      return LIST_NO_MEMORY;

    list->elements = newElements;
    list->capacity += 1;
  }

  for (int i = list->size; i > index; i--) {
    list->elements[i] = list->elements[i - 1];
  }

  list->elements[index] = elem;
  list->size++;
  return LIST_OK;
}

int listRemove(PtList list, int rank, int *ptElem) {
  if (list == NULL)
    return LIST_NULL;
  if (list->size == 0)
    return LIST_EMPTY;
  if (rank < 0 || rank > list->size - 1)
    return LIST_INVALID_RANK;

  *ptElem = list->elements[rank];

  for (int i = rank; i < list->size - 1; i++) {
    list->elements[i] = list->elements[i + 1];
  }
  list->size--;

  return LIST_OK;
}

int listGet(PtList list, int rank, int *ptElem) {
  if (list == NULL)
    return LIST_NULL;
  if (list->size == 0)
    return LIST_EMPTY;
  if (rank < 0 || rank > list->size - 1)
    return LIST_INVALID_RANK;

  *ptElem = list->elements[rank];

  return LIST_OK;
}

int listDestroy(PtList *ptList) {
  PtList list = *ptList;

  if (list == NULL)
    return LIST_NULL;

  free(list->elements);
  free(list);

  *ptList = NULL;

  return LIST_OK;
}

int listSet(PtList list, int rank, int elem, int *ptOldElem) {}

int listSize(PtList list, int *ptSize) {}

int listIsEmpty(PtList list) {}

int listClear(PtList list) {}

int listPrint(PtList list) {
  if (list == NULL) {
    return LIST_NULL;
  } else if (/*listIsEmpty(list)*/ list->size == 0) {
    return LIST_EMPTY;
  } else {
    for (int i = 0; i < list->size; i++) {
      printf("Rank %d : ", i);
      printf("%d\n", list->elements[i]);
    }
    return LIST_OK;
  }
}

int testList() {
  PtList list = listCreate(1);
  listAdd(list, 0, 1);
  listAdd(list, 1, 2);
  listAdd(list, 2, 3);
  printf("%d list size\n", list->size);
  int elem;
  listRemove(list, 1, &elem);
  printf("%d elem removed\n", elem);
  printf("%d list size\n", list->size);
  listPrint(list);
  return LIST_OK;
}
