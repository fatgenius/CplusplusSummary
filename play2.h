
#include "play.h"
void printstring(Dog dog[],int size);

void printstring(Dog dog[],int size){
   for(int i=0;i <size;i++){
     dog[i].print();
   }
}
