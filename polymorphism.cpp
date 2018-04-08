
#include "polymorphism.h"
using namespace std;
int main()
{
    const string status ="salary";
    string level;
    cin>>level;
  //  level ="salary";
    Employee *e1;
    /*
      when we want to extend class could run the function
      in the main class we have to use virtual in the Construct
      #if
      mvfkv
      #endif



    */
    if(status!=level)
    {
    //  Employee e1;
      e1= new Employee();
      //cout << "e1 pays:"<<e1->calcWeeklyPay() << '\n';
    }
    else
    {
    //  Manager e1;
    //  e1.setPayRate(12000.0);
      e1 =new Manager();

      //cout << "e1 pays: "<<e1.calcWeeklyPay() << '\n';
    }
    e1->setPayRate(12000.0);
    cout << "e1 pays: "<<e1->calcWeeklyPay() << '\n';
    delete e1;
    return 0;
}
