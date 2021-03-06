/*
 * Copyright (C) 2010 Samsung Electronics
 * Minkyu Kang <mk7.kang@samsung.com>
 * Wonguk Jeong <wonguk.jeong@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 */

#ifndef __LINUX_USB_SWITCH_FSA9480_H_
#define __LINUX_USB_SWITCH_FSA9480_H_

#include <linux/types.h>

#define FSA9480_DETECT_NONE			(0)
#define FSA9480_DETECT_USB			(1 << 0)
#define FSA9480_DETECT_USB_HOST			(1 << 1)
#define FSA9480_DETECT_CHARGER			(1 << 2)
#define FSA9480_DETECT_JIG			(1 << 3)
#define FSA9480_DETECT_UART			(1 << 4)

#define FSA9480_DETECT_ALL			(FSA9480_DETECT_USB | \
						 FSA9480_DETECT_USB_HOST | \
						 FSA9480_DETECT_CHARGER | \
						 FSA9480_DETECT_JIG | \
						 FSA9480_DETECT_UART)

struct fsa9480_detect_set {
	int	prio;
	u32	mask;
	bool	fallback;
};

struct fsa9480_platform_data {
	int				detect_time;

	void				(*enable)(bool enable);
	void				(*detected)(int device);

	struct fsa9480_detect_set	*detect_sets;
	int				num_sets;
};

#endif
