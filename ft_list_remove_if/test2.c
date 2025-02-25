/*Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"list.h"

void print_l(t_list *l)
{
    t_list *l_t;

    l_t = l;
    while(l_t != NULL) //l_t->data != (void*)7
    {
        printf("l = %s\n", l_t->data);
        l_t = l_t->next;
    }
}

t_list *add_list(char *d)
{
    t_list *l;

    l = malloc(sizeof(t_list));
    l->data = d;
    l->next = NULL;

    return(l);
}

int cmp2(char *a, char *b)
{
    int i;
    int j;

    i = 0;
    while(a[i])
        i++;

    j = 0;
    while(b[j])
        j++;
    
    if(i != j)
        return(-1);

    while(i >= 0)
    {
        if(a[i] != b[i])
            return(-1);
        i--;
    }
    return(0);
}

void ft_list_remove_if(t_list **begin_list, char *data_ref, int (*cmp)())
{
    t_list *l;
    t_list *prev;

    l = *begin_list;
    prev = NULL;
    while(l)
    {
        if(cmp(data_ref, l->data) == 0)
        {
            if(prev ==0)
            {
                *begin_list = l->next;
                free(l);
                l = *begin_list;
            }
            else
            {
                prev->next = l->next;
                free(l);
                l = prev->next;
            }
        }
        else
        {
            prev = l;
            l = prev->next;
        }
    }
}

int main (void)
{
    t_list *l;

    l = add_list("ab");
    l->next = add_list("abc");
    l->next->next = add_list("abcd");

    print_l(l);

    printf("\n");
    ft_list_remove_if(&l, "abc", &cmp2);

    print_l(l);

    return(0);
}