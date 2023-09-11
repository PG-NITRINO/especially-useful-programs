#ifndef MYRING_H_INCLUDED
#define MYRING_H_INCLUDED

template <typename T>
class Ring
{
private:
	int count;		//���-�� ��-���
	unsigned int max_size;   //������������ ���-�� ��-���
	struct Value
	{
		T val;		//�������� ������
		Value* add;	//����� �� ��������� ������
	};
	Value* add_1;	//����� ������ ������
public:
	Ring(unsigned int max)
	{
	    max_size = max;
		count = -1;
        add_1 = new Value;
        Value* buf_add = add_1;
//����� �������� ����������� �������� ���-�� ������
        for(unsigned int i = 0; i < max_size; i++)
        {
            buf_add->add = new Value;
            buf_add = buf_add->add;
            buf_add->val = -999;
        }
        buf_add->add = add_1;
    }
	Ring(unsigned int max, T value): Ring(max)
	{
		count = 0;
		add_1->val = value;
	}

	void push(T value)              ///������� � ����� ������
	{
		if (count < static_cast<int>(max_size))    //���� ��������� �����
		{
			Value* buf_add = add_1;   //����� ���������� ��-��
			for(int i = -1; i<count; i++)
            {
                buf_add = buf_add->add;
            }
            buf_add->val = value;
			count++;
		}
		else      //���� ����� ��������, �� ���������� ������ ��-�
		{
			add_1->val = value;
			add_1 = add_1->add;
		}
	}

	void print() //����� ���� ��-���
	{
	    std::cout << "\nPrint:\n";
	    Value* buf_add = add_1;
        for(int i = 0; i<count; i++)
        {
            std::cout << buf_add->val << "\n";
            buf_add = buf_add->add;
        }
        std::cout << buf_add->val << "\n";
        std::cout << "\n";
	}

	T pop()             ///��������� ������� � ������
	{
	    if(count > -1)
        {
            count--;
            T val = add_1->val;
            add_1 = add_1->add;
            return val;
        }
        else
        {
            std::cout << "Ring buffer is empty\n";
            return 0;
        }
	}

	void insert(T value, int index) ///������� �������� � ������������ ����� ������
	{                               //����������� ������ ��������, ����� ������� ���������
	    if(count == -1)     //���� � ������ ��� ��-���
        {
            count = 0;
            add_1->val = value;
            return;
        }
        if(index < 0 ) index = 0;
        else if((index > count) & (count == static_cast<int>(max_size))) index = count;
        else if((index > count) & (count < static_cast<int>(max_size))) index = count + 1;

        Value* buf_add = add_1;
        for(int i = 0; i < index; i++)
        {//���������� ��� �������� �� index
            buf_add = buf_add->add;
        }
        T buf_val = buf_add->val;
        buf_add->val = value; //��������� ����� ��������

        T buf_val_2;
        for(int i = index; i < count; i++)
        {//������� ��� �������� ����� index
            buf_add = buf_add->add;
            buf_val_2 = buf_add->val;
            buf_add->val = buf_val;
            buf_val = buf_val_2;
        }
        //����� �������� ��������� ������(��������������) �� ����������� ������
        if(count != static_cast<int>(max_size) - 1) buf_add->add->val = buf_val;

        if(count < static_cast<int>(max_size)) count++;
	}

	void erase(int index)               /// �������� �������� �� ������������� ����� ������
	{
	    if(count > -1)
        {
            if(count == 0)
            {//���� ������ ���� ��-�, �� ��� � �������
                count = -1;
                return;
            }
            if(index < 0) index = 0;
            if(index >= count)
            { //������ ����� ������� ��������� ��-�
                count--;
                return;
            }

            Value* buf_add = add_1;
            for(int i = 0; i < index; i++)
            { //���������� ��� �������� �� index
                buf_add = buf_add->add;       //����� ��������, ������� �������
            }
            count--;

            for(int i = index; i<count; i++)
            {//��� �������� ����� ������� �������� �����
                buf_add->val = buf_add->add->val;
                buf_add = buf_add->add;
            }
            buf_add->val = buf_add->add->val;
        }
        else
        {
            std::cout << "\nRing buffer is empty\n";
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
            for(int i=0; i<count; i++)
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

	void SortList()    ///��������� ����� �� �����������
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

	//����� �������� ���������� � �������� ����� � ���-�� ��-��� � ���� �����������
	void MergeList(Ring<T> &sl)        ///������� ���� ������� � ���� � �������������� ��� �� �����������
	{
	    if(sl.count > -1)             //�� ���������� ������ ���� ��������
	    {
	        Value* buf_add = sl.add_1;
	        for(int i = 0; i<sl.count; i++)
            {
                this->push(buf_add->val);
                buf_add = buf_add->add;
            }
            this->push(buf_add->val);
	    }
	    this->SortList();
	}

	Ring<T> MinMaxList()  ///���������� ������ �� ������������ � ������������� ��������
	{                           ///�������� ������ � ������� �� �� ����.
	    Ring<T> MinMaxSL(1);
	    if(count > -1)
        {
            Value* buf_add = add_1;
            int minInd = 0;
            T minVal = add_1->val;
            int maxInd = 0;
            T maxVal = add_1->val;
            int index = 0;         //������� ������
            for(int i = 0; i<count; i++)
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

            MinMaxSL.push(minVal);
            MinMaxSL.push(maxVal);
        }
        return MinMaxSL;
	}

	~Ring()
	{
        if(count == -1)
            std::cout << "Destructor is worked, ring buffer is empty\n";
        else std::cout << "Destructor is worked, elements on the ring buffer:\n";
        Value* buf1_add = add_1;
        buf1_add = add_1;
        Value* buf2_add = add_1->add;
        for(unsigned int i=0; i <= max_size; i++)
        {
            if(count > -1)
            {
                std::cout << buf1_add->val << "\n";
                count--;
            }
            delete buf1_add;
            buf1_add = buf2_add;
            buf2_add = buf2_add->add;
        }
	}

	bool operator>(const Ring<T> &s) const;
	bool operator<(const Ring<T> &s) const;
	bool operator==(const Ring<T> &s) const;
	bool operator!=(const Ring<T> &s) const;

};

template <typename T>
bool Ring<T>::operator>(const Ring<T> &s) const
{
    return((this->count)>(s.count));
}

template <typename T>
bool Ring<T>::operator<(const Ring<T> &s) const
{
    return((this->count)<(s.count));
}

template <typename T>
bool Ring<T>::operator==(const Ring<T> &s) const
{
    return((this->count)==(s.count));
}

template <typename T>
bool Ring<T>::operator!=(const Ring<T> &s) const
{
    return((this->count)!=(s.count));
}

#endif // MYRING_H_INCLUDED
