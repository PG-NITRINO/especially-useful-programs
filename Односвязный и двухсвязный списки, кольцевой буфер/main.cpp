#include <iostream>
#include "MySingleList.h"
#include "MyDoubleList.h"
#include "MyRing.h"

#include "MyTimer.h"
#include <forward_list>
#include <list>

int main()
{
    ///Тестирование методов односвязного списка
    /*std::cout << "Singly list test.. \nAppending elements 0, 1, 2, 3, 4\n";
    SingleList<int> sl(1);
    sl.push_end(3);
    sl.push_top(0);
    sl.push_end(4);
    sl.insert(2, 2);

    std::cout << "\nRemoving element with index 2\n";
    sl.erase(2);

    std::cout << "\nLink to the beginnig of the structure: " << sl.begin();
    std::cout << "\nLink to the end of the structure: " << sl.end() << "\n";

    std::cout << "\nMerging two single list...\n";
    SingleList<int> sk(9);
    sk.push_end(5); sk.push_end(8); sk.push_end(4); sk.push_end(17);

    sk.MergeList(sl);
    std::cout << "\nRemoving min and max from list...\n\n";
    SingleList<int> smm = sk.MinMaxList();

    ///Тестирование методов двусвязного списка
    std::cout << "\nDoubly list test.. \nAppending elements 0, 1, 2, 3, 4\n";
    DoubleList<int> dl(1);
    dl.push_end(3);
    dl.push_top(0);
    dl.push_end(4);
    dl.insert(2, 2);

    std::cout << "\nRemoving element with index 2\n";
    dl.erase(2);

    std::cout << "\nLink to the beginnig of the structure: " << dl.begin();
    std::cout << "\nLink to the end of the structure: " << dl.end() << "\n";

    std::cout << "\nMerging two doubly list...\n";
    DoubleList<int> dk(9);
    dk.push_end(5); dk.push_end(8); dk.push_end(4); dk.push_end(17);

    dk.MergeList(dl);
    std::cout << "\nRemoving min and max from list...\n\n";
    DoubleList<int> dmm = dk.MinMaxList();

    ///Тестирование методов кольцевого буфера
    std::cout << "\nRing buffer test.. \nAppending elements 0, 1, 2, 3, 4\n";
    Ring<int> rg(7);
    rg.push(0);
    rg.push(1);
    rg.push(3);
    rg.push(4);
    rg.insert(2, 2);

    std::cout << "\nRemoving element with index 2\n";
    rg.erase(2);

    std::cout << "\nLink to the beginnig of the structure: " << rg.begin();
    std::cout << "\nLink to the end of the structure: " << rg.end() << "\n";

    std::cout << "\nMerging two ring buffer...\n";
    Ring<int> rh(9);
    rh.push(5); rh.push(8); rh.push(4); rh.push(17);

    rh.MergeList(rg);
    std::cout << "\nRemoving min and max from buffer...\n\n";
    Ring<int> rmm = rh.MinMaxList();*/

    srand(static_cast<unsigned int>(time(0)));
    Timer t;
    double elapsed;                     ///Хранит время задержки
    const int32_t repeat = 100000;      ///Кол-во повторений

    SingleList<int> my_sl;
    DoubleList<int> my_dl;
    Ring<int> my_rg(repeat);
    std::forward_list<int> stl_sl;
    std::list<int> stl_dl;
///------------
    for(int i = 0; i < repeat; i++)
    {
        my_sl.push_top(i);
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(MySingleList.push): " << elapsed << "\n\n";
    t.reset();
///------------
    for(int i = 0; i < repeat; i++)
    {
        stl_sl.push_front(i);
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(STL_SingleList.push): " << elapsed << "\n\n";
    t.reset();
///------------
    for(int i = 0; i < repeat; i++)
    {
        my_sl.pop_top();
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(MySingleList.pop): " << elapsed << "\n\n";
    t.reset();
///------------
    for(int i = 0; i < repeat; i++)
    {
        stl_sl.pop_front();
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(STL_SingleList.pop): " << elapsed << "\n\n";
    t.reset();
///------------///------------///------------
    for(int i = 0; i < repeat; i++)
    {
        my_dl.push_top(i);
    }
    elapsed = t.elapsed();
    std::cout << "\nElapsed time(MyDoubleList.push): " << elapsed << "\n\n";
    t.reset();
///------------
    for(int i = 0; i < repeat; i++)
    {
        stl_dl.push_front(i);
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(STL_DoubleList.push): " << elapsed << "\n\n";
    t.reset();
///------------
    for(int i = 0; i < repeat; i++)
    {
        my_dl.pop_top();
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(MyDoubleList.pop): " << elapsed << "\n\n";
    t.reset();
///------------
    for(int i = 0; i < repeat; i++)
    {
        stl_dl.pop_front();
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(STL_DoubleList.pop): " << elapsed << "\n\n";
    t.reset();
///------------///------------///------------
    for(int i = 0; i < repeat; i++)
    {
        my_rg.push(i);
    }
    elapsed = t.elapsed();
    std::cout << "\nElapsed time(MyRing.push): " << elapsed << "\n\n";
    t.reset();
///------------
    for(int i = 0; i < repeat; i++)
    {
        my_rg.pop();
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(MyRing.pop): " << elapsed << "\n\n";
    t.reset();
	return 0;
}
