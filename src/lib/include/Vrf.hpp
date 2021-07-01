// VRF C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef SRC_LIB_INCLUDE_VRF_HPP_
#define SRC_LIB_INCLUDE_VRF_HPP_

#include <cstdint>
#include <string>

namespace frr_pp {

class Vrf {
 public:
  static char const* default_name;
  static uint32_t const default_id;

  std::string const& name() const;
  uint32_t id() const;
  bool enabled() const;

  static Vrf* lookup_by_id(uint32_t id);
  static Vrf* lookup_by_name(std::string const& name);

 private:
};

}  // namespace frr_pp

#endif  // SRC_LIB_INCLUDE_VRF_HPP_
