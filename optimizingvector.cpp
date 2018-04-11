#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
  float x,y,z;
    Vertex(float x, float y,float z)
    :x(x),y(y),z(z)
    {   }
    Vertex(const Vertex& v)
    :x(v.x),y(v.y),z(v.z)
    {
      std::cout << "copy" << '\n';
    }

};

 int main()
{
  std::vector<Vertex> v;
  v.reserve(3);//make  the reserve of the space
  /*
      this is important  to have the reserve space
  */
  v.push_back(Vertex(1,2,3));
  v.push_back(Vertex(1,2,3));
  v.push_back(Vertex(1,2,3));
//now we have 6 copy

  /* code */
  return 0;
}
