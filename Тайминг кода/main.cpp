#include <iostream>
#include <cassert>

#include <chrono> // ��� ������� �� std::chrono
#include <cmath>
#include <string>
#include <random>
#include <ctime>

class Timer
{
private:
	// ���������� ����� ������������ ��� �������� ������� � ��������� �����
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

class Numbers{
    private:
double first;
double second;
    public:
void set_num(double x, double y){
    first = x;
    second = y;
}
void print(){
std::cout << "first = " << first << "\nsecond = " << second << "\n";
}

bool isEqual(const Numbers &a)
{
    return(first==a.first&&second==a.second);
}
};

class Point
{
private:
    double m_a, m_b;
public:
    Point(double a=0.0, double b=0.0) :m_a(a), m_b(b)
    {}
    void print()
    {
        std::cout << "Point( " << m_a << " , " << m_b << " )\n";
    }
    double distanceTo(const Point &second)
    {
        return sqrt((m_a - second.m_a) * (m_a - second.m_a) +
                    (m_b - second.m_b) * (m_b - second.m_b));
    }
};

class Monster
{
public:
    enum MonsterType
    {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MAX_MONSTER_TYPES
    };
private:
    MonsterType m_type;
    std::string m_name;
    int m_health;
public:
    Monster(MonsterType type = Dragon, std::string name = "Jack", int health = 100)
            :m_type(type), m_name(name), m_health(health)
    {}
    std::string getTypeString(MonsterType type)
    {
        switch(type)
        {
            case Dragon:    return "Dragon";
            case Goblin:    return "Goblin";
            case Ogre:      return "Ogre";
            case Orc:       return "Orc";
            case Skeleton:  return "Skeleton";
            case Troll:     return "Troll";
            case Vampire:   return "Vampire";
            case Zombie:    return "Zombie";
            default:        return "Unknow";
        }
    }
    void print()
    {
        std::cout << m_name << " is the " << getTypeString(m_type)
                  << " that has " << m_health << " health points.\n";
    }
};
class MonsterGenerator
{
public:
    // ���������� ��������� ����� ����� min � max (������������).
	// ��������������, ��� srand() ��� ��� ������
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // ���������� static, ��� ��� ��� �������� ����� ��������� ��������
		// ���������� ������������ ���������� �������� �� ������ ���������
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
	static Monster generateMonster()
	{
	    static std::string s_names[6]{ "John", "Brad", "Alex", "Thor", "Hulk", "Asnee" };
		return Monster(static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES-1)),
                       s_names[getRandomNumber(0, 5)], getRandomNumber(1, 100));

	}
};
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Timer t;
    Monster m = MonsterGenerator::generateMonster();
	m.print();
	Monster m1 = MonsterGenerator::generateMonster();
	m1.print();
	Monster m2 = MonsterGenerator::generateMonster();
	m2.print();
	Monster m3 = MonsterGenerator::generateMonster();
	m3.print();
    /*Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
*/
    {///������� ������
    /*Numbers mynum1;
    mynum1.set_num(1.4, 2.7);
    mynum1.print();
    Numbers mynum2;
    mynum2.set_num(2.4, 2.7);
    mynum2.print();
    Numbers mynum3;
    mynum3.set_num(2.4, 2.7);
    mynum3.print();

    if(mynum1.isEqual(mynum2))
        std::cout << "\n1 and 2 is Equal\n";
    else std::cout << "\n1 and 2 is not Equal\n";

    if(mynum2.isEqual(mynum3))
        std::cout << "\n2 and 3 is Equal\n";
    else std::cout << "\n2 and 3 is not Equal\n";
       */ }
 std::cout << "Time elapsed: " << t.elapsed() << '\n';
     return 0;
}
/*#include <iostream>

#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <windowsx.h>

#include <ctime>
#include <cmath>

#include <tchar.h>

HWND hWnd = GetConsoleWindow();
HDC hDC = GetDC(hWnd);

class Draw
{
private:
	// �������� �������, ����� ������
	int y=0;         //�������� ������������ ���
	int Y_;       //���������� ���
	int x;        //�������� �� �
	int rb;         //������� ������
	int rs;         //��������� ������
	int xmax;      //������������ �
	const int N = 5;    //�������� ��������� [-N;N]
	HPEN p1;
	HBRUSH b1, b2, b3;

	//��������������� �������
	HPEN PenCreate(void)  ///��������� ���� �����
	{
		int colR, colG, colB;      //color

		colR = rand() % 255;
		colG = rand() % 255;
		colB = rand() % 255;
		return CreatePen(PS_SOLID, 1, RGB(colR, colG, colB));
	}

	//��������������� �������
	void DrawEllipse(HDC hDC, int x, int y, int rb, int rs)
	{
		HPEN p2 = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

		Ellipse(hDC, x - rb, y - rs, x + rb, y + rs);
		Ellipse(hDC, x - rs, y - rb, x + rs, y + rb);
		Sleep(10);

		SelectObject(hDC, p2);
		Ellipse(hDC, x - rb, y - rs, x + rb, y + rs);
		Ellipse(hDC, x - rs, y - rb, x + rs, y + rb);

		DeleteObject(p2);
	}

	//��������������� �������
	void ChangeXY(int* x, int* y, int Y_)
	{
		if (*x % 5 == 0)
		{    //��� �������� �� ���������
			double sinY = sin(0.03 * (static_cast<double>(*x))) * 100;
			*y = Y_ + static_cast<int>(sinY);   //������ �������� y
		}
		*x = *x + 1;                       //������ �������� x
	}

	//������� �������

	//r - ���������� ������
            //N - �������� ���������
            //rmax, rmin - ������������ � ����������� �������� �������
	int ChangeRadius(int r, int N, int rmin, int rmax)
	{
		int rr = rand() % (2 * N + 2) - N; //��������� ������
		if ((r + rr >= rmin) && (r + rr <= rmax))
			r = r + rr;
		return r;
	}

	//������� �������
	void draw_text()
	{
		char c[1024] = "Ellipse";
		//sprintf_s(c, "Ellipse");
		TextOutA(hDC, x, y+rb+10, c, strlen(c) + 1);
	}

public:
	// �����������
	Draw(int Y_1, int x1, int rb1, int rs1, int xmax1)//(COLORREF Color_P2, COLORREF Color_B2, int x_left, int y_left, int x_booton, int y_booton)
	{
		b1 = GetStockBrush(NULL_BRUSH);
		b2 = CreateSolidBrush(RGB(255, 255, 255));
		Y_ = Y_1;       //���������� ���
		x = x1;        //�������� �� �
		rb = rb1;         //������� ������
		rs = rs1;         //��������� ������
		xmax = xmax1;      //������������ �

		SetTextAlign(hDC, TA_CENTER | TA_BASELINE);
		SetBkMode(hDC, 0); //���������� ���
	}

	//������ ����������
	void moveEllipse() {
		while (x < xmax)
		{
			SelectObject(hDC, b2);
			Rectangle(hDC, 10, 10, 600, 800);

			SelectObject(hDC, b1);

			p1 = PenCreate();
			SelectObject(hDC, p1);

			ChangeXY(&x, &y, Y_);

			DrawEllipse(hDC, x, y, rb, rs);

			draw_text();

			//Sleep(10);

			rb = ChangeRadius(rb, N, 10, 50);
			rs = ChangeRadius(rs, N, 5, 20);

			DeleteObject(p1);
		}
	}

	//����������
	~Draw()
	{
		DeleteObject(b1);
		DeleteObject(b2);
		std::cin.get();
	}
};
int main()
{
	srand(time(0));

	//Draw draw1(100, 50, 25, 10, 500);
	//draw1.moveEllipse();
	Draw draw2(300, 200, 25, 10, 400);
	draw2.moveEllipse();

	return 0;
}*/
