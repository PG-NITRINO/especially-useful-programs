#ifndef MYSINGLELIST_H_INCLUDED
#define MYSINGLELIST_H_INCLUDED

template <typename T>
class SingleList
{
private:
	int count;		//Кол-во эл-тов
	struct Value
	{
		T val;		//Значения ячейки
		Value* add;	//Адрес на следующюю ячейку
	};
	Value* add_1;	//Адрес первой ячейки
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

	void push_end(T value)              ///Вставка в конец списка
	{
		if (count > -1)
		{
			Value* buf_add = add_1;
			while (buf_add->add != nullptr) //Ищем адрес на последний элемент списка
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

	void push_top(T value)              ///Вставка в начало спика
	{
	    Value* buf_add = add_1;
	    add_1 = new Value;
        add_1->val = value;
        add_1->add = buf_add;
        count++;
	}

	T pop_end()             ///Выталкием элемент с конца
	{
	    if(count > -1)
        {
            Value* buf1_add = add_1;
            Value* buf2_add;
			while (buf1_add->add != nullptr) //Ищем адрес на последний элемент списка
			{
			    buf2_add = buf1_add;         //Храним, чтобы очистить адрес у предпоследнего элемента
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

	T pop_top()             ///Выталкием элемент с начала
	{
	    if(count > -1)
        {
            count--;
            Value* buf_add = add_1->add; //Сохраняем адрес на второй элемент
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

	void insert(T value, int index)     ///вставка элемента в произвольное место списка
	{                                   //Указывается индекс элемента, ПЕРЕД которым вставляем
	    if(index <= 0 )
        {
            push_top(value);
            return;
        }
	    if(index > count) index = count + 1;

	    Value* buf1_add = add_1;
        for(int i = 0; i < index-1; i++)
        {
            buf1_add = buf1_add->add; //Храним адрес элемента, ПОСЛЕ которого вставляем новый
        }
        count++;
        Value* buf2_add = buf1_add->add; //Адрес элемента, ПЕРЕД которым вставляем новый
        buf1_add->add = new Value;
        buf1_add->add->add = buf2_add;
        buf1_add->add->val = value;
	}

	void erase(int index)               /// удаление элемента из произвольного места списка
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
                buf1_add = buf1_add->add;       //Адрес элемента, ПОСЛЕ которым удаляем
            }
            count--;
            Value* buf2_add = buf1_add->add->add;  //Адрес элемента, ПЕРЕД которым удаляем
            delete buf1_add->add;
            buf1_add->add = buf2_add;
        }
        else
        {
            std::cout << "\nSingly liked list is empty\n";
        }
	}

	T* begin()          ///возврат указателя на первый элемент
	{
	    return &(add_1->val);
	}

	T* end()            ///возврат указателя на последний элемент
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

	int count_()        ///возврат количества элементов в списке
	{
	    return count + 1;
	}

	void SortList()    ///Сортирует список по возрастанию
	{
	    if(count > 0)
        {
            T array[count + 1]; //Массив для сортировки значений списка
            Value* buf_add = add_1;
            for(int i = 0; i <= count; i++)
            {
                array[i] = buf_add->val;
                buf_add = buf_add->add;
            }

            for(int i = 1; i <= count; i++)     ///Сортировка включением
            {                               //i-ый эл-т смещается вправо, пока не встретит
                T value = array[i];         //эл-т меньше себя
                int index = i;
                while((index > 0) && (array[index - 1] > value))
                {
                    array[index] = array[index - 1];
                    index--;
                }
                array[index] = value;
            }

            buf_add = add_1;
            for(int i = 0; i <= count; i++)  //Переписываем отсортированный массив в список
            {
                buf_add->val = array[i];
                buf_add = buf_add->add;
            }

        }
	}

	void MergeList(SingleList<T> &sl)        ///Слияние двух списков в один и упорядочивание его по возрастанию
	{
	    if(sl.count > -1)             //Во включаемом списке есть значения
	    {
            if(this->count > -1)      //В обоих списках есть значения
            {
                Value* buf_add = this->add_1;      //Адрес последнего элемент в текущем списке
                while(buf_add->add != nullptr)
                {
                    buf_add = buf_add->add;
                }

                Value* buf_sl_add = sl.add_1;       //Итерируем по значениям включаемого списка
                while(buf_sl_add->add != nullptr)
                {
                    this->push_end(buf_sl_add->val);
                    buf_sl_add = buf_sl_add->add;
                }
                this->push_end(buf_sl_add->val);
            }
            else                             //В нашем списке нет значений
            {
                this->push_top(sl.add_1->val);
                Value* buf_sl_add = sl.add_1;       //Итерируем по значениям включаемого списка
                while(buf_sl_add->add != nullptr)
                {
                    buf_sl_add = buf_sl_add->add;
                    this->push_end(buf_sl_add->val);
                }
            }
	    }
	    this->SortList();
	}

	SingleList<T> MinMaxList()  ///Возвращает список из минимального и максимального значений
	{                           ///текущего списка и удаляет их из него.
	    SingleList<T> MinMaxSL;
	    if(count > -1)
        {
            Value* buf_add = add_1;
            int minInd = 0;
            T minVal = add_1->val;
            int maxInd = 0;
            T maxVal = add_1->val;
            int index = 0;              //текущий индекс
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

            if(minInd < maxInd) //При удалении у второго элемента может измениться индекс
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
