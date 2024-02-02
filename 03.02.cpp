

#include <iostream>
using namespace std;


int PLUS(int a, int b) {
	return (a + b);
}
int MINUS(int a, int b) {
	return a - b;
}
int UMNOJIT(int a, int b) {
	return a * b;
}
int DELENIE(int a, int b) {

	if (b != 0) {
		return a / b;
	}

	cout << "делить на ноль нельзя!" << endl;

	return 0;
}

float myPlus(float a, float b) {
	return a + b;
}
float myMinus(float a, float b) {
	return a - b;
}
float myUMNOJIT(float a, float b) {
	return a * b;
}
float myDELENIE(float a, float b) {
	if (b != 0) {
		return a / b;
	}
	cout << "делить на ноль нельзя!" << endl;
	return 0;
}

int foo1(int a, int b, char c) {

	switch (c) {

	case '+':
		return PLUS(a, b);

	case '-':
		return MINUS(a, b);

	case '*':
		return UMNOJIT(a, b);

	case '/':
		return DELENIE(a, b);

	default:

		cout << "ошибка" << endl;

		return 0;
	}
}



float foo1(float a, float b, char c) {

	switch (c) {

	case '+':
		return myPlus(a, b);

	case '-':
		return myMinus(a, b);

	case '*':
		return myUMNOJIT(a, b);

	case '/':
		return myDELENIE(a, b);

	default:

		cout << "ошибкаw" << endl;

		return 0;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	float a, b;

	char c;

	cout << "Первое число: ";
	cin >> a;

	cout << "Второе число: ";
	cin >> b;

	cout << "(+) (-) (*) (/):  ";
	cin >> c;

	if (c == '+' || c == '-' || c == '*' || c == '/') cout << foo1(a, b, c);


	else {
		cout << "Error " << endl;
	}



}