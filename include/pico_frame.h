/*********************************************************************
   PicoTCP. Copyright (c) 2012 TASS Belgium NV. Some rights reserved.
   See LICENSE and COPYING for usage.

 *********************************************************************/
#ifndef _INCLUDE_PICO_FRAME
#define _INCLUDE_PICO_FRAME
#include "pico_config.h"


#define PICO_FRAME_FLAG_BCAST   (0x01)
#define PICO_FRAME_FLAG_SACKED  (0x80)
#define IS_BCAST(f) ((f->flags & PICO_FRAME_FLAG_BCAST) == PICO_FRAME_FLAG_BCAST)


struct pico_socket;


struct pico_frame {

    /* Connector for queues */
    struct pico_frame *next;

    /* Start of the whole buffer, total frame length. */
    unsigned char *buffer;
    uint32_t buffer_len;

    /* For outgoing packets: this is the meaningful buffer. */
    unsigned char *start;
    uint32_t len;

    /* Pointer to usage counter */
    uint32_t *usage_count;

    /* Pointer to protocol headers */
    uint8_t *datalink_hdr;

    uint8_t *net_hdr;
    uint16_t net_len;
    uint8_t *transport_hdr;
    uint16_t transport_len;
    uint8_t *app_hdr;
    uint16_t app_len;

    /* Pointer to the phisical device this packet belongs to.
     * Should be valid in both routing directions
     */
    struct pico_device *dev;

    pico_time timestamp;

    /* Failures due to bad datalink addressing. */
    uint16_t failure_count;

    /* Protocol over IP */
    uint8_t proto;

    /* PICO_FRAME_FLAG_* */
    uint8_t flags;

    /* Pointer to payload */
    unsigned char *payload;
    uint16_t payload_len;

#ifdef PICO_SUPPORT_IPFRAG
    /* Payload fragmentation info (big endian)*/
    uint16_t frag;
#endif

    /* Pointer to socket */
    struct pico_socket *sock;

    /* Pointer to transport info, used to store remote UDP duple (IP + port) */
    void *info;

    /*Priority. "best-effort" priority, the default value is 0. Priority can be in between -10 and +10*/
    int8_t priority;
    uint8_t transport_flags_saved;
};

/** frame alloc/dealloc/copy **/
void pico_frame_discard(struct pico_frame *f);
struct pico_frame *pico_frame_copy(struct pico_frame *f);
struct pico_frame *pico_frame_deepcopy(struct pico_frame *f);
struct pico_frame *pico_frame_alloc(uint32_t size);
uint16_t pico_checksum(void *inbuf, uint32_t len);
uint16_t pico_dualbuffer_checksum(void *b1, uint32_t len1, void *b2, uint32_t len2);

static inline int pico_is_digit(char c)
{
    if (c < '0' || c > '9')
        return 0;

    return 1;
}

#endif
