/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode{
    int val;
    struct ListNode *next;
} _ListNode;

struct ListNode* l1;
struct ListNode* l2;
struct ListNode* lr;

int _l2[] = {2, 4, 5};
int _l1[] = {5, 6, 7, 9, 9, 9, 9, 9, 9};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int c = 0;
    int s = 0;
    struct ListNode* p;
    struct ListNode* q;

    if(l1 == NULL)
    {
        if(l2 == NULL)
            return NULL;
        else
            return l2;
    }
    if(l2 == NULL)
        return l1;

    p = l1;
    q = l2;
    while(1)
    {
        int i = 0;
        i++;
        s = p->val + q->val + c;
        c = s / 10;
        p->val = q->val = s % 10;
        if(p->next == NULL)
        {
            if(q->next == NULL)
            {
                /* both next are null, check carry and return list 1 */
                while( c != 0 )
                {
                    p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                    p = p->next;
                    s = c;
                    c = s / 10;
                    p->val = s % 10;
                    p->next = NULL;
                }
                return l1;
            }
            else
            {
                while( c!= 0)
                {
                    if(q->next == NULL)
                    {
                        q->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                        q->next->val = 0;
                        q->next->next = NULL;
                    }

                    q = q->next;
                    s = q->val + c;
                    c = s / 10;
                    q->val = s % 10;
                }
                return l2;
            }
        }
        if(q->next == NULL)
        {
            while( c!= 0)
            {
                if(p->next == NULL)
                {
                    p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                    p->next->val = 0;
                    p->next->next = NULL;
                }

                p = p->next;
                s = p->val + c;
                c = s / 10;
                p->val = s % 10;
            }
            return l1;
        }
        p = p->next;
        q = q->next;
    }
}

void assign_array_to_list(struct ListNode* l, int _l[], int sz)
{
    int i;
    struct ListNode* lp;
    lp = l;
    i = 0;

    while(lp != NULL)
    {
        lp->val = _l[i++];
        if(sz == i)
        {
            lp->next = NULL;
            break;
        }
        lp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        lp = lp->next;
    }
}

void init(void)
{
    int sl1, sl2;
    sl1 = (int)(sizeof(_l1)/sizeof(int));
    sl2 = (int)(sizeof(_l2)/sizeof(int));

    if(sl1 == 0)
        l1 = NULL;
    else
    {
        l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        assign_array_to_list(l1, _l1, sl1);
    }

    if(sl2 == 0)
        l2 = NULL;
    else
    {
        l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
        assign_array_to_list(l2, _l2, sl2);
    }
}

void print_list(struct ListNode* l)
{
    while(l != NULL)
    {
        printf(" %d ->", l->val);
        l = l->next;
    }
    printf("\n");
}

void free_list(struct ListNode* l)
{
    struct ListNode* p;
    int c = 0;
    if(l == NULL)
        return;
    p = l;
    do{
        while(p->next != NULL)
        {
            p = p->next;
        }
        free(p);
        p = l;
        c++;
        if(c > 10)
            break;
    } while(p != l);
}

void dismiss(void)
{
    free_list(l1);
}

int main(void)
{
    init();
    print_list(l1);
    print_list(l2);

    l1 = addTwoNumbers(l1, l2);
    print_list(l1);

    dismiss();
    printf("%d, %d\n", (int)sizeof(_l1), (int)sizeof(_l2));
    return 0;
}
