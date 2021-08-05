#include <iostream>
// #include <tuple>
#include<string>
using namespace std;

// to compile this file simply copy and paste following in the cmd
// clear; g++ IFA.cpp -o IFA; ./IFA

// run the followinig in cmd to update git repo
// git add .; git commit -m "someworks"; git psuh; git status

void print_line_space_with_lenght(int j = 10){
    cout<<endl;
    for (int i=0;i<j;i++){ printf("=");}
}



class Full_bit{
    // instances = []
    // full bit details - attributes
    // self.__class__.instances.append(self)
public:

    string name;
    float ROP_constant;
    float Data_WOB;
    float Data_ROP;
    // self.Data_WOB.sort()
    // self.Data_ROP.sort()
    float Db;
    float RPM;
    float UCS;
    int NOC;
    int BR;
    float Dc;
    int NOB;
            
    // more attributes are calculated at the following
    // float Ac = math.pi*Dc**2 / 4 // cutter face area sq-inch
    // float AB_max = Ac*sin(radians(BR))
    // float Re = Db/(2*(2**0.5)) // calculate the equivalent radius
    // int Number_of_DataPoints = len(Data_WOB)
    // float WOC = [Data_WOB[i]/NOC for i in range(0,Number_of_DataPoints)] //calculate the weight on cutter
    // float A_bit = (pi*(Db**2))/4 // bit area
    // float AB = [WOC/UCS for WOC in self.WOC ] // calculate the cutter beanth area
    // float AB = [AB_max if x > AB_max else x for x in AB] // filter those values that are greater than availabe cutter beanth area
    // float UCSN = UCS/5000 // calculate the normalized UCS
    // float V_Cutter_Equivalent = 2*pi*self.Re*RPM/60 // calculate equivalent velocity
    // float VN = V_Cutter_Equivalent/2.1 // normalize the equivalent velocity

    //constructor
    Full_bit(string inst_name, float inst_ROP_constant, float inst_Data_WOB, 
    float inst_Data_ROP, float inst_Db, float inst_RPM, float inst_UCS, int inst_NOC, 
    int inst_BR,float  inst_Dc, int inst_NOB){

        name = inst_name;
        ROP_constant = inst_ROP_constant;
        Data_WOB = inst_Data_WOB;
        Data_ROP = inst_Data_ROP;
        // Data_WOB.sort()
        // Data_ROP.sort()
        Db = inst_Db;
        RPM = inst_RPM;
        UCS = inst_UCS;
        NOC = inst_NOC;
        BR = inst_BR;
        Dc = inst_Dc;
        NOB = inst_NOB;

        printf("\nThe object created with name %s", name.c_str());cout<<endl;


        print_line_space_with_lenght(75);

    }

    void (){

        




    }





};










int main()
{


    printf("This is OOP for interfacial friction angle calculations\n"
            "the main function was developed in the python language.\n");
            // "=======================================================\n"); cout<<endl;

    Full_bit bit1("first_bit", 25, 25000,20, 8.5, 
                    150, 18000, 25, 20, 0.51, 7);

    print_line_space_with_lenght(75);


}