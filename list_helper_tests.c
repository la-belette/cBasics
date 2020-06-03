#include "list_helper_tests.h"
#include "list_helper.h"
#include "common.h"
#include "memory_manager.h"

void doubleV(s_node *node)
{
    node->a *= 2;
}

int test_list_iterate()
{
    int err = 0;

    s_node* list = malloc(5*sizeof(s_node));
    s_node* expected_output = malloc(5*sizeof(s_node));
    s_node *element = list;
    s_node *expected_element = expected_output;
    for (int i = 0; i < 5; i++)
    {
        if (i != 4)
        {
            element->next = list+1+i;
            expected_element->next = expected_output + 1 + i;
        }
        else
        {
            element->next = NULL;
            expected_element->next = NULL;
        }
        element->a = i;
        expected_element->a = i*2;
        element = element->next;
        expected_element = expected_element->next;
    }

    list_iterate(list, doubleV);

    if (0 != list_cmp(list, expected_output))
    {
        printf("fail in %s: list doubled returns\n", __func__);
        list_print(list);
        printf("instead of expected\n");
        list_print(expected_output);
        err = -1;
    }

    return err;
}

int test_node_increment()
{
    int err = 0;

    s_node element;
    element.a = 10;
    s_node expected_element;
    expected_element.a = 11;

    node_increment(&element);
    if(element.a != expected_element.a)
    {
        printf("fail in %s: incremented element returns %d instead of expected %d.\n",
                __func__,
                element.a,
                expected_element.a);
        err = -1;
    }

    return err;
}

int test_node_print()
{
    int err = 0;
    s_node node;
    node.a = 15;
    node_print(&node);
    return err;
}

int test_node_clear()
{
    int err = 0;

    s_node node;
    node.a = 123;
    node_clear(&node);
    if (0 != node.a)
    {
        printf("fail in %s: cleared node holds value %d",
                __func__,
                node.a);
        err = -1;
    }

    return err;
}

int test_list_helper()
{
    int err = 0;

    err += test_list_iterate();
    err += test_node_increment();
    err += test_node_print();
    err += test_node_clear();

    return err;
}