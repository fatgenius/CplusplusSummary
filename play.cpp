#include <iostream>
using namespace std;  //namespaces is work most of time but for big project is not that good
const int weightGoal = 100;//const val cannot change cannot Differences
int main() {
    cout<< "Hello world, I am ready for C++";//using namespaces dont have to std::cout
    cout<<"int size = "<<sizeof(int)<<"\n";//using sizeof() function to check the size of variables
    cout<<"short size = "<<sizeof(short)<<"\n";
    cout<<"long size = "<<sizeof(long)<<"\n";
    cout<<"char size = "<<sizeof(char)<<"\n";
    cout<<"float size = "<<sizeof(float)<<"\n";
    cout<<"double size = "<<sizeof(double)<<"\n";
    cout<<"bool size = "<<sizeof(bool)<<"\n";
    cout<<"const val cannot change"<<weightGoal<<"\n";
    enum MONTHS {Jan, Feb, Mar, Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};//define bestMonth as a variable type MONTHS
    //enum is the way we could define a data type
    MONTHS bestMonth;//assign bestMonth one of the values of MONTHS
    bestMonth = Feb;
    if(bestMonth == Feb)
    {
      cout<<"I'm not so sure January is the best month\n";
  }

    return 0;
 }
