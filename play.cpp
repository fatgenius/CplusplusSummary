

using namespace std;  //namespaces is work most of time but for big project is not that good
const int weightGoal = 100;//const val cannot change cannot Differences

#include"play.h"

int main()
{

    string line;
    string reader;
    string min;
    string max;
    ifstream myfileread("c++.txt");//the ifstream is using to read the file
    if(myfileread.is_open())
    {
      myfileread>>reader;//read line
      myfileread>>max;//buffer
      myfileread>>min;

      while (myfileread>>reader)
       {//using string to read the file words by words

        if(line>min){
          reader = min;
        }
        if (line>max) {
          reader =max;
        }
      //  cout << reader << '\n';
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
    pointer(length);
    pointeradd(length);
    cout<<"after the change value is "<<length<<'\n';
    Dog dog1(123);
    dog1.print();
    return 0;
 }
