/*
    Copyright (c) 2012 250bpm s.r.o.

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom
    the Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#ifndef SP_USOCK_INCLUDED
#define SP_USOCK_INCLUDED

#include "aio.h"
#include "addr.h"

#include <stddef.h>

struct sp_usock {
    struct sp_io_hndl hndl;
    struct sp_aio *aio;
    int domain;
    int type;
    int protocol;
};

int sp_usock_init (struct sp_usock *self, int domain, int type, int protocol,
    struct sp_aio *aio);
void sp_usock_term (struct sp_usock *self);

int sp_usock_bind (struct sp_usock *self, const struct sockaddr *addr,
    sp_socklen addrlen);
int sp_usock_connect (struct sp_usock *self, const struct sockaddr *addr,
    sp_socklen addrlen);
int sp_usock_listen (struct sp_usock *self, int backlog);
int sp_usock_accept (struct sp_usock *self, struct sp_usock *usock);

int sp_usock_send (struct sp_usock *self, const void *buf, size_t *len,
    int flags);
int sp_usock_recv (struct sp_usock *self, void *buf, size_t *len, int flags);

#endif
