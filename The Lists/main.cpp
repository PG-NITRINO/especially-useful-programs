#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class List
{
private:
    Node* head;
public:
    List()
    {
        head = NULL;
    }

    void create_last(int d) //ставиться в конец
    {
        Node* new_node = new Node;
        new_node->data = d;
        new_node->next = NULL;

        if(head == NULL)
            head = new_node;
        else
        {
            Node* current;
            current = head;
            while(current->next != NULL)
                current = current->next;

            current->next = new_node;
        }
    }

    void create_first(int d)  //первый эл-т становиться вторым
    {
        Node* new_node = new Node;
        new_node->data = d;
        new_node->next = head;
        head = new_node;
    }

    void create_inside(int d, int index) //встает на место index+1
    {
        Node* new_node = new Node;
        Node* current = head;

        for(int i=0; i<index; i++)
            current = current->next;

        new_node->next = current->next;
        current->next = new_node;
        new_node->data = d;
    }

    void delete_node(int index)
    {
        Node* current = head;
        Node* buf = head;

        for(int i=0; i<index; i++)
        {
            buf = current;
            current = current->next;
        }

        if(buf == head) //удаляем первый
        {
            head = buf->next;
        }
        else
        {
            if(current == NULL) //удаляем последний
            {
                buf->next = NULL;
            }
            else
            {
                buf->next = current->next;
            }
        }

        delete current;
    }

    void show()
    {
        Node* current = head;

        while(current->next != NULL)
        {
            std::cout << current->data << "\t" << current->next << "\n";
            current = current->next;
        }
        std::cout << current->data << "\t" << current->next << "\n\n\n";
    }

    ~List()
    {
        Node* current = head;

        while(current->next != NULL)
        {
            Node* buf = current->next;
            delete current;
            current = buf;
        }
        delete current;
    }
};

int main()
{
    List l1;
    l1.create_last(4);
    l1.create_last(5);
    l1.create_last(6);
    l1.create_last(7);
    l1.show();
    std::cout << "---------------------------------" << "\n";
   l1.create_first(11);
    l1.show();
    std::cout << "---------------------------------------" << "\n";
    l1.create_inside(44, 2);
    l1.show();
    std::cout << "------------------------------------------" << "\n";
    l1.delete_node(5);
    l1.show();
    return 0;
}
