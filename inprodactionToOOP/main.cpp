#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:

}; 
//#define STRUC_POINT
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUC_POINT


	int a;//объявление переменной 'a' типа 'int'
	Point A;//обявление переменной 'А' типа 'Point'
			// Объявление объекта А' структуры 'Point'
			// Создание экземпляра 'А' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(A) << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUC_POINT
}