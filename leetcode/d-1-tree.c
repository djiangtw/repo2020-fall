
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

struct TreeNode* t;
struct TreeNode* t1;

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

#define malloc_node ((struct TreeNode*)malloc(sizeof(struct TreeNode)))
#define METHOD_1  true
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
void newTree1(struct TreeNode* p, int nums[], int numSize)
{
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
}
#endif
/* thought 1, from scratch up. but it failed to construct the tree. 
 * it's helpful for future thinking about the mistakes
 * 
 */
#if METHOD_1
void insert_TreeNode(struct TreeNode* t, int v, bool bl, bool br)
{
    t->val = v;
    if(bl)
        t->left = malloc_node;
    else
        t->left = NULL;
    if(br)
        t->right = malloc_node;
    else
        t->right = NULL;
}

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

void create_tree(struct TreeNode* t, int nums[], int numSize)
{
    int i = 0;
    struct TreeNode** p;
    bool* notnull;
    notnull = (bool*)malloc(sizeof(bool) * numSize);
    for(i = 0; i < numSize; i++)
    {
        notnull[i] = (nums[i] == -1) ? false : true;
    }
    printf("allocate pointers\n");
    p = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * numSize);
    p[0] = t;
    insert_TreeNode(t, nums[0], true, true);
    for(i = 1; i < numSize; i++)
    {
        bool left, right;
        if(notnull[i] == false)
            break;
        if( (2*i+1) >= numSize)
            left = false;
        if( (2*i+2) >= numSize)
            right = false;
        left = notnull[2*i+1];
        right = notnull[2*i+2];
        {
            p[i] = (i % 2 == 0) ? p[(i+1)/2-1]->right : p[(i+1)/2-1]->left;
            insert_TreeNode(p[i], nums[i], left, right);
        }
    }
    printf("insert nodes\n");
    print_tree(t);
    free(notnull);
    free(p);
}
#endif

void init()
{
    t = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    insert_TreeNode(t, 9, true, true);

    insert_TreeNode(t->left, 3, false, true);
    insert_TreeNode(t->right, 4, true, false);

    insert_TreeNode(t->left->right, 5, true, true);
    insert_TreeNode(t->right->left, 6, false, true);

    insert_TreeNode(t->left->right->left, 7, false, false);
    insert_TreeNode(t->left->right->right, 5, false, false);
    insert_TreeNode(t->right->left->right, 8, false, false);
}

void end()
{
}

void foo(void)
{
    struct TreeNode* p;
    p = t;
    printf("L1: %d\n", p->val);
    printf("L2: %d, %d\n", p->left->val, p->right->val);
    printf("L3: %d, %d\n", p->left->right->val, p->right->left->val);
    printf("L1: %d, %d, %d\n", p->left->right->left->val,
            p->left->right->right->val,
            p->right->left->right->val);

}

int main(void)
{
    /*struct TreeNode* tt;*/
    init();
    t1 = malloc_node;
    /*create_tree(t1, ar0, 15);*/
    t = newTree(ar0, 15);
    print_tree(t);
    foo();
    return 0;
}
