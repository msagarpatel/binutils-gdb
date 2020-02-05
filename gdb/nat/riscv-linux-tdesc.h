/* GNU/Linux/RISC-V native target description support for GDB.
   Copyright (C) 2020 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef NAT_RISCV_LINUX_TDESC_H
#define NAT_RISCV_LINUX_TDESC_H

struct target_desc;

/* Return a target description for the LWP identified by TID.  */
const struct target_desc *riscv_linux_read_description (int tid);

#endif /* NAT_RISCV_LINUX_TDESC_H */
