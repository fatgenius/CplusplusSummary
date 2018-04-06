#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

 void pointer(float length);
 void pointer(float length);
 void input()
 {
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
 }
 /*
 it is import that  the function is to change value  forever or inside the main function
 so we should using the pointer derefference
 */
 void pointeradd(float &a ){
   a++;
   cout<<" during the function val is:  "<<a<<'\n';
 }

 void pointer(float length){
   //int a =54;
   cout << "length ="<<length << '\n';
   cout << "address of length " <<&length<< '\n';//once have the data type the have address
   float *b=&length; //new pointer which derefference by address of length
   cout << "value after direfference of b " <<b<< '\n';
   cout << "value after direfference of *b " <<*b<< '\n';
   cout << "address of b " <<&b<< '\n';//new address of the b make another address
 }


class Dog
{
    private:
        int license;
        string name;
    public:
        Dog();
        Dog(string nameIn,int licenseIn);
        void setLicense(int licenseIn);
        void setName(string nameIn);
        int getLicense();
        string getName();
        ~Dog();//destru
        void print();
};

Dog::Dog()
{
   license = 0;
}

Dog::~Dog()
{
    cout<<"\nDeleting the dog"<<"/n"; //this is something program must running;
}
Dog::Dog(string nameIn,int licenseIn)
{
   name =nameIn;
   license = licenseIn;
}
void Dog::setLicense(int licenseIn)
{
    license = licenseIn;
}
void Dog::setName(string nameIn)
{
    name = nameIn;
}
int Dog::getLicense()
{
    return license;
}
string Dog::getName()
{
    return name;
}
void Dog::print(){
    cout<<"Dog name is "<<name<<"\n";
    cout<<"Dog license is "<<license<<"\n";
}
