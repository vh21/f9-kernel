# Copyright (c) 2013 The F9 Microkernel Project. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

lib-str-y += \
	strlen.o \
	memcpy.o \
	memset.o

kernel-lib-y += \
	queue.o \
	ktable.o \
	stdio.o \
	bsearch.o \
	sort.o \
	$(lib-str-y)
