#include "list_helper.h"
#include "common.h"

void list_print(s_node *list)
{
    s_node *element = list;
    while (element->next != NULL)
    {
        printf("%d ", element->a);
        element = element->next;
    }
    printf("%d\n", element->a);
}

int list_cmp(s_node *listA, s_node *listB)
{
    s_node *elementA = listA;
    s_node *elementB = listB;
    int diff = 0;
    while ((elementA->next != NULL) && (elementB->next != NULL))
    {
        diff = elementA->a - elementB->a;
        if (0 != diff)
            return diff;
        elementA = elementA->next;
        elementB = elementB->next;
    }
    diff = elementA->a - elementB->a;
    if (0 != diff)
        return diff;

    if (elementA->next != NULL)
        return elementA->next->a;
    if  (elementB->next != NULL)
        return elementB->next->a;

    return 0;
}

void list_iterate(s_node *list, f_node_handler callback)
{
    s_node *element = list;
    while (element->next != NULL)
    {
        callback(element);
        element = element->next;
    }
    callback(element);
}

void node_print(s_node *node)
{
    printf("%d\n", node->a);
}

void node_increment(s_node *node)
{
    node->a ++;
}

void node_clear(s_node *node)
{
    node->a = 0;
}