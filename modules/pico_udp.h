/*********************************************************************
   PicoTCP. Copyright (c) 2012 TASS Belgium NV. Some rights reserved.
   See LICENSE and COPYING for usage.

   .

 *********************************************************************/
#ifndef _INCLUDE_PICO_UDP
#define _INCLUDE_PICO_UDP
#include "pico_addressing.h"
#include "pico_protocol.h"
#include "pico_socket.h"
#define PICO_UDP_MODE_UNICAST 0x01
#define PICO_UDP_MODE_MULTICAST 0x02
#define PICO_UDP_MODE_BROADCAST 0xFF

struct pico_socket_udp
{
    struct pico_socket sock;
    int mode;
    uint8_t mc_ttl; /* Multicasting TTL */
};


extern struct pico_protocol pico_proto_udp;

struct __attribute__((packed)) pico_udp_hdr {
    struct pico_trans trans;
    uint16_t len;
    uint16_t crc;
};
#define PICO_UDPHDR_SIZE 8

struct pico_socket *pico_udp_open(void);
uint16_t pico_udp_recv(struct pico_socket *s, void *buf, uint16_t len, void *src, uint16_t *port);
uint16_t pico_udp_checksum_ipv4(struct pico_frame *f);

#endif
