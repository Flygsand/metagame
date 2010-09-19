#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([metagame], [0.1], [martin.haeger@gmail.com])
AM_INIT_AUTOMAKE([metagame], [0.1])
AC_CONFIG_SRCDIR([src/metagame.h])
AC_CONFIG_HEADERS([src/config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for libraries.
AC_CHECK_LIB([gcrypt], [gcry_md_hash_buffer], [], [AC_MSG_ERROR([libgcrypt required but not found.])])

PKG_CHECK_MODULES([CHECK], [check >= 0.9.4])
AM_PROG_CC_C_O

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([strdup])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 tests/Makefile])
AC_OUTPUT
