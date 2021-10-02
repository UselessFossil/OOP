#include<iostream>
using namespace std;

#define tab "\t"

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
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
};

double distance(Point A, Point B);

//#define STRUCT_POINT

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

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl;

	Point B;
	B.set_x(4);
	B.set_y(5);
	//distance - возвращает расстояние до указанной точки
	cout << A.distance(B) << endl;
	cout << B.distance(A) << endl;
	cout << endl;
	cout << distance(A, B) << endl;
	cout << distance(B, A) << endl;
}

double distance(Point A, Point B)
{
	//double x_distance = A.get_x() - B.get_x();
	//double y_distance = A.get_y() - B.get_y();
	//double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	//return distance;
	//return sqrt((A.get_x() - B.get_x()) * (A.get_x() - B.get_x()) + (A.get_y() - B.get_y()) * (A.get_y() - B.get_y()));
	return sqrt(pow(A.get_x() - B.get_x(), 2) + (pow(A.get_y() - B.get_y(), 2)));
	//return pow(pow(A.get_x() - B.get_x(), 2) + (pow(A.get_y() - B.get_y(), 2)), 0.5);
}