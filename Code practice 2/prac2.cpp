#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #include <chrono>
// #include <sys/time.h>
// #include <ctime>

using namespace std;

void my_long_operation(){
    
        for(int i = 0; i<1000000; i++){
        cout<<"value of is = "<< i <<endl;
        
    }
};

// int main() {
//     struct timeval time_now;
//     gettimeofday(&time_now, nullptr);
//     time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
//     cout << "seconds since epoch: " << time_now.tv_sec << endl;
//     cout << "milliseconds since epoch: "  << msecs_time << endl << endl;
//     return EXIT_SUCCESS;
// }


int main(){
    // declaring argument of time()
    time_t start_time = time(NULL);
    my_long_operation();
    time_t end_time = time(NULL);
    printf("%s", ctime(&start_time));
    printf("%s", ctime(&end_time));
    // printf(end_time-start_time);
};