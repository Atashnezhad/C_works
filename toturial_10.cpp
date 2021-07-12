#include <iostream>
using namespace std;

int main(){


    int x = 3;
    for(int i = -x; i<x;i++){

        cout << i<<endl;

    }

    
    int y=20000;
    int arr[y];


    for (int i = 0; i < y; i++){
        arr[i] = i;

    
    }
    
    cout<<"size of one element = "<<sizeof(arr[0])<< " bits " <<endl;
    cout<<"size of whole element = "<<sizeof(arr)<<" bits " <<endl;      


 
}