
/* 
Author: Amin Atashnezhad
Interfacial friction angle calculations
*/

#include <iostream>
#include<vector>
#include <cmath>
#include <math.h>       /* pow */ /* sin */
#include<string>
#include<bits/stdc++.h>
// using namespace std;



// define some constants
#define PI 3.14159265
#define diff1 10000000000000 // initiate it with a long value
#define Number_of_random_attempts 10000;
#define IFA_search 0





// to compile this file simply copy and paste following in the cmd
// clear; g++ IFA.cpp -o IFA; ./IFA
// clear; g++ -std=c++11 IFA.cpp -o IFA; ./IFA



// run the followinig in cmd to update git repo
// git add .; git commit -m "defultmessage"; git push; git status; clear



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

class Full_bit{
    // instances = []
    // full bit details - attributes
    // self.__class__.instances.append(self)
public:

    std::string name;
    std::vector <float> Data_WOB, Data_ROP;
    float ROP_constant, Db, RPM, UCS, Dc;
    int NOC, BR, NOB;


    // more attributes are calculated at the following
    float Ac; // cutter face area sq-inch
    float AB_max;
    float Re;// calculate the equivalent radius
    int Number_of_DataPoints;
    std::vector <float>  WOC; // weight on cutter
    float A_bit; // bit area
    std::vector <float>  AB; // calculate the cutter beanth area
    // float ABB;
    float UCSN; // calculate the normalized UCS
    float V_Cutter_Equivalent; // calculate equivalent velocity
    float VN; // normalize the equivalent velocity


    // int IFA;



    //constructor
    Full_bit(std::string inst_name, float inst_ROP_constant, std::vector <float> inst_Data_WOB, 
            std::vector <float>  inst_Data_ROP, float inst_Db, float inst_RPM, float inst_UCS, 
            int inst_NOC, int inst_BR, float  inst_Dc, int inst_NOB){

        name = inst_name;
        ROP_constant = inst_ROP_constant;

        Data_WOB = inst_Data_WOB; 
        sort(Data_WOB.begin(), Data_WOB.end());

        Data_ROP = inst_Data_ROP; 
        sort(Data_ROP.begin(), Data_ROP.end());

        Db = inst_Db;
        RPM = inst_RPM;
        UCS = inst_UCS;
        NOC = inst_NOC;
        BR = inst_BR;
        Dc = inst_Dc;
        NOB = inst_NOB;

        printf("The object created with name %s", name.c_str()); std::cout<<std::endl;
        // print_line_space_with_lenght(40);

        // more attributes are calculated at the following

        Ac = PI*pow(Dc, 2) / 4; // cutter face area sq-inch
        AB_max = Ac*sin((( BR * PI ) / 180 ));
        Re = Db/(2*pow(2, 0.5)); // calculate the equivalent radius
        Number_of_DataPoints = Data_WOB.size();

        //calculate the weight on cutter
        // for (auto wob : Data_WOB)
        // {
        //     WOC.push_back(wob/NOC);
        // }   
        for (int i=0; i< Data_WOB.size(); i++)
        {
            WOC.push_back(Data_WOB[i]/NOC);
        }          

        A_bit = (PI*pow(Db, 2))/4; // bit area


        // calculate the cutter beanth area and
        // filter those values that are greater 
        // than availabe cutter beanth area (AB_max)
        float par;
        for (int i=0; i<WOC.size(); i++)
        {
            par = WOC[i]/UCS;
            if (par<AB_max){
                AB.push_back(par);
            }else{
                AB.push_back(AB_max);
            }
            
        }   
   
        // calculate the normalized UCS
        UCSN = UCS/5000;

        // calculate equivalent velocity
        V_Cutter_Equivalent = 2*PI*Re*RPM/60; 

        // normalize the equivalent velocity
        VN = V_Cutter_Equivalent/2.1;


    }

    void print_inserted_attributes_details(){

        std::cout<<"Here is the inserted attributes for"<<std::endl;
        printf("object name = %s", name.c_str()); std::cout<<std::endl;

        printf("ROP_constant = %.2f", ROP_constant); std::cout<<std::endl;

        std::cout<<"WOB data values"<<std::endl;
        print_my_vector(Data_WOB);
        std::cout<<"ROP data values"<<std::endl;
        print_my_vector(Data_ROP);
        printf("Db =  %.2f inch", Db); std::cout<<std::endl;
        printf("RPM =  %.2f", RPM); std::cout<<std::endl;
        printf("UCS =  %.2f psi", UCS); std::cout<<std::endl;
        printf("NOC =  %i", NOC); std::cout<<std::endl;
        printf("BR =  %i", BR); std::cout<<std::endl;
        printf("UCSN =  %.2f", UCSN); std::cout<<std::endl;
        printf("NOB =  %i", NOB); std::cout<<std::endl;
    }

    void print_calculated_attributes_details(){

        std::cout<<"here are calculated attributes for"<<std::endl;
        printf("object name = %s", name.c_str()); std::cout<<std::endl;

        printf("cutter face area sq-inch = %f", Ac); std::cout<<std::endl;
        printf("cutter AB_max sq-inch = %f", AB_max); std::cout<<std::endl;
        printf("calculated the equivalent radius (Re) inch = %f", Re); std::cout<<std::endl;
        printf("Number of data points = %i", Number_of_DataPoints); std::cout<<std::endl;

        std::cout<<"WOC data values"<<std::endl;
        print_my_vector(WOC);

        printf("A_bit = %.2f inch2", A_bit); std::cout<<std::endl;

        std::cout<<"calculated the cutter beanth area data values"<<std::endl;
        print_my_vector(AB);

        std::cout<<"filtered calculated the cutter beanth area data values"<<std::endl;
        print_my_vector(AB);
        printf("UCSN = %.2f", UCSN); std::cout<<std::endl;
        printf("V_Cutter_Equivalent = %.2f inch/sec", V_Cutter_Equivalent); std::cout<<std::endl;
        printf("Normalized V_Cutter_Equivalent = %.2f", VN); std::cout<<std::endl;


    }


    float A_Front(float AB_tocalc_A_Front, 
                    int IFA_tocalc_A_Front, 
                    int BR_tocalc_A_Front){
        // ABB = A_B;
        // IFA = IF_A;
        // A function that takes the cutter beneath area,
        // back rake and IFA and returns the cutter front area.
        float A_Front_value = (AB_tocalc_A_Front/tan((((BR_tocalc_A_Front+IFA_tocalc_A_Front) * PI ) / 180 )));

        printf("value of A_Front = %.2f", A_Front_value); std::cout<<std::endl;
        return A_Front_value;
    }
       
    float ROP_model(int NOC_tocalc_ROP_model, 
                    float Re_tocalc_ROP_model, 
                    float AF_tocalc_ROP_model, 
                    float RPM_tocalc_ROP_model, 
                    float A_bit_tocalc_ROP_model){
        // A ROP model (function). A function that takes number of cutters (NOC),
        // bit equivalent radius (Re), cutter front area (AF), cutter back rake (BR),
        // interfacial friction angle (IFA), revolutions per minute (RPM), 
        // and bit area (A_bit).'''
        
        float ROP_model_value = ((2*NOC_tocalc_ROP_model*PI*Re_tocalc_ROP_model*\
                                AF_tocalc_ROP_model*RPM_tocalc_ROP_model)\
                                /(A_bit_tocalc_ROP_model))*5;

        printf("value of ROP_model_value = %.2f", 
        ROP_model_value); std::cout<<std::endl;
        return ROP_model_value;
    }



    // float Model_IFA(float DOC_tocalc_Model_IFA){
    //     // A model for IFA calculation. it takes DOC,
    //     // normalized cutter velocity, normalized rock 
    //     // UCS and cutter back rake and returns the IFA.
    //     // comperhensive IFA model utilizing both fullbit 
    //     // and single cutter data for soft and hard rocks

                
    //     // GH-IFA (II)
    //     DOCn = DOC / Dc // normalize DOC
    //     a = 18.90 + (-142.78)/((VN)**0.65 + 2.83)
    //     b = 75.56 + (150)/((VN)**2 + 100)
    //     c = 0.454
    //     d = 0.323 + (53.61)/((UCSN**2.5) + 84.86)

    //     float Model_IFA_value = (a + b / ((DOCn**c) + d))-BR;
 
    //     return Model_IFA_value



    // }












    // float Find_IFA(float AB_tocalc_Find_IFA, float maxvalue_tocalc_Find_IFA){

    //     AB = A_B;
    //     maxvalue = max_value;

    //     // diff1 = 10000000000000; // initite it with a big value
    //     // Number_of_random_attempts = 10000;
    //     // IFA_search = 0;

    //     // while diff1 > 0.0001 and IFA_search < maxvalue:
    //     do{

    //         IFA_search = IFA_search + 0.1;
    //         AF = self.A_Front(AB,IFA_search) #calculate the cutter front area
    //         ROP = self.ROP_model(AF) # calculate the ROP
    //         DOC = ROP/(self.RPM*5) # calculate the depth of cut
    //         IFA = self.Model_IFA(DOC)

    //         diff2 = abs(IFA_search - IFA)
            
    //         if diff2 < diff1:
    //             diff1 = diff2
    //             self.Best_IFA = IFA_search

    //     } while (diff1 > 0.0001 && IFA_search < maxvalue);

            

    //     return self.Best_IFA, diff1
    //     // return 0

    // }



};




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

    WOB_data = {2280,2380,2570,2810,3070,3310,3540,3820,4080};
    ROP_data = {11.4,12.5,14.9,18.2,22.9,27.7,34.8,43,50};
    Full_bit case3_FullBit ("SWG_4B_200", 0.9, 
                            WOB_data, ROP_data, 
                            3.75, 200, 21500, 12, 20, 0.5, 4);



    WOB_data = {900,1180,1230,1360,1510,1650,1730,1780};
    ROP_data = {24.8,48.9,53.4,54,62,70.8,81.3,84.1};
    Full_bit case4_FullBit ("BSS_4B_100", 0.9, 
                            WOB_data, ROP_data, 
                            3.75, 100, 7100, 12, 20, 0.5, 4);

    WOB_data = {970,1090,1110,1300,1520,1720,1770,1960};
    ROP_data = {40.8,61.9,64.5,71.7,91.5,102.9,106.9,127.7};
    Full_bit case5_FullBit ("BSS_4B_150", 0.9, 
                            WOB_data, ROP_data, 
                            3.75, 150, 7100, 12, 20, 0.5, 4);

    WOB_data = {850,960,1150,1210,1270,1340,1570,1800};
    ROP_data = {30.5,59.5,84.8,87.8,96.5,96.6,120.9,136};
    Full_bit case6_FullBit ("BSS_4B_200", 0.9, 
                            WOB_data, ROP_data, 
                            3.75, 200, 7100, 12, 20, 0.5, 4);

    std::cout<<"data was fed"<<std::endl;

    case1_FullBit.A_Front(0.5, 20, 12);
    case1_FullBit.ROP_model(30, 1.5, 0.05, 100, 7);
    














    // case1_FullBit.print_inserted_attributes_details();
    // print_line_space_with_lenght(25);
    // case2_FullBit.print_inserted_attributes_details();
    // print_line_space_with_lenght(25);
    // case3_FullBit.print_inserted_attributes_details();
    // print_line_space_with_lenght(25);
    // case4_FullBit.print_inserted_attributes_details();
    // print_line_space_with_lenght(25);
    // case5_FullBit.print_inserted_attributes_details();
    // print_line_space_with_lenght(25);
    // case6_FullBit.print_inserted_attributes_details();
    // print_line_space_with_lenght(25);

    // case1_FullBit.print_calculated_attributes_details();
    // print_line_space_with_lenght(25);
    // case2_FullBit.print_calculated_attributes_details();
    // print_line_space_with_lenght(25);
    // case3_FullBit.print_calculated_attributes_details();
    // print_line_space_with_lenght(25);
    // case4_FullBit.print_calculated_attributes_details();
    // print_line_space_with_lenght(25);
    // case5_FullBit.print_calculated_attributes_details();
    // print_line_space_with_lenght(25);
    // case6_FullBit.print_calculated_attributes_details();
    // print_line_space_with_lenght(25);


}