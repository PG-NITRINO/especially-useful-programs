#ifndef MYQUEUE_H_INCLUDED
#define MYQUEUE_H_INCLUDED

template <typename T>
class Queue
{
private:
	T* arr;
	const int c_min;
	int front;      ///кол-во эл-тов в очереди(на 1 меньше)
	int end;
	int size;            ///Размер очереди
public:
	Queue() :c_min(2)
	{
		front = 0;
		end = -1;
		size = 0;
		arr = new T[c_min]; ///Создание динамического массива(очереди)
	}

	void push(T value)   ///Добавление нового элемента
	{
		if (end + 1 == size) ///Если свободных мест нет
		{
			size++;
			T* _arr = arr;
			arr = new T[size];
			for (int i = 0; i <= end; i++)
			{
				arr[i] = _arr[i];
			}
			delete[] _arr;
		}
		end++;
		arr[end] = value;
		//std::cout << "PUSH: count = " << end << "\n";
	}

	T pop()   ///Выталкивание эл-та
	{
		//std::cout << "\ncount = " << front << "\n";
		if (front >= 0)
		{
			T a = arr[front];
			front++;
			return a;
		}
		else
		{
			std::cout << "\nQueue empty\n";
			return 0;
		}
	}

	T peek() ///Возврат верхнего эл-та
	{
		if (front >= 0)
		{
			return arr[front];
		}
		else
		{
			std::cout << "\nQueue empty\n";
			return 0;
		}
	}

	int Count() const         ///Кол-во эл-тов
	{
		return front;
	}

	void remove_range(int start, int end) ///Удаление диапазона значений
	{
		int count = front;
		if (start > end)
		{
			int buf = end;
			end = start;
			start = buf;
		}
		if ((start > count) || (start < 0) || (end < 0))
		{
			std::cout << "\nIndex was outside the bounds of the queue\n";
			return;
		}
		if (end > count)
		{
			end = count;
		}

		int remove_count = end - start + 1; ///Кол-во удаляемых значений

		T* _arr = arr;
		arr = new T[size];
		for (int i = 0; i < start; i++)
		{
			arr[i] = _arr[i];
		}
		for (int i = end + 1; i <= count; i++)
		{
			arr[i - remove_count] = _arr[i];
		}
		count = count - remove_count;
		delete[] _arr;
	}

	void reverse() ///Смена порядка элементов
	{
		int count = front;
		if (count > 0)
		{
			int rev1 = 0;
			int rev2 = count;
			T buf;
			while (rev1 < rev2)
			{
			    std::cout << "reverse";
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
		delete[] arr; ///Удаление динамического массива
	}

	bool operator > (const Queue<T>& s2) const;
	bool operator < (const Queue<T>& s2) const;
	bool operator == (const Queue<T>& s2) const;
	bool operator != (const Queue<T>& s2) const;

};


template <typename T>
bool Queue<T>::operator > (const Queue<T>& s2) const
{
	if ((this->Count()) > (s2.Count()))
	{
		return true;
	}
	return false;
}

template <typename T>
bool Queue<T>::operator < (const Queue<T>& s2) const
{
	if ((this->Count()) < (s2.Count()))
	{
		return true;
	}
	return false;
}

template <typename T>
bool Queue<T>::operator == (const Queue<T>& s2) const
{
	if ((this->Count()) == (s2.Count()))
	{
		return true;
	}
	return false;
}

template <typename T>
bool Queue<T>::operator != (const Queue<T>& s2) const
{
	if ((this->Count()) != (s2.Count()))
	{
		return true;
	}
	return false;
}

#endif // MYQUEUE_H_INCLUDED
