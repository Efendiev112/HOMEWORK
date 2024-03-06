
#include <iostream>
#define random(min,max) (min + rand() % (max - min + 1))
#include <fstream>
using namespace std;

void fillArray(int** array, int* newArray) {
	int size1 = _msize(array) / sizeof(array[0]);
	int size2 = _msize(array[0]) / sizeof(array[0][0]);
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			array[i][j] = random(0, 10);
			newArray[i] = random(0, 10);
		}
	}
}
void showArray(int** array, int* newArray) {
	int size1 = _msize(array) / sizeof(array[0]);
	int size2;
	for (int i = 0; i < size1; i++) {
		size2 = _msize(array[i]) / sizeof(array[i][0]);
		for (int j = 0; j < size2; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}
/*9*/
void addArray(int**& array, int* newArray, int index) {
	int size1 = _msize(array) / sizeof(array[0]);
	int size2 = _msize(array[0]) / sizeof(array[0][0]);
	if (index > 0 && index < size1) {
		int size3 = _msize(newArray) / sizeof(newArray[0]);
		int** buf = new int* [size1 + 1];

		for (int i = 0; i < index; i++) {
			buf[i] = array[i];
		}

		buf[index] = newArray;

		for (int i = index; i < size1; i++) {
			buf[i + 1] = array[i];
		}

		delete[] array;
		array = buf;
	}
	
}
void fillDoubleArray(int** array) {
	int size1 = _msize(array) / sizeof(array[0]);

	for (int i = 0; i < size1; i++) {
		int size2 = _msize(array[i]) / sizeof(array[i][0]);
		for (int j = 0; j < size2; j++) {
			array[i][j] = random(1, 10);
		}
	}
}

/*Задание 7*/
void CopyArray(int** array, int** array2) {
	int size1 = _msize(array) / sizeof(array[0]);
	int size2 = _msize(array[0]) / sizeof(array[0][0]);
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++) {
			array2[i][j] = array[i][j];
		}
	}
}
void showArray(int** array, int** array2) {
	int size1 = _msize(array) / sizeof(array[0]);
	int size2 = _msize(array[0]) / sizeof(array[0][0]);
	cout << endl;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout <<  endl;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++) {
			cout << array2[i][j] << " ";
		}
		cout << endl;
	}
}

/*Задание 13*/
int KolvoSymbols(string str) {
	int counter = 0;
	for (int i = 0; i <= str.length(); i++){
		counter++;
	}
	counter--;
	return counter;
}




/*Задание 8*/
void deleteElementbyindex(int*& array, int index) {
	int size = _msize(array) / sizeof(array[0]);
	int* buf = new int[size - 1];
	for (int i = 0; i < index; i++) {
		buf[i] = array[i];
	}
	for (int i = index + 1; i < size; i++) {
		buf[i - 1] = array[i];
	}
	delete[] array;
	array = buf;
}
	




int main()
{
	setlocale(LC_ALL, "rus");
	
	/*1*/
	/*float a, b, c, d;
	cin >> a >> b >> c >> d;
	cout <<"AVG: "<< (a + b + c + d) / 4;*/

	/*2*/
	/*for (int i = 2; i <= 40; i+=2)
	{
		cout << i <<" ";
	}*/

	/*3/
	/*int storona;
	cin >> storona;
	for (int i = 0; i <= storona; i++)
	{
		for (int j = 0; j <i ; j++)
		{
			cout << "*";
		}
		cout << endl;
		
	}*/


	/*4*/
	/*int num, count = 0;
	cout << "число:\t";
	cin >> num;
	if (num == 0) count = 1;
	else {
		while (num != 0) {
			num = num / 10;
			count++;
		}
	}
	cout << "Число содержит разрядов-  " << count; 
	*/

	
	/*5*/
	/*
	const int size = 5;
	int min, max, array3[size];
	cout << "диапазон:";
	cin >> min >> max;
	if (min > max) swap(min, max);
	for (int i = 0; i < size; i++) {
		array3[i] = random(min, max);
		cout << array3[i] << " ";
	}*/




	
	const int row = 5;
	const int column = 5;
	int** array = new int* [row];
	int** array2 = new int* [row];
	int* array4 = new int[column] {10, 25, 32, 43, 45};

	for (int i = 0; i < column; i++) {
		array[i] = new int[column];
	}
	for (int i = 0; i < column; i++) {
		array2[i] = new int[column];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			array[i][j] = random(1, 10);
		}
	}

	/*Задание 8*/
	int index = 0;
		for (int i = 0; i < row; i++) {
			/*cout << array4[i] << " ";*/
		}
		cout << endl;
		/*deleteElementbyindex(array4, index);*/
		for (int i = 0; i < row-1; i++) {
			/*cout << array4[i] << " ";*/
		}
		cout << endl;

	//CopyArray(array, array2); /*Задание 7*/
	//showArray(array, array2);
		



	/*Задание 13*/
	/*string str;
	cin >> str;
	cout << KolvoSymbols(str);*/


		/*9*/
		const int size1 = 5;
		const int size2 = 5;
		int** array5 = new int* [size1];
		for (int i = 0; i < size2; i++) {
			array5[i] = new int[size2];
		}
		int* newArray = new int[size2];
		fillArray(array5, newArray);
		;
		showArray(array5, newArray);
		addArray(array5, newArray, 2);
		cout << endl;
		showArray(array5, newArray);





	


}

