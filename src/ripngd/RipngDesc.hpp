// Ripng daemon descriptor C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef _ZEBRA_RIPNG_DESC_HPP
#define _ZEBRA_RIPNG_DESC_HPP

#include <DaemonDescBase.hpp>

namespace frr_pp {

class RipngDesc : public DaemonDescBase {
 public:
  RipngDesc() noexcept;

 private:
  void SigHupCb() override noexcept;
  void SigUsrt1Cb() override noexcept;
  void SigIntCb() override noexcept;
  void SigTermCb() override noexcept;
};

}  // namespace frr_pp

#endif  // _ZEBRA_RIPNG_DESC_HPP
