// C++ interface to yang
//
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef SRC_LIB_INCLUDE_YANG_HPP_
#define SRC_LIB_INCLUDE_YANG_HPP_

#include <map>
#include <PpTypes.hpp>

namespace frr_pp {

class Yang {
 public:
  static YangModuleInfo const* GetFilterModule();
  static YangModuleInfo const* GetInterfaceModule();
  static YangModuleInfo const* GetRouteMapModule();
  static YangModuleInfo const* GetRoutingModule();
  static YangModuleInfo const* GetVrfModule();
};

}  // namespace frr_pp

#endif  // SRC_LIB_INCLUDE_YANG_HPP_
