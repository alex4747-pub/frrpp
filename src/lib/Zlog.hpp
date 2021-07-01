// Zlog C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef _ZEBRA_ZLOG_HPP
#define _ZEBRA_ZLOG_HPP

namespace frr_pp {

class Zlog {
 public:
  static void Info(char const* info);
  static void Notice(char const* info);
  static void Rotate();
};

}  // namepsace frr_pp

#endif  //  _ZEBRA_ZLOG_HPP

