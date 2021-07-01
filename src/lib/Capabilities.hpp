// Capabilities C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef _ZEBRA_CAPS_HPP
#define _ZEBRA_CAPS_HPP

namespace frr_pp {

// Set of c++ aliases for zebra
// capabilities
enum class Capability: int {
  kSetid,
  kBind,
  kNetAdmin,
  kSysAdmin,
  kNetRaw,
  kChroot,
  kNice,
  kPtrace,
  kDacOverride,
  kReadSearch,
  kFowner,
  kIpcLock,
  kMax = kIpcLock
};

}  // namepsace frr_pp

#endif  //  _ZEBRA_CPAS_HPP

