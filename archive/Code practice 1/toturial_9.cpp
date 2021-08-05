#include <iostream>
using namespace std;

int main()
{
    int x =2;
    int arr[] = {1,2,3,4,5};

    cout<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<"number of elements = "<<sizeof(arr)/sizeof(arr[0])<<endl;

    for (int i = 0;i<5;i++){

        cout << arr[i]<<endl;
    }



}