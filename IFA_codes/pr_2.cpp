
// Passing vector object to a constructor.
#include <iostream>
#include <vector>
using namespace std;
  
class MyClass {
    vector<int> vec;
    int ROP;
  
public:
    MyClass(vector<int> v, int rop) 
    {
       vec = v;
       ROP = rop;
    }
    void print()
    {
        /// print the value of vector
        // for (int i = 0; i < vec.size(); i++)
        //     cout << vec[i] << " ";

        cout<< vec[0] << "   ";

        cout << ROP << "   ";
    }
};
  
int main()
{
    vector<int> vec = {1,2,2,2,2,5,5,5};
    int rop_data = 500;
    // for (int i = 1; i <= 5; i++)
    //     vec.push_back(i);




    MyClass obj(vec, rop_data);
    obj.print();
    return 0;
}