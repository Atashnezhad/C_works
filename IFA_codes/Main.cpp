
/* 
Author: Amin Atashnezhad
Interfacial friction angle calculations
*/
// standard funcs
#include <iostream>
// made up funcs
#include "Full_bit.h"
#include "Full_bit.h"
#include "write_csv.h"

// to compile this file simply copy and paste following in the cmd
// clear; g++ IFA.cpp -o IFA; ./IFA
// clear; g++ -std=c++11 IFA.cpp -o IFA; ./IFA
// run the followinig in cmd to update git repo
// git add .; git commit -m "default_message"; git push; git status; clear

int main()
{


    printf("This is OOP for interfacial friction angle calculations\n"
            "the main function was developed in the python language.\n");
    print_line_space_with_lenght(75);

    std::vector<float> WOB_data;
    std::vector<float> ROP_data;

    WOB_data = {2300,2420,2660,2910,3180,3410,3660,3940,4170};
    ROP_data = {9.9,11,14.7,18.1,22.6,27.2,31.1,36.5,39.4};
    Full_bit case1_FullBit ("SWG_4B_100", 0.9, 
                            WOB_data, ROP_data, 
                            3.75, 100, 21500, 12, 20, 0.5, 4);

    WOB_data = {2150,2300,2560,2810,3060,3290,3540,3820,4070};
    ROP_data = {10.2,11.9,15.1,19.6,25.6,31.4,37.7,44.3,50.8};
    Full_bit case2_FullBit ("SWG_4B_150", 1, 
                            WOB_data, ROP_data, 
                            3.75, 150, 21500, 12, 20, 0.5, 4);










    // WOB_data = {2280,2380,2570,2810,3070,3310,3540,3820,4080};
    // ROP_data = {11.4,12.5,14.9,18.2,22.9,27.7,34.8,43,50};
    // Full_bit case3_FullBit ("SWG_4B_200", 0.9, 
    //                         WOB_data, ROP_data, 
    //                         3.75, 200, 21500, 12, 20, 0.5, 4);


    // WOB_data = {900,1180,1230,1360,1510,1650,1730,1780};
    // ROP_data = {24.8,48.9,53.4,54,62,70.8,81.3,84.1};
    // Full_bit case4_FullBit ("BSS_4B_100", 0.9, 
    //                         WOB_data, ROP_data, 
    //                         3.75, 100, 7100, 12, 20, 0.5, 4);

    // WOB_data = {970,1090,1110,1300,1520,1720,1770,1960};
    // ROP_data = {40.8,61.9,64.5,71.7,91.5,102.9,106.9,127.7};
    // Full_bit case5_FullBit ("BSS_4B_150", 0.9, 
    //                         WOB_data, ROP_data, 
    //                         3.75, 150, 7100, 12, 20, 0.5, 4);

    // WOB_data = {850,960,1150,1210,1270,1340,1570,1800};
    // ROP_data = {30.5,59.5,84.8,87.8,96.5,96.6,120.9,136};
    // Full_bit case6_FullBit ("BSS_4B_200", 0.9, 
    //                         WOB_data, ROP_data, 
    //                         3.75, 200, 7100, 12, 20, 0.5, 4);

    std::cout<<"data was fed"<<std::endl;
    print_line_space_with_lenght(75);

    //run the code and print the rop, diff and IFA values

    printf("run the code and print the rop, diff and IFA values for case name %s",
            case1_FullBit.name.c_str());std::cout<<std::endl;

    case1_FullBit.calculate_fitness();

    std::cout<<"rop list is \n" << std::endl;
    print_my_vector(case1_FullBit.ROP_Model_esti_list);
    print_line_space_with_lenght(25);

    std::cout<<"IFA list is \n" << std::endl;
    print_my_vector(case1_FullBit.IFAlist);
    print_line_space_with_lenght(25);

    std::cout<<"difflist  is \n" << std::endl;
    print_my_vector(case1_FullBit.difflist);
    print_line_space_with_lenght(25);




    // generate a csv file from calculations
    // Make three vectors of data
    std::vector<float> wob = case1_FullBit.Data_WOB;
    std::vector<float> rop = case1_FullBit.Data_ROP;
    std::vector<float> rop_calc = case1_FullBit.ROP_Model_esti_list;
    std::vector<float> ifa_calc = case1_FullBit.IFAlist;
    std::vector<float> diff_calc = case1_FullBit.difflist;

    
    // Wrap into a vector
    std::vector<std::pair<std::string, std::vector<float>>> output = {{"WOB lbf", wob}, 
        {"ROP ft/hr", rop}, 
        {"ROP calc ft/hr", rop_calc},
        {"IFA degree", ifa_calc}, 
        {"diff", diff_calc}};
    
    // Write the vector to CSV
    write_csv("calculations.csv", output);



//     printf("run the code and print the rop, diff and IFA values for case name %s",
//             case2_FullBit.name.c_str());std::cout<<std::endl;

//     case2_FullBit.calculate_fitness();

//     std::cout<<"rop list is \n" << std::endl;
//     print_my_vector(case2_FullBit.ROP_Model_esti_list);
//     print_line_space_with_lenght(25);

//     std::cout<<"IFA list is \n" << std::endl;
//     print_my_vector(case2_FullBit.IFAlist);
//     print_line_space_with_lenght(25);

//     std::cout<<"difflist  is \n" << std::endl;
//     print_my_vector(case2_FullBit.difflist);
//     print_line_space_with_lenght(25);





}

