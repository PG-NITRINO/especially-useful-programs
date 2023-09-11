#ifndef MYSINGLELIST_H_INCLUDED
#define MYSINGLELIST_H_INCLUDED

template <typename T>
class SingleList
{
private:
	int count;		//���-�� ��-���
	struct Value
	{
		T val;		//�������� ������
		Value* add;	//����� �� ��������� ������
	};
	Value* add_1;	//����� ������ ������
public:
	SingleList()
	{
		count = -1;
		add_1 = nullptr;
	}
	SingleList(T value)
	{
		count = 0;
		add_1 = new Value;
		add_1->val = value;
		add_1->add = nullptr;
	}

	void push_end(T value)              ///������� � ����� ������
	{
		if (count > -1)
		{
			Value* buf_add = add_1;
			while (buf_add->add != nullptr) //���� ����� �� ��������� ������� ������
			{
				buf_add = buf_add->add;
			}
			count++;
			buf_add->add = new Value;
			buf_add->add->val = value;
			buf_add->add->add = nullptr;
		}
		else
		{
			count = 0;
			add_1 = new Value;
			add_1->val = value;
			add_1->add = nullptr;
		}
	}

	void push_top(T value)              ///������� � ������ �����
	{
	    Value* buf_add = add_1;
	    add_1 = new Value;
        add_1->val = value;
        add_1->add = buf_add;
        count++;
	}

	T pop_end()             ///��������� ������� � �����
	{
	    if(count > -1)
        {
            Value* buf1_add = add_1;
            Value* buf2_add;
			while (buf1_add->add != nullptr) //���� ����� �� ��������� ������� ������
			{
			    buf2_add = buf1_add;         //������, ����� �������� ����� � �������������� ��������
				buf1_add = buf1_add->add;
			}
			count--;
			T buf_val = buf1_add->val;

			delete buf1_add;
			if(count == -1)
                add_1 = nullptr;
            else buf2_add->add = nullptr;

			return buf_val;
        }
        else
        {
            std::cout << "Singly linked list is empty\n";
            return 0;
        }
	}

	T pop_top()             ///��������� ������� � ������
	{
	    if(count > -1)
        {
            count--;
            Value* buf_add = add_1->add; //��������� ����� �� ������ �������
            T buf_val = add_1->val;
            delete add_1;
            add_1 = buf_add;
            return buf_val;
        }
        else
        {
            std::cout << "Singly linked list is empty\n";
            return 0;
        }
	}

	void insert(T value, int index)     ///������� �������� � ������������ ����� ������
	{                                   //����������� ������ ��������, ����� ������� ���������
	    if(index <= 0 )
        {
            push_top(value);
            return;
        }
	    if(index > count) index = count + 1;

	    Value* buf1_add = add_1;
        for(int i = 0; i < index-1; i++)
        {
            buf1_add = buf1_add->add; //������ ����� ��������, ����� �������� ��������� �����
        }
        count++;
        Value* buf2_add = buf1_add->add; //����� ��������, ����� ������� ��������� �����
        buf1_add->add = new Value;
        buf1_add->add->add = buf2_add;
        buf1_add->add->val = value;
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
                buf1_add = buf1_add->add;       //����� ��������, ����� ������� �������
            }
            count--;
            Value* buf2_add = buf1_add->add->add;  //����� ��������, ����� ������� �������
            delete buf1_add->add;
            buf1_add->add = buf2_add;
        }
        else
        {
            std::cout << "\nSingly liked list is empty\n";
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
            while(buf_add->add != nullptr)
            {
                buf_add = buf_add->add;
            }
            return &(buf_add->val);
        }
        else
        {
            std::cout << "\nSingly linked list is empty\n";
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
                buf_add = buf_add->add;
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
                buf_add = buf_add->add;
            }

        }
	}

	void MergeList(SingleList<T> &sl)        ///������� ���� ������� � ���� � �������������� ��� �� �����������
	{
	    if(sl.count > -1)             //�� ���������� ������ ���� ��������
	    {
            if(this->count > -1)      //� ����� ������� ���� ��������
            {
                Value* buf_add = this->add_1;      //����� ���������� ������� � ������� ������
                while(buf_add->add != nullptr)
                {
                    buf_add = buf_add->add;
                }

                Value* buf_sl_add = sl.add_1;       //��������� �� ��������� ����������� ������
                while(buf_sl_add->add != nullptr)
                {
                    this->push_end(buf_sl_add->val);
                    buf_sl_add = buf_sl_add->add;
                }
                this->push_end(buf_sl_add->val);
            }
            else                             //� ����� ������ ��� ��������
            {
                this->push_top(sl.add_1->val);
                Value* buf_sl_add = sl.add_1;       //��������� �� ��������� ����������� ������
                while(buf_sl_add->add != nullptr)
                {
                    buf_sl_add = buf_sl_add->add;
                    this->push_end(buf_sl_add->val);
                }
            }
	    }
	    this->SortList();
	}

	SingleList<T> MinMaxList()  ///���������� ������ �� ������������ � ������������� ��������
	{                           ///�������� ������ � ������� �� �� ����.
	    SingleList<T> MinMaxSL;
	    if(count > -1)
        {
            Value* buf_add = add_1;
            int minInd = 0;
            T minVal = add_1->val;
            int maxInd = 0;
            T maxVal = add_1->val;
            int index = 0;              //������� ������
            while(buf_add->add != nullptr)
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
                buf_add = buf_add->add;
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

	~SingleList()
	{
		if (count > -1)
		{
		    std::cout << "Destructor is worked, elements on the singly linked list:\n";
			Value* buf1_add = add_1;
			Value* buf2_add;
			while (buf1_add->add != nullptr)
			{
				std::cout << buf1_add->val << "\n";
				buf2_add = buf1_add->add;
				delete buf1_add;
				buf1_add = buf2_add;
			}
			std::cout << buf1_add->val << "\n";
			delete buf1_add;
		}
		else std::cout << "\nDestructor is worked, singly linked list is empty\n";
	}

	bool operator>(const SingleList<T> &s) const;
	bool operator<(const SingleList<T> &s) const;
	bool operator==(const SingleList<T> &s) const;
	bool operator!=(const SingleList<T> &s) const;

};

template <typename T>
bool SingleList<T>::operator>(const SingleList<T> &s) const
{
    return((this->count)>(s.count));
}

template <typename T>
bool SingleList<T>::operator<(const SingleList<T> &s) const
{
    return((this->count)<(s.count));
}

template <typename T>
bool SingleList<T>::operator==(const SingleList<T> &s) const
{
    return((this->count)==(s.count));
}

template <typename T>
bool SingleList<T>::operator!=(const SingleList<T> &s) const
{
    return((this->count)!=(s.count));
}

#endif // MYSINGLELIST_H_INCLUDED
