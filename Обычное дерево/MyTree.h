#ifndef MYTREE_H_INCLUDED
#define MYTREE_H_INCLUDED

#include <vector>
#include <stdarg.h>     //��� �������������� ����������

template <typename T>
class Tree
{
protected:
    struct Node
    {
        T info;                         //������ ����
        std::vector<Node*> node_ptr;    //������ ���������� �� ����������
    };

    Node *add_1;                        //��������� �� ������
    int count_;                          //���������� �����

    void del(Node *ptr)
    {//�������� ��� �������� ��������� ������ ��� ~Tree
        int cnt = ptr->node_ptr.size();     //���������� ����������� � ����
        std::cout << "*_ " << ptr->info << " _* ";
        if(cnt > 0)
            for(int i = 0; i < cnt; i++)
            {
                del(ptr->node_ptr[i]);       //��������������� ������ ����������
            }
        delete ptr;
        return;
    }

    void prnt(Node *ptr)
    {//�������� ��� ������ ��������� ������
        int cnt = ptr->node_ptr.size();         //���������� ����������� � ����
        std::cout << " ( " << ptr->info << " ";
        if(cnt > 0)
            for(int i = 0; i < cnt; i++)
            {
                prnt(ptr->node_ptr[i]);         //��������������� ������ ����������
            }
        std::cout << ")";
        return;
    }

    void fnd(Node* ptr, bool &f, T inf)
    {//�������� ��� ������ �������� �� ��������
        if(f == true) return;
        if(ptr->info == inf)
        {
            f = true;
            return;
        }
        int cnt = ptr->node_ptr.size();     //���������� ����������� � ����
        if(cnt > 0)
        {
            for(int i = 0; i < cnt; i++)
            {
                fnd(ptr->node_ptr[i], f, inf);
            }
        }
        return;
    }

    void hght(Node* ptr, int& max_height)
    {//�������� ��� �������� ������
        int cnt = ptr->node_ptr.size();
        if(cnt == 0) return;                //��� ����

        int m = max_height;
        int mxh;
        for(int i = 0; i < cnt; i++)
        {
            mxh = m;
            hght(ptr->node_ptr[i], ++mxh);
            if(mxh > max_height) max_height = mxh;
        }
    }

    void pth(Node* ptr, const T& inf, std::vector<int>& paths, int path_)
    {//�������� ��� ������ �����
        if(ptr->info == inf)
                paths.push_back(path_);
        int cnt = ptr->node_ptr.size();
        if(cnt == 0) return;                //��� ����

        int p = path_;
        for(int i = 0; i < cnt; i++)
        {
            path_ = p;
            pth(ptr->node_ptr[i], inf, paths, ++path_);
        }
        return;
    }

    void smm(Node* ptr, T& s)
    {//�������� ��� ���������� ����� �����
        s += ptr->info;
        int cnt = ptr->node_ptr.size();
        for(int i = 0; i < cnt; i++)
        {
            smm(ptr->node_ptr[i], s);
        }
        return;
    }
public:
    Tree()
    {
        add_1 = nullptr;
        count_ = 0;
    }
    Tree(T inf)
    {
        add_1 = new Node;
        add_1->info = inf;
        count_ = 1;
    }

    void push(T inf, unsigned int level, ...)   //level - ���������� �������(�����) �� ������� ����� ����������
    {                                           //0 - ������, 1 - ���������� ����� � ��� �����
                                                //... - ������� ����� ������� � 0
        if(add_1 == nullptr)
        {
            if(level == 0)
            {
                add_1 = new Node;
                add_1->info = inf;
                count_ = 1;
                return;
            }
            else
            {
                std::cout << "\n--Tree.pop()--\nIndexError\n";
                return;
            }
        }
        if(level == 0)
        {   //���� ������, �� ��������� ����� � ����
            add_1->node_ptr.push_back(new Node);
            int cnt = add_1->node_ptr.size() - 1;   //�������� 1, ����� �������� ������
            add_1->node_ptr[cnt]->info = inf;
            count_++;
            return;
        }

        va_list ptr;
        va_start(ptr, level);       //��� �������� �� �������������� ����������
        Node* buf_add = add_1;

        for(unsigned int i = 0; i < level; i++)
        {
            static int cnt;
            cnt = buf_add->node_ptr.size() - 1;  //�������� 1, ����� �������� ������
            static int arg;
            arg = va_arg(ptr, int);
            if(arg > cnt)
            {   //��������� ����� ������ �� �������� ������������ ��������
                std::cout << "\n--Tree.push()--\nIndexError\n";
                return;
            }
            buf_add = buf_add->node_ptr[arg];
        }
        va_end(ptr);        //������� ���������

        buf_add->node_ptr.push_back(new Node);
        int cnt = buf_add->node_ptr.size() - 1;     //�������� 1, ����� �������� ������
        buf_add->node_ptr[cnt]->info = inf;
        count_++;
        return;
    }

    void print() //����� ������ � ������ ������� (������ � ���������� ����� ������)
    {
        if(add_1 == nullptr)
        {
            std::cout << "( )";
        }
        else prnt(add_1);
    }

    T pop(unsigned int level = 0, ...)  //level - ���������� �������(�����) �� ������� �����
    {                               //����������, 0 - ������, 1 - ���������� ����� � ��� �����
        //... - ������� ����� ������� � 0
        //������� �� ��������� � ������ �������� � ���� ��� �� ����, �� ���� ����� ������ ����
        //� ����������� ���.
        if(add_1 == nullptr) //� ������ ��� ���� �����
        {
            std::cout << "Tree is empty\n";
            return 0;
        }
        if(add_1->node_ptr.size() == 0) //� ������ ������ ������ ��� �����������
        {
            if(level == 0)
            {
                T inf = add_1->info;
                delete add_1;
                add_1 = nullptr;
                count_ = 0;
                return inf;
            }
            else
            {
                std::cout << "\n--Tree.pop()--\nIndexError\n";
                return 0;
            }
        }

        Node *buf_add = add_1;
        Node *old_add;
        int cnt;
        int arg;
        if(level > 0)
        {
            va_list ptr;
            va_start(ptr, level);

            for(unsigned int i = 0; i < level; i++)
            {
                cnt = buf_add->node_ptr.size() - 1;
                arg = va_arg(ptr, int);
                if(arg > cnt)
                {   //��������� ����� ������ �� �������� ������������ ��������
                    std::cout << "\n--Tree.pop()--\nIndexError\n";
                    return 0;
                }
                old_add = buf_add;
                buf_add = buf_add->node_ptr[arg];
            }
            va_end(ptr);
        }
        //����� �� ��������� � ������ ��������
        cnt = buf_add->node_ptr.size();

        if(cnt > 0) //���� ��� �� ����
        {
            do
            {
                old_add = buf_add;
                buf_add = buf_add->node_ptr[cnt - 1];
                cnt = buf_add->node_ptr.size();
            }while(cnt);                        //���� �� ����� �� �����
            cnt = old_add->node_ptr.size() - 1; //������ ����� ����� � ���������� ���������
        }
        else cnt = arg;                         //��� ���� � ������ ��� ������ �� � ����� �������

        T inf = buf_add->info;

        delete old_add->node_ptr[cnt];                              //��, ��� �������� �� ����
        old_add->node_ptr.erase(old_add->node_ptr.begin() + cnt);   //��� ������� �������
        count_++;
        return inf;
    }

    bool find(T inf) //True - ����� ��-� ������
    {
        if(add_1 == nullptr) return false;
        bool f = false;
        fnd(add_1, f, inf);
        return f;
    }

    int count()     //���������� ���������� �����
    {
        return count_;
    }

    int height()        //���������� ������ ������
    {
        if(add_1 == nullptr) return 0;      //������ ������
        int cnt = add_1->node_ptr.size();
        if(cnt == 0) return 1;              //������ ������

        int max_height = 1;
        int mxh;
        for(int i = 0; i < cnt; i++)
        {
            mxh = 1; //������� ��������
            hght(add_1->node_ptr[i], ++mxh);
            if(mxh > max_height) max_height = mxh;
        }
        return max_height;
    }

    void path(const T& inf, std::vector<int> &paths)//������� ����� ���� �� ����� �� ���������� ����
    {
        paths.clear();
        if(add_1 == nullptr) return;        //������ ������

        if(add_1->info == inf)
                paths.push_back(1);

        int cnt = add_1->node_ptr.size();
        if(cnt == 0) return;     //������ ������

        int path_;
        for(int i = 0; i < cnt; i++)
        {
            path_ = 1; //������� ����
            pth(add_1->node_ptr[i], inf, paths, ++path_);
        }
        return;
    }

    T sum(Tree<T> &tr) //���������� ����� �������� ���� �����
    {
        T s = 0;
        if(this->add_1)
            smm(this->add_1, s);
        if(tr.add_1)
            smm(tr.add_1, s);
        return s;
    }

    ~Tree()
    {
        std::cout << "Destructor is worked. Tree Nodes:\n";
        if(add_1 == nullptr)
        {
            std::cout << "Tree is empty\n";
        }
        else del(add_1);
        std::cout << "\n";
    }

    bool operator>(const Tree<T> &tr) const;
    bool operator<(const Tree<T> &tr) const;
    bool operator==(const Tree<T> &tr) const;
    bool operator!=(const Tree<T> &tr) const;

};

template <typename T>
bool Tree<T>::operator>(const Tree<T> &tr) const
{
    return (this->count_ > tr.count_);
}
template <typename T>

bool Tree<T>::operator<(const Tree<T> &tr) const
{
    return (this->count_ < tr.count_);
}

template <typename T>
bool Tree<T>::operator==(const Tree<T> &tr) const
{
    return (this->count_ == tr.count_);
}

template <typename T>
bool Tree<T>::operator!=(const Tree<T> &tr) const
{
    return (this->count_ != tr.count_);
}
#endif // MYTREE_H_INCLUDED
