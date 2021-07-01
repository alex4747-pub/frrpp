// Daemon descriptor base class C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef _ZEBRA_DAEMON_DESC_BASE_HPP
#define _ZEBRA_DAEMON_DESC_BASE_HPP

#include <Capability.hpp>
#include <PpTypes.hpp>
#include <YangRegistry.hpp>

#include <string>
#include <vector>

namespace frr_pp {

// Common base class for all daemon
// descriptors
class DaemonDescBase {
 public:
  DaemonDescBase() noexcept { assert(self_ == nullptr); self_ = this; }

 protected:
  // Note: we terminate on out of memory conditions, so all the functions
  // here are noexecept

  // Set user/group/vty_group
  void SetUser(std::string const& val) noexcept { user_ = val; }
  void SetGroup(std::string const& val) noexcept { group_ = val; }
  void SetVtyGroup(std::string const& val) noexcept { vty_group_ = val; }

  // Set capabilies
  void SetCapabilities(std::vector<Capabilities> const& caps) noexcept {
    caps_p_ = caps;
  }

  // Set supported signals, so far we support SIGHUP,
  // SIGUSR1, SIGINT, SIGTERM all other will cause
  // assert
  void SetSignals(std::vector<int> const& sigs) noexcept {
    signals_ = sigs;
  }

  void SetYangModules(std::vector<YangRegistry::ModuleId> const& yangs) noexcept {
    yang_modules_ = yangs;
  }

  void ReloadConfig() noexcept;

 private:
  // Signal functions
  static void SigHupFunc();
  static void SigUsr1Func();
  static void SigIntFunc();
  static void SigTermFunc();

  // Cooked signal functions
  virtual void SigHupCb() noexcept = 0;
  virtual void SigUsr1Cb() noexcept = 0;
  virtual void SigIntCb() noexcept = 0;
  virtual void SigTermCb() noexcept = 0;
  
  std::string user_;
  std::string group_;
  std::string vty_group_; 
  std::vector<Capability> caps_p_;
  std::vector<int> signals_;
  std::vector<YangRegistry::ModuleId> yang_modules_;

  // We have one instance
  static DaemonDescBase* self_;
};
        

}  // namespace frr_pp

#endif  //  _ZEBRA_DAEMON_DESC_BASE_HPP

