#include <iostream>
// #include <tuple>
#include<string>
using namespace std;
#include<vector>
// sort header ref: https://www.geeksforgeeks.org/sorting-a-vector-in-c/
#include <bits/stdc++.h>



// run codes using following cmd
// clear; g++ pr.cpp -o pr; ./pr

int main(){

    vector<float> wob = {10000,8000, 25000, 15000, 35000};
    sort(wob.begin(), wob.end());

    // for (int i=0; i < wob.size(); i++){
    //     printf("wieght on bit vector, data = %.2f lbf", wob[i]);cout<<endl;

    // }

    for (auto x : wob){
        printf("wieght on bit vector, data = %.2f lbf", x);cout<<endl;

    }

    // cout << "it is pr file, here!"<<endl;


    return 0;
}