#include <iostream>
#include <string>
/*
 the ternary is kind of way to make
 c++ program running fast
 it could instead of  using if else statement
*/
int a;
int b;

int main()
{
  std::cin>>a;
  /*
  if(a>5)
    b=10;
  else
    b=5;

this is the old fasion to deal with it
but we could use the ternary to instead
*/
  b=a>5?10:5;
// after ? is the statement after : is the else statement
  std::cout << "b is: "<<b << '\n';

}
