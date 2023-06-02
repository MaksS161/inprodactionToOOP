#include "String.h"

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
