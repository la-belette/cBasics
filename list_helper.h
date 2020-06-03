#ifndef CBASICS_LIST_HELPER_H
#define CBASICS_LIST_HELPER_H

typedef struct node
{
    int a;
    struct node *next;
} s_node;
typedef void (*f_node_handler)(s_node*);

/*
 * list_iterate applies callback to each element of list.
 * @param list: target list
 * @param callback: function to apply to list
 */
void list_iterate(s_node *list, f_node_handler callback);

/*
 * list_print prints the list elements in list
 * @param list: target list to print
 */
void list_print(s_node *list);

/*
 * list_cmp compares listA with listB.
 * @param listA: first list to compare
 * @param lisB: second list to compare
 * @return 0 if listA and listB contains the same a for each element,
 * the difference between listA a and listB a for the first different
 * element or the first extra element if lists have common start but
 * different lengths.
 */
int list_cmp(s_node *listA, s_node *listB);

/*
 * node_print prints the integer of the given node.
 * @param node: target node
 */
void node_print(s_node *node);

/*
 * node_increment increments the value of the given node.
 * @param node: target node
 */
void node_increment(s_node *node);

/*
 * node_clear reset node value to 0.
 * @param node: target node
 */
void node_clear(s_node *node);

#endif //CBASICS_LIST_HELPER_H
