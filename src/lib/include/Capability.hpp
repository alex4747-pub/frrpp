// Capabilities C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef SRC_LIB_INCLUDE_CAPABILITY_HPP_
#define SRC_LIB_INCLUDE_CAPABILITY_HPP_

namespace frr_pp {

// Set of c++ aliases for zebra
// capabilities
enum class Capability : int {
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

}  // namespace frr_pp

#endif  // SRC_LIB_INCLUDE_CAPABILITY_HPP_
