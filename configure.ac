#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([turing2], [1.0.0], [dario.cangialosi@gmail.com])
AC_CONFIG_SRCDIR([c/turing.c])
AC_CONFIG_HEADERS([config.h])

# added from autoscan: automake section
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_OUTPUT([Makefile])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h termios.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([c/Makefile])
AC_OUTPUT
