#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


////////////////////////////////////////////////////////////////////
///////////		ОБЪЯВЛЕНИЕ КЛАССА - CLFSS DECLARATION		////////
class String;
String operator+(const String& left, const String& right);


class String
{
	int size;		//размер строки в Байтах
	char* str;		//адрес строки в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Constructors:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();
	//			Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	char operator[](int i) const;
	char& operator[](int i);

	//				Methods:
	void print()const;
};


///////////		КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА - CLASS DECLARATION	END	////////
////////////////////////////////////////////////////////////////////////

///------------------------------------------------------------------///


////////////////////////////////////////////////////////////////////
///////////		ОПРЕДЕЛЕНИЕ КЛАССА - CLASS DEFINITION		////////


int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return this->str;
}
char* String::get_str()
{
	return this->str;
}

//				Constructors:
String::String(int size) : size(size), str(new char [size] {})
{
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char str[]) : String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) : size(other.size), str(other.str)
{
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}
//			Operators:
String& String::operator=(const String& other)
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
String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
char String::operator[](int i) const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//				Methods:
void String::print()const
{
	cout << "Size: " << size << endl;
	cout << "Str:  " << str << endl;
}
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


///////////		КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА - CLASS DEFINITION	END	////////
////////////////////////////////////////////////////////////////////////

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
