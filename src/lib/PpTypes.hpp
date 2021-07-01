// C++ types
// Copyright (C) 2021 Aleksey Romanov
//
// For the time being we are going to reuse
// a lot of c- types defined as c++ typedfs

#ifndef _ZEBRA_PP_TYPES_HPP
#define _ZEBRA_PP_TYPES_HPP

#ifndef __cplusplus
#error "This file should not be included into c- code"
#endif

extern "C" {
  struct thread_master;
  struct frr_yang_module_info;
}

namespace frr_pp {
  typedef ::thread_master ThreadMaster;
  typedef ::frr_yang_module_info YangModuleInfo;
}  // namespace frr_pp

#endif   // _ZEBRA_PP_TYPES_HPP
