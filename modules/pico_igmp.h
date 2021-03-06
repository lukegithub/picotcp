/*********************************************************************
   PicoTCP. Copyright (c) 2012 TASS Belgium NV. Some rights reserved.
   See LICENSE and COPYING for usage.

   .

   Authors: Kristof Roelants, Simon Maes, Brecht Van Cauwenberghe
 *********************************************************************/

#ifndef _INCLUDE_PICO_IGMP
#define _INCLUDE_PICO_IGMP

#define PICO_IGMPV1               1
#define PICO_IGMPV2               2
#define PICO_IGMPV3               3

#define PICO_IGMP_STATE_CREATE    1
#define PICO_IGMP_STATE_UPDATE    2
#define PICO_IGMP_STATE_DELETE    3

#define PICO_IGMP_QUERY_INTERVAL  125

extern struct pico_protocol pico_proto_igmp;

int pico_igmp_state_change(struct pico_ip4 *mcast_link, struct pico_ip4 *mcast_group, uint8_t filter_mode, struct pico_tree *MCASTFilter, uint8_t state);
#endif /* _INCLUDE_PICO_IGMP */
