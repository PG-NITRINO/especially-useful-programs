#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"
#include "MyVector.h"
#include "MyTimer.h"

#include <stack>
#include <queue>
#include <vector>

int main()
{
    ///Тестирование методов структур данных
    /*std::cout << "Stack test... \nAppending elements 0, 1, 2, 3, 4\n";
    Stack<int32_t> stc;
    stc.push(0);    stc.push(1);    stc.push(2);    stc.push(3);    stc.push(4);

    std::cout << "Removing range(2,3)\n\n";
	stc.remove_range(2,3);

	std::cout << "Stack peek = " << stc.peek() << "\n";
	std::cout << "Quantity of elements on the stack = " << stc.Count() << "\n\n";

	std::cout << "Stack reversing\n";
	stc.reverse();
	std::cout << "Pop elements from stack:\n";
	std::cout << stc.pop() << "\n";
	std::cout << stc.pop() << "\n";
	std::cout << stc.pop() << "\n";
	std::cout << stc.pop() << "\n\n";


	std::cout << "Queue test... \nAppending elements 0, 1, 2, 3, 4\n";
    Queue<int32_t> que;
    que.push(0);    que.push(1);    que.push(2);    que.push(3);    que.push(4);

    std::cout << "Removing range(2,3)\n\n";
	que.remove_range(2,3);

	std::cout << "Queue peek = " << que.peek() << "\n";
	std::cout << "Quantity of elements on the queue = " << que.Count() << "\n\n";

	std::cout << "Queue reversing\n";
	que.reverse();
	std::cout << "Pop elements from queue:\n";
	std::cout << que.pop() << "\n";
	std::cout << que.pop() << "\n";
	std::cout << que.pop() << "\n";
	std::cout << que.pop() << "\n\n";


	std::cout << "Vector test... \nAppending elements 0, 1, 2, 3, 4\n";
    Vector<int32_t> vec;
    vec.push(0);    vec.push(1);    vec.push(2);    vec.push(3);    vec.push(4);

    std::cout << "Removing range(2,3)\n\n";
	vec.remove_range(2,3);

	std::cout << "Vector peek = " << vec.peek() << "\n";
	std::cout << "Quantity of elements on the vector = " << vec.Count() << "\n\n";

	std::cout << "Reading element through index: vec[1] = " << vec.At(1) << "\n";
	std::cout << "Changing element value from index = 1 on 199\n\n";
	vec.At(1) = 199;

	std::cout << "Vector reversing\n";
	vec.reverse();
	std::cout << "Pop elements from vector:\n";
	std::cout << vec.pop() << "\n";
	std::cout << vec.pop() << "\n";
	std::cout << vec.pop() << "\n";
	std::cout << vec.pop() << "\n\n";*/

    srand(static_cast<unsigned int>(time(0)));
    Timer t;
    double elapsed;                     ///Хранит время задержки
    const int32_t repeat = 100000;      ///Кол-во повторений

    Stack<int32_t> my_stc;
    std::stack<int32_t> stl_stc;
/**/
    for(int32_t i = 0; i < repeat; i++)
    {
        my_stc.push(i);
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(MyStack.push): " << elapsed << "\n\n";
    t.reset();
/**/
	for(int32_t i = 0; i < repeat; i++)
    {
        stl_stc.push(i);
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(STL_Stack.push): " << elapsed << "\n\n";
    t.reset();
/**/
    for(int32_t i = 0; i < repeat; i++)
    {
        my_stc.pop();
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(MyStack.pop): " << elapsed << "\n\n";
    t.reset();
/**/
	for(int32_t i = 0; i < repeat; i++)
    {
        stl_stc.pop();
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(STL_Stack.pop): " << elapsed << "\n\n----------\n";
    t.reset();

/**//**/

    Queue<int32_t> my_que;
    std::queue<int32_t> stl_que;
/**/
    for(int32_t i = 0; i < repeat; i++)
    {
        my_que.push(i);
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(MyQueue.push): " << elapsed << "\n\n";
    t.reset();
/**/
	for(int32_t i = 0; i < repeat; i++)
    {
        stl_que.push(i);
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(STL_Queue.push): " << elapsed << "\n\n";
    t.reset();
/**/
    for(int32_t i = 0; i < repeat; i++)
    {
        my_que.pop();
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(MyQueue.pop): " << elapsed << "\n\n";
    t.reset();
/**/
	for(int32_t i = 0; i < repeat; i++)
    {
        stl_que.pop();
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(STL_Queue.pop): " << elapsed << "\n\n----------\n";
    t.reset();

/**//**/

    Vector<int32_t> my_vec;
    std::vector<int32_t> stl_vec;
/**/
    for(int32_t i = 0; i < repeat; i++)
    {
        my_vec.push(i);
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(MyVector.push): " << elapsed << "\n\n";
    t.reset();
/**/
	for(int32_t i = 0; i < repeat; i++)
    {
        stl_vec.push_back(i);
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(STL_Vector.push): " << elapsed << "\n\n";
    t.reset();
/**/
    for(int32_t i = 0; i < repeat; i++)
    {
        my_vec.pop();
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(MyVector.pop): " << elapsed << "\n\n";
    t.reset();
/**/
	for(int32_t i = 0; i < repeat; i++)
    {
        stl_vec.pop_back();
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(STL_Vector.pop): " << elapsed << "\n\n";
    t.reset();

	return 0;
}
