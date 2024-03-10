﻿#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void addString(string* &array, string stroka, int size) {
    string* buf = new string[size + 1];
    for (int i = 0; i < size; i++)
    {
        buf[i] = array[i];
    }
    buf[size] = stroka;
    delete[] array;
    array = buf;
}
void readfile(string path, string*& array, int& size) {
    string* stringArray = new string[0];
    ifstream in(path);
    if (in.is_open()) {
        string str;
        while (getline(in, str))
        {
            addString(stringArray, str, size++);
        }
    }
   
    delete[] array;
    array = stringArray;
}
void showArray(string* array, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}
void copy(string path) {
    string* stringArray = new string[0];
    int size = 0;
    readfile(path, stringArray, size);



    string copyPath;
    for (int i = 0; i < path.length(); i++) {
        if (path[i] == '.') copyPath += "(COPY)";
        copyPath += path[i];
    }



    ofstream out(copyPath);
    if (out.is_open()) {
        for (int i = 0; i < size; i++)
        {
            out << stringArray[i] << endl;
        }
    }
    out.close();
}
int main()
{
    setlocale(LC_ALL, "rus");
    //int arraySize = 0;
    //string* stringArray = new string[0];
    //readfile("hello.txt", stringArray, arraySize);
    //showArray(stringArray, arraySize);
    copy("hello.txt");

}
