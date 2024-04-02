// [Summarized From Author: Andrei Alexandrescu]
//
namespace TL {
template<typename T, typename U>
struct Typelist {
  typedef T Head;
  typedef U Tail;
}
#define TL_1(T1) Typelist<T1, NullType> 
#define TL_2(T1, T2) Typelist<T1, TL_1<T2>>
}