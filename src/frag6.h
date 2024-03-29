/*
 * Copyright (c) 2015, Paul Meng (mirnshi@gmail.com)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met:
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 * THE POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef _FRAG6_H_
#define _FRAG6_H_

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "ip.h"

struct frag6link
{
	struct frag6link *prev;
	struct frag6link *next;
	struct packet *m;							/* to ip headers of fragments */
	u_int expired;
	u_int flags:4,								/* first and last fragments */
	  nfrags:4;										/* count of fragments */
#define FF_HEAD 1
#define FF_TAIL  2
	u_char proto;									/* protocol of this fragment */
	u_int32_t id;									/* sequence id for reassembly */
	ip6 sip;
	ip6 dip;
};

void init_ip6frag (void);
struct packet *ipfrag6 (struct packet *m0, int mtu);
struct packet *ipreass6 (struct packet *m);

#endif
