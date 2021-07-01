// Daemon info base class
// Copyright (C) 2021 Aleksey Romanov
//
#include <DaemonInfo.hpp>

namespace frr_pp {

// Signal functions
void Daemon::Info::SigHupFunc() { GetInfo().SigHupCb(); }

void Daemon::Info::SigUsr1Func() { GetInfo().SigUsr1Cb(); }

void Daemon::Info::SigIntFunc() { GetInfo().SigIntCb(); }

void Daemon::Info::SigTermFunc() { GetInfo().SigTermCb(); }

}  // namespace frr_pp
