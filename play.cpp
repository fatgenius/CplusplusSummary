#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;  //namespaces is work most of time but for big project is not that good
const int weightGoal = 100;//const val cannot change cannot Differences


int main()
{
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


    string line;
    ofstream myfile("c++.txt"); // using the ofstream function to create new file
    if (myfile.is_open()) {
      myfile<<"\n my c++ summary file. \n";// add the writing to the txt file
      myfile.close();//once open the file  must close it
    }

    ifstream myfileread("c++.txt");//the ifstream is using to read the file
    if(myfileread.is_open())
    {
      while (getline(myfileread,line)) {//using string to read the file
        cout << line << '\n';
      }
      myfileread.close();
    }

    string stringlenth, stringWidth;
    float length =0;
    float width =0;
    cout<<" Enter the length"<<"\n";
    getline(cin,stringlenth);
    stringstream(stringlenth)>>length;
    cout << "the length is: "<<length << '\n';


    return 0;
 }
