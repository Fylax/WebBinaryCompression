/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ARCHITECTURE_CHECKER_H
#define WEB_BINARY_COMPRESSION_ARCHITECTURE_CHECKER_H
#ifdef __GNUC__
  #include <endian.h>
#endif

#ifndef __BYTE_ORDER
#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || \
      defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64) || \
      defined(__arm__) || defined(__TARGET_ARCH_ARM) || \
      defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || \
      defined(__arm) || defined(__aarch64__) || defined(i386) || \
      defined(__i386) || defined(__i386__) || defined(__IA32__) || \
      defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || \
      defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || \
      defined(__INTEL__) || defined(__ia64__) || defined(_IA64) || \
      defined(__IA64__) || defined(__ia64) || defined(_M_IA64) || \
      defined(__itanium__) || defined(__sparc_v9__) || defined(__sparcv9)

#define __LITTLE_ENDIAN 1
#define __BYTE_ORDER __LITTLE_ENDIAN

#else
    #define __BYTE_ORDER__ 0
#endif
#endif
#endif

