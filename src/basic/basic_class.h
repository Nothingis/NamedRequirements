/*
 * basic_class.h
 *
 *  Created on: Feb 17, 2019
 *      Author: nam
 */

#ifndef SRC_BASIC_BASIC_CLASS_H_
#define SRC_LAYOUT_LAYOUT_H_

namespace basic {

class DefaultConstructible {
 public:
  DefaultConstructible() {}
  DefaultConstructible(const DefaultConstructible&) = delete;
  DefaultConstructible& operator=(const DefaultConstructible&) = delete;
};

class NonDefaultConstructible {
 public:
  explicit NonDefaultConstructible(int ) {}
};

class MoveConstructible {
 public:
  MoveConstructible() {}
  MoveConstructible(const MoveConstructible&) = delete;
  MoveConstructible(MoveConstructible&&) {}
};

class CopyConstructible {
 public:
  CopyConstructible() {}
  CopyConstructible(const CopyConstructible&) {}
};

class MoveAssignable {
 public:
  MoveAssignable() {}
  MoveAssignable& operator=(const MoveAssignable&) = delete;
  MoveAssignable& operator=(MoveAssignable&&) {
    return *this;
  }
};

class CopyAssignable {
 public:
  CopyAssignable() {}
  CopyAssignable(const CopyAssignable&) = delete;
  CopyAssignable& operator-(const CopyAssignable&) {
    return *this;
  }
};

class NonDestructible {
 public:
  ~NonDestructible() = delete;
};

}  // namespace basic

#endif /* SRC_BASIC_BASIC_CLASS_H_ */
