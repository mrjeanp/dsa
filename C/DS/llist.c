#include <stdlib.h>
#include <string.h>

/**
 * Struct of a doubly linked list node.
 */
typedef struct LListNode
{
  char *data;
  LListNode *prev;
  LListNode *next;
} LListNode;

/**
 * Struct of a doubly linked list.
 */
typedef struct LList
{
  LListNode *head;
  LListNode *tail;
  int size;
} LList;

/**
 * Creates a new doubly linked list.
 */
LList *llist()
{

  LList *list = (LList *)malloc(sizeof(LList));

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

/**
 * Prepends a new node to the head of the list.
 */
void llist_prepend(LList *list, const char *str)
{
  // new node
  LListNode *node = (LListNode *)malloc(sizeof(LListNode));
  node->data = strdup(str); // copy string
  node->prev = NULL;
  node->next = list->head;

  if (list->head == NULL)
  {
    list->tail = node;
  }
  else
  {
    list->head->prev = node;
  }

  list->head = node;
  list->size++;
}

/**
 * Appends a new node to the tail of the list.
 */
void llist_append(LList *list, const char *str)
{
  LListNode *node = (LListNode *)malloc(sizeof(LListNode));
  node->data = strdup(str); // string duplicate
  node->prev = list->tail;
  node->next = NULL;

  if (list->tail == NULL)
  {
    list->head = node;
  }
  else
  {
    list->tail->next = node;
  }

  list->tail = node;
  list->size++;
}

/**
 * Removes a node from the list.
 */
void llist_remove(LList *list, LListNode *node)
{
  if (node == NULL)
    return;

  if (list->head == node)
  {
    // remove current head and link it to next
    list->head = node->next;
  }
  else
  {
    // link the prev to next,
    // unlinking the middle reference
    node->prev->next = node->next;
  }

  if (list->tail == node)
  {

    // remove current tail and link it to prev
    list->tail = node->prev;
  }
  else
  {
    // link right to the prev
    // unlinking the middle reference
    node->next->prev = node->prev;
  }

  // free data and object
  free(node->data);
  free(node);
  list->size--;
}

/**
 * Finds a node by it's value in the list.
 */
LListNode *llist_find(LList *list, const char *str)
{
  LListNode *current = list->head;

  while (current != NULL)
  {
    // string compare
    if (strcmp(current->data, str))
    {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

/**
 * Free the whole list
 */
void llist_free(LList *list)
{
  LListNode *current = list->head;
  while (current != NULL)
  {
    llist_remove(list, current);
  }

  free(list);
}
