#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;  //namespaces is work most of time but for big project is not that good
const int weightGoal = 100;//const val cannot change cannot Differences


int main()
{

    string line;
    ofstream myfile("c++.txt"); // using the ofstream function to create new file
    if (myfile.is_open()) {
          myfile<<"my c++ summary file z ."<<"\n";// add the writing to the txt file
          myfile<< "Hello world, I am ready for C++"<<"\n";//using namespaces dont have to std::cout
          myfile<<"int size = "<<sizeof(int)<<"\n";//using sizeof() function to check the size of variables
          myfile<<"short size = "<<sizeof(short)<<"\n";
          myfile<<"long size = "<<sizeof(long)<<"\n";
          myfile<<"char size = "<<sizeof(char)<<"\n";
          myfile<<"float size = "<<sizeof(float)<<"\n";
          myfile<<"double size = "<<sizeof(double)<<"\n";
          myfile<<"bool size = "<<sizeof(bool)<<"\n";
          myfile<<"const val cannotfuck change"<<weightGoal<<"\n";
          enum MONTHS {Jan, Feb, Mar, Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};//define bestMonth as a variable type MONTHS
          //enum is the way we could define a data type
          MONTHS bestMonth;//assign bestMonth one of the values of MONTHS
          bestMonth = Feb;
          if(bestMonth == Feb)
          {
            cout<<"I'm not so sure January is the best month\n";
        }
      myfile.close();//once open the file  must close it
    }
    string reader;
    string min;
    string max;
    ifstream myfileread("c++.txt");//the ifstream is using to read the file
    if(myfileread.is_open())
    {
      myfileread>>reader;//read line
      myfileread>>max;//buffer
      myfileread>>min;

      while (myfileread>>reader) {//using string to read the file words by words
5
        if(line>min){
          reader = min;
        }
        if (line>max) {
          reader =max;
        }
        cout << reader << '\n';
      }

      std::cout << "max is: "<<max << '\n';
      std::cout << "min is: "<<min << '\n';
      myfileread.close();
    }

    string stringlenth, stringWidth;
    float length =0;

    cout<<" Enter the length"<<"\n";
    getline(cin,stringlenth);
    stringstream(stringlenth)>>length;
    cout << "the length is: "<<length << '\n';

/*
    pointers
*/

    //int a =54;
    cout << "length ="<<length << '\n';
    cout << "address of length " <<&length<< '\n';//once have the data type the have address
    float *b=&length; //new pointer which derefference by address of length
    cout << "value after direfference of b " <<b<< '\n';
    cout << "value after direfference of *b " <<*b<< '\n';
    cout << "address of b " <<&b<< '\n';//new address of the b make another address
/*

*/
    return 0;
 }
