/*********************************************************************
   PicoTCP. Copyright (c) 2012 TASS Belgium NV. Some rights reserved.
   See LICENSE and COPYING for usage.

 *********************************************************************/
#ifndef _PICO_MODULE_IPV4_H
#define _PICO_MODULE_IPV4_H

struct pico_arp_entry {
    struct eth dest;
#ifdef PICO_CONFIG_IPV4
    struct ipv4 addr_ipv4;
#endif
    RB_ENTRY(pico_arp_entry) node;
};

/* Configured device */
struct pico_eth_link {
    struct pico_device *dev;
    struct eth address;
    struct eth netmask;
    RB_ENTRY(pico_eth_link) node;
};

#ifndef IS_MODULE_ETH
# define _mod extern
#else
# define _mod
#endif
_mod struct pico_module pico_module_eth;
#undef _mod

#endif
