using namespace std;  //namespaces is work most of time but for big project is not that good
const int weightGoal = 100;//const val cannot change cannot Differences

//#include"play.h"

#include"play2.h"
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
    //Dog dog1("hello",123);
    //dog1.print();
    const int SIZE=3;
    Dog roster[SIZE];

    roster[0].setName("Blue");
    roster[1].setName("King");
    roster[2].setName("Spot");
    roster[0].setLicense(1);
    roster[1].setLicense(2);
    roster[2].setLicense(3);

    printstring(roster,SIZE);
    return 0;
}
