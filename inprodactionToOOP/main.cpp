#include<iostream>//маптпы 
using namespace std;
#define delimitr "\n---------------------------------------------------------\n"

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
		this -> x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//		Constructors:
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;

	}
	Point(double x,double y)
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
	//			Operftors:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
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
		cout << "X= " << x<< "\tY = " << y << endl;
	}
}; 

double distance (Point &A, Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUC_POINT
//#define CONSTRUCTORS_CHECK
#define DISTANCE_CHECK
//#define ASSIGMENT_CHECK

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

#ifdef CONSTRUCTORS_CHECK
	Point A;
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;//Copy constructor
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	A.print();
	Point B(7, 8);
	B.print();

	cout << "Расстояни от точки А до точки В : " << A.distance(B) << endl;
	cout << delimitr << endl;
	cout << "Расстояни от точки А до точки В : " << B.distance(A) << endl;
	cout << delimitr << endl;
	cout << "Расстояни между точками А и В : " << distance(A,B) << endl;
	cout << delimitr << endl;
	cout << "Расстояни между точками В и А : " << distance(B,A) << endl;
	cout << delimitr << endl;
#endif // DISTANCE_CHECK
#ifdef ASSIGMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimitr << endl;
	A = B = C = Point(2, 3);
	cout << delimitr << endl;
	A.print();
	B.print();
	C.print();
#endif // #ASSIGMENT_CHECK
}