#include <iostream>
using namespace std;
class My_Class{
   private:
      static int count;
   public:
      My_Class() { //in constructor increase the count value
         cout << "Calling Constructor" << endl;
         count++;
      } static int objCount() {
         return count;
      }
   };
int My_Class::count;
main() {
   
   P

}