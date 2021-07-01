// Ripng daemon info C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef SRC_RIPNGD_RIPNGINFO_HPP_
#define SRC_RIPNGD_RIPNGINFO_HPP_

#include <vector>

#include <DaemonInfo.hpp>

namespace frr_pp {

class RipngInfo : public Daemon::Info {
 public:
  explicit RipngInfo(Daemon* daemon) noexcept;

 private:
  std::vector<Capability> const& GetCapabilities() const noexcept override;
  std::vector<int> const& GetSignals() const noexcept override;
  std::vector<YangModuleInfo const*> const& GetYangModules()
      const noexcept override;

  void SigHupCb() noexcept override;
  void SigUsr1Cb() noexcept override;
  void SigIntCb() noexcept override;
  void SigTermCb() noexcept override;

  std::vector<Capability> caps_;
  std::vector<int> signals_;
  std::vector<YangModuleInfo const*> yang_modules_;
};

}  // namespace frr_pp

#endif  // SRC_RIPNGD_RIPNGINFO_HPP_
