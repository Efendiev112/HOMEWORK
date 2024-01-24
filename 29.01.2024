
#include <iostream>
using namespace std;

float foo1(int a){
    
    return (a%2);
}




int foo2(int a, int t = 0) {
    int y = a;
    while (y > 0) {
        t = t * 10 + y % 10;
        y /= 10;
    }
    return (a==t);
}





 long long foo3(int q) {
    int h = 1;
    for (int i = 2; i <= q; i++) {
        h *= i;
    }
    return h;
}





int main()

{
    setlocale(LC_ALL, "");
	
    int g;
    cout << "Число: ";
    cin >> g;
	(foo1(g)) ? cout << "Нечетное" : cout << "Четное" << endl; 

    int v;
    cout << "число: ";
    cin >> v;
    (foo2(v)) ? cout << " полиндром" : cout << " не полиндром";
    cout << endl;

    int n;
    cout << "число: ";
    cin >> n;
    cout << foo3(n);

}

