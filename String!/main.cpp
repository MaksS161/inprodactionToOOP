#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);


class String
{
	int size;		//размер строки в Байтах
	char* str;		//адрес строки в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return this->str;
	}
	char* get_str()
	{
		return this->str;
	}

	//				Constructors:
	explicit String(int size = 80) : size(size), str(new char [size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "Constructor:\t" << this << endl;
	}
	String(const char str[]): size (strlen(str) + 1), str (new char[size] {})
	{
		//this->size = strlen(str) + 1; //Послкольку класс хранит размер в байтаз, +1 нужен для хранения NULL элемента
		//this->str = new char[size] {};//выделяем память подстраку 
		for (int i = 0; i<size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other):size (other.size), str (new char[size] {})
	{
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other): size (other.size), str (other.str)
	{
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}
	//			Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	char operator[](int i) const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	//				Methods:
	void print()const
	{
		cout << "Size: " << size << endl;
		cout << "Str:  " << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat  (left.get_size() + right.get_size()-1);
	for (int i = 0; i < left.get_size(); i++)
	{
	//	cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
	//	cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];
	}
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

#define HOME_WORK
//#define CONSTRUCTOR_CALLING

void main()
{
	setlocale(LC_ALL, "");
	/*cout << "Hello" << endl;
	String str1;
	str1.print();*/

	//String str = "Hello";
	////str.print();
	//cout << str << endl;

#ifdef HOME_WORK
	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;
	
	String str3 = str1 +" " + str2;
	//String str3;
	//str3 = str1 + str2;

	cout << str3 << endl;
	str1 += str2;
	cout << str1 << endl;

	

#endif // HOME_WORK

#ifdef CONSTRUCTOR_CALLING

	String str1;		//Default constructor
	str1.print();

	String str2 (22);	//Singel-Argument constructor 'int'
	str2.print();
	 
	String str3 = "Hello";//Singel-Argument constructor 'const char'
	str3.print();

	String str4();	//Default constructor Невозможно вызвать таким образом 
	// В этой страке объявляется функция 'str4', которая ничего не принимает,
	// и возвращает объект класса 'String'
	//str4().print();
	//Если нужно вызвать конструктор по умолчанию, то это можно сдделать так 
	String str5{}; //Default constructor
	str5.print();

	String str6{ "World" };
	str6.print();

	String str7 = str3;	//CopyConstractor
	str7.print();

	String str8;
	str8 = str6;		//CopyAssignment (Присваивание)
	str8.print();

#endif // CONSTRUCTOR_CALLING

}
