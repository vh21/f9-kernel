/* Copyright (c) 2005-2013 Rich Felker. All rights reserved.
 * Copyright (c) 2013 The F9 Microkernel Project. All rights reserved.
 * Use of this source code is governed by MIT license that can be found
 * in the LICENSE file.
 */

#include <lib/string.h>

char *strcat(char *restrict dest, const char *restrict src)
{
	strcpy(dest + strlen(dest), src);
	return dest;
}
