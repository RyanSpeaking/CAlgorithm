#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#define true 1
#define false 0
typedef int bool;
typedef struct
{
    bool isRoot;
    int data;
    struct treeNode *parentNode;
    struct treeNode *leftNode;
    struct treeNode *rightNode;
} treeNode;

void treeDemo();

#endif // TREE_H_INCLUDED
