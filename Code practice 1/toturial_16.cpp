#include <iostream>
#include <tuple>
// #include<string>
using namespace std;

int main(){

    tuple <int, string> person(20,"amin atashnezhad"); // this how to initialize the values and name of tuple

    cout << get<1>(person) << endl; //and notice that the 0 means the first element and 1 means the second element and so on!
    // if you gonna change an element of tuple check out below
    cout << "\n\n" << endl;
    get<1>(person) = "billy";    
    cout << get<1>(person) << endl;


    // we can also initialize tuple in differnet line









}