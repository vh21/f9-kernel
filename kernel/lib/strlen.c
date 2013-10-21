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

size_t strlen(const char *s)
{
	const char *a = s;
	const size_t *w;
	for (; (uintptr_t) s % ALIGN; s++) {
		if (!*s)
			return s-a;
	}
	for (w = (const void *) s; !HASZERO(*w); w++);
	for (s = (const void *) w; *s; s++);
	return s-a;
}
