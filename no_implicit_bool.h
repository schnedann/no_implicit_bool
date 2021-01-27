#ifndef NO_IMPLICIT_H
#define NO_IMPLICIT_H

#define DISABLE_IMPLICIT_CASTS(func_name) \
  template<typename... T>               \
  void func_name(T...)=delete

namespace No_Implicit{

/**************************************************
 * inspired by http://www.gockelhut.com/cpp-pirate/disable-implicit-casts.html
 **************************************************/

  bool nibool(bool const in);
  DISABLE_IMPLICIT_CASTS(nibool);

  //--- convenience functions

  template<typename T> bool cmp_eq(T const& t1, T const& t2){
    return t1==t2;
  }

  template<typename T> bool cmp_neq(T const& t1, T const& t2){
    return t1!=t2;
  }
}

#endif // NO_IMPLICIT_H
