#ifndef MYQUEUE_H_INCLUDED
#define MYQUEUE_H_INCLUDED

template <typename T>
class Queue
{
private:
	T * arr;
	const int c_min;
	int32_t count;           ///���-�� ��-��� � �������(�� 1 ������)
	int32_t size;            ///������ �������
public:
	Queue():c_min(3)
	{
		count = -1;
		size = 0;
		arr = new T[c_min]; ///�������� ������������� �������(�������)
	}

	void push(T value)   ///���������� ������ ��������
	{
		if(count + 1 == size) ///���� ��������� ���� ���
		{
			size += 3;
			T * _arr = arr;
			arr = new T[size];
			for (int32_t i=0; i <= count; i++)
			{
				arr[i+1] = _arr[i];
			}
			delete[] _arr;
		}
		///����� ������� ������ ��������� � ������ �������
		///����� ������ ��-� �� ����� ����� � �������� count
		else
        {
            for (int32_t i=count; i >= 0; i--)
			{
				arr[i+1] = arr[i];
			}
		}
		count++;
		arr[0] = value;
		//std::cout << "PUSH: " << value << ", count = " << count << "\n";
	}


	T pop()               ///������������ ��-��
	{
	    //std::cout << "\ncount = " << count << "\n";
		if (count > -1)
		{
			count--;
			return arr[count + 1];
		}
		else
		{
			std::cout << "Queue empty\n";
			return 0;
		}
	}

	T peek() ///������� �������� ��-��
	{
		if (count > -1)
		{
			return arr[count];
		}
		else
		{
			std::cout << "\nQueue empty\n";
			return 0;
		}
	}

	int32_t Count() const         ///���-�� ��-���
	{
		return count + 1;
	}

	void remove_range(int32_t start, int32_t end) ///�������� ��������� ��������
	{
	    ///�.�. �� ��������� ����� ��-�� � ������ �������
	    ///� ��� ���������� ������ ������������
	    start = count - start;
	    end = count - end;
	    if(start > end)
        {
            int32_t buf = end;
            end = start;
            start = buf;
        }
	    if((start > count) || (start < 0) || (end < 0))
        {
            std::cout << "\nIndex was outside the bounds of the queue\n";
            return;
        }
        if(end > count)
        {
            end = count;
        }

        int32_t remove_count = end - start + 1; ///���-�� ��������� ��������

        T * _arr = arr;
        arr = new T[size];
        for (int32_t i=0; i < start; i++)
        {
            arr[i] = _arr[i];
        }
        for (int32_t i=end + 1; i <= count; i++)
        {
            arr[i-remove_count] = _arr[i];
        }
        count = count - remove_count;
        delete[] _arr;
	}

	void reverse() ///����� ������� ���������
	{
	    if(count > 0)
        {
            int32_t rev1 = 0;
            int32_t rev2 = count;
            T buf;
            while(rev1 < rev2)
            {
                buf = arr[rev1];
                arr[rev1] = arr[rev2];
                arr[rev2] = buf;
                rev1++;
                rev2--;
            }
        }
	}

	~Queue()
	{
		delete[] arr; ///�������� ������������� �������
	}

	bool operator > (const Queue<T> &s2) const;
	bool operator < (const Queue<T> &s2) const;
	bool operator == (const Queue<T> &s2) const;
	bool operator != (const Queue<T> &s2) const;

};


template <typename T>
bool Queue<T>::operator > (const Queue<T> &s2) const
{
	if((this->Count()) > (s2.Count()))
	{
		return true;
	}
	return false;
}

template <typename T>
bool Queue<T>::operator < (const Queue<T> &s2) const
{
	if ((this->Count()) < (s2.Count()))
	{
		return true;
	}
	return false;
}

template <typename T>
bool Queue<T>::operator == (const Queue<T> &s2) const
{
	if ((this->Count()) == (s2.Count()))
	{
		return true;
	}
	return false;
}

template <typename T>
bool Queue<T>::operator != (const Queue<T> &s2) const
{
	if ((this->Count()) != (s2.Count()))
	{
		return true;
	}
	return false;
}

#endif // MYQUEUE_H_INCLUDED
