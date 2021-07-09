// Ripng daemon info C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#include <RipngInfo.hpp>

#include <csignal>

#include <Northbound.hpp>
#include <Zlog.hpp>

namespace frr_pp {

RipngInfo::RipngInfo(Daemon* daemon) noexcept
    : Daemon::Info(daemon),
      caps_{Capability::kNetRaw, Capability::kBind, Capability::kSysAdmin},
      signals_{SIGHUP, SIGUSR1, SIGINT, SIGTERM},
      yang_modules_{
          Northbound::GetFilterModule(), Northbound::GetInterfaceModule(),
          // Put local module here
          Northbound::GetRouteMapModule(), Northbound::GetVrfModule()} {}

std::vector<Capability> const& RipngInfo::GetCapabilities() const noexcept {
  return caps_;
}

std::vector<int> const& RipngInfo::GetSignals() const noexcept {
  return signals_;
}

std::vector<YangModuleInfo const*> const& RipngInfo::GetYangModules()
    const noexcept {
  return yang_modules_;
}

void RipngInfo::SigHupCb() noexcept {
  Zlog::Info("SIGHUP received");
  ReloadConfig();
}

void RipngInfo::SigUsr1Cb() noexcept { Zlog::Rotate(); }

void RipngInfo::SigIntCb() noexcept {
  Zlog::Notice("Terminating on signal");

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // TODO(alex) - implement
#if 0
  ripng_vrf_terminate();
  if_rmap_terminate();
  ripng_zebra_stop();
  frr_fini();
#endif
  exit(0);
}

void RipngInfo::SigTermCb() noexcept {
  // Same as the sigint case
  SigIntCb();
}

}  // namespace frr_pp
