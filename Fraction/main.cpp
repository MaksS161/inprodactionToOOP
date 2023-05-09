#include<iostream>
using namespace std;

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
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
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
	//Прямо в 'return' создаем временный безымянный объект типа 'Fraction'
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator/(Fraction left,Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()* right.get_denominator(),
		left.get_denominator()*right.get_numerator()
	).to_proper();
	
}
//#define CONSTRACTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRACTORS_CHECK
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
	
	Fraction C = A * B;
	A.print();
	B.print();
	C.print();

	Fraction D = A / B;
	D.print();
}