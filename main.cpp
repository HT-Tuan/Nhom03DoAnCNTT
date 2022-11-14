  
//   * * * * * * * * * * * * * * * * * * * * * * * * * *
//   *  De tai: Do An 3 - Cay Nhi Phan Tim Kiem (BST)  *
//   *  Thuc hien:                                     *
//   *            1. Huynh Thanh Tuan - 20110120       *
//   *            2. Tran Nguyen Duy Linh - 20110516   *
//   * * * * * * * * * * * * * * * * * * * * * * * * * *
//   * * * * * * * * * * * * * * * * * * * * * * * * * * 
// Khai bao thu vien
#include <iostream>
#include <conio.h>
#include <malloc.h>
#include <string.h>
using namespace std;
// Xay dung lop TuNgu
class TuNgu
{
public:
    // Thuoc tinh
    char TiengAnh[21]; // KEY
    char Tuloai[21];
    char TiengViet[21];
    char Vidu[21];
    // constructor
    TuNgu()
    {
        Create_TuNgu();
    }
    // Phuong thuc
    void Create_TuNgu()
    {
        this->TiengAnh[0] = '\0';
        this->TiengViet[0] = '\0';
        this->Tuloai[0] = '\0';
        this->Vidu[0] = '\0';
    }
    bool operator<(TuNgu B)
    {
        if (strcmp(this->TiengAnh, B.TiengAnh) < 0)
        {
            return true;
        }
        return false;
    }
    bool operator!=(TuNgu B)
    {
        if (strcmp(this->TiengAnh, B.TiengAnh) != 0)
        {
            return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &os, TuNgu data)
    {
        os << "Tu tieng anh: " << data.TiengAnh << "\nTu nghia tieng viet: " << data.TiengViet << "\nTu loai: " << data.Tuloai << "\nVi du: " << data.Vidu;
        return os;
    }
};
// dac ta Node cho cay BST
template <typename T>
class Node
{
public:
    // Thuoc tinh
    T data;
    Node *left, *right, *parent;
    // constructor
    Node()
    {
        Creat_Node();
    }
    // Phuong thuc
    void Creat_Node()
    {
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};
// Node cho danh sach lien ket
template <typename T>
class Node_list
{
public:
    // Thuoc tinh
    Node<T> data;
    Node_list *next;
    // constructor
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
// Xay dung hang doi
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
    //
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
    //
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
// Ngan Xep
template <typename T>
class Stack
{
public:
    // Thuoc tinh
    Node_list<T> *sp;
    // constructor
    Stack()
    {
        Create_Stack();
    }
    // Phuong thuc
    void Create_Stack()
    {
        this->sp = NULL;
    }
    //
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
    //
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
// Binary search tree (BST)
template <typename T>
class BST
{
public:
    // constructor
    BST()
    {
        Create_BST();
    }
    // destructor
    ~BST()
    {
        DestroyTree();
    }
    // Phuong thuc
    void Create_BST()
    {
        this->Root = NULL;
    }
    //
    void DestroyTree()
    {
        DESTROY_TREE(this->Root);
        this->Root = NULL;
    }
    //
    int InsertTree(T value)
    {
        return TREE_INSERT(this->Root, value);
    }
    //
    Node<T> *Timkey(T key)
    {
        return TREE_SEARCH(this->Root, key);
    }
    //
    Node<T> *XoaKey(T key)
    {
        Node<T> *temp;
        temp = TREE_SEARCH(this->Root, key);
        if (temp != NULL)
            return TREE_DELETE(this->Root, temp);
        return NULL;
    }
    //
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

    void DuyetRongTruoc()
    {
        BFS(this->Root);
    }

    void DuyetSauTruoc()
    {
        DFS(this->Root);
    }

    void Clone_Tree(Node<T> *temp)
    {
        this->Root = temp;
    }
    //
    void ThongTinCay()
    {
        INFO_TREE(this->Root);
    }
    //
    void Slg_Node(int &kq)
    {
        SOLUONG_NODE(this->Root, kq);
    }
    //
    void Value_Node_Truoc(int N)
    {
        Node<T> *temp;
        int index;
        temp = NULL;
        index = 1;
        NthPreordernode(this->Root, N, temp, index);

        if (temp != NULL)
            cout << temp->data << endl;
        else
            cout << "Khong tim thay node thu " << N << "!!!" << endl;
    }
    void Value_Node_Giua(int N)
    {
        Node<T> *temp;
        int index;
        temp = NULL;
        index = 1;
        NthInordernode(this->Root, N, temp, index);

        if (temp != NULL)
            cout << temp->data << endl;
        else
            cout << "Khong tim thay node thu " << N << "!!!" << endl;
    }
    void Value_Node_Sau(int N)
    {
        Node<T> *temp;
        int index;
        temp = NULL;
        index = 1;
        NthPostordernode(this->Root, N, temp, index);

        if (temp != NULL)
            cout << temp->data << endl;
        else
            cout << "Khong tim thay node thu " << N << "!!!" << endl;
    }
    //
    void Del_Node_Truoc(int N)
    {
        Node<T> *temp;
        int index;
        temp = NULL;
        index = 1;
        NthPreordernode(this->Root, N, temp, index);

        if (temp != NULL)
        {
            temp = TREE_DELETE(this->Root, temp);
            free(temp);
            cout << "Da xoa node thu " << N << " trong cay" << endl;
        }
        else
            cout << "Khong tim thay node thu " << N << "!!!" << endl;
    }
    void Del_Node_Giua(int N)
    {
        Node<T> *temp;
        int index;
        temp = NULL;
        index = 1;
        NthInordernode(this->Root, N, temp, index);

        if (temp != NULL)
        {
            temp = TREE_DELETE(this->Root, temp);
            free(temp);
            cout << "Da xoa node thu " << N << " trong cay" << endl;
        }
        else
            cout << "Khong tim thay node thu " << N << "!!!" << endl;
    }
    void Del_Node_Sau(int N)
    {
        Node<T> *temp;
        int index;
        temp = NULL;
        index = 1;
        NthPostordernode(this->Root, N, temp, index);

        if (temp != NULL)
        {
            temp = TREE_DELETE(this->Root, temp);
            free(temp);
            cout << "Da xoa node thu " << N << " trong cay" << endl;
        }
        else
            cout << "Khong tim thay node thu " << N << "!!!" << endl;
    }
    //
    Node<T> *SaoChepPreorder_N(int N)
    {
        Node<T> *temp;
        Node<T> *roottemp;
        int index;
        temp = NULL;
        roottemp = NULL;
        index = 1;
        NthPreordernode(this->Root, N, temp, index);
        if (temp != NULL)
        {
            Copy_Node(roottemp, temp);
        }
        return roottemp;
    }
    Node<T> *SaoChepInorder_N(int N)
    {
        Node<T> *temp;
        Node<T> *roottemp;
        int index;
        temp = NULL;
        roottemp = NULL;
        index = 1;
        NthInordernode(this->Root, N, temp, index);
        if (temp != NULL)
        {
            Copy_Node(roottemp, temp);
        }
        return roottemp;
    }
    Node<T> *SaoChepPostorder_N(int N)
    {
        Node<T> *temp;
        Node<T> *roottemp;
        int index;
        temp = NULL;
        roottemp = NULL;
        index = 1;
        NthPostordernode(this->Root, N, temp, index);
        if (temp != NULL)
        {
            Copy_Node(roottemp, temp);
        }
        return roottemp;
    }
    //
    //========TD=========//
    //
    void IN_THEO_CHAR(char key)
    {
        return TREE_SEARCH_CHAR(this->Root, key);
    }

    int ThongTinNode_TN(T key)
    {
        Node<T> *temp;
        temp = TREE_SEARCH(this->Root, key);
        if (temp != NULL)
        {
            cout << "Ket qua:" << endl;
            cout << temp->data << endl;
            return 1;
        }
        return 0;
    }

private:
    // Thuoc tinh
    Node<T> *Root;
    //
    // Phuong Thuc
    int TREE_INSERT(Node<T> *&Root, T value)
    {
        Node<T> *x, *y, *z;
        // z = new Node<T>(value);
        z = (Node<T> *)malloc(sizeof(Node<T>));
        if (z == NULL)
        {
            return 0;
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
        return 1;
    }
    //
    Node<T> *TREE_SEARCH(Node<T> *root, T key)
    {
        while ((root != NULL) && (root->data) != key)
        {
            if (key < root->data)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
    //
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
    // Duyet Truoc
    void PREORDER_TREE_WALK(Node<T> *R)
    {
        if (R != NULL)
        {
            cout << R->data << "\t";
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
            cout << R->data << "\t";
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
            cout << R->data << "\t";
        }
    }
    // Thuat toan duyet rong truoc BFS
    void BFS(Node<T> *Root)
    {
        Queue<T> HangDoi;
        Node<T> temp;
        if (Root == NULL)
            return;
        HangDoi.PushQ(*Root);
        while (HangDoi.Front != NULL)
        {
            HangDoi.PopQ(&temp);
            cout << temp.data << "\t";
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
        if (Root == NULL)
            return;
        NganXep.PushS(*Root);
        while (NganXep.sp != NULL)
        {
            NganXep.PopS(&temp);
            cout << temp.data << "\t";
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
    //
    void INFO_TREE(Node<T> *root)
    {
        if (root != NULL)
        {
            if (root->parent == NULL)
            {
                cout << root->data << " Goc" << endl;
            }
            else
            {
                if (root == (root->parent)->left)
                {
                    cout << root->data << " nut con trai cua " << (root->parent)->data << endl;
                }
                else
                {
                    cout << root->data << " nut con phai cua " << (root->parent)->data << endl;
                }
            }
            INFO_TREE(root->left);
            INFO_TREE(root->right);
        }
    }
    //
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
    void NthInordernode(Node<T> *R, int N, Node<T> *&temp, int &flag)
    {
        if (R != NULL)
        {
            NthInordernode(R->left, N, temp, flag);
            if (flag == N)
            {
                temp = R;
            }
            flag = flag + 1;
            NthInordernode(R->right, N, temp, flag);
        }
    }
    void NthPostordernode(Node<T> *R, int N, Node<T> *&temp, int &flag)
    {
        if (R != NULL)
        {
            NthPostordernode(R->left, N, temp, flag);
            NthPostordernode(R->right, N, temp, flag);
            if (flag == N)
            {
                temp = R;
            }
            flag = flag + 1;
        }
    }
    //
    void Copy_Node(Node<T> *&Roottemp, Node<T> *temp)
    {
        if (temp != NULL)
        {
            TREE_INSERT(Roottemp, temp->data);
            Copy_Node(Roottemp, temp->left);
            Copy_Node(Roottemp, temp->right);
        }
    }

    void SOLUONG_NODE(Node<T> *root, int &kq)
    {
        if (root != NULL)
        {
            SOLUONG_NODE(root->left, kq);
            kq += 1;
            SOLUONG_NODE(root->right, kq);
        }
    }
    //
    //=======TD=============
    void TREE_SEARCH_CHAR(Node<TuNgu> *root, char k)
    {
        if (root != NULL)
        {
            TREE_SEARCH_CHAR(root->left, k);
            if (root->data.TiengAnh[0] == k)
            {
                cout << root->data.TiengAnh << endl;
            }
            TREE_SEARCH_CHAR(root->right, k);
        }
    }
    //
    void DESTROY_TREE(Node<T> *&root)
    {
        if (root != NULL)
        {
            DESTROY_TREE(root->left);
            DESTROY_TREE(root->right);
            free(root);
        }
    }
};

class APP
{
public:
    APP()
    {
        this->GiaoDienChinh();
    }

private:
    int Xoa_Vung_Nho_Tam()
    {
        char temp;
        int trangthai = 0;
        temp = cin.get();
        if (temp == '\n')
        {
            trangthai = 0;
        }
        while (temp != '\n')
        {
            if (temp != ' ' && temp != '\t')
                trangthai = 1;
            temp = cin.get();
        }
        return trangthai;
    }

    int Nhap_TuVung(char A[], int slg)
    {
        char temp;
        int i;
        do
        {
            cout << "Nhap: ";
            i = 0;
            temp = cin.get();
            while (temp == '\n' || temp == ' ' || temp == '\t')
            {
                temp = cin.get();
            }
            while (((temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z')) && i < slg)
            {
                if (temp >= 'A' && temp <= 'Z')
                {
                    temp = temp + 32;
                }
                A[i] = temp;
                i = i + 1;
                temp = cin.get();
            }
            if (i != 0 && (temp == '\n' || ((temp == ' ' || temp == '\t') && Xoa_Vung_Nho_Tam() == 0)))
            {
                A[i] = '\0';
            }
            else
            {
                if (temp != ' ' && temp != '\t')
                {
                    Xoa_Vung_Nho_Tam();
                }
                if (slg != 1)
                    cout << "Co loi. Chi nhap ky tu chu, toi da la 20 ky tu va khong co khoang cach giua cac tu  !!!" << endl;
                else
                    cout << "Co loi. Chi nhap ky tu chu, toi da la 1 ky tu !!!" << endl;
                cout << "Thuc hien lai" << endl;
                continue;
            }
            cout << "Tu vua nhap la: " << A << endl;
            cout << "Nhan phim esc de nhap lai, enter xac nhan, space de thoat" << endl;
            while (1)
            {
                temp = getch();
                if (temp == 27 || temp == 13 || temp == 32)
                {
                    break;
                }
                cout << "Chi nhan 1 phim esc hoac enter hoac space !" << endl;
                cout << "Nhap lai: " << endl;
            }
            if (temp == 13)
                return 1;
            else if (temp == 32)
                return 0;
        } while (1);
    }

    void Nhap_char_so(char &temp)
    {
        do
        {
            temp = cin.get();
            while (temp == '\n' || temp == ' ' || temp == '\t')
            {
                temp = cin.get();
            }
            if (Xoa_Vung_Nho_Tam() == 1)
            {
                cout << "Chi nhap vao so nguyen co 1 chu so !!!" << endl;
                cout << "Nhap lai: ";
                continue;
            }
            if (temp >= '0' && temp <= '9')
                break;
            else
            {
                cout << "Chi nhap vao so nguyen!\n";
                cout << "Nhap lai 1 so nguyen va nhan enter: ";
            }
        } while (1);
    }

    char KieuT()
    {
        char temp;
        do
        {
            cout << "Lua chon kieu du lieu: ";
            cout.width(10);
            cout << "1. Int";
            cout.width(12);
            cout << "2. Float";
            cout.width(11);
            cout << "3. Char" << endl;
            cout << "Nhap: ";
            Nhap_char_so(temp);
            if (temp != '1' && temp != '2' && temp != '3')
            {
                cout << "Nhap lai !!!" << endl;
                cout << "Nhap vao 1 so nguyen tu 1 den 3 va nhan enter: " << endl;
            }
            else
                break;
        } while (1);
        return temp;
    }

    int Nhap(char T, int &x, float &y, char &z)
    {
        char c;
        do
        {
            cout << "Nhap: ";
            switch (T)
            {
            case '1':
                while (!(cin >> x))
                {
                    cout << "Co loi. Vui long chi nhap so nguyen" << endl;
                    cout << "Nhap lai: ";
                    cin.clear();
                    Xoa_Vung_Nho_Tam();
                };
                cout << "Ban vua nhap vao so: " << x << endl;
                break;
            case '2':
                while (!(cin >> y))
                {
                    cout << "Co loi. Vui long chi nhap so thuc" << endl;
                    cout << "Nhap lai: ";
                    cin.clear();
                    Xoa_Vung_Nho_Tam();
                };
                cout << "Ban vua nhap vao so: " << y << endl;
                break;
            case '3':
                while (!(cin >> z))
                {
                    cout << "Co loi. Vui long chi nhap mot ky tu" << endl;
                    cout << "Nhap lai: ";
                    cin.clear();
                    Xoa_Vung_Nho_Tam();
                };
                cout << "Ban vua nhap vao so: " << z << endl;
                break;
            default:
                break;
            }
            cout << "Nhan phim esc de nhap lai, enter xac nhan, space de thoat" << endl;
            while (1)
            {
                c = getch();
                if (c == 27 || c == 13 || c == 32)
                {
                    break;
                }
                cout << "Chi nhan 1 phim esc hoac enter hoac space !" << endl;
                cout << "Nhap lai: " << endl;
            }
            if (c == 13)
                return 1;
            else if (c == 32)
                return 0;
        } while (1);
    }

    char Lua_Chon_Duyet()
    {
        char c;
        do
        {
            cout << "Lua chon kieu duyet: ";
            cout.width(11);
            cout << "1. Giua";
            cout.width(12);
            cout << "2. Truoc";
            cout.width(10);
            cout << "3. Sau" << endl;
            cout << "Nhan mot phim:" << endl;
            ;
            c = getch();
            if (c == 49 || c == 50 || c == 51)
                break;
            cout << "Chi nhan phim 1 hoac 2 hoac 3 !!!" << endl;
        } while (1);
        return c;
    }
    //
    void GiaoDienChinh()
    {
        char temp;
        do
        {
            system("cls");
            cout << "\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                         MENU CHINH                            *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*   1. Nhap 1 de tao cay voi kieu T.                            *\n";
            cout << "*   2. Nhap 2 de su dung ung dung tu dien.                      *\n";
            cout << "*   3. Nhap 0 de thoat chuong trinh.                            *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "Nhap vao 1 so nguyen tu 0 den 2 va nhan enter: ";
            // goi ham nhap char
            do
            {
                Nhap_char_so(temp);
                if (temp != '1' && temp != '2' && temp != '0')
                {
                    cout << "Nhap lai !!!" << endl;
                    cout << "Nhap vao 1 so nguyen tu 0 den 2 va nhan enter: ";
                }
                else
                    break;
            } while (1);

            switch (temp)
            {
            case '1':
                GiaoDienSoMot();
                break;
            case '2':
                GiaoDienSoHai();
                break;
            default:
                break;
            }
            if (temp == '0')
            {
                cout << "Da chon 3" << endl;
                cout << "Thoat ..." << endl;
                break;
            }
        } while (1);
    }
    void GiaoDienSoMot()
    {
        int Tong, c, kq;
        char temp;
        char T;
        BST<int> Tree1;
        BST<float> Tree2;
        BST<char> Tree3;
        Node<int> *in;
        Node<float> *fl;
        Node<char> *ch;
        BST<int> tree1temp;
        BST<float> tree2temp;
        BST<char> tree3temp;
        int val1;
        float val2;
        char val3;
        T = '1'; // default = int
        do
        {
            Tong = 0;
            system("cls");
            switch (T)
            {
            case '1':
                Tree1.Slg_Node(Tong);
                break;
            case '2':
                Tree2.Slg_Node(Tong);
                break;
            case '3':
                Tree3.Slg_Node(Tong);
                break;
            default:
                break;
            }
            cout << "\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                                    MENU CAY KIEU T                                    *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*   1. Nhap 1 de tao cay voi kieu T.                                                    *\n";
            cout << "*   2. Nhap 2 de them node vao cay.                                                     *\n";
            cout << "*   3. Nhap 3 de tim kiem node trong cay.                                               *\n";
            cout << "*   4. Nhap 4 de xoa node khi biet key.                                                 *\n";
            cout << "*   5. Nhap 5 de duyet cay theo thu tu giua/truoc/sau.                                  *\n";
            cout << "*   6. Nhap 6 de duyet theo BFS/DFS.                                                    *\n";
            cout << "*   7. Nhap 7 de xem gia tri nut thu n theo thu tu giua/truoc/sau.                      *\n";
            cout << "*   8. Nhap 8 de xoa nut thu n theo thu tu giua/truoc/sau.                              *\n";
            cout << "*   9. Nhap 9 de them nut vao cay con co goc la nut thu n theo thu tu giua/truoc/sau.   *\n";
            cout << "*   10. Nhap 0 de xoa cay hien tai va quay tro lai menu chinh.                          *\n";
            cout << "*                                                                                       *\n";
            cout << "*   Kieu du lieu hien tai: ";
            cout.width(5);
            switch (T)
            {
            case '1':
                cout << left << "Int";
                break;
            case '2':
                cout << left << "Float";
                break;
            case '3':
                cout << left << "Char";
                break;
            default:
                break;
            }
            cout << "                                  So Node hien tai: ";
            cout.width(3);
            cout << left << Tong;
            cout << " *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "Nhap vao 1 so nguyen tu 0 den 9 va nhan enter: ";
            Nhap_char_so(temp);
            switch (temp)
            {
            case '1':
                cout << "  Luu y: lua chon nay se xoa cay hien tai" << endl;
                cout << "Nhan phim esc de huy hoac enter de tiep tuc: " << endl;
                while (1)
                {
                    c = getch();
                    if (c == 27 || c == 13)
                    {
                        break;
                    }
                    cout << "\nChi nhan 1 phim esc hoac enter !" << endl;
                    cout << "Nhap lai: " << endl;
                }
                if (c == 27)
                {
                    break;
                }
                else if (c == 13)
                {
                    switch (T)
                    {
                    case '1':
                        Tree1.DestroyTree();
                        break;
                    case '2':
                        Tree2.DestroyTree();
                        break;
                    case '3':
                        Tree3.DestroyTree();
                        break;
                    default:
                        break;
                    }
                }
                T = KieuT();
                break;
            case '2':
                do
                {
                    kq = Nhap(T, val1, val2, val3);
                    switch (T)
                    {
                    case '1':
                        if (kq == 1)
                        {
                            if (Tree1.Timkey(val1) == NULL && Tree1.InsertTree(val1) == 1)
                                cout << "Da them thanh cong" << endl;
                            else
                                cout << "Loi them that bai" << endl;
                        }
                        break;
                    case '2':
                        if (kq == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree2.Timkey(val2) == NULL && Tree2.InsertTree(val2) == 1)
                                cout << "Da them thanh cong" << endl;
                            else
                                cout << "Loi them that bai" << endl;
                        }
                        break;
                    case '3':
                        if (kq == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree3.Timkey(val3) == NULL && Tree3.InsertTree(val3) == 1)
                                cout << "Da them thanh cong" << endl;
                            else
                                cout << "Loi them that bai" << endl;
                        }
                        break;
                    default:
                        break;
                    }
                    if (kq == 0)
                        break;
                    cout << "--------------" << endl;
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    c = getch();
                    if (c == 27)
                    {
                        break;
                    }
                } while (1);

                break;
            case '3':
                do
                {
                    switch (T)
                    {
                    case '1':
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree1.Timkey(val1) != NULL)
                                cout << "Tim thay" << endl;
                            else
                                cout << "Khong tim thay" << endl;
                        }
                        break;
                    case '2':
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree2.Timkey(val2) != NULL)
                                cout << "Tim thay" << endl;
                            else
                                cout << "Khong tim thay" << endl;
                        }
                        break;
                    case '3':
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree3.Timkey(val3) != NULL)
                                cout << "Tim thay" << endl;
                            else
                                cout << "Khong tim thay" << endl;
                        }
                        break;
                    default:
                        break;
                    }
                    cout << "--------------" << endl;
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    c = getch();
                    if (c == 27)
                    {
                        break;
                    }
                } while (1);
                break;
            case '4':
                do
                {
                    switch (T)
                    {
                    case '1':
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree1.XoaKey(val1) != NULL)
                                cout << "Da Xoa" << endl;
                            else
                                cout << "Loi Khong The Xoa do khong co Key " << val1 << endl;
                        }
                        break;
                    case '2':
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree2.XoaKey(val2) != NULL)
                                cout << "Da Xoa" << endl;
                            else
                                cout << "Loi Khong The Xoa do khong co Key " << val2 << endl;
                        }
                        break;
                    case '3':
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree3.XoaKey(val3) != NULL)
                                cout << "Da Xoa" << endl;
                            else
                                cout << "Loi Khong The Xoa do khong co Key " << val3 << endl;
                        }
                        break;
                    default:
                        break;
                    }
                    cout << "--------------" << endl;
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    c = getch();
                    if (c == 27)
                    {
                        break;
                    }
                } while (1);
                break;
            case '5':
                do
                {
                    c = Lua_Chon_Duyet();
                    switch (T)
                    {
                    case '1':
                        cout << "Ket qua: ";
                        if (c == 49)
                        {
                            Tree1.DuyetGiua();
                        }
                        else if (c == 50)
                        {
                            Tree1.DuyetTruoc();
                        }
                        else if (c == 51)
                        {
                            Tree1.DuyetSau();
                        }
                        cout << endl;
                        break;
                    case '2':
                        cout << "Ket qua: ";
                        if (c == 49)
                        {
                            Tree2.DuyetGiua();
                        }
                        else if (c == 50)
                        {
                            Tree2.DuyetTruoc();
                        }
                        else if (c == 51)
                        {
                            Tree2.DuyetSau();
                        }
                        cout << endl;
                        break;
                    case '3':
                        cout << "Ket qua: ";
                        if (c == 49)
                        {
                            Tree3.DuyetGiua();
                        }
                        else if (c == 50)
                        {
                            Tree3.DuyetTruoc();
                        }
                        else if (c == 51)
                        {
                            Tree3.DuyetSau();
                        }
                        cout << endl;
                        break;
                    default:
                        break;
                    }
                    cout << "--------------" << endl;
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    c = getch();
                    if (c == 27)
                    {
                        break;
                    }
                } while (1);
                break;
            case '6':
                do
                {
                    do
                    {
                        cout << "Lua chon kieu duyet: ";
                        cout.width(29);
                        cout << "1. BFS(chieu rong truoc)";
                        cout.width(28);
                        cout << "2. DFS(chieu sau truoc)" << endl;
                        cout << "Nhan mot phim" << endl;
                        ;
                        c = getch();
                        if (c == 49 || c == 50)
                            break;
                        cout << "Chi nhan phim 1 hoac 2 !!!" << endl;
                    } while (1);
                    switch (T)
                    {
                    case '1':
                        cout << "Ket qua: ";
                        if (c == 49)
                        {
                            Tree1.DuyetRongTruoc();
                        }
                        else if (c == 50)
                        {
                            Tree1.DuyetSauTruoc();
                        }
                        cout << endl;
                        break;
                    case '2':
                        cout << "Ket qua: ";
                        if (c == 49)
                        {
                            Tree2.DuyetRongTruoc();
                        }
                        else if (c == 50)
                        {
                            Tree2.DuyetSauTruoc();
                        }
                        cout << endl;
                        break;
                    case '3':
                        cout << "Ket qua: ";
                        if (c == 49)
                        {
                            Tree3.DuyetRongTruoc();
                        }
                        else if (c == 50)
                        {
                            Tree3.DuyetSauTruoc();
                        }
                        cout << endl;
                        break;
                    default:
                        break;
                    }
                    cout << "--------------" << endl;
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    c = getch();
                    if (c == 27)
                    {
                        break;
                    }
                } while (1);
                break;
            case '7':
                do
                {
                    c = Lua_Chon_Duyet();
                    cout << "---Node thu N---" << endl;
                    if (Nhap('1', val1, val2, val3) == 0)
                        break;
                    switch (T)
                    {
                    case '1':
                        cout << "Ket qua: ";
                        if (c == 49)
                        {
                            Tree1.Value_Node_Giua(val1);
                        }
                        else if (c == 50)
                        {
                            Tree1.Value_Node_Truoc(val1);
                        }
                        else if (c == 51)
                        {
                            Tree1.Value_Node_Sau(val1);
                        }
                        break;
                    case '2':
                        cout << "Ket qua: ";
                        if (c == 49)
                        {
                            Tree2.Value_Node_Giua(val1);
                        }
                        else if (c == 50)
                        {
                            Tree2.Value_Node_Truoc(val1);
                        }
                        else if (c == 51)
                        {
                            Tree2.Value_Node_Sau(val1);
                        }
                        break;
                    case '3':
                        cout << "Ket qua: ";
                        if (c == 49)
                        {
                            Tree3.Value_Node_Giua(val1);
                        }
                        else if (c == 50)
                        {
                            Tree3.Value_Node_Truoc(val1);
                        }
                        else if (c == 51)
                        {
                            Tree3.Value_Node_Sau(val1);
                        }
                        break;
                    default:
                        break;
                    }
                    cout << "--------------" << endl;
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    c = getch();
                    if (c == 27)
                    {
                        break;
                    }
                } while (1);
                break;
            case '8':
                do
                {
                    c = Lua_Chon_Duyet();
                    cout << "---Node thu N---" << endl;
                    if (Nhap('1', val1, val2, val3) == 0)
                        break;
                    cout << "Ket qua: ";
                    switch (T)
                    {
                    case '1':
                        if (c == 49)
                        {
                            Tree1.Del_Node_Giua(val1);
                        }
                        else if (c == 50)
                        {
                            Tree1.Del_Node_Truoc(val1);
                        }
                        else if (c == 51)
                        {
                            Tree1.Del_Node_Sau(val1);
                        }
                        break;
                    case '2':
                        if (c == 49)
                        {
                            Tree2.Del_Node_Giua(val1);
                        }
                        else if (c == 50)
                        {
                            Tree2.Del_Node_Truoc(val1);
                        }
                        else if (c == 51)
                        {
                            Tree2.Del_Node_Sau(val1);
                        }
                        break;
                    case '3':
                        if (c == 49)
                        {
                            Tree3.Del_Node_Giua(val1);
                        }
                        else if (c == 50)
                        {
                            Tree3.Del_Node_Truoc(val1);
                        }
                        else if (c == 51)
                        {
                            Tree3.Del_Node_Sau(val1);
                        }
                        break;
                    default:
                        break;
                    }
                    cout << "--------------" << endl;
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    c = getch();
                    if (c == 27)
                    {
                        break;
                    }
                } while (1);
                break;
            case '9':
                do
                {
                    c = Lua_Chon_Duyet();
                    cout << "---Node thu N---" << endl;
                    if (Nhap('1', val1, val2, val3) == 0)
                        break;
                    switch (T)
                    {
                    case '1':
                        in = NULL;
                        if (c == 49)
                        {
                            in = Tree1.SaoChepInorder_N(val1);
                        }
                        else if (c == 50)
                        {
                            in = Tree1.SaoChepPreorder_N(val1);
                        }
                        else if (c == 51)
                        {
                            in = Tree1.SaoChepPostorder_N(val1);
                        }

                        if (in != NULL)
                        {
                            tree1temp.Clone_Tree(in);
                            do
                            {
                                Tong = 0;
                                cout << "---Gia tri node---" << endl;
                                kq = Nhap(T, val1, val2, val3);
                                if (kq == 0)
                                    break;
                                if (kq == 1)
                                {
                                    cout << "Ket qua: ";
                                    if (tree1temp.Timkey(val1) == NULL && tree1temp.InsertTree(val1) == 1)
                                        cout << "Da them thanh cong" << endl;
                                    else
                                        cout << "Loi them that bai" << endl;
                                }
                                tree1temp.Slg_Node(Tong);
                                cout << "Cay hien tai co: " << Tong << " Node" << endl;
                                tree1temp.ThongTinCay();
                                cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                                c = getch();
                                if (c == 27)
                                {
                                    cout << "  Luu y: thoat se xoa cay hien tai" << endl;
                                    cout << "Nhan phim esc de huy hoac enter de tiep tuc" << endl;
                                    while (1)
                                    {
                                        c = getch();
                                        if (c == 27 || c == 13)
                                        {
                                            break;
                                        }
                                        cout << "Chi nhan 1 phim esc hoac enter !" << endl;
                                        cout << "Nhap lai: " << endl;
                                    }
                                    if (c == 27)
                                    {
                                        break;
                                    }
                                    else if (c == 13)
                                    {
                                        tree1temp.DestroyTree();
                                        in = NULL;
                                        break;
                                    }
                                    if (c == 13)
                                        break;
                                }
                            } while (1);
                        }
                        else
                        {
                            cout << "Ket qua: ";
                            cout << "Khong tim thay node thu " << val1 << "!!!" << endl;
                        }
                        break;
                    case '2':
                        fl = NULL;
                        if (c == 49)
                        {
                            fl = Tree2.SaoChepInorder_N(val1);
                        }
                        else if (c == 50)
                        {
                            fl = Tree2.SaoChepPreorder_N(val1);
                        }
                        else if (c == 51)
                        {
                            fl = Tree2.SaoChepPostorder_N(val1);
                        }
                        if (fl != NULL)
                        {
                            tree2temp.Clone_Tree(fl);
                            do
                            {
                                Tong = 0;
                                cout << "---Gia tri node---" << endl;
                                kq = Nhap(T, val1, val2, val3);
                                if (kq == 0)
                                    break;
                                if (kq == 1)
                                {
                                    cout << "Ket qua: ";
                                    if (tree2temp.Timkey(val2) == NULL && tree2temp.InsertTree(val2) == 1)
                                        cout << "Da them thanh cong" << endl;
                                    else
                                        cout << "Loi them that bai" << endl;
                                }
                                tree2temp.Slg_Node(Tong);
                                cout << "Cay hien tai co: " << Tong << " Node" << endl;
                                tree2temp.ThongTinCay();
                                cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                                c = getch();
                                if (c == 27)
                                {
                                    cout << "  Luu y: thoat se xoa cay hien tai" << endl;
                                    cout << "Nhan phim esc de huy hoac enter de tiep tuc" << endl;
                                    while (1)
                                    {
                                        c = getch();
                                        if (c == 27 || c == 13)
                                        {
                                            break;
                                        }
                                        cout << "Chi nhan 1 phim esc hoac enter !" << endl;
                                        cout << "Nhap lai: " << endl;
                                    }
                                    if (c == 27)
                                    {
                                        break;
                                    }
                                    else if (c == 13)
                                    {
                                        tree2temp.DestroyTree();
                                        fl = NULL;
                                        break;
                                    }
                                    if (c == 13)
                                        break;
                                }
                            } while (1);
                        }
                        else
                        {
                            cout << "Ket qua: ";
                            cout << "Khong tim thay node thu " << val1 << "!!!" << endl;
                        }
                        break;
                    case '3':
                        ch = NULL;
                        if (c == 49)
                        {
                            ch = Tree3.SaoChepInorder_N(val1);
                        }
                        else if (c == 50)
                        {
                            ch = Tree3.SaoChepPreorder_N(val1);
                        }
                        else if (c == 51)
                        {
                            ch = Tree3.SaoChepPostorder_N(val1);
                        }

                        if (ch != NULL)
                        {
                            tree3temp.Clone_Tree(ch);
                            do
                            {
                                Tong = 0;
                                cout << "---Gia tri node---" << endl;
                                kq = Nhap(T, val1, val2, val3);
                                if (kq == 0)
                                    break;
                                if (kq == 1)
                                {
                                    cout << "Ket qua: ";
                                    if (tree3temp.Timkey(val3) == NULL && tree3temp.InsertTree(val3) == 1)
                                        cout << "Da them thanh cong" << endl;
                                    else
                                        cout << "Loi them that bai" << endl;
                                }
                                tree3temp.Slg_Node(Tong);
                                cout << "Cay hien tai co: " << Tong << " Node" << endl;
                                tree3temp.ThongTinCay();
                                cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                                c = getch();
                                if (c == 27)
                                {
                                    cout << "  Luu y: thoat se xoa cay hien tai" << endl;
                                    cout << "Nhan phim esc de huy hoac enter de tiep tuc" << endl;
                                    while (1)
                                    {
                                        c = getch();
                                        if (c == 27 || c == 13)
                                        {
                                            break;
                                        }
                                        cout << "Chi nhan 1 phim esc hoac enter !" << endl;
                                        cout << "Nhap lai: " << endl;
                                    }
                                    if (c == 27)
                                    {
                                        break;
                                    }
                                    else if (c == 13)
                                    {
                                        tree3temp.DestroyTree();
                                        ch = NULL;
                                        break;
                                    }
                                    if (c == 13)
                                        break;
                                }
                            } while (1);
                        }
                        else
                        {
                            cout << "Ket qua: ";
                            cout << "Khong tim thay node thu " << val1 << "!!!" << endl;
                        }
                        break;
                    default:
                        break;
                    }
                    cout << "--------------" << endl;
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    c = getch();
                    if (c == 27)
                    {
                        break;
                    }
                } while (1);
                break;
            default:
                break;
            }
            if (temp == '0')
            {
                Tree1.DestroyTree();
                Tree2.DestroyTree();
                Tree3.DestroyTree();
                cout << "Da chon 10" << endl;
                cout << "Thoat ..." << endl;
                break;
            }
        } while (1);
    }
    void GiaoDienSoHai()
    {
        char temp;
        int kq, Tong;
        BST<TuNgu> Tree_TN;
        TuNgu vocal;
        Node<TuNgu> *poin_TN;
        do
        {
            // taotudien
            Tong = 0;
            Tree_TN.Slg_Node(Tong);
            system("cls");
            cout << "\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                        MENU TU DIEN                           *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*   1. Nhap 1 de tra tu vung.                                   *\n";
            cout << "*   2. Nhap 2 de liet ke theo chu cai dau tien.                 *\n";
            cout << "*   3. Nhap 3 de them tu vung.                                  *\n";
            cout << "*   4. Nhap 4 de xoa tu vung.                                   *\n";
            cout << "*   5. Nhap 5 de chinh sua tu vung.                             *\n";
            cout << "*   6. Nhap 6 de tao file txt tu dien.                          *\n";
            cout << "*   7. Nhap 0 de thoat chuong trinh.                            *\n";
            cout << "*                                                               *\n";
            cout << "*   So tu vung: ";
            cout.width(47);
            cout << left << Tong;
            cout << " *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "Nhap vao 1 so nguyen tu 0 den 5 va nhan enter: ";
            //
            do
            {
                Nhap_char_so(temp);
                if (temp < '0' || temp > '5')
                {
                    cout << "Nhap lai !!!" << endl;
                    cout << "Nhap vao 1 so nguyen tu 0 den 6 va nhan enter: ";
                }
                else
                    break;
            } while (1);
            switch (temp)
            {
            case '1':
                do
                {
                    cout << "Tu vung can tra cuu" << endl;
                    kq = Nhap_TuVung(vocal.TiengAnh, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                    if (kq == 0)
                    {
                        cout << "Chua nhap tu can tra" << endl;
                        cout << "Nhan esc de thoat hoac phim bat ky de nhap lai" << endl;
                        temp = getch();
                        if (temp == 27)
                        {
                            break;
                        }
                    }
                    else
                    {
                        kq = Tree_TN.ThongTinNode_TN(vocal);
                        if (kq == 0)
                        {
                            cout << "Ket qua:";
                            cout << " khong tim thay tu " << vocal.TiengAnh << " trong tu dien !!!" << endl;
                        }
                    }
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    temp = getch();
                    if (temp == 27)
                    {
                        break;
                    }
                } while (1);
                break;
            case '2':
                do
                {
                    cout << "Ky tu can tim" << endl;
                    kq = Nhap_TuVung(vocal.TiengAnh, 1);
                    if (kq == 0)
                    {
                        cout << "Chua nhap ky tu can tim" << endl;
                        cout << "Nhan esc de thoat hoac phim bat ky de nhap lai" << endl;
                        temp = getch();
                        if (temp == 27)
                        {
                            break;
                        }
                    }
                    else
                    {
                        cout << "Ket qua:" << endl;
                        Tree_TN.IN_THEO_CHAR(vocal.TiengAnh[0]);
                        cout << "=======hoan thanh=======" << endl;
                    }
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    temp = getch();
                    if (temp == 27)
                    {
                        break;
                    }
                } while (1);

                break;
            case '3':
                do
                {
                    cout << "Tu tieng anh" << endl;
                    kq = Nhap_TuVung(vocal.TiengAnh, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                    while (kq == 0 || Tree_TN.Timkey(vocal) != NULL)
                    {
                        if (kq == 0)
                            cout << "Chua nhap tu tieng anh" << endl;
                        else
                            cout << "Da co " << vocal.TiengAnh << " trong tu dien !!!" << endl;
                        cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                        temp = getch();
                        if (temp == 27)
                        {
                            break;
                        }
                        cout << "Tu tieng anh" << endl;
                        kq = Nhap_TuVung(vocal.TiengAnh, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                    }
                    if (kq == 0)
                        break;
                    cout << "Nghia tieng viet" << endl;
                    kq = Nhap_TuVung(vocal.TiengViet, (sizeof(vocal.TiengViet) / sizeof(char)) - 1);
                    while (kq == 0)
                    {
                        cout << "Chua nhap nghia tieng viet" << endl;
                        cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                        temp = getch();
                        if (temp == 27)
                        {
                            break;
                        }
                        cout << "Nghia tieng viet" << endl;
                        kq = Nhap_TuVung(vocal.TiengViet, (sizeof(vocal.TiengViet) / sizeof(char)) - 1);
                    }
                    if (kq == 0)
                        break;
                    cout << "Tu loai" << endl;
                    kq = Nhap_TuVung(vocal.Tuloai, (sizeof(vocal.Tuloai) / sizeof(char)) - 1);
                    while (kq == 0)
                    {
                        cout << "Chua nhap tu loai" << endl;
                        cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                        temp = getch();
                        if (temp == 27)
                        {
                            break;
                        }
                        cout << "Tu loai" << endl;
                        kq = Nhap_TuVung(vocal.Tuloai, (sizeof(vocal.Tuloai) / sizeof(char)) - 1);
                    }
                    if (kq == 0)
                        break;
                    cout << "Vi du" << endl;
                    kq = Nhap_TuVung(vocal.Vidu, (sizeof(vocal.Vidu) / sizeof(char)) - 1);
                    while (kq == 0)
                    {
                        cout << "Chua nhap vi du" << endl;
                        cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                        temp = getch();
                        if (temp == 27)
                        {
                            break;
                        }
                        cout << "Vi du" << endl;
                        kq = Nhap_TuVung(vocal.Vidu, (sizeof(vocal.Vidu) / sizeof(char)) - 1);
                    }
                    if (kq == 0)
                        break;
                    //
                    if (Tree_TN.InsertTree(vocal) == 1)
                        cout << "Da them thanh cong" << endl;
                    else
                        cout << "Loi them that bai" << endl;
                    //
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    temp = getch();
                    if (temp == 27)
                    {
                        break;
                    }
                } while (1);
                break;
            case '4':
                do
                {
                    cout << "Tu vung tieng anh can xoa" << endl;
                    kq = Nhap_TuVung(vocal.TiengAnh, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                    if (kq == 0)
                    {
                        cout << "Chua nhap tu can xoa" << endl;
                        cout << "Nhan esc de thoat hoac phim bat ky de nhap lai" << endl;
                        temp = getch();
                        if (temp == 27)
                        {
                            break;
                        }
                    }
                    else
                    {
                        cout << "Ket qua:" << endl;
                        if (Tree_TN.XoaKey(vocal) != NULL)
                        {
                            cout << "Da xoa thanh cong tu: " << vocal.TiengAnh << endl;
                        }
                        else
                        {
                            cout << "Khong tim thay tu: " << vocal.TiengAnh << " trong tu dien" << endl;
                        }
                    }
                    cout << "=======hoan thanh=======" << endl;
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    temp = getch();
                    if (temp == 27)
                    {
                        break;
                    }
                } while (1);
                break;
            case '5':
                do
                {
                    cout << "Nhap tu vung tieng anh can chinh sua" << endl;
                    kq = Nhap_TuVung(vocal.TiengAnh, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                    if (kq == 0)
                    {
                        cout << "Chua nhap tu can chinh sua" << endl;
                        cout << "Nhan esc de thoat hoac phim bat ky de nhap lai" << endl;
                        temp = getch();
                        if (temp == 27)
                        {
                            break;
                        }
                    }
                    else
                    {
                        poin_TN = Tree_TN.Timkey(vocal);
                        if (poin_TN != NULL)
                        {
                            strcpy(vocal.TiengAnh, poin_TN->data.TiengAnh);
                            strcpy(vocal.TiengViet, poin_TN->data.TiengViet);
                            strcpy(vocal.Tuloai, poin_TN->data.Tuloai);
                            strcpy(vocal.Vidu, poin_TN->data.Vidu);
                            cout << "-------Thuc hien chinh sua-------" << endl;
                            //
                            cout << "Tu tieng anh hien tai: " << vocal.TiengAnh << endl;
                            cout << "Nhan esc de chinh sua hoac phim bat ky de giu nguyen" << endl;
                            temp = getch();
                            if (temp == 27)
                            {
                                cout << "---Tu tieng anh---" << endl;
                                kq = Nhap_TuVung(vocal.TiengAnh, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                                while (kq == 0)
                                {
                                    if (kq == 0)
                                        cout << "Chua nhap tu tieng anh" << endl;
                                    else
                                        cout << "Da co " << vocal.TiengAnh << " trong tu dien !!!" << endl;
                                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                                    temp = getch();
                                    if (temp == 27)
                                    {
                                        break;
                                    }
                                    cout << "---Tu tieng anh---" << endl;
                                    kq = Nhap_TuVung(vocal.TiengAnh, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                                }
                                if (kq == 0)
                                    break;
                            }
                            //
                            cout << "Tu tieng viet hien tai: " << vocal.TiengViet << endl;
                            cout << "Nhan esc de chinh sua hoac phim bat ky de giu nguyen" << endl;
                            temp = getch();
                            if (temp == 27)
                            {
                                cout << "---Nghia tieng viet---" << endl;
                                kq = Nhap_TuVung(vocal.TiengViet, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                                while (kq == 0)
                                {
                                    cout << "Chua nhap nghia tieng viet" << endl;
                                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                                    temp = getch();
                                    if (temp == 27)
                                    {
                                        break;
                                    }
                                    cout << "---Nghia tieng viet---" << endl;
                                    kq = Nhap_TuVung(vocal.TiengViet, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                                }
                                if (kq == 0)
                                    break;
                            }
                            //
                            cout << "Tu loai hien tai: " << vocal.Tuloai << endl;
                            cout << "Nhan esc de chinh sua hoac phim bat ky de giu nguyen" << endl;
                            temp = getch();
                            if (temp == 27)
                            {
                                cout << "---Tu loai---" << endl;
                                kq = Nhap_TuVung(vocal.Tuloai, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                                while (kq == 0)
                                {
                                    cout << "Chua nhap tu loai" << endl;
                                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                                    temp = getch();
                                    if (temp == 27)
                                    {
                                        break;
                                    }
                                    cout << "---Tu loai---" << endl;
                                    kq = Nhap_TuVung(vocal.Tuloai, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                                }
                                if (kq == 0)
                                    break;
                            }
                            //
                            cout << "Vi du hien tai: " << vocal.Vidu << endl;
                            cout << "Nhan esc de chinh sua hoac phim bat ky de giu nguyen" << endl;
                            temp = getch();
                            if (temp == 27)
                            {
                                cout << "---Vi du---" << endl;
                                kq = Nhap_TuVung(vocal.Vidu, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                                while (kq == 0)
                                {
                                    cout << "Chua nhap vi du" << endl;
                                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                                    temp = getch();
                                    if (temp == 27)
                                    {
                                        break;
                                    }
                                    cout << "---Vi du---" << endl;
                                    kq = Nhap_TuVung(vocal.Vidu, (sizeof(vocal.TiengAnh) / sizeof(char)) - 1);
                                }
                                if (kq == 0)
                                    break;
                            }
                            // kiem tra key
                            if (poin_TN->data != vocal)
                            {
                                poin_TN = Tree_TN.XoaKey(poin_TN->data);
                                if (poin_TN != NULL)
                                {
                                    if (Tree_TN.InsertTree(vocal) == 1)
                                        cout << "=======Da chinh sua thanh cong=======" << endl;
                                    else
                                        cout << "Co loi khong the thuc hien chinh sua" << endl;
                                }
                                else
                                {
                                    cout << "Co loi khong the thuc hien chinh sua" << endl;
                                }
                            }
                            else
                            {
                                strcpy(poin_TN->data.TiengViet, vocal.TiengViet);
                                strcpy(poin_TN->data.Tuloai, vocal.Tuloai);
                                strcpy(poin_TN->data.Vidu, vocal.Vidu);
                            }
                            //
                            cout << "-------Ket qua chinh sua-------" << endl;
                            cout << vocal << endl;
                            cout << "-------------------------------" << endl;
                        }
                        else
                        {
                            cout << "-------Ket qua: Khong tim thay tu-------" << vocal.TiengAnh << " trong cay" << endl;
                        }
                    }
                    cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                    temp = getch();
                    if (temp == 27)
                    {
                        break;
                    }
                } while (1);
                break;
            case '6':

                break;
            default:
                break;
            }
            if (temp == '0')
            {
                Tree_TN.DestroyTree();
                cout << "Da chon 7" << endl;
                cout << "Thoat ..." << endl;
                break;
            }
        } while (1);
    }
};

int main()
{
    APP main;
    return 0;
}
