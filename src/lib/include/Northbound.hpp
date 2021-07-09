// Northbound c++ wrapper
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef SRC_LIB_INCLUDE_NORTHBOUND_HPP_
#define SRC_LIB_INCLUDE_NORTHBOUND_HPP_

#include <map>
#include <PpTypes.hpp>

namespace frr_pp {

class Northbound {
 public:
  static YangModuleInfo const* GetFilterModule();
  static YangModuleInfo const* GetInterfaceModule();
  static YangModuleInfo const* GetRouteMapModule();
  static YangModuleInfo const* GetRoutingModule();
  static YangModuleInfo const* GetVrfModule();
};

}  // namespace frr_pp

#endif  // SRC_LIB_INCLUDE_NORTHBOUND_HPP_
