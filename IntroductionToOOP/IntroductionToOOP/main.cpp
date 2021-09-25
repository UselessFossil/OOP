#include<iostream>
using namespace std;

#define tab "\t"

//Создание структуры:
class Point
{
	double x;
	double y;
public:
};

#define STRUCT_POINT

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

}