#include <stdio.h>
#include <string.h>
#include "tree.h"

//==========================
// private
//==========================
int height = 0;

treeNode* bornATreeNode()
{
    //born a treeNode
    treeNode* tn = malloc(sizeof(treeNode));
    if (tn == NULL)
    {
        return mallocFail();
        return NULL;
    }
    else
        //clean memory before using it
        memset(tn, 0, sizeof(treeNode));
    //init data
    tn->data = -1;
    tn->parentNode = NULL;
    tn->leftNode = NULL;
    tn->rightNode = NULL;
    return tn;
}

void buildTree(treeNode *rt, int nd[], int nodeNumber)
{
    //travel nd[] to build tree
    int i;

    printf("Building tree...\n");
    for(i = 0; i <= nodeNumber - 1; i++)
    {
        printf("Processing %d:\n", nd[i]);
        //assign first element to root node
        if (i == 0)
        {
            printf("Root is %d\n", nd[i]);
            rt->data = nd[i];
            continue;
        }
        else
        {
            insertNode(rt, nd[i]);
        }

    }
}

void insertNode(treeNode *tn, int num)
{
    if (tn == NULL)
        return;

    //already inserted and duplicate
    if (tn->data == num)
        return;

    //already inserted, find left/right subtree
    if (tn->data != -1)
    {
        //insert to left subtree
        if (num < tn->data)
        {
            printf("Insert to left tree\n");
            //if left subtree root is already inserted before
            if (tn->leftNode != NULL)
            {
                insertNode(tn->leftNode, num);
            }
            //left subtree is not inserted
            else
            {
                treeNode *newTreeNode = bornATreeNode();
                tn->leftNode = newTreeNode;
                newTreeNode->parentNode = tn;
                insertNode(newTreeNode, num);
            }

        }
        //insert to right subtree
        else if (num > tn->data)
        {
            printf("Insert to right tree\n");
            //if left subtree root is already inserted before
            if (tn->rightNode != NULL)
            {
                insertNode(tn->rightNode, num);
            }
            //left subtree is not inserted
            else
            {
                treeNode *newTreeNode = bornATreeNode();
                tn->rightNode = newTreeNode;
                newTreeNode->parentNode = tn;
                insertNode(newTreeNode, num);
            }
        }
    }
    //tn is a new node, directly insert
    else
    {
        ++height;
        printf("Insert here, height = %d\n", height);
        tn->data = num;
        tn->leftNode = bornATreeNode();
        tn->rightNode = bornATreeNode();

    }
}

void mallocFail()
{
    printf("Malloc failed!!!\n");
}

void traverseBinaryTree(treeNode *tn)
{
    //go to leftiest leaf
    if (tn->leftNode != NULL)
    {
        traverseBinaryTree(tn->leftNode);
    }

    //print self
    if (tn->data != -1)
        printf("%d\n", tn->data);

    //print search right if has
    if (tn->rightNode != NULL)
    {
        traverseBinaryTree(tn->rightNode);
    }
}

void freeTree(treeNode *node)
{
    //not root node has parent, need to free it
    if (!node->isRoot && node->parentNode != NULL)
    {
        free(node->parentNode);
    }
    //free left node
    if (node->leftNode != NULL)
    {
        freeTree(node->leftNode);
    }
    //free right node
    if (node->rightNode != NULL)
    {
        freeTree(node->rightNode);
    }

    free(node);
}
//=========================
// public
//=========================
void treeDemo()
{
    int node[] = {5,19, 80, 7, 3, 54, 17, 44};
    treeNode *rootTreeNode = bornATreeNode();
    if (rootTreeNode == NULL)
        return;
    else
        rootTreeNode->isRoot = true;

    //buildTree from root node
    buildTree(rootTreeNode, node, sizeof(node)/sizeof(node[0]));
    //traverse tree
    printf("Traversing tree...\n");
    traverseBinaryTree(rootTreeNode);
    freeTree(rootTreeNode);
    printf("Tree demo done!!!\n");
}
