//===========================================================================
//                     Preorder Tree Construction
//                      Developed By: Leron Julian
//               PROGRAM COMPLETED PER PROGRAM SPECIFICATION
//===========================================================================
#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;


struct BinaryTreeNode
{
    char Node;
    
    BinaryTreeNode *LeftSubtree = NULL, *RightSubtree = NULL;
};

typedef BinaryTreeNode *BinaryTree;

void InOrder(BinaryTree T);
void PreOrder(BinaryTree T);
void PostOrder(BinaryTree T);

void From_PreOrder(BinaryTree root, int &index, string preorder);

int find_Max_BST(BinaryTree node, int min, int max);
int isBST(BinaryTree node);

void printLevelOrder(BinaryTree root);
void printGivenLevel(BinaryTree root, int level);
int height(BinaryTree node);


int main()
{
    string preorderInput;
    
    cout << "Enter a preorder expression -> ";
    cin >> preorderInput;
    
    BinaryTree root = new(BinaryTreeNode);
    
    int index = 0;
    From_PreOrder(root, index, preorderInput);
    
    cout << endl;
    
    cout << "Preorder: ";
    PreOrder(root);
    cout << endl;
    
    cout << "InOrder: ";
    InOrder(root);
    cout << endl;
    
    cout << "PostOrder: ";
    PostOrder(root);
    cout << endl;
    
    cout << "Level-Order: ";
    printLevelOrder(root);
    cout << endl;
    
    cout << endl;
    
    if(isBST(root))
        cout << "This Binary Tree is a Binary Search Tree" << endl;
    
    else if (!isBST(root))
        cout << "This Binary Tree is not a Binary Search Tree" << endl << endl;
    return 0;
}

//===========================================================================
//  This function prints the preorder traversal in Inorder
//===========================================================================
void InOrder(BinaryTree T)
{
    if (T->LeftSubtree == NULL)
        cout << "." ;
    
    else
    {
        InOrder(T->LeftSubtree) ;
        
        cout << T->Node ;
        
        InOrder(T->RightSubtree) ;
    }
}

//===========================================================================
//  This function prints the preorder traversal in PreOrder
//===========================================================================
void PreOrder(BinaryTree T)
{
    if (T->LeftSubtree == NULL)
        cout << "." ;
    
    else
    {
        cout << T->Node ;
    
        PreOrder(T->LeftSubtree);
        PreOrder(T->RightSubtree);
    }
}

//===========================================================================
//  This function prints the preorder traversal in PostOrder
//===========================================================================
void PostOrder( BinaryTree T )
{
    if (T->LeftSubtree == NULL)
        
        cout << "." ;
    
    else
    {
        PostOrder( T->LeftSubtree ) ;
        PostOrder( T->RightSubtree ) ;
        cout << T->Node ;
    }
}

//===========================================================================
//  This function converts a preorder input to a binary tree
//===========================================================================
void From_PreOrder(BinaryTree root, int &index, string preorder)
{
    char ch = preorder[index];

    if (ch == '.')
        return;
    
    root->Node = ch;

    root->LeftSubtree = new BinaryTreeNode;
    
    From_PreOrder(root->LeftSubtree, ++index, preorder);

    root->RightSubtree = new BinaryTreeNode;

    From_PreOrder(root->RightSubtree, ++index, preorder);
}

//===========================================================================
//  This function returns 0 if it is not a BST and 1 if it is
//===========================================================================
int isBST(BinaryTree node)
{
    return(find_Max_BST(node, INT_MIN, INT_MAX));
}

//========================================================================================
//  This function gets the maximum element in a binary tree to see if it is a binary tree
//========================================================================================
int find_Max_BST(BinaryTree node, int min, int max)
{
    if (node->LeftSubtree == NULL)
        return 1;
    
    if (node->Node < min || node->Node > max)
        return 0;
    
    return(find_Max_BST(node->LeftSubtree, min, node->Node-1) && find_Max_BST(node->RightSubtree, node->Node+1, max));
}


//========================================================================================
//  This function prints every prints the level order traversal of a binary tree
//========================================================================================
void printLevelOrder(BinaryTree root)
{
    int h = height(root);
    
    int i;
    
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

//========================================================================================
//  This function prints every level of a binary tree
//========================================================================================
void printGivenLevel(BinaryTree root, int level)
{
    if (root == NULL)
        return;
    
    if (level == 1)
        cout << root->Node << " ";
    
    else if (level > 1)
    {
        printGivenLevel(root->LeftSubtree, level - 1);
        printGivenLevel(root->RightSubtree, level - 1);
    }
}

//========================================================================================
//  This function gets the height of a binary tree
//========================================================================================
int height(BinaryTree node)
{
    if (node == NULL)
        return 0;
    
    else
    {
        int left_Height = height(node->LeftSubtree);
        int right_Height = height(node->RightSubtree);
        
        if (left_Height > right_Height)
            return(left_Height + 1);
        
        else
            return(right_Height + 1);
    }
}


