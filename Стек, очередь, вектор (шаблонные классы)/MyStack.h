#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

template <typename T>
class Stack
{
private:
	T * arr;
	const int c_min;
	int32_t count;           ///кол-во эл-тов в стеке(на 1 меньше)
	int32_t size;            ///Размер стека
public:
	Stack():c_min(3)
	{
		count = -1;
		size = 0;
		arr = new T[c_min]; ///Создание динамического массива(Стека)
	}

	void push(T value)   ///Добавление нового элемента
	{
		if(count + 1 == size) ///Если свободных мест нет
		{
			size += 3;
			T * _arr = arr;
			arr = new T[size];
			for (int32_t i=0; i <= count; i++)
			{
				arr[i] = _arr[i];
			}
			delete[] _arr;
		}
		count++;
		arr[count] = value;
		//std::cout << "PUSH: " << value << ", count = " << count << "\n";
	}


	T pop()               ///Выталкивание эл-та
	{
	    //std::cout << "\ncount = " << count << "\n";
		if (count > -1)
		{
			count--;
			return arr[count + 1];
		}
		else
		{
			std::cout << "Stack empty\n";
			return 0;
		}
	}

	T peek() ///Возврат верхнего эл-та
	{
		if (count > -1)
		{
			return arr[count];
		}
		else
		{
			std::cout << "\nStack empty\n";
			return 0;
		}
	}

	int32_t Count() const         ///Кол-во эл-тов
	{
		return count + 1;
	}

	void remove_range(int32_t start, int32_t end) ///Удаление диапазона значений
	{
	    if(start > end)
        {
            int32_t buf = end;
            end = start;
            start = buf;
        }
	    if((start > count) || (start < 0) || (end < 0))
        {
            std::cout << "\nIndex was outside the bounds of the stack\n";
            return;
        }
        if(end > count)
        {
            end = count;
        }

        int32_t remove_count = end - start + 1; ///Кол-во удаляемых значений

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

	void reverse() ///Смена порядка элементов
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

	~Stack()
	{
		delete[] arr; ///Удаление динамического массива
	}

	bool operator > (const Stack<T> &s2) const;
	bool operator < (const Stack<T> &s2) const;
	bool operator == (const Stack<T> &s2) const;
	bool operator != (const Stack<T> &s2) const;

};


template <typename T>
bool Stack<T>::operator > (const Stack<T> &s2) const
{
	if((this->Count()) > (s2.Count()))
	{
		return true;
	}
	return false;
}

template <typename T>
bool Stack<T>::operator < (const Stack<T> &s2) const
{
	if ((this->Count()) < (s2.Count()))
	{
		return true;
	}
	return false;
}

template <typename T>
bool Stack<T>::operator == (const Stack<T> &s2) const
{
	if ((this->Count()) == (s2.Count()))
	{
		return true;
	}
	return false;
}

template <typename T>
bool Stack<T>::operator != (const Stack<T> &s2) const
{
	if ((this->Count()) != (s2.Count()))
	{
		return true;
	}
	return false;
}

#endif // MYSTACK_H_INCLUDED
