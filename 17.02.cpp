#include <iostream>
#define random(min, max) min + rand() % (max - min + 1)
using namespace std;
void fillArray(int** arr) {
    int size1 = _msize(arr) / sizeof(arr[0]), \
        size2 = _msize(arr[0]) / sizeof(arr[0][0]);

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size1; j++) {
            arr[i][j] = random(0, 9);
        }
    }
}
void showArray(int** arr) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2;

    for (int i = 0; i < size1; i++) {
        size2 = _msize(arr[i]) / sizeof(arr[i][0]);
        for (int j = 0; j < size2; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
void removeArray(int**& arr, int index) {
    int size1 = _msize(arr) / sizeof(arr[0]);

    if (index < 0 || index > size1) {
        cout << "Error";
        return;
    }

    int** newArr = new int* [size1 - 1];
    for (int i = 0, j = 0; i < size1; i++) {
        if (i != index)
            newArr[j++] = arr[i];
    }

    delete[]arr[index];
    delete[]arr;
    arr = newArr;
}

int main()
{
    srand(time(NULL));

    int** arr = new int* [5];
    for (short i = 0; i < 5; i++) {
        arr[i] = new int[5];
    }

    fillArray(arr);
    showArray(arr);
    removeArray(arr, 3);
    showArray(arr);
}