#include <iostream>
using namespace std;
bool linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return true;  
        }
    }
     
}

int main() {
    
    setlocale(LC_ALL, "");
    int array[] = { 8,15,23,54,52,21,37,17,600 };
    int size = sizeof(array) / sizeof(array[0]);
    int Key =1;
    

    if (linearSearch(array, size, Key)) {
        cout << "Ключ найден в массиве.\n"<<Key;
    }
    else {
        cout << "Ключ не найден в массиве.\n";
    }

}
