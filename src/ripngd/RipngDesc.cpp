// Ripng daemon descriptor C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#include <RipngDesc.hpp>
#include <Zlog.hpp>
#include <csignal>

using namespace frr_pp;

RipngDesc::RipngDesc() {
#if defined(FRR_USER)
  SetUser(FRR_USER);
#endif
  
#if defined FRR_GROUP
  SetGroup(group);
#endif
  
#ifdef VTY_GROUP
  SetVtyGroup(VTY_GROUP);
#endif
  
  std::vector<Capabilities> caps{
    Capability::kNetRaw,
    Capability::kBind,
    Capability::kSysAdmin
  };

  SetCapabilities(caps);

  std::vector<int> signals{SIGHUP, SIGUSR1, SIGINT, SIGTERM};
  
  SetSignals(singals);

  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // TODO: add registration of local yang module
  std::vector<YangRegistry::ModuleId> yang_modules {
    YangRegistry::ModuleId::kFilter,
    YangRegistry::ModuleId::kInterface,
    YangRegistry::ModuleId::kLocal,
    YangRegistry::ModuleId::kRouteMap,
    YangRegistry::ModuleId::kVrf
  };
}

void RipngDesc::SigHupCb() override noexcept {
  Zlog::Info("SIGHUP received");
  ReloadConfig();
}

void RipngDesc::SigUsrt1Cb() override noexcept {
  Zlog::Rotate();
}

void RipngDesc::SigIntCb() override noexcept {
  Zlog::Notice("Terminating on signal");

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // TODO - implement
#if 0
  ripng_vrf_terminate();
  if_rmap_terminate();
  ripng_zebra_stop();
  frr_fini();
#endif
  exit(0);
}

void RipngDesc::SigTermCb() override noexcept {
  // Same as the sigint case
  SigIntCb();
}
