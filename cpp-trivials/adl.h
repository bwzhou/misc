namespace A
{
   void f(int x); // like our std::sqrt(double)
}

namespace B
{
   struct S {}; // user-defined type with associated namespace B

   void f(S);

   void f(int, int);

   void test1() {
      using namespace A; // using DIRECTIVE
      f(1);       // ERROR  namespace A is not considered because
                  //        B contains two overloads for 'f'
      f(1,2);     // OK     B::f(int,int)
      f(B::S());  // OK     B::f(S)
   }   

   void test2() {
      using A::f; // using DECLARATION
      f(1);       // OK     A::f(int)
      f(1,2);     // ERROR  A::f  hides  B::f(int,int)
      f(B::S());  // OK     B::f(S) due to ADL!
   }
}

namespace C
{
   void test3() {
      using namespace A; // using DIRECTIVE
      f(1);       // OK     A::f(int)
      f(B::S());  // OK     B::f(S) due to ADL!
   }   

   void test4() {
      using A::f; // using DECLARATION
      f(1);       // OK     A::f(int)
      f(B::S());  // OK     B::f(S) due to ADL!
   }
}
