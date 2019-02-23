
#include <iostream>
#include <type_traits>

#include "layout.h"

int main() {
  using namespace layout;
  TriviallyCopyable tc1;
  TriviallyCopyable tc2 = tc1;

  std::cout << std::boolalpha
      << "TriviallyCopyable class is TriviallyCopyable? : "
      << std::is_trivially_copyable<TriviallyCopyable>::value
      << std::endl;

  TrivialType tt;

  std::cout
      << "TrivialType class is TrivialType? : "
      << std::is_trivial<TrivialType>::value
      << std::endl
      << "NonTrivialType class is TrivialType? : "
      << std::is_trivial<NonTrivialType>::value
      << std::endl;

  std::cout << "StandardLayoutType class is StandardLayout? : "
      << std::is_standard_layout<StandardLayoutType>::value
      << std::endl
      << "NonStandardLayoutType class is StandardLayout? : "
      << std::is_standard_layout<NonStandardLayoutType>::value
      << std::endl;

  std::cout << "PODType class is PODType? : "
      << std::is_pod<PODType>::value
      << std::endl
      << "NonPodType class is PODType? : "
      << std::is_pod<NonPODType>::value
      << std::endl;

  return 0;
}
