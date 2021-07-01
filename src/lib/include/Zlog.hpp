// Zlog C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef SRC_LIB_INCLUDE_ZLOG_HPP_
#define SRC_LIB_INCLUDE_ZLOG_HPP_

namespace frr_pp {

class Zlog {
 public:
  static void Info(char const* info);
  static void Notice(char const* info);
  static void Rotate();
};

}  // namespace frr_pp

#endif  // SRC_LIB_INCLUDE_ZLOG_HPP_
