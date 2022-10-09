#include <malloc.h>
#include <iostream>
using namespace std;

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
    Node()
    {
        Creat_Node();
    }
    //
    void Creat_Node()
    {
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};
//
// Node dang ds lien ket dung cho Queue va stack
template <typename T>
class Node_list
{
public:
    // Thuoc tinh
    Node<T> data;
    Node_list *next;
    //
    Node_list(Node<T> data)
    {
        Creat_Node_list(data);
    }
    // Phuong thuc
    void Creat_Node_list(Node<T> data)
    {
        this->data = data;
        this->next = NULL;
    }
};
//
template <typename T>
class Queue
{
public:
    Queue()
    {
        Create_Queue();
    }
    // Phuong thuc
    // Enqueue
    int PushQ(Node<T> value)
    {
        Node_list<T> *p;
        p = (Node_list<T> *)malloc(sizeof(Node_list<T>));
        if (p == NULL)
        {
            cout << "\nCo loi! khong the cap phat bo nho." << endl;
            return 0;
        }
        p->Creat_Node_list(value);
        if (this->Front == NULL)
        {
            this->Front = p;
            this->Rear = p;
        }
        else
        {
            (this->Rear)->next = p;
            this->Rear = p;
        }
        return 1;
    }
    // Dequeue
    int PopQ(Node<T> *value)
    {
        Node_list<T> *p;
        p = this->Front;
        if (p != NULL)
        {
            *value = p->data;
            this->Front = p->next;
            if (this->Front == NULL)
            {
                this->Rear = NULL;
            }
            free(p);
            return 1;
        }
        return 0;
    }

private:
    // Thuoc tinh
    Node_list<T> *Front;
    Node_list<T> *Rear;
    // constructor
    void Create_Queue()
    {
        this->Front = NULL;
        this->Rear = NULL;
    }
};
//
template <typename T>
class Stack
{
public:
    Stack()
    {
        Create_Stack();
    }
    void Create_Stack()
    {
        this->sp = NULL;
    }
    // Them vao dinh stack
    int PushS(Node<T> value)
    {
        Node_list<T> *p;
        p = (Node_list<T> *)malloc(sizeof(Node_list<T>));
        if (p == NULL)
        {
            cout << "\nCo loi! khong the cap phat bo nho." << endl;
            return 0;
        }
        p->data = value;
        p->next = this->sp;
        this->sp = p;
        return 1;
    }
    // lay tu dinh stack
    int PopS(Node<T> *value)
    {
        Node_list<T> *p;
        p = this->sp;
        if (p != NULL)
        {
            *value = (this->sp)->data;
            this->sp = p->next;
            free(p);
            return 1;
        }
        return 0;
    }

private:
    Node_list<T> *sp;
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
        if (z == NULL)
        {
            cout << "\nCo loi! khong the cap phat bo nho." << endl;
            return;
        }
        z->Creat_Node();
        z->data = value;
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
    // BST<int> Tree;
    // Tree.InsertTree(12);
    // Tree.InsertTree(18);
    // Tree.InsertTree(5);
    // Tree.InsertTree(2);
    // Tree.InsertTree(9);
    // Tree.InsertTree(15);
    // Tree.InsertTree(19);
    // Tree.InsertTree(17);
    // Tree.DuyetGiua();
    // cout << endl;
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
    //================= test Queue - Stack ===================
    // Node<int> x, y, z, temp;
    // x.data = 1;
    // y.data = 2;
    // z.data = 3;
    // Stack<int> s1;
    // s1.PushS(x);
    // s1.PushS(y);
    // s1.PushS(z);
    // s1.PopS(&temp);
    // cout << "stack:" << temp.data << endl;
    // Queue<int> q1;
    // q1.PushQ(x);
    // q1.PushQ(y);
    // q1.PushQ(z);
    // q1.PopQ(&temp);
    // cout << "Queue:" << temp.data << endl;
    //==================
    
    return 0;
}
