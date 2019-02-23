/*
 * layout.h
 *
 *  Created on: Feb 23, 2019
 *      Author: nam
 */

#ifndef SRC_BASIC_BASIC_CLASS_H_
#define SRC_LAYOUT_LAYOUT_H_

namespace layout {

// (1)
// trivial copy ctor means
// it is not user-provided
// T has no virtual member function, base classes
// the copy ctor selected for every direct base of T is trivial
// the copy constructor selected for every non-static class type of
// (or array of class type) member of T is trivial

// (2)
// trivial destructor means
// dtor is not user-provided
// dtor is not virtual
// all direct base classes have trivial dtor
// all non-static data members of class type
// (or array of class type) have trivial dtor

// (3)
// trivial constructor means
// ctor is not user-provided
// T has no virtual member function
// T has no virtual base classed
// T has no non-static members with default-initializers
// Every direct base of T has trivial default ctor
// Every non-static member of class type default ctor

class TriviallyCopyable {
 public:
  TriviallyCopyable() = default;
  // at least one copy ctor, move ctor, copy=, move= is non-deleted
  // every copy ctor is trivial or deleted (1)
  TriviallyCopyable(const TriviallyCopyable&) = default;
  // every move ctor is trivial or deleted
  // every copy= is trivial or deleted
  // every move= is trivial or deleted
  // Trivially non-deleted dtor (2)
  ~TriviallyCopyable() = default;
};

class TrivialType {
 public:
  // TriviallyCopyable
  // Has one or more default ctor, all of which are
  // either trivial(3) or deleted,
  // and at least one of which is not deleted
  TrivialType() = default;
};

class NonTrivialType {
 private:
  int a = 0;
};

class StandardLayoutType {
  // All non-static data member have the same access control
  // Has no virtual functions or virtual base classes
  // Has no non-static data members of reference type
  // All non-static data members and bas classes are
  // themselves standard layout types
  // Either
  //   has no base class with non-static data members, or
  //   has no non-static data members in the most derived class and
  //   most one base class with non-static data members
  // has no base classes of the same type as the first non-static data member
 private:
  int m1;
};

class BaseClass {
  int a;
};

class NonStandardLayoutType : public BaseClass {
 private:
  BaseClass bc;
};

class PODType {
  // Plain Old Data
  // This types can be exchanged with C libraries directly.
  // This type is deprecated in C++20
  // Either
  //   scalar type
  //   a class type that:
  //     is a trivial type
  //     is a standard layout type
  //     has no non-static members that are non-POD
  //   an array of such type
 public:
  int m1;
  int m2;
};

class NonPODType {
 public:
  int m1;
  int m2 = 0;
};

}  // namespace layout
#endif /* SRC_LAYOUT_LAYOUT_H_ */
