#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------\n"

//Создание структуры:
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		if (x < 0)x = 0;
		if (x > 1000)x = 1000;
		this->x = x;
	}
	void set_y(double y)
	{
		if (y < 0)y = 0;
		if (y > 1000)y = 1000;
		this->y = y;
	}


	//				 Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//					Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignmnet:\t\t" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	//					Increment/Decrement

	Point& operator++() //Prefix increment
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int) //Suffix increment
	{
		Point old = *this;
		this->x++;
		this->y++;
		return old;
	}

	//					Methods:
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}

};

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}
Point operator-(const Point& left, const Point& right)
{
	Point res(left.get_x() - right.get_x(), left.get_y() - right.get_y());
	return res;
}

bool operator==(const Point left, const Point right)
{
	if (left.get_x() == right.get_x() && left.get_y() == right.get_y())return true;
	else return false;
}

double distance(const Point& A, const Point& B);

//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a;		//Объявление переменной 'a' типа 'int'.
	Point A;	//Объявление переменной 'A' типа 'Point'			
				//Создание (Объявление) объекта 'А' структуры 'Point'.
				//Создание экземпляра структуры 'Point'.
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl;

	Point B;
	B.set_x(4);
	B.set_y(5);
	B.print();
	//distance - возвращает расстояние до указанной точки
	cout << "\n--------------------------------------\n";
	cout << A.distance(B) << endl;
	cout << "\n--------------------------------------\n";
	cout << B.distance(A) << endl;
	cout << "\n--------------------------------------\n";
	cout << distance(A, B) << endl;
	cout << "\n--------------------------------------\n";
	cout << distance(B, A) << endl;
	cout << "\n--------------------------------------\n";

#endif // DISTANCE
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << i << tab;
	//}
	//cout << endl;
#ifdef CONSTRUCTORS_CHECK
	Point A;		//Default constractor
	A.print();
	Point B(2, 3);
	B.print();
	Point C = B;
	C.print();		//CopyConstructor
	Point D(C);		//CopyConstructor
	D.print();
	Point E;		//Default constructor
	E = C;			//CopyAssignmnet
	E.print();
	A = B;
	A.print();

	//Point(); -	Конструктор класса Point
	//~Point(); -	Деструктор класса Point  
#endif // CONSCTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(15, 18);
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();

#endif // ASSIGNMENT_CHECK

#ifdef ARITHMETICAL_OPERATORS
	Point A(2, 3);
	Point B(3, 4);
	A += B;
	A.print();
	Point C = A + B;
	C.print();
	C = A - B;
	C.print();
	Point D = C++;
	C.print();
	D.print();
#endif // ARITHMETICAL_OPERATORS

	Point A(2, 3);
	//Point B(3, 4);
	Point B = A;
	//B++;
	if (A == ++B)
	{
		cout << "Точки равны" << endl;
	}
	else
	{
		cout << "Точки разные" << endl;
	}
}

double distance(const Point& A, const Point& B)
{
	//double x_distance = A.get_x() - B.get_x();
	//double y_distance = A.get_y() - B.get_y();
	//double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	//return distance;
	//return sqrt((A.get_x() - B.get_x()) * (A.get_x() - B.get_x()) + (A.get_y() - B.get_y()) * (A.get_y() - B.get_y()));
	return sqrt(pow(A.get_x() - B.get_x(), 2) + (pow(A.get_y() - B.get_y(), 2)));
	//return pow(pow(A.get_x() - B.get_x(), 2) + (pow(A.get_y() - B.get_y(), 2)), 0.5);
}