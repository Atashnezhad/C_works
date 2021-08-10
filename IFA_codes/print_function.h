#include <iostream>
#include<vector>

#pragma once



// #include "print_line_space_with_lenght.h"
void print_line_space_with_lenght(int j = 10){
    std::cout<<std::endl;
    for (int i=0;i<j;i++){ printf("=");}
    std::cout<<std::endl;
}

void print_my_vector(std::vector<float> vec){

        // for (auto val : vec){
        //     std::cout<<val<<" ";}
        for (int i=0; i < vec.size();i++){

            std::cout<<vec[i]<<" ";}


        std::cout<<std::endl;
}




