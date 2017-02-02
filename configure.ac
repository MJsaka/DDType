#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT([ddtype],[1.0.0],[mjsaka@qq.com])
AM_INIT_AUTOMAKE([-Wall gnu subdir-objects])
AC_CONFIG_SRCDIR([src/main.cc])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
PKG_CHECK_MODULES([GTKMM], [gtkmm-3.0])
PKG_CHECK_MODULES([LIBXMLPP], [libxml++-3.0])
PKG_CHECK_MODULES([LIBSIGCXX], [sigc++-2.0])

AC_CONFIG_FILES([
				 Makefile
				 src/Makefile
				 resources/Makefile
				 resources/pixmap/Makefile
				 resources/schema/Makefile
				 resources/schema/def/Makefile
				 resources/schema/dtd/Makefile
				 resources/schema/data/Makefile
				 resources/schema/data/zhengma/Makefile
				 ])
AC_OUTPUT
