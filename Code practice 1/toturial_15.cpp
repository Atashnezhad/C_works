#include <iostream>
#include<string>
using namespace std;

int main(){

    int x = 4;
    // string y2 = &x;
    int *y = &x;

    cout << "\n\n\nvalue of x is " << x << endl;
    // cout << " \nlocation of y2 is "<< y2 << endl;
    cout << " \nlocation of x is "<< &x << endl;
    cout << " \nvalue of y is "<< y << endl;
    cout << " \nlocation of y is " << &y << endl;
    cout << " \nvalue of *y is \n\n\n" << *y << endl;
}

