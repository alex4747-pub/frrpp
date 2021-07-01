// Registry of global yang modules
//
// Copyright (C) 2021 Aleksey Romanov
//
#include <Yang.hpp>
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

YangModuleInfo const* Yang::GetFilterModule() { return &::frr_filter_info; }
YangModuleInfo const* Yang::GetInterfaceModule() {
  return &::frr_interface_info;
}
YangModuleInfo const* Yang::GetRouteMapModule() {
  return &::frr_route_map_info;
}
YangModuleInfo const* Yang::GetRoutingModule() { return &::frr_routing_info; }
YangModuleInfo const* Yang::GetVrfModule() { return &::frr_vrf_info; }

}  // namespace frr_pp
