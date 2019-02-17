
#include <iostream>
#include <type_traits>
#include "basic_class.h"

int main() {
  using namespace basic;
  DefaultConstructible dc1;
  DefaultConstructible dc2{};
  DefaultConstructible dc3();
  // NonDefaultConstructible a1;
  // NonDefaultConstructible a2{};
  // NonDefaultConstructible a3();
  std::cout << std::boolalpha
      << "DefaultConstructible class is default-constructible? : "
      << std::is_default_constructible<DefaultConstructible>::value
      << std::endl
      << "NonDefaultConstructible class is default-constructible? : "
      << std::is_default_constructible<NonDefaultConstructible>::value
      << std::endl;

  MoveConstructible mc1 = MoveConstructible();
  MoveConstructible mc2(MoveConstructible());
  // DefaultConstructible mc = DefaultConstructible();

  std::cout << std::boolalpha
      << "MoveConstructible class is move-constructible? : "
      << std::is_move_constructible<MoveConstructible>::value
      << std::endl
      << "DefaultConstructible class is move-constructible? : "
      << std::is_move_constructible<DefaultConstructible>::value
      <<std::endl;

  CopyConstructible tmp_cc;
  CopyConstructible cc1 = tmp_cc;
  CopyConstructible cc2(tmp_cc);
  // DefaultConstructible cc = dc1;

  std::cout << std::boolalpha
      << "CopyConstructible class is copy-constructible? : "
      << std::is_copy_constructible<CopyConstructible>::value
      << std::endl
      << "MoveConstructible class is copy-constructible? : "
      << std::is_copy_constructible<MoveConstructible>::value
      << std::endl;

  MoveAssignable ma1;
  ma1 = MoveAssignable();

  std::cout << std::boolalpha
      << "MoveAssignable class is move-assignable? : "
      << std::is_move_assignable<MoveAssignable>::value
      << std::endl
      << "DefaultConstructible class is move-assignable? : "
      << std::is_move_assignable<DefaultConstructible>::value
      << std::endl;

  CopyAssignable tmp_ca;
  CopyAssignable ca1;
  ca1 = tmp_ca;

  std::cout << std::boolalpha
      << "CopyAssignable class is copy-assignable? : "
      << std::is_move_assignable<CopyAssignable>::value
      << std::endl
      << "DefaultConstructible class is copy-assignable? : "
      << std::is_move_assignable<DefaultConstructible>::value
      << std::endl;

  // NonDestructible* nd = new NonDestructible();
  // nd.~NonDestructible();

  std::cout << std::boolalpha
      << "DefaultConstructible class is destructible? : "
      << std::is_destructible<DefaultConstructible>::value
      << std::endl
      << "NonDestructible class is destructible? : "
      << std::is_destructible<NonDestructible>::value
      <<std::endl;

  return 0;
}


