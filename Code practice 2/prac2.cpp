#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



using namespace std;

void my_long_operation(){
    
        for(int i = 0; i<1000000; i++){
        // cout<<"value of is = "<< i <<endl;
        
    }
};

void print_string(int j, string i){
    for (int k = 0;k<j; k++){
        cout << i << endl;
    }
    
}
void print_double_number(double i){
    cout << i << endl;
}



int main(){
    print_string(4, "------");
    system("ls -lrt"); 
    print_string(4, "------");
    print_string(1, "amin");
    print_double_number(323424);
    print_string(4, "------");

   

    // declaring argument of time()
    time_t start_time = time(NULL);
    my_long_operation();
    time_t end_time = time(NULL);
    printf("%s", ctime(&start_time));
    printf("%s", ctime(&end_time));
    // printf(end_time-start_time);
};