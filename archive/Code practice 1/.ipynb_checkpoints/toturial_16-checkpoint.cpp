#include <iostream>
#include <tuple>
#include<string>
using namespace std;

int main(){

    // typename person;
    tuple<int, string> person(20,"amin atashnezhad");
    

    cout << get<1>(person) << endl; 
    // cout << "\n\n" << endl;
    // get<1>(person) = "billy";    
    // cout << get<1>(person) << endl;


    // we can also initialize tuple in differnet line


}