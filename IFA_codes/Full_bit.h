#include <iostream>
#pragma once

// made up func
#include "print_function.h"

#include <iostream>
#include<vector>
#include <cmath>
#include <math.h>       /* pow */ /* sin */
#include<string>
#include<bits/stdc++.h>

// define some constants
#define PI 3.14159265
// #define diff1 10000000000000 // initiate it with a long value
#define Number_of_random_attempts 10000;



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
    std::vector <float>  AB_vec; // calculate the cutter beanth area vector
    std::vector <float>  AB_vec_filt; // filtered calculate the cutter beanth area vector
    // float ABB;
    float UCSN; // calculate the normalized UCS
    float V_Cutter_Equivalent; // calculate equivalent velocity
    float VN; // normalize the equivalent velocity


    std::vector<float> ROP_Model_esti_list;
    std::vector<float> IFAlist;
    std::vector<float> difflist;





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



        // ROP_Model_esti_list = ROP_Model_esti_list;
        // IFAlist = IFAlist;
        // difflist = IFAlist;








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
            AB_vec.push_back(par);
            if (par<AB_max){
                AB_vec_filt.push_back(par);
            }else{
                AB_vec_filt.push_back(AB_max);
            }
            
        }   
   
        // calculate the normalized UCS
        UCSN = UCS/5000;

        // calculate equivalent velocity
        V_Cutter_Equivalent = 2*PI*Re*RPM/60; 

        // normalize the equivalent velocity
        VN = V_Cutter_Equivalent/2.1;


    };

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
        print_my_vector(AB_vec);

        std::cout<<"filtered calculated the cutter beanth area data values"<<std::endl;
        print_my_vector(AB_vec_filt);
        printf("UCSN = %.2f", UCSN); std::cout<<std::endl;
        printf("V_Cutter_Equivalent = %.2f inch/sec", V_Cutter_Equivalent); std::cout<<std::endl;
        printf("Normalized V_Cutter_Equivalent = %.2f", VN); std::cout<<std::endl;


    }

    float A_Front(float AB, int IFA){

        // A function that takes the cutter beneath area,
        // back rake and IFA and returns the cutter front area.
        // float A_Front_value = (AB/tan((((BR+IFA) * PI ) / 180 )));

        // printf("value of A_Front = %.2f", (AB/tan((((BR+IFA) * PI ) / 180 )))); 
        // std::cout<<std::endl;
        return (AB/tan((((BR+IFA) * PI ) / 180 )));
    };
       
    float ROP_model(float AF){
        // A ROP model (function). A function that takes number of cutters (NOC),
        // bit equivalent radius (Re), cutter front area (AF), cutter back rake (BR),
        // interfacial friction angle (IFA), revolutions per minute (RPM), 
        // and bit area (A_bit).'''
        
        // float ROP_model_value = (((2*NOC*PI*Re*\
        //                         AF*RPM)\
        //                         /(A_bit))*5);

        // printf("value of ROP_model_value = %.2f", (((2*NOC*PI*Re* AF*RPM)\
        //         /(A_bit))*5)); std::cout<<std::endl;

        return (((2*NOC*PI*Re*AF*RPM)/(A_bit))*5);
    };

    float Model_IFA(float DOC){
        // A model for IFA calculation. it takes DOC,
        // normalized cutter velocity, normalized rock 
        // UCS and cutter back rake and returns the IFA.
        // comperhensive IFA model utilizing both fullbit 
        // and single cutter data for soft and hard rocks

        // GH-IFA (II)
        float DOCn = DOC / Dc; // normalize DOC
        float a = 18.90 + (-142.78)/(pow(VN, 0.65) + 2.83);
        float b = 75.56 + (150)/(pow(VN, 2) + 100);
        float c = 0.454;
        float d = 0.323 + (53.61)/(pow(UCSN, 2.5) + 84.86);

        float Model_IFA_value = (a + b / (pow(DOCn, c) + d))-BR;
 
        return Model_IFA_value;
    };


    std::tuple < float, float>  Find_IFA(float AB, float maxvalue){

        float IFA_search = 0;
        long diff1 = 1000000000;
        float Best_IFA;

        do{

            IFA_search = IFA_search + 0.1;
            float AF = A_Front(AB, IFA_search); // calculate the cutter front area
            float ROP = ROP_model(AF); // calculate the ROP
            float DOC = ROP/(RPM*5); // calculate the depth of cut
            float IFA = Model_IFA(DOC);

            long diff2 = abs(IFA_search - IFA);
            
            if (diff2 < diff1){
                diff1 = diff2;
                Best_IFA = IFA_search;
            }
            // printf("best IFA %.2f ", Best_IFA); std::cout<<std::endl;

        } while (diff1 > 0.0001 && IFA_search < maxvalue);
        

        return std::make_tuple(Best_IFA, diff1);
    }



    std::tuple < float, float, float>   calculate_ROP(float AB, float maxvalue){
        // A function that takes the cutter beneath
        // area and returns the ROP estimated

        float IFA = (std::get<0> (Find_IFA(AB, maxvalue)));
        float diff = (std::get<1> (Find_IFA(AB, maxvalue)));
        float AF = A_Front(AB, IFA);
        float Estimated_ROP = ROP_constant * ROP_model(AF);

        return  std::make_tuple(Estimated_ROP, IFA, diff);

    }


    std::tuple<std::vector<float>, std::vector<float>, std::vector<float>> calculate_fitness(){

        // ROP calculation
        // std::vector<float> ROP_Model_esti_list;
        // std::vector<float> IFAlist;
        // std::vector<float> difflist;
        float maxvalue = 90 - BR;
        for (int i = 0;i<Number_of_DataPoints; i++){

            float ROP_Model_esti = (std::get<0> (calculate_ROP(AB_vec_filt[i], maxvalue)));        
            float IFA = (std::get<1> (calculate_ROP(AB_vec_filt[i], maxvalue))); 
            float diff = (std::get<2> (calculate_ROP(AB_vec_filt[i], maxvalue))); 

            ROP_Model_esti_list.push_back(ROP_Model_esti);
            difflist.push_back(diff);     
            maxvalue = IFA; // make sure descending trend for IFA vs DOC
            IFAlist.push_back(IFA); 

        }

        return  std::make_tuple(ROP_Model_esti_list, difflist, IFAlist);

    }
        


};

