// Registry of global yang modules
//
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef _ZEBRA_YANG_MODULE_REGISTRY_HPP
#define _ZEBRA_YANG_MODULE_REGISTRY_HPP

#include <PpTypes.hpp>
#include <map>

namespace frr_pp {

class YangRegistry {
 public:
  
  // We mix well-known modules with
  // module defined by local daemon
  enum class ModuleId: int {
    kFilter,
    kInterface,
    kLocal,
    kRouteMap,
    kVrf,
    kMax = kVrf
  };

  // Register local module
  static void SetLocal(YangModuleInfo const& local);

  // Get module by id
  static YangModuleInfo const& GetModule(ModuleId id);

 private:
  std::map<ModuleId, YangModuleInfo const*> ymap_;
};

}  // namespace frr_ppp


#endif  // _ZEBRA_YANG_MODULE_REGISTRY_HPP
