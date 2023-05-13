#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);



class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//			Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstruct:\t" << this << endl;
	}
	Fraction(int integen)
	{
		this->integer = integen;
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator (denominator);
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constractor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;	
		cout << "CopyConstructor:" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//			Operators:
	//Fraction& operator() (int integer, int numerator, int denominator)
	//{
	//	obj.set_integer(integer);
	//	obj.set_numerator(numerator);
	//	obj.set_denominator(denominator);

	//}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this  = *this*other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this/other;
	}

	//			Increment/Decrement:
	Fraction& operator++()	//Prefix increment
	{
		to_proper();
		integer++;
		return *this;
	}
	Fraction operator++(int)//Postfix(Suffix) increment
	{
		//������ ��������� ���� � ����� ���� �������� ���� 'int', � ������ 'int'
		//��� ��������� ����������� �� ������ ���������� ������� �������� ����������� ��������� �� ����������� 
		to_proper();
		Fraction old = *this;
		integer++;
		return old;
	} 
	operator int()
	{
		to_proper();
		return integer;
	}
	operator  double()
	{
		return integer +(double) numerator/denominator;
	}



	//			Methods:


	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	} 
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		inverted.numerator ^= inverted.denominator;
		inverted.denominator ^= inverted.numerator;
		inverted.numerator ^= inverted.denominator;
		return inverted;
	}
	Fraction& reduse()
	{
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;//GCD - Greatest Common Divisor (���������� ����� ��������)
		numerator /= GCD;
		denominator /= GCD;
		return*this;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*( Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	//Fraction result;
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());
	
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;*/
	//����� � 'return' ������� ��������� ���������� ������ ���� 'Fraction'
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduse();
}

Fraction operator/(const Fraction& left,const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()* right.get_denominator(),
		left.get_denominator()*right.get_numerator()
	).to_proper();*/
	return left * right.inverted();
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		os<< obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os<< ")";
	}
	else if (obj.get_integer() == 0)os<< 0;
	return os;
	}
//std::iostream& operator>>(std::iostream& is, Fraction& obj)
//{
//	int integer, numerator, denominator;
//	is >> integer >> numerator >> denominator;
//	obj(integer,numerator,denominator)
//	return is;
//}


bool operator==(Fraction left, Fraction right)
{
	
	left.to_improper();
	right.to_improper();
	
		return	((left.get_integer() * right.get_denominator() + left.get_numerator() * right.get_denominator()) == (right.get_integer() * left.get_denominator() + right.get_numerator() * left.get_denominator())) && ((left.get_denominator() * right.get_denominator()) == (right.get_denominator() * left.get_denominator()));
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return	!(left==right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return	left.get_numerator() * right.get_denominator() >
	right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return	left.get_numerator() * right.get_denominator()<
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return!(left < right);
	//return	left > right|| left == right;
}
bool operator<= (const Fraction & left, const Fraction & right)
{
	return!(left > right);
	//return	left > right|| left == right;
}

//#define CONSTRACTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_DECREMENT
//#define IOSTREAM_OPERATOR
//#define CONVERSION_FROM_CLASS
#define HOME_WORK_1


void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRACTORS_CHECK
#ifdef ARITHMETICAL_OPERATORS_CHECK


	Fraction A; //Default constructor
	A.print();

	Fraction B = 5; //Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();
	
	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRACTORS_CHECK

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();
	
	/*Fraction C = A * B;
	A.print();
	B.print();
	C.print();

	Fraction D = A / B;
	D.print();*/

	A *= B;
	A.print();

	A /= B;
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK
#ifdef INCREMENT_DECREMENT
	for (double i = 0.5; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}
#endif //INCREMENT_DECREMENT 

	//Fraction A(2, 3, 4);
	//cout << A << endl;

#ifdef IOSTREAM_OPERATOR

	cout << (Fraction(1, 2) <= Fraction(5, 10)) << endl;
#endif // IOSTREAM_OPERATOR
#ifdef CONVERSION_FROM_CLASS
	Fraction A(2, 3, 4);
	cout << A << endl;
	
	double a = A;

	cout << a << endl;
#endif // CONVERSION_FROM_CLASS

#ifdef HOME_WORK_1
	Fraction A = 2.75;
	cout << A << endl;

#endif // HOME_WORK_1






}