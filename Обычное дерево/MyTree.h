#ifndef MYTREE_H_INCLUDED
#define MYTREE_H_INCLUDED

#include <vector>
#include <stdarg.h>     //для необязательных аргументов

template <typename T>
class Tree
{
protected:
    struct Node
    {
        T info;                         //Данные узла
        std::vector<Node*> node_ptr;    //Вектор указателей на поддеревья
    };

    Node *add_1;                        //Указатель на корень
    int count_;                          //Количество узлов

    void del(Node *ptr)
    {//рекурсия для удаления поддерева дерева для ~Tree
        int cnt = ptr->node_ptr.size();     //Количество поддеревьев у узла
        std::cout << "*_ " << ptr->info << " _* ";
        if(cnt > 0)
            for(int i = 0; i < cnt; i++)
            {
                del(ptr->node_ptr[i]);       //Рассматриваются другие поддеревья
            }
        delete ptr;
        return;
    }

    void prnt(Node *ptr)
    {//рекурсия для вывода поддерева дерева
        int cnt = ptr->node_ptr.size();         //Количество поддеревьев у узла
        std::cout << " ( " << ptr->info << " ";
        if(cnt > 0)
            for(int i = 0; i < cnt; i++)
            {
                prnt(ptr->node_ptr[i]);         //Рассматриваются другие поддеревья
            }
        std::cout << ")";
        return;
    }

    void fnd(Node* ptr, bool &f, T inf)
    {//рекурсия для поиска елемента по значению
        if(f == true) return;
        if(ptr->info == inf)
        {
            f = true;
            return;
        }
        int cnt = ptr->node_ptr.size();     //Количество поддеревьев у узла
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
    {//рекурсия для подсчета высоты
        int cnt = ptr->node_ptr.size();
        if(cnt == 0) return;                //Это лист

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
    {//рекурсия для поиска путей
        if(ptr->info == inf)
                paths.push_back(path_);
        int cnt = ptr->node_ptr.size();
        if(cnt == 0) return;                //Это лист

        int p = path_;
        for(int i = 0; i < cnt; i++)
        {
            path_ = p;
            pth(ptr->node_ptr[i], inf, paths, ++path_);
        }
        return;
    }

    void smm(Node* ptr, T& s)
    {//рекурсия для вычисления суммы узлов
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

    void push(T inf, unsigned int level, ...)   //level - количество уровней(узлов) на которые нужно спуститься
    {                                           //0 - корень, 1 - поддеревья корня и так далее
                                                //... - индексы узлов начиная с 0
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
        {   //Если корень, то добавляем сразу в него
            add_1->node_ptr.push_back(new Node);
            int cnt = add_1->node_ptr.size() - 1;   //Вычитаем 1, чтобы получить индекс
            add_1->node_ptr[cnt]->info = inf;
            count_++;
            return;
        }

        va_list ptr;
        va_start(ptr, level);       //Для перехода по необязательным параметрам
        Node* buf_add = add_1;

        for(unsigned int i = 0; i < level; i++)
        {
            static int cnt;
            cnt = buf_add->node_ptr.size() - 1;  //Вычитаем 1, чтобы получить индекс
            static int arg;
            arg = va_arg(ptr, int);
            if(arg > cnt)
            {   //Проверяем чтобы индекс не превышал существующее значение
                std::cout << "\n--Tree.push()--\nIndexError\n";
                return;
            }
            buf_add = buf_add->node_ptr[arg];
        }
        va_end(ptr);        //Очищаем указатель

        buf_add->node_ptr.push_back(new Node);
        int cnt = buf_add->node_ptr.size() - 1;     //Вычитаем 1, чтобы получить индекс
        buf_add->node_ptr[cnt]->info = inf;
        count_++;
        return;
    }

    void print() //Вывод дерева в прямом порядке (корень и поддеревья слева напрво)
    {
        if(add_1 == nullptr)
        {
            std::cout << "( )";
        }
        else prnt(add_1);
    }

    T pop(unsigned int level = 0, ...)  //level - количество уровней(узлов) на которые нужно
    {                               //спуститься, 0 - корень, 1 - поддеревья корня и так далее
        //... - индексы узлов начиная с 0
        //Доходит до поддерева с нужным индексом и если это НЕ лист, то ищет самый правый лист
        //и выталкивает его.
        if(add_1 == nullptr) //В дереве нет даже корня
        {
            std::cout << "Tree is empty\n";
            return 0;
        }
        if(add_1->node_ptr.size() == 0) //В дереве только корень без поддеревьев
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
                {   //Проверяем чтобы индекс не превышал существующее значение
                    std::cout << "\n--Tree.pop()--\nIndexError\n";
                    return 0;
                }
                old_add = buf_add;
                buf_add = buf_add->node_ptr[arg];
            }
            va_end(ptr);
        }
        //Дошли до поддерева с нужным индексом
        cnt = buf_add->node_ptr.size();

        if(cnt > 0) //Если это НЕ лист
        {
            do
            {
                old_add = buf_add;
                buf_add = buf_add->node_ptr[cnt - 1];
                cnt = buf_add->node_ptr.size();
            }while(cnt);                        //Пока не дойдём до листа
            cnt = old_add->node_ptr.size() - 1; //Индекс этого листа в предыдущем поддереве
        }
        else cnt = arg;                         //Это лист и значит его индекс не в конце вектора

        T inf = buf_add->info;

        delete old_add->node_ptr[cnt];                              //То, что выделили из кучи
        old_add->node_ptr.erase(old_add->node_ptr.begin() + cnt);   //Сам элемент вектора
        count_++;
        return inf;
    }

    bool find(T inf) //True - такой эл-т найден
    {
        if(add_1 == nullptr) return false;
        bool f = false;
        fnd(add_1, f, inf);
        return f;
    }

    int count()     //Возвращает количество узлов
    {
        return count_;
    }

    int height()        //Возвращает высоту дерева
    {
        if(add_1 == nullptr) return 0;      //Пустое дерево
        int cnt = add_1->node_ptr.size();
        if(cnt == 0) return 1;              //Только корень

        int max_height = 1;
        int mxh;
        for(int i = 0; i < cnt; i++)
        {
            mxh = 1; //Текущий максимум
            hght(add_1->node_ptr[i], ++mxh);
            if(mxh > max_height) max_height = mxh;
        }
        return max_height;
    }

    void path(const T& inf, std::vector<int> &paths)//подсчёт длины пути от корня до указанного узла
    {
        paths.clear();
        if(add_1 == nullptr) return;        //Дерево пустое

        if(add_1->info == inf)
                paths.push_back(1);

        int cnt = add_1->node_ptr.size();
        if(cnt == 0) return;     //Только корень

        int path_;
        for(int i = 0; i < cnt; i++)
        {
            path_ = 1; //Текущий путь
            pth(add_1->node_ptr[i], inf, paths, ++path_);
        }
        return;
    }

    T sum(Tree<T> &tr) //Возвращает сумму значений всех узлов
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
