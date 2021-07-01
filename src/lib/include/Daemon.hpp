// Daemon base class C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef SRC_LIB_INCLUDE_DAEMON_HPP_
#define SRC_LIB_INCLUDE_DAEMON_HPP_

#include <cassert>

namespace frr_pp {

class Daemon {
 public:
  Daemon() noexcept {
    assert(self_ == nullptr);
    info_ = nullptr;
    self_ = this;
  }
  virtual ~Daemon() {}

  Daemon(Daemon const& other) = delete;
  Daemon& operator=(Daemon const& other) = delete;

  static Daemon& GetInstance() { return *self_; }

  class Info;

 protected:
  Info* info_;

 private:
  static Daemon* self_;
};

}  // namespace frr_pp

#endif  // SRC_LIB_INCLUDE_DAEMON_HPP_
