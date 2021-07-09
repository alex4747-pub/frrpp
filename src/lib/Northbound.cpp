// Northbound c++ wrapper
// Copyright (C) 2021 Aleksey Romanov
//
#include <Northbound.hpp>
#include <config.h>
#include <northbound.h>

extern "C" {
extern const struct frr_yang_module_info frr_filter_info;
extern const struct frr_yang_module_info frr_interface_info;
extern const struct frr_yang_module_info frr_route_map_info;
extern const struct frr_yang_module_info frr_routing_info;
extern const struct frr_yang_module_info frr_vrf_info;
}

namespace frr_pp {

YangModuleInfo const* Northbound::GetFilterModule() {
  return &::frr_filter_info;
}
YangModuleInfo const* Northbound::GetInterfaceModule() {
  return &::frr_interface_info;
}
YangModuleInfo const* Northbound::GetRouteMapModule() {
  return &::frr_route_map_info;
}
YangModuleInfo const* Northbound::GetRoutingModule() {
  return &::frr_routing_info;
}
YangModuleInfo const* Northbound::GetVrfModule() { return &::frr_vrf_info; }

}  // namespace frr_pp
