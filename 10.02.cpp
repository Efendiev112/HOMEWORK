

#include <iostream>

using namespace std;
void FillArray(int* array) {
	int size = _msize(array) / sizeof(array[0]);
	for (int i = 0; i < size; i++) {
		array[i] = (1 + rand() % (99 - 1 + 1));
	}
}
void ShowArray(int* array) {
	int size = _msize(array) / sizeof(array[0]);
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}



void Sort(int* array) {
	int size = _msize(array) / sizeof(array[0]);
	int count = 0;
	for (int i = size - 1; i > 0; i--) {
		bool flag = true;
		for (int j = 0; j < i; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
				flag = false;
				count++;
			}
		}
		if (flag)
			break;
	}
}



int main()
{
	srand(time(NULL));
	int* array = new int[15];
	FillArray(array);
	ShowArray(array);
	Sort(array);
	cout << endl;
	ShowArray(array);
}

