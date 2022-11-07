#include <malloc.h>
#include <string.h>
#include <conio.h>
#include <iostream>
using namespace std;
//
class TuNgu
{
public:
    char TiengAnh[20]; // KEY
    char Tuloai[20];
    char TiengViet[20];
    char Vidu[20];
    TuNgu(char TiengAnh[], char Tuloai[], char TiengViet[], char Vidu[])
    {
        Create_TuNgu(TiengAnh, Tuloai, TiengViet, Vidu);
    }
    void Create_TuNgu(char TiengAnh[], char Tuloai[], char TiengViet[], char Vidu[])
    {
        strcpy(this->TiengAnh, TiengAnh);
        strcpy(this->TiengViet, TiengViet);
        strcpy(this->Tuloai, Tuloai);
        strcpy(this->Vidu, Vidu);
    }
    friend bool operator<(TuNgu A, TuNgu B)
    {
        if (strcmp(A.TiengAnh, B.TiengAnh) < 0)
        {
            return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &out, TuNgu temp)
    {
        out << temp.TiengAnh;
        return out;
    }
};
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
        Create_BST();
    }
    void Create_BST()
    {
        this->Root = NULL;
    }
    // destructor
    ~BST()
    {
        DestroyTree();
    }
    void DestroyTree()
    {
        DESTROY_TREE(this->Root);
        this->Root = NULL;
    }
    int InsertTree(T value)
    {
        return TREE_INSERT(this->Root, value);
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
    Node<TuNgu> *Timkey_TN(char key[])
    {
        return TREE_SEARCH_TN(this->Root, key);
    }
    Node<T> *Timkey(T key)
    {
        return TREE_SEARCH(this->Root, key);
    }
    Node<TuNgu> *XoaKey_TN(char key[])
    {
        Node<TuNgu> *temp;
        temp = TREE_SEARCH_TN(this->Root, key);
        if (temp != NULL)
        {
            return TREE_DELETE(this->Root, temp);
        }
        return NULL;
    }
    Node<T> *XoaKey(T key)
    {
        Node<T> *temp;
        temp = TREE_SEARCH(this->Root, key);
        if (temp != NULL)
            return TREE_DELETE(this->Root, temp);
        return NULL;
    }
    void ThongTinNode(char key[])
    {
        Node<TuNgu> *temp;
        temp = TREE_SEARCH_TN(this->Root, key);
        if (temp != NULL)
        {
            NODE_INFO(temp);
        }
        else
            cout << "Khong co key: " << key << " trong cay" << endl;
    }
    void Slg_Node(int &kq)
    {
        SOLUONG_NODE(this->Root, kq);
    }
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
            cout << "\nCo loi error" << endl;
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
    // Xoa mot nut khi biet key
    // tim key trong cay
    Node<TuNgu> *TREE_SEARCH_TN(Node<TuNgu> *x, char k[])
    {
        while ((x != NULL) && (strcmp(k, (x->data).TiengAnh) != 0))
        {
            if (strcmp(k, (x->data).TiengAnh) < 0)
                x = x->left;
            else
                x = x->right;
        }
        return x;
    }
    Node<T> *TREE_SEARCH(Node<T> *root, T key)
    {
        while ((root != NULL) && (root->data) != key)
        {
            if (root->data > key)
                root = root->left;
            else
                root = root->right;
        }
        return root;
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

    // b1 tim nut trai nhat // DUNG CHUNG
    Node<T> *TREE_MINIMUM(Node<T> *temp)
    {
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    // b2 Tim Successor // DUNG CHUNG
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
    // b3 xoa // DUNG CHUNG
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
    // in thong tin cua mot nut khi biet key
    void NODE_INFO(Node<TuNgu> *temp)
    {
        cout << (temp->data).TiengAnh;
        cout.width(10);
        cout << (temp->data).TiengViet;
        cout.width(10);
        cout << (temp->data).Tuloai;
        cout.width(10);
        cout << (temp->data).Vidu << endl;
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
    void Nhap_char(char &temp)
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
    void GiaoDienChinh()
    {
        char temp;
        do
        {
            cout << "\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*                         MENU CHINH                            *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "*   1. Nhap 1 de tao cay voi kieu T.                            *\n";
            cout << "*   2. Nhap 2 de su dung ung dung tu dien.                      *\n";
            cout << "*   3. Nhap 3 de thoat chuong trinh.                            *\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
            cout << "Nhap vao 1 so nguyen tu 1 den 3 va nhan enter: ";
            // goi ham nhap char
            do
            {
                Nhap_char(temp);
                if (temp != '1' && temp != '2' && temp != '3')
                {
                    cout << "Nhap lai !!!" << endl;
                    cout << "Nhap vao 1 so nguyen tu 1 den 3 va nhan enter: ";
                }
                else
                    break;
            } while (1);

            switch (temp)
            {
            case '1':
                cout << "Da chon 1" << endl;
                GiaoDienSoMot();
                break;
            case '2':
                cout << "Da chon 2" << endl;
                break;
            default:
                break;
            }
            if (temp == '3')
            {
                cout << "Da chon 3" << endl;
                cout << "Thoat ..." << endl;
                break;
            }
        } while (1);
    }
    char KieuT()
    {
        char temp;
        do
        {
            cout << "\nLua chon kieu du lieu: ";
            cout.width(10);
            cout << "1. Int";
            cout.width(12);
            cout << "2. Float";
            cout.width(11);
            cout << "3. Char" << endl;
            Nhap_char(temp);
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
            cout << "\nNhap: ";
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
                cout << "\nChi nhan 1 phim esc hoac enter hoac space !" << endl;
                cout << "Nhap lai: ";
            }
            if (c == 13)
                return 1;
            else if (c == 32)
                return 0;
        } while (1);
    }
    void GiaoDienSoMot()
    {
        int Tong, c;
        char temp;
        char T;
        BST<int> Tree1;
        BST<float> Tree2;
        BST<char> Tree3;
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
            cout << "*   0. Nhap 0 de quay tro lai menu chinh.                                               *\n";
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
            Nhap_char(temp);
            switch (temp)
            {
            case '1':
                cout << "  Luu y: lua chon nay se xoa cay hien tai" << endl;
                cout << "Nhan phim esc de huy hoac enter de tiep tuc: ";
                while (1)
                {
                    c = getch();
                    if (c == 27 || c == 13)
                    {
                        break;
                    }
                    cout << "\nChi nhan 1 phim esc hoac enter !" << endl;
                    cout << "Nhap lai: ";
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
                    switch (T)
                    {
                    case '1':
                        // nếu người dùng nhập khác data lựa chọn
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            if (Tree1.Timkey(val1) == NULL && Tree1.InsertTree(val1) == 1)
                                cout << "Da them thanh cong" << endl;
                            else
                                cout << "Loi them that bai" << endl;
                        }
                        break;
                    case '2':
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree2.Timkey(val2) == NULL && Tree2.InsertTree(val2) == 1)
                                cout << "Da them thanh cong" << endl;
                            else
                                cout << "Loi them that bai" << endl;
                        }
                        break;
                    case '3':
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            // Kiem tra trung

                            //
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
                        // nếu người dùng nhập khác data lựa chọn
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
                            if (Tree1.Timkey(val2) != NULL)
                                cout << "Tim thay" << endl;
                            else
                                cout << "Khong tim thay" << endl;
                        }
                        break;
                    case '3':
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree1.Timkey(val3) != NULL)
                                cout << "Tim thay" << endl;
                            else
                                cout << "Khong tim thay" << endl;
                        }
                        break;
                    default:
                        break;
                    }
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
                        // nếu người dùng nhập khác data lựa chọn
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree1.XoaKey(val1) != NULL)
                                cout << "Da Xoa" << endl;
                            else
                                cout << "Loi Khong The Xoa. Do Khong co Key: " << val1 << endl;
                        }
                        break;
                    case '2':
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree1.XoaKey(val2) != NULL)
                                cout << "Da Xoa" << endl;
                            else
                                cout << "Loi Khong The Xoa. Do Khong co Key: " << val2 << endl;
                        }
                        break;
                    case '3':
                        if (Nhap(T, val1, val2, val3) == 1)
                        {
                            cout << "Ket qua: ";
                            if (Tree1.XoaKey(val3) != NULL)
                                cout << "Da Xoa" << endl;
                            else
                                cout << "Loi Khong The Xoa. Do Khong co Key: " << val3 << endl;
                        }
                        break;
                    default:
                        break;
                    }
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
                    do
                    {
                        cout << "\nLua chon kieu duyet: ";
                        cout.width(11);
                        cout << "1. Giua";
                        cout.width(12);
                        cout << "2. Truoc";
                        cout.width(10);
                        cout << "3. Sau" << endl;
                        cout << "Nhan mot phim: ";
                        c = getch();
                        if (c == 49 || c == 50 || c == 51)
                            break;
                        cout << "\nChi nhan phim 1 hoac 2 hoac 3 !!!" << endl;
                    } while (1);
                    switch (T)
                    {
                    case '1':
                        cout << "\nKet qua: ";
                        if (c == 49)
                        {
                            Tree1.DuyetGiua();
                            cout << endl;
                        }
                        else if (c == 50)
                        {
                            Tree1.DuyetTruoc();
                            cout << endl;
                        }
                        else if (c == 51)
                        {
                            Tree1.DuyetSau();
                            cout << endl;
                        }
                        break;
                    case '2':
                        cout << "\nKet qua: ";
                        if (c == 49)
                        {
                            Tree2.DuyetGiua();
                            cout << endl;
                        }
                        else if (c == 50)
                        {
                            Tree2.DuyetTruoc();
                            cout << endl;
                        }
                        else if (c == 51)
                        {
                            Tree2.DuyetSau();
                            cout << endl;
                        }
                        break;
                    case '3':
                        cout << "\nKet qua: ";
                        if (c == 49)
                        {
                            Tree3.DuyetGiua();
                            cout << endl;
                        }
                        else if (c == 50)
                        {
                            Tree3.DuyetTruoc();
                            cout << endl;
                        }
                        else if (c == 51)
                        {
                            Tree3.DuyetSau();
                            cout << endl;
                        }
                        break;
                    default:
                        break;
                    }
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
                        cout << "\nLua chon kieu duyet: ";
                        cout.width(29);
                        cout << "1. BFS(chieu rong truoc)";
                        cout.width(28);
                        cout << "2. DFS(chieu sau truoc)" << endl;
                        cout << "Nhan mot phim: ";
                        c = getch();
                        if (c == 49 || c == 50)
                            break;
                        cout << "\nChi nhan phim 1 hoac 2 !!!" << endl;
                    } while (1);
                    switch (T)
                    {
                    case '1':
                        cout << "\nKet qua: ";
                        if (c == 49)
                        {
                            Tree1.DuyetRongTruoc();
                            cout << endl;
                        }
                        else if (c == 50)
                        {
                            Tree1.DuyetSauTruoc();
                            cout << endl;
                        }
                        break;
                    case '2':
                        cout << "\nKet qua: ";
                        if (c == 49)
                        {
                            Tree2.DuyetRongTruoc();
                            cout << endl;
                        }
                        else if (c == 50)
                        {
                            Tree2.DuyetSauTruoc();
                            cout << endl;
                        }
                        break;
                    case '3':
                        cout << "\nKet qua: ";
                        if (c == 49)
                        {
                            Tree3.DuyetRongTruoc();
                            cout << endl;
                        }
                        else if (c == 50)
                        {
                            Tree3.DuyetSauTruoc();
                            cout << endl;
                        }
                        break;
                    default:
                        break;
                    }
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
                    do
                    {
                        cout << "\nLua chon kieu duyet: ";
                        cout.width(11);
                        cout << "1. Giua";
                        cout.width(12);
                        cout << "2. Truoc";
                        cout.width(10);
                        cout << "3. Sau" << endl;
                        cout << "Nhan mot phim: ";
                        c = getch();
                        if (c == 49 || c == 50 || c == 51)
                            break;
                        cout << "\nChi nhan phim 1 hoac 2 hoac 3 !!!" << endl;
                    } while (1);
                    cout << "\nNode thu N";
                    val1 = -1;
                    while (Nhap('1', val1, val2, val3) == 0)
                    {
                        cout << "Nhan esc de thoat hoac phim bat ky de tiep tuc" << endl;
                        c = getch();
                        if (c == 27)
                        {
                            break;
                        }
                        cout << "\nNode thu N";
                    }
                    if (val1 == -1)
                        break;
                    switch (T)
                    {
                    case '1':
                        cout << "\nKet qua: ";
                        if (c == 49)
                        {
                             Tree1.DuyetTruoc();
                            cout << endl;
                        }
                        else if (c == 50)
                        {
                            Tree1.Value_Node_Truoc(val1);
                            cout << endl;
                        }
                        else if (c == 51)
                        {
                            Tree1.DuyetSau();
                            cout << endl;
                        }
                        break;
                    case '2':
                        cout << "\nKet qua: ";
                        if (c == 49)
                        {
                            Tree2.DuyetGiua();
                            cout << endl;
                        }
                        else if (c == 50)
                        {
                            Tree2.DuyetTruoc();
                            cout << endl;
                        }
                        else if (c == 51)
                        {
                            Tree2.DuyetSau();
                            cout << endl;
                        }
                        break;
                    case '3':
                        cout << "\nKet qua: ";
                        if (c == 49)
                        {
                            Tree3.DuyetGiua();
                            cout << endl;
                        }
                        else if (c == 50)
                        {
                            Tree3.DuyetTruoc();
                            cout << endl;
                        }
                        else if (c == 51)
                        {
                            Tree3.DuyetSau();
                            cout << endl;
                        }
                        break;
                    default:
                        break;
                    }
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
                cout << "Da chon 0" << endl;
                cout << "Thoat ..." << endl;
                break;
            }
        } while (1);
    }
};

int main()
{
    // BST<int> Tree;
    // Tree.InsertTree(12);
    // Tree.InsertTree(18);
    // Tree.InsertTree(5);
    // Tree.InsertTree(5);
    // Tree.InsertTree(2);
    // Tree.InsertTree(9);
    // Tree.InsertTree(15);
    // Tree.InsertTree(19);
    // Tree.InsertTree(17);
    // if (Tree.Timkey(7) != NULL)
    //     cout << "Tim thay" << endl;
    // else
    //     cout << "Khong tim thay" << endl;
    // Tree.DuyetRongTruoc();
    // cout << endl;
    // Tree.DuyetSauTruoc();
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
    // TuNgu a1("hello4", "danhtu", "xin chao", "hello co");
    // TuNgu a2("hello2", "danhtu", "xin chao", "hello co");
    // TuNgu a3("hello3", "danhtu", "xin chao", "hello co");
    // TuNgu a4("hello7", "danhtu", "xin chao", "hello co");
    // TuNgu a5("hello6", "danhtu", "xin chao", "hello co");
    // TuNgu a6("hello8", "danhtu", "xin chao", "hello co");
    // BST<TuNgu> Tree;
    // Tree.InsertTree(a1);
    // Tree.InsertTree(a2);
    // Tree.InsertTree(a3);
    // Tree.InsertTree(a4);
    // Tree.InsertTree(a5);
    // Tree.InsertTree(a6);
    // Tree.DuyetGiua();
    // test xoa key
    //  if (Tree.XoaKey(a4) == NULL)
    //      cout << "Khong tim thay" << endl;
    //  else
    //      cout << "Tim thay" << endl;
    //  Tree.DuyetGiua();
    //
    // if (Tree.XoaKey("hello3") != NULL)
    //     cout << "Tim thay/ da xoa" << endl;
    // else
    //     cout << "khong tim thay" << endl;
    //  Tree.DuyetGiua();
    // Tree.ThongTinNode("hello8");
    //
    // =================================Phan code goi chay giao dien===================================
    APP main;

    return 0;
}
