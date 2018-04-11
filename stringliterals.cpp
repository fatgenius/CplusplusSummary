#include <iostream>
#include <string>
#include <stdlib.h>

class fat
{
    private:
      int m_x=5,m_y;
      mutable int m_change;
    public:
     int getx() const//if move the const coz if not const the m_x could be changed inside the getx() function
      {
        m_change =2; // the mutable function could be changed but the others will remain the same
        return m_x;
      }

      int getx()
      {
        return m_y;   //if not const the print will not go through this
      }
      void setx(int x)
      {
        m_x=x;
      }
};

void print(const fat& a)  //here const is to make sure we do not change any object make sure the parimitaer
{
  std::cout << "/* message */" <<a.getx()<< '\n';//coz the const class fat& so we could call the function
}
int main()
{
   fat a;
   print(a);
}
