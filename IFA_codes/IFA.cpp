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
        print_line_space_with_lenght(40);



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

        cout<<"here are inserted attributes for"<<endl;
        printf("object name = %s", name.c_str()); cout<<endl;

        printf("ROP_constant = %.2f", ROP_constant); cout<<endl;

        cout<<"WOB data values"<<endl;
        print_my_vector(Data_WOB);
        cout<<"ROP data values"<<endl;
        print_my_vector(Data_ROP);
        printf("Db =  %.2f", Db); cout<<endl;
        printf("RPM =  %.2f", RPM); cout<<endl;
        printf("UCS =  %.2f", UCS); cout<<endl;
        printf("NOC =  %i", NOC); cout<<endl;
        printf("BR =  %i", BR); cout<<endl;
        printf("UCS =  %.2f", UCS); cout<<endl;
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
            // "=======================================================\n"); cout<<endl;
    print_line_space_with_lenght(75);



    vector<float> WOB_data = {2300,2420,2660,2910,3180,3410,3660,3940,4170};
    vector<float> ROP_data = {9.9,11,14.7,18.1,22.6,27.2,31.1,36.5,39.4};

    Full_bit bit1("SWG_4B_100", 1, 
                    WOB_data, 
                    ROP_data, 
                    8.5, 100, 25000, 
                    28, 20, 0.5, 7);



    Full_bit bit2("SWG_4B_150", 1, 
                    WOB_data, 
                    ROP_data, 
                    8.5, 150, 25000, 
                    28, 20, 0.5, 7);

    // Full_bit bit1("SWG_4B_100", 25, 25000,20, 8.5, 150, 18000, 25, 20, 0.51, 7);

    // Full_bit bit2("SWG_4B_150", 15, 30000,15, 12.25, 1000, 34000, 20, 18, 0.71, 4);
    // Full_bit bit3("SWG_4B_200", 25, 25000,20, 8.5, 150, 18000, 25, 20, 0.51, 7);
    // Full_bit bit4("BSS_4B_100", 15, 30000,15, 12.25, 1000, 34000, 20, 18, 0.71, 4);

    bit1.print_inserted_attributes_details();
    print_line_space_with_lenght(25);
    bit1.print_calculated_attributes_details();
    print_line_space_with_lenght(25);


    // bit2.print_inserted_attributes_details();
    // print_line_space_with_lenght(25);



}