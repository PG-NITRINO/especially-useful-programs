#ifndef MYVECTOR_H_INCLUDED
#define MYVECTOR_H_INCLUDED

template <typename T>
class Vector
{
private:
	T * arr;
	T   err;                 ///Возвращается из at() при ошибке
	const int c_min;
	int32_t count;           ///кол-во эл-тов в векторе(на 1 меньше)
	int32_t size;            ///Размер вектора
public:
	Vector():c_min(3)
	{
		count = -1;
		size = 0;
		arr = new T[c_min]; ///Создание динамического массива(Вектора)
	}

	void push(T value)   ///Добавление нового элемента
	{
		if(count + 1 == size) ///Если свободных мест нет
		{
			size += 3;
			T * _arr = arr;
			arr = new T[size];
			for (int i=0; i <= count; i++)
			{
				arr[i] = _arr[i];
			}
			delete[] _arr;
		}
		count++;
		arr[count] = value;
	}

	T pop()               ///Выталкивание эл-та
	{
		if (count > -1)
		{
			count--;
			return arr[count + 1];
		}
		else
		{
			std::cout << "Vector empty\n";
			return 0;
		}
	}

	T& At(int32_t index) ///Произвольный доступ к эл-ту
	{
	    if((index > count) || (index < 0))
	    {
	        std::cout << "\nIndex was outside the bounds of the vector\n";
	        return err;
	    }
	    return arr[index];
	}


	T peek() ///Возврат верхнего эл-та
	{
		if (count > -1)
		{
			return arr[count];
		}
		else
		{
			std::cout << "\nVector empty\n";
			return 0;
		}
	}

	int Count() const         ///Кол-во эл-тов
	{
		return count + 1;
	}

	void remove_range(int start, int end) ///Удаление диапазона значений
	{
	    if(start > end)
        {
            int buf = end;
            end = start;
            start = buf;
        }
	    if((start > count) || (start < 0) || (end < 0))
        {
            std::cout << "\nIndex was outside the bounds of the vector\n";
            return;
        }
        if(end > count)
        {
            end = count;
        }

        int remove_count = end - start + 1; ///Кол-во удаляемых значений

        T * _arr = arr;
        arr = new T[size];
        for (int i=0; i < start; i++)
        {
            arr[i] = _arr[i];
        }
        for (int i=end + 1; i <= count; i++)
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
            int rev1 = 0;
            int rev2 = count;
            int buf;
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

	~Vector()
	{
		delete[] arr; ///Удаление динамического массива
	}

	bool operator > (const Vector<T> &s2) const;
	bool operator < (const Vector<T> &s2) const;
	bool operator == (const Vector<T> &s2) const;
	bool operator != (const Vector<T> &s2) const;

};


template <typename T>
bool Vector<T>::operator > (const Vector<T> &s2) const
{
	if((this->Count()) > (s2.Count()))
	{
		return true;
	}
	return false;
}

template <typename T>
bool Vector<T>::operator < (const Vector<T> &s2) const
{
	if ((this->Count()) < (s2.Count()))
	{
		return true;
	}
	return false;
}

template <typename T>
bool Vector<T>::operator == (const Vector<T> &s2) const
{
	if ((this->Count()) == (s2.Count()))
	{
		return true;
	}
	return false;
}

template <typename T>
bool Vector<T>::operator != (const Vector<T> &s2) const
{
	if ((this->Count()) != (s2.Count()))
	{
		return true;
	}
	return false;
}

#endif // MYVECTOR_H_INCLUDED
