// VRF C++ definitions
// Copyright (C) 2021 Aleksey Romanov
//
#ifndef _ZEBRA_VRF_HPP
#define _ZEBRA_VRF_HPP

class Vrf {
public:
    static char const* default_name;
    static uint32_t const default_id;

    std::string const& name() const;
    uint32_t id() const;
    bool enabled() const;


    static Vrf* lookup_by_id(uing32_t id);
    static Vrf* lookup_by_name(std::string const& name);
    
private:
};

#endif  //  _ZEBRA_VRF_HPP

