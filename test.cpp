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
   My_Class my_obj1, my_obj2, my_obj3;
   int cnt;
   cnt = My_Class::objCount();
   cout << "Number of objects:" << cnt;
}