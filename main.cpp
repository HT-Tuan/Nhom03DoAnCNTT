#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;
//
// Lop NODE
template <typename T>
class Node
{
public:
    //
    // data
    T data;
    Node *left, *right, *parent;
    // constructor
    Node(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
    //
    void Creat_Node(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};
//
// Lop Cay binary search tree (BST)
template <typename T>
class BST
{
public:
    // constructor
    BST()
    {
        this->Root = NULL;
    }
    // destructor
    ~BST()
    {
        printf("Da Huy tree");
    }
    void InsertTree(T value)
    {
        TREE_INSERT(this->Root, value);
    }
    void DuyetTruoc()
    {
        PREORDER_TREE_WALK(this->Root);
    }
    void DuyetGiua()
    {
        INORDER_TREE_WALK(this->Root);
    }
    void DuyetSau()
    {
        POSTORDER_TREE_WALK(this->Root);
    }

private:
    // Thuoc tinh
    Node<T> *Root;
    //
    // Phuong Thuc
    void TREE_INSERT(Node<T> *&Root, T value)
    {
        Node<T> *x, *y, *z;
        // z = new Node<T>(value);
        z = (Node<T> *)malloc(sizeof(Node<T>));
        z->Creat_Node(value);
        if (z == NULL)
        {
            printf("\nCo loi! khong the cap phat bo nho.\n");
            return;
        }
        y = NULL;
        x = Root;
        while (x != NULL)
        {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == NULL)
            Root = z;
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;
    }
    //
    // Duyet Truoc
    void PREORDER_TREE_WALK(Node<T> *R)
    {
        if (R != NULL)
        {
            cout << R->data << endl;
            INORDER_TREE_WALK(R->left);
            INORDER_TREE_WALK(R->right);
        }
    }
    // Duyet Giua
    void INORDER_TREE_WALK(Node<T> *R)
    {
        if (R != NULL)
        {
            INORDER_TREE_WALK(R->left);
            cout << R->data << endl;
            INORDER_TREE_WALK(R->right);
        }
    }
    // Duyet Sau
    void POSTORDER_TREE_WALK(Node<T> *R)
    {
        if (R != NULL)
        {
            INORDER_TREE_WALK(R->left);
            INORDER_TREE_WALK(R->right);
            cout << R->data << endl;
        }
    }
};
int main()
{
    BST<int> Tree;
    Tree.InsertTree(12);
    Tree.InsertTree(18);
    Tree.InsertTree(5);
    Tree.InsertTree(2);
    Tree.InsertTree(9);
    Tree.InsertTree(15);
    Tree.InsertTree(19);
    Tree.InsertTree(17);
    Tree.DuyetGiua();
    // cout<<endl;
    // Tree.DuyetGiua();
    // cout<<endl;
    // //
    // //
    // //
    // BST<char> Tree1;
    // Tree1.InsertTree('d');
    // Tree1.InsertTree('b');
    // Tree1.InsertTree('f');
    // Tree1.InsertTree('a');
    // Tree1.InsertTree('c');
    // Tree1.InsertTree('e');
    // Tree1.InsertTree('h');
    // Tree1.InsertTree('g');
    // Tree1.DuyetGiua();
    // cout<<endl;
    // //
    // //
    // BST<float> Tree2;
    // Tree2.InsertTree(12.5);
    // Tree2.InsertTree(12.9);
    // Tree2.InsertTree(12.1);
    // Tree2.InsertTree(11);
    // Tree2.InsertTree(11.5);
    // Tree2.InsertTree(12.7);
    // Tree2.InsertTree(13);
    // Tree2.InsertTree(12.8);
    // Tree2.DuyetGiua();
    // cout<<endl;

    return 0;
}