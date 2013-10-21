/* Copyright (c) 2005-2013 Rich Felker. All rights reserved.
 * Copyright (c) 2013 The F9 Microkernel Project. All rights reserved.
 * Use of this source code is governed by MIT license that can be found
 * in the LICENSE file.
 */

#include <types.h>
#include <lib/string.h>
#include <limits.h>

#define ALIGN (sizeof(size_t))
#define ONES ((size_t)-1/UCHAR_MAX)
#define HIGHS (ONES * (UCHAR_MAX/2+1))
#define HASZERO(x) (((x)-ONES) & ~(x) & HIGHS)

char *stpcpy(char *restrict d, const char *restrict s)
{
	size_t *wd;
	const size_t *ws;

	if ((uintptr_t) s % ALIGN == (uintptr_t) d % ALIGN) {
		for (; (uintptr_t) s % ALIGN; s++, d++) {
			if (!(*d = *s))
				return d;
		}
		wd = (void *) d;
		ws = (const void *) s;
		for (; !HASZERO(*ws); *wd++ = *ws++);
		d = (void *) wd;
		s = (const void *) ws;
	}

	for (; (*d = *s); s++, d++);

	return d;
}

char *strcpy(char *restrict dest, const char *restrict src)
{
#if 1
	stpcpy(dest, src);
	return dest;
#else
	const unsigned char *s = src;
	unsigned char *d = dest;
	while ((*d++ = *s++));
	return dest;
#endif
}
