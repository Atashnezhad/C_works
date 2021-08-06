#include <iostream>
#include<vector>
#include <cmath>
#include <math.h>       /* pow */ /* sin */
#include<string>
#include<bits/stdc++.h>
using namespace std;

// define some constants
#define PI 3.14159265


// to compile this file simply copy and paste following in the cmd
// clear; g++ IFA.cpp -o IFA; ./IFA
// run the followinig in cmd to update git repo
// git add .; git commit -m "message"; git push; git status

void print_line_space_with_lenght(int j = 10){
    cout<<endl;
    for (int i=0;i<j;i++){ printf("=");}
    cout<<endl;
}
void print_my_vector(vector<float> vec){

        for (auto val : vec){
            cout<<val<<" ";}
        cout<<endl;
}

class Full_bit{
    // instances = []
    // full bit details - attributes
    // self.__class__.instances.append(self)
public:

    string name;
    vector <float> Data_WOB, Data_ROP;
    float ROP_constant, Db, RPM, UCS, Dc;
    int NOC, BR, NOB;


    // more attributes are calculated at the following
    float Ac; // cutter face area sq-inch
    float AB_max;
    float Re;// calculate the equivalent radius
    int Number_of_DataPoints;
    vector <float>  WOC; // weight on cutter
    float A_bit; // bit area
    vector <float>  AB; // calculate the cutter beanth area
    float UCSN; // calculate the normalized UCS
    float V_Cutter_Equivalent; // calculate equivalent velocity
    float VN; // normalize the equivalent velocity

    //constructor
    Full_bit(string inst_name, float inst_ROP_constant, vector <float> inst_Data_WOB, 
            vector <float>  inst_Data_ROP, float inst_Db, float inst_RPM, float inst_UCS, 
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

        printf("The object created with name %s", name.c_str()); cout<<endl;
        // print_line_space_with_lenght(40);

        // more attributes are calculated at the following

        Ac = PI*pow(Dc, 2) / 4; // cutter face area sq-inch
        AB_max = Ac*sin((( BR * PI ) / 180 ));
        Re = Db/(2*pow(2, 0.5)); // calculate the equivalent radius
        Number_of_DataPoints = Data_WOB.size();

        //calculate the weight on cutter
        for (auto wob : Data_WOB)
        {
            WOC.push_back(wob/NOC);
        }          

        A_bit = (PI*pow(Db, 2))/4; // bit area


        // calculate the cutter beanth area and
        // filter those values that are greater 
        // than availabe cutter beanth area (AB_max)
        float par;
        for (auto woc : WOC)
        {
            par = woc/UCS;
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

        cout<<"Here is the inserted attributes for"<<endl;
        printf("object name = %s", name.c_str()); cout<<endl;

        printf("ROP_constant = %.2f", ROP_constant); cout<<endl;

        cout<<"WOB data values"<<endl;
        print_my_vector(Data_WOB);
        cout<<"ROP data values"<<endl;
        print_my_vector(Data_ROP);
        printf("Db =  %.2f inch", Db); cout<<endl;
        printf("RPM =  %.2f", RPM); cout<<endl;
        printf("UCS =  %.2f psi", UCS); cout<<endl;
        printf("NOC =  %i", NOC); cout<<endl;
        printf("BR =  %i", BR); cout<<endl;
        printf("UCSN =  %.2f", UCSN); cout<<endl;
        printf("NOB =  %i", NOB); cout<<endl;
    }

    void print_calculated_attributes_details(){

        cout<<"here are calculated attributes for"<<endl;
        printf("object name = %s", name.c_str()); cout<<endl;

        printf("cutter face area sq-inch = %f", Ac); cout<<endl;
        printf("cutter AB_max sq-inch = %f", AB_max); cout<<endl;
        printf("calculated the equivalent radius (Re) inch = %f", Re); cout<<endl;
        printf("Number of data points = %i", Number_of_DataPoints); cout<<endl;

        cout<<"WOC data values"<<endl;
        print_my_vector(WOC);

        printf("A_bit = %.2f inch2", A_bit); cout<<endl;

        cout<<"calculated the cutter beanth area data values"<<endl;
        print_my_vector(AB);

        cout<<"filtered calculated the cutter beanth area data values"<<endl;
        print_my_vector(AB);
        printf("UCSN = %.2f", UCSN); cout<<endl;
        printf("V_Cutter_Equivalent = %.2f inch/sec", V_Cutter_Equivalent); cout<<endl;
        printf("Normalized V_Cutter_Equivalent = %.2f", VN); cout<<endl;


    }

};


int main()
{


    printf("This is OOP for interfacial friction angle calculations\n"
            "the main function was developed in the python language.\n");
    print_line_space_with_lenght(75);



    vector<float> WOB_data;
    vector<float> ROP_data;


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




    case1_FullBit.print_inserted_attributes_details();
    print_line_space_with_lenght(25);
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

    case1_FullBit.print_calculated_attributes_details();
    print_line_space_with_lenght(25);
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