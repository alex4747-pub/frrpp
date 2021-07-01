// Daemon info base class C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef SRC_LIB_INCLUDE_DAEMONINFO_HPP_
#define SRC_LIB_INCLUDE_DAEMONINFO_HPP_

#include <cassert>
#include <string>
#include <vector>
#include <Daemon.hpp>
#include <Capability.hpp>
#include <PpTypes.hpp>

namespace frr_pp {

// Common base class for all daemon
// descriptors
class Daemon::Info {
 protected:
  explicit Info(Daemon* daemon) noexcept { daemon->info_ = this; }
  virtual ~Info() {}

  Info(Info const& other) = delete;
  Info& operator=(Info const& other) = delete;

  void ReloadConfig() noexcept;

 private:
  virtual std::vector<Capability> const& GetCapabilities() const noexcept = 0;
  virtual std::vector<int> const& GetSignals() const noexcept = 0;
  virtual std::vector<YangModuleInfo const*> const& GetYangModules()
      const noexcept = 0;

  // Cooked signal functions
  virtual void SigHupCb() noexcept = 0;
  virtual void SigUsr1Cb() noexcept = 0;
  virtual void SigIntCb() noexcept = 0;
  virtual void SigTermCb() noexcept = 0;

  // Signal functions
  static void SigHupFunc();
  static void SigUsr1Func();
  static void SigIntFunc();
  static void SigTermFunc();

  static Info& GetInfo() { return *Daemon::GetInstance().info_; }
};

}  // namespace frr_pp

#endif  // SRC_LIB_INCLUDE_DAEMONINFO_HPP_
