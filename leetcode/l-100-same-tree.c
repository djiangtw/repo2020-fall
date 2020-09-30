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

int ar0[] = {9, 
    3, 4, 
    -1, 5, 6, -1, 
    -1, -1, 7, 5, -1, 8, -1, -1 };

struct TreeNode* t;

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{

    return true;
}

#define malloc_node ((struct TreeNode*)malloc(sizeof(struct TreeNode)))

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

void create_tree(struct TreeN* t, int nums[], int numSize)
{

}

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
    insert_TreeNode(t->right->left->right, 5, false, false);
}

void end()
{
}

int main(void)
{
    init();
    return 0;
}
