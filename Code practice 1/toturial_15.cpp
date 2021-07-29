#include <iostream>
#include<string>
using namespace std;

int main(){

    int x = 4;
    int *y = &x;

    cout << "\n &x location of x is "<<&x<<endl;
    cout << "y is "<<y<<endl;
    cout << "&y location of y is " <<&y<<endl;
    cout << " *y value of y is " <<*y<<endl;
}

