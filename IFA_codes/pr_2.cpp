
// Passing vector object to a constructor.
#include <iostream>
#include <vector>
using namespace std;
  
class MyClass
{
public:
    vector<int> vec;
    int ROP;
    int A, B;
  
public:
    MyClass(vector<int> v, int rop) 
    {
       vec = v;
       ROP = rop;
    }

    int func_1(int a, int b)
    {
        A=a*b;
        return A;
    }


    int func_2()
    {
        B=A*A;
        return B;
    }

    void print()
    {
        cout<< "A " << A<< endl;
        cout<< "B " << B<< endl;    
    }
};
  
int main()
{
    vector<int> vec = {1,2,2,2,2,5,5,5};
    int rop_data = 500;
    // for (int i = 1; i <= 5; i++)
    //     vec.push_back(i);
    MyClass obj(vec, rop_data); MyClass obj_2(vec, rop_data); 

    obj.func_1(2,8); obj_2.func_1(2,4); 
    obj.func_2(); obj_2.func_2(); 

    obj.print();obj_2.print();

    printf("obj 1 A and B values are %i, %i", obj.A, obj.B); cout<<endl;
    printf("obj 2 A and B values are %i, %i", obj_2.A, obj_2.B);

    return 0;
}