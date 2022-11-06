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
    // Thuoc tinh
    Node_list<T> *Front;
    Node_list<T> *Rear;
    // constructor
    Queue()
    {
        Create_Queue();
    }
    // Phuong thuc
    void Create_Queue()
    {
        this->Front = NULL;
        this->Rear = NULL;
    }
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
};
//
template <typename T>
class Stack
{
public:
    Node_list<T> *sp;
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
        cout << "Da Huy tree" << endl;
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
    //
    void DuyetSau()
    {
        POSTORDER_TREE_WALK(this->Root);
    }
    void DuyetRongTruoc()
    {
        BFS(this->Root);
    }
    void DuyetSauTruoc()
    {
        DFS(this->Root);
    }

    void TimPreorder(int N)
    {
        Node<T> *temp;
        int index;
        temp = NULL;
        index = 1;
        NthPreordernode(this->Root, N, temp, index);

        if (temp != NULL)
            cout << temp->data << endl;
        else
            cout << "co loi error" << endl;
    }

    void Xoa(int N)
    {
        Node<T> *temp;
        int index;
        temp = NULL;
        index = 1;
        NthPreordernode(this->Root, N, temp, index);
        if (temp != NULL)
            TREE_DELETE(this->Root, temp);
        else
            cout << "co loi error" << endl;
    }

private:
    // Thuoc tinh
    Node<T> *Root;
    //
    // Phuong Thuc

    struct node *minValueNode(Node<T> *node)
    {
        struct node *current = node;

        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    Node<T> *TREE_MINIMUM(Node<T> *temp)
    {
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node<T> *TREE_SUCCESSOR(Node<T> *temp)
    {
        if (temp->right != NULL)
            return TREE_MINIMUM(temp->right);
        Node<T> *y;
        y = temp->parent;
        while ((y != NULL) && (temp == y->right))
        {
            temp = y;
            y = y->parent;
        }
        return y;
    }

    Node<T> *TREE_DELETE(Node<T> *&root, Node<T> *z)
    {
        Node<T> *x, *y;
        if ((z->left == NULL) || (z->right == NULL))
            y = z;
        else
            y = TREE_SUCCESSOR(z);

        if (y->left != NULL)
            x = y->left;
        else
            x = y->right;

        if (x != NULL)
            x->parent = y->parent;

        if (y->parent == NULL)
            root = x;
        else
        {
            if (y == ((y->parent)->left))
                (y->parent)->left = x;
            else
                (y->parent)->right = x;
        }
        if (y != z)
        {
            z->data = y->data;
        }

        return y;
    }

    void NthPreordernode(Node<T> *R, int N, Node<T> *&temp, int &flag)
    {
        if (R != NULL)
        {
            if (flag == N)
            {
                temp = R;
            }
            flag = flag + 1;
            NthPreordernode(R->left, N, temp, flag);
            NthPreordernode(R->right, N, temp, flag);
        }
    }

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
            PREORDER_TREE_WALK(R->left);
            PREORDER_TREE_WALK(R->right);
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
            POSTORDER_TREE_WALK(R->left);
            POSTORDER_TREE_WALK(R->right);
            cout << R->data << endl;
        }
    }
    // Thuat toan duyet rong truoc BFS
    void BFS(Node<T> *Root)
    {
        Queue<T> HangDoi;
        Node<T> temp;
        HangDoi.PushQ(*Root);
        while (HangDoi.Front != NULL)
        {
            HangDoi.PopQ(&temp);
            cout << temp.data << endl;
            if (temp.left != NULL)
            {
                HangDoi.PushQ(*(temp.left));
            }
            if (temp.right != NULL)
            {
                HangDoi.PushQ(*(temp.right));
            }
        }
    }
    // Thuat toan duyet sau truoc DFS
    void DFS(Node<T> *Root)
    {
        Stack<T> NganXep;
        Node<T> temp;
        NganXep.PushS(*Root);
        while (NganXep.sp != NULL)
        {
            NganXep.PopS(&temp);
            cout << temp.data << endl;
            if (temp.right != NULL)
            {
                NganXep.PushS(*(temp.right));
            }
            if (temp.left != NULL)
            {
                NganXep.PushS(*(temp.left));
            }
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
    // cout << endl;
    // Tree.DuyetRongTruoc();
    // cout << endl;
    // Tree.DuyetSauTruoc();
    Tree.DuyetTruoc();
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
    int N = 6;

    // tim gia tri n, duyet truoc
    cout << endl;
    Tree.TimPreorder(N);
    Tree.TimPreorder(4);
    Tree.Xoa(N);
    cout << endl;
    Tree.DuyetTruoc();

    // xoa gia tri n, duyet giua
    //  Tree = Xoa (Tree, 17);
    //  Tree.DuyetGiua();

    return 0;
}
