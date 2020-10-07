/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Test tree:
 *            9
 *          /   \
 *         3     4
 *         \    / \
 *          5  6
 *        / \   \
 *       7  5    8
 */
int ar0[] = {9, 
    3, 4, 
    -1, 5, 6, -1, 
    -1, -1, 7, 5, -1, 8, -1, -1 };

int ar1[] = {1, 3, 5};
int ar2[] = {1, 3, 5};
int ar3[] = {1, 2, 5};

struct TreeNode* p;
struct TreeNode* q;
struct TreeNode* r;

void tree_cmp(struct TreeNode* p, struct TreeNode* q, bool* is_same)
{
    if(p == NULL)
    {
        if(q != NULL)
            *is_same = false;
        return;
    }
    if(q == NULL)
    {
        *is_same = false;
        return;
    }
    if(p->val != q->val)
    {
        *is_same = false;
        return;
    }
    tree_cmp(p->left, q->left, is_same);
    tree_cmp(p->right, q->right, is_same);
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    bool r = true;
    tree_cmp(p, q, &r);

    return r;
}

/* 
 * following functions are for tests and trials.
 *
 * */
#define malloc_node ((struct TreeNode*)malloc(sizeof(struct TreeNode)))
#define METHOD_2  true

#if METHOD_2
/* in newNode1 when the allocated p returned to the caller, it goes empty.
 * think about it!
 */
void newNode1(struct TreeNode* p, int v)
{
    p = malloc_node;
    p->val = v;
    p->left = NULL;
    p->right = NULL;
}

struct TreeNode*  newNode(int v)
{
    struct TreeNode *p;
    p = malloc_node;
    p->val = v;
    p->left = NULL;
    p->right = NULL;
    return p;
}

/* create a new tree from array*/
struct TreeNode* newTree(int nums[], int numSize)
{
    struct TreeNode* p;
    int i;
    struct TreeNode** r;
    r = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * numSize);
    p = newNode(nums[0]);
    r[0] = p;
    for(i = 1; i < numSize; i++)
    {
        if(nums[i] != -1)
        {
            r[i] = newNode(nums[i]);
            if(i % 2 == 0)
                r[(i+1)/2-1]->right = r[i];
            else
                r[(i+1)/2-1]->left = r[i];
        }
    }
    free(r);
    return p;
}
#endif
void print_tree(struct TreeNode* p)
{
    if(p == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d, ", p->val);
    print_tree(p->left);
    print_tree(p->right);
}

void init()
{
    p = newTree(ar1, 3);
    q = newTree(ar2, 3);
    r = newTree(ar3, 3);
    print_tree(p);
    print_tree(q);
    print_tree(r);
}

/* there will be memory leak for now. 
 * TODO:
 * free all allocated memory
 */
void end()
{
}

int main(void)
{
    /*struct TreeNode* tt;*/
    init();
    printf("%d\n", isSameTree(p, q));
    printf("%d\n", isSameTree(p, r));

    return 0;
}
