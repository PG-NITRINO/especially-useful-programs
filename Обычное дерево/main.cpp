#include <iostream>
#include "MyTree.h"
#include "Timer.h"

int main()
{
    std::cout << "Normal tree test...\n";
    Tree<int> th(1);
    th.push(2, 0);
    th.push(3, 0);
    th.push(4, 0);
    std::cout << "th.pop() = " << th.pop() << "\n";
    std::cout << "th.pop() = " << th.pop() << "\n";
    std::cout << "th.pop() = " << th.pop() << "\n";
    std::cout << "th.pop() = " << th.pop() << "\n";
    th.push(20, 0);
    th.push(30, 0);
    th.push(40, 0);

    Tree<int> tr;
    tr.push(1, 0);
    tr.push(2, 0);
    tr.push(3, 0);
    tr.push(4, 0);
    tr.push(55, 0);
    tr.push(5, 1, 0);
    tr.push(6, 1, 0);
    tr.push(9, 2, 0, 0);
    tr.push(10, 2, 0, 0);
    tr.push(7, 2, 0, 1);
    tr.push(8, 2, 0, 1);

    tr.push(11, 1, 2);
    tr.push(22, 1, 2);
    tr.push(33, 2, 2, 0);
    tr.push(44, 2, 2, 1);
    tr.push(55, 2, 2, 1);
    tr.push(88, 2, 2, 1);
    tr.push(77, 3, 2, 1, 1);
    tr.push(88, 4, 2, 1, 1, 0);
    tr.push(600, 5, 2, 1, 1, 0, 0);
    tr.print();
    std::cout << "\n\n";

    std::cout << std::boolalpha;
    std::cout << "tr.find(44) = " << tr.find(44) << "\n";
    std::cout << "tr.find(3) = " << tr.find(44) << "\n";
    std::cout << "tr.find(15) = " << tr.find(15) << "\n";
    std::cout << "tr.find(600) = " << tr.find(600) << "\n";
    std::cout << std::noboolalpha;
    std::cout << "tr.count() = " << tr.count() << "\n";
    std::cout << "tr.height() = " << tr.height() << "\n";

    std::vector<int> paths;
    tr.path(55, paths);
    std::cout << "\ntr.path(55, paths):\n{ ";
    for(unsigned int i = 0; i < paths.size(); i++)
        std::cout << paths[i] << ", ";
    std::cout << " }\n";

    std::cout << "tr.smm(th) = " << tr.sum(th) << "\n";

    std::cout << "\n\n";

    srand(static_cast<unsigned int>(time(0)));
    Timer t;
    double elapsed;                     ///Хранит время задержки
    const int32_t repeat = 100000;      ///Кол-во повторений

    Tree<int> tg;
    ///------------
    for(int i = 0; i < repeat; i++)
    {
        tg.push(i,0);
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(MyTree.push): " << elapsed << "\n\n";
    t.reset();
///------------
    for(int i = 0; i < repeat; i++)
    {
        tg.pop();
    }
    elapsed = t.elapsed();
    std::cout << "Elapsed time(MyTree.pop): " << elapsed << "\n\n";
    t.reset();
    return 0;
}
