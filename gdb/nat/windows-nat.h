/* Internal interfaces for the Windows code
   Copyright (C) 1995-2020 Free Software Foundation, Inc.

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

#ifndef NAT_WINDOWS_NAT_H
#define NAT_WINDOWS_NAT_H

#include <windows.h>

namespace windows_nat
{

/* Thread information structure used to track extra information about
   each thread.  */
struct windows_thread_info
{
  windows_thread_info (DWORD tid_, HANDLE h_, CORE_ADDR tlb)
    : tid (tid_),
      h (h_),
      thread_local_base (tlb)
  {
  }

  ~windows_thread_info ();

  DISABLE_COPY_AND_ASSIGN (windows_thread_info);

  /* Ensure that this thread has been suspended.  */
  void suspend ();

  /* Resume the thread if it has been suspended.  */
  void resume ();

  /* The Win32 thread identifier.  */
  DWORD tid;

  /* The handle to the thread.  */
  HANDLE h;

  /* Thread Information Block address.  */
  CORE_ADDR thread_local_base;

  /* This keeps track of whether SuspendThread was called on this
     thread.  -1 means there was a failure or that the thread was
     explicitly not suspended, 1 means it was called, and 0 means it
     was not.  */
  int suspended = 0;

#ifdef _WIN32_WCE
  /* The context as retrieved right after suspending the thread. */
  CONTEXT base_context {};
#endif

  /* The context of the thread, including any manipulations.  */
  union
  {
    CONTEXT context {};
#ifdef __x86_64__
    WOW64_CONTEXT wow64_context;
#endif
  };

  /* Whether debug registers changed since we last set CONTEXT back to
     the thread.  */
  bool debug_registers_changed = false;

  /* Nonzero if CONTEXT is invalidated and must be re-read from the
     inferior thread.  */
  bool reload_context = false;

  /* True if this thread is currently stopped at a software
     breakpoint.  This is used to offset the PC when needed.  */
  bool stopped_at_software_breakpoint = false;

  /* The name of the thread, allocated by xmalloc.  */
  gdb::unique_xmalloc_ptr<char> name;
};


/* Possible values to pass to 'thread_rec'.  */
enum thread_disposition_type
{
  /* Do not invalidate the thread's context, and do not suspend the
     thread.  */
  DONT_INVALIDATE_CONTEXT,
  /* Invalidate the context, but do not suspend the thread.  */
  DONT_SUSPEND,
  /* Invalidate the context and suspend the thread.  */
  INVALIDATE_CONTEXT
};

/* Find a thread record given a thread id.  THREAD_DISPOSITION
   controls whether the thread is suspended, and whether the context
   is invalidated.

   This function must be supplied by the embedding application.  */
extern windows_thread_info *thread_rec (ptid_t ptid,
					thread_disposition_type disposition);

/* Return the name of the DLL referenced by H at ADDRESS.  UNICODE
   determines what sort of string is read from the inferior.  Returns
   the name of the DLL, or NULL on error.  If a name is returned, it
   is stored in a static buffer which is valid until the next call to
   get_image_name.  */
extern const char *get_image_name (HANDLE h, void *address, int unicode);

}

#endif