#ifndef MYDOUBLELIST_H_INCLUDED
#define MYDOUBLELIST_H_INCLUDED

template <typename T>
class DoubleList
{
private:
	int count;		//���-�� ��-���
	struct Value
	{
		T val;		//�������� ������
		Value* add_next;	//����� �� ��������� ������
		Value* add_before;  //����� ���������� ������
	};
	Value* add_1;	//����� ������ ������
public:
	DoubleList()
	{
		count = -1;
		add_1 = nullptr;
	}
	DoubleList(T value)
	{
		count = 0;
		add_1 = new Value;
		add_1->val = value;
		add_1->add_next = nullptr;
		add_1->add_before = nullptr;
	}

	void push_end(T value)              ///������� � ����� ������
	{
		if (count > -1)
		{
			Value* buf_add = add_1;
			while (buf_add->add_next != nullptr) //���� ����� �� ��������� ������� ������
			{
				buf_add = buf_add->add_next;
			}
			count++;
			buf_add->add_next = new Value;
			buf_add->add_next->val = value;
			buf_add->add_next->add_next = nullptr;
			buf_add->add_next->add_before = buf_add;
		}
		else
		{
			count = 0;
			add_1 = new Value;
			add_1->val = value;
			add_1->add_next = nullptr;
            add_1->add_before = nullptr;
		}
	}

	void push_top(T value)              ///������� � ������ �����
	{
	    Value* buf_add = add_1;
	    add_1 = new Value;
        add_1->val = value;
        add_1->add_next = buf_add;
        add_1->add_before = nullptr;
        if(buf_add != nullptr)        //�� push_top ���� ��� � ������ ��-��
            buf_add->add_before = add_1;
        count++;
	}

	T pop_end()             ///��������� ������� � �����
	{
	    if(count > -1)
        {
            Value* buf1_add = add_1;
			while (buf1_add->add_next != nullptr) //���� ����� �� ��������� ������� ������
			{
				buf1_add = buf1_add->add_next;
			}

			T buf_val = buf1_add->val;

            if(count > 0)               //�������� ����� �� ��������� ��-� � ������������� ��-��
                buf1_add->add_before->add_next = nullptr;
            else add_1 = nullptr; //�.�. ������� ���� ������� ��� � �������

            delete buf1_add;
            count--;
			return buf_val;
        }
        else
        {
            std::cout << "Doubly linked list is empty\n";
            return 0;
        }
	}

	T pop_top()             ///��������� ������� � ������
	{
	    if(count > -1)
        {
            count--;
            Value* buf_add = add_1->add_next; //��������� ����� �� ������ �������
            T buf_val = add_1->val;
            delete add_1;
            add_1 = buf_add;
            return buf_val;
        }
        else
        {
            std::cout << "Doubly linked list is empty\n";
            return 0;
        }
	}

	void insert(T value, int index)     ///������� �������� � ������������ ����� ������
	{             //����������� ������ ��������, ����� ������� ���������
	    if(index <= 0 )
        {
            push_top(value);
            return;
        }
	    if(index > count) index = count+1;

	    Value* buf1_add = add_1;
        for(int i = 0; i < index-1; i++)
        {
            buf1_add = buf1_add->add_next; //������ ����� ��������, ����� �������� ��������� �����
        }
        count++;
        Value* buf2_add = buf1_add->add_next; //����� ��������, ����� ������� ��������� �����
        buf1_add->add_next = new Value;
        buf1_add->add_next->add_next = buf2_add;
        buf1_add->add_next->val = value;

        buf1_add->add_next->add_before = buf1_add;
        if(buf2_add != nullptr)                     //���� ������� ��������� ��-�
            buf2_add->add_before = buf1_add->add_next;
	}

	void erase(int index)               /// �������� �������� �� ������������� ����� ������
	{
	    if(count > -1)
        {
            if((index <= 0) || (count == 0))
            {
                pop_top();
                return;
            }
            if(index > count) index = count;

            Value* buf1_add = add_1;
            for(int i = 0; i < index - 1; i++)
            {
                buf1_add = buf1_add->add_next;       //����� ��������, ����� ������� �������
            }
            count--;
            Value* buf2_add = buf1_add->add_next->add_next;  //����� ��������, ����� ������� �������
            delete buf1_add->add_next;
            buf1_add->add_next = buf2_add;
            if(buf2_add != nullptr)                  //���� ������� ��������� ��-�
                buf2_add->add_before = buf1_add;
        }
        else
        {
            std::cout << "\nDoubly liked list is empty\n";
        }
	}

	T* begin()          ///������� ��������� �� ������ �������
	{
	    return &(add_1->val);
	}

	T* end()            ///������� ��������� �� ��������� �������
	{
	    if(count > -1)
        {
            Value* buf_add = add_1;
            while(buf_add->add_next != nullptr)
            {
                buf_add = buf_add->add_next;
            }
            return &(buf_add->val);
        }
        else
        {
            std::cout << "\nDoubly linked list is empty\n";
            return nullptr;
        }
	}

	int count_()        ///������� ���������� ��������� � ������
	{
	    return count + 1;
	}

	void SortList()    ///��������� ������ �� �����������
	{
	    if(count > 0)
        {
            T array[count + 1]; //������ ��� ���������� �������� ������
            Value* buf_add = add_1;
            for(int i = 0; i <= count; i++)
            {
                array[i] = buf_add->val;
                buf_add = buf_add->add_next;
            }

            for(int i = 1; i <= count; i++)     ///���������� ����������
            {                               //i-�� ��-� ��������� ������, ���� �� ��������
                T value = array[i];         //��-� ������ ����
                int index = i;
                while((index > 0) && (array[index - 1] > value))
                {
                    array[index] = array[index - 1];
                    index--;
                }
                array[index] = value;
            }

            buf_add = add_1;
            for(int i = 0; i <= count; i++)  //������������ ��������������� ������ � ������
            {
                buf_add->val = array[i];
                buf_add = buf_add->add_next;
            }

        }
	}

	void MergeList(DoubleList<T> &sl)        ///������� ���� ������� � ���� � �������������� ��� �� �����������
	{
	    if(sl.count > -1)             //�� ���������� ������ ���� ��������
	    {
            if(this->count > -1)      //� ����� ������� ���� ��������
            {
                Value* buf_add = this->add_1;      //����� ���������� ������� � ������� ������
                while(buf_add->add_next != nullptr)
                {
                    buf_add = buf_add->add_next;
                }

                Value* buf_sl_add = sl.add_1;       //��������� �� ��������� ����������� ������
                while(buf_sl_add->add_next != nullptr)
                {
                    this->push_end(buf_sl_add->val);
                    buf_sl_add = buf_sl_add->add_next;
                }
                this->push_end(buf_sl_add->val);
            }
            else                             //� ����� ������ ��� ��������
            {
                this->push_top(sl.add_1->val);
                Value* buf_sl_add = sl.add_1;       //��������� �� ��������� ����������� ������
                while(buf_sl_add->add_next != nullptr)
                {
                    buf_sl_add = buf_sl_add->add_next;
                    this->push_end(buf_sl_add->val);
                }
            }
	    }
	    this->SortList();
	}

	DoubleList<T> MinMaxList()  ///���������� ������ �� ������������ � ������������� ��������
	{                           ///�������� ������ � ������� �� �� ����.
	    DoubleList<T> MinMaxSL;
	    if(count > -1)
        {
            Value* buf_add = add_1;
            int minInd = 0;
            T minVal = add_1->val;
            int maxInd = 0;
            T maxVal = add_1->val;
            int index = 0;              //������� ������
            while(buf_add->add_next != nullptr)
            {
                if(minVal > buf_add->val)
                {
                    minVal = buf_add->val;
                    minInd = index;
                }
                else if(maxVal < buf_add->val)
                {
                    maxVal = buf_add->val;
                    maxInd = index;
                }
                buf_add = buf_add->add_next;
                index++;
            }

            if(minVal > buf_add->val)
            {
                minVal = buf_add->val;
                minInd = index;
            }
            else if(maxVal < buf_add->val)
            {
                maxVal = buf_add->val;
                maxInd = index;
            }

            if(minInd < maxInd) //��� �������� � ������� �������� ����� ���������� ������
            {
                erase(maxInd);
                erase(minInd);
            }
            else
            {
                erase(minInd);
                erase(maxInd);
            }

            MinMaxSL.push_top(minVal);
            MinMaxSL.push_end(maxVal);
        }
        return MinMaxSL;
	}

	~DoubleList()
	{
		if (count > -1)
		{
		    std::cout << "Destructor is worked, elements on the doubly linked list:\n";
			Value* buf1_add = add_1;
			Value* buf2_add;
			while (buf1_add->add_next != nullptr)
			{
				std::cout << buf1_add->val << "\n";
				buf2_add = buf1_add->add_next;
				delete buf1_add;
				buf1_add = buf2_add;
			}
			std::cout << buf1_add->val << "\n";
			delete buf1_add;
		}
		else std::cout << "\nDestructor is worked, doubly linked list is empty\n";
	}

	bool operator>(const DoubleList<T> &s) const;
	bool operator<(const DoubleList<T> &s) const;
	bool operator==(const DoubleList<T> &s) const;
	bool operator!=(const DoubleList<T> &s) const;

};

template <typename T>
bool DoubleList<T>::operator>(const DoubleList<T> &s) const
{
    return((this->count)>(s.count));
}

template <typename T>
bool DoubleList<T>::operator<(const DoubleList<T> &s) const
{
    return((this->count)<(s.count));
}

template <typename T>
bool DoubleList<T>::operator==(const DoubleList<T> &s) const
{
    return((this->count)==(s.count));
}

template <typename T>
bool DoubleList<T>::operator!=(const DoubleList<T> &s) const
{
    return((this->count)!=(s.count));
}

#endif // MYDOUBLELIST_H_INCLUDED
