#include <iostream>
#include "no_implicit_bool.h"

using namespace std;

int main(){

  cout << "Hello No-Implicit-Bool!" << endl;

  constexpr static  int const ref1 = 1;
  constexpr static bool const ref2 = true;

  //Clearly a Failure! here the Programmer intended something like
  //if(var==ref
  //But the Compiler will not warn you and convert int=1 to bool=true without further notification
  //In Best case you get a Warning for an implicit cast...
  if(ref1){
    cout << "Implicit int" << endl;
  }

  //OK... might be a Failure too, but as ref2 is bool, we never will be able to detect, right?
  if(ref2){
    cout << "bool" << endl;
  }

  {//So here we use a wrapper which will cause a compile error if anything but a bool is used
   //This will solve the first case partly as now the if-statement is protected from anything but bool's
    auto const decision = 1==ref1;
    if(No_Implicit::nibool(decision)){
      cout << "no_implicit_bool int" << endl;
    }
  }

  {//to enhance further we use a second wrapper which will demand 2 parameters - this will prevent the first case (only apply
   //the ref, but forget the comparison) in allmost certainly
    auto const decision = No_Implicit::cmp_eq<decltype(ref1)>(1,ref1);
    if(No_Implicit::nibool(decision)){
      cout << "no_implicit_bool int" << endl;
    }
  }

  /*{//uncomment to get a compiler error... just to prove!
    if(no_implicit_bool(p1)){
      cout << "no_implicit_bool int" << endl;
    }
  }*/

  {//Our solution in one line
    if(No_Implicit::nibool(No_Implicit::cmp_eq<decltype(ref1)>(1,ref1))){
      cout << "no_implicit_bool int" << endl;
    }
  }

  //Of course this will still work...
  if(No_Implicit::nibool(ref2)){
    cout << "no_implicit_bool bool" << endl;
  }

  return 0;
}
