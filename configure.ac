#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# AC_PREREQ(2.59)
AC_INIT([uniset-example], [0.1])
AM_INIT_AUTOMAKE(AC_PACKAGE_NAME,AC_PACKAGE_VERSION)
AC_CONFIG_HEADER(config.h)

dnl Initialize maintainer mode
AM_MAINTAINER_MODE

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL

dnl Runtime directories.
AC_SUBST([runtimedir], ['/var/run'])
AC_SUBST([lockdir], ['/var/lock'])
AC_SUBST([logdir], ['/var/log'])

# Checks for libraries.
# check uniset
PKG_CHECK_MODULES(UNISET, libUniSet2 >= 1.0,,exit)

# check uniset-extensions
PKG_CHECK_MODULES(UNISET_EXT, libUniSet2Extensions,,exit)
AC_SUBST(UNISET_EXT_LIBS)
AC_SUBST(UNISET_EXT_CFLAGS)

PKG_CHECK_MODULES(UNISET_EXT_SM, libUniSet2SharedMemory,,exit)
AC_SUBST(UNISET_EXT_SM_LIBS)
AC_SUBST(UNISET_EXT_SM_CFLAGS)

# check uniset-unet2
#PKG_CHECK_MODULES(UNISET_EXT_UNET, libUniSet2UNetUDP,,exit)
#AC_SUBST(UNISET_EXT_UNET_LIBS)
#AC_SUBST(UNISET_EXT_UNET_CFLAGS)

CXXFLAGS="$CXXFLAGS $UNISET_CFLAGS $UNISET_EXT_CFLAGS"
LDFLAGS="$LDFLAGS $UNISET_LIBS $UNISET_EXT_LIBS"

# add my "include"
CXXFLAGS="$CXXFLAGS -I\$(top_builddir)/include -funsigned-char -D_GNU_SOURCE -Wall"

AC_SUBST(LDFLAGS)
AC_SUBST(CXXFLAGS)

# check uniset-codegen
if test "x$UNISET_CODEGEN" = x ; then
	UNISET_CODEGEN=uniset2-codegen
fi
AC_SUBST(UNISET_CODEGEN)
echo "UNISET_CODEGEN: $UNISET_CODEGEN"

# check Doxygen
DOXYGEN=""
doc=false
dox=
AC_MSG_CHECKING([Generate docs])
AC_ARG_ENABLE(docs,AC_HELP_STRING([--enable-docs], [enable build docs]),
[ doc=true; ],[ doc=false; ])

if test ${doc} = true; then
	AC_MSG_RESULT([yes])
	AC_CHECK_PROG(dox,doxygen,[yes])
	if test "x$dox" != x ; then
		DOXYGEN="doxygen"
	else
		AC_MSG_WARN([*** Doxygen not found])
	fi
else
	DOXYGEN=
	AC_MSG_RESULT([no])
fi
AC_SUBST(DOXYGEN)
AM_CONDITIONAL(HAVE_DOXYGEN, test x$DOXYGEN != x)

# check Omninames
NO_CHECK_OMNI="yes"
LOCAL_IOR="1"
COMMENT_OMNI="#"
omni=false
AC_ARG_ENABLE(omninames,AC_HELP_STRING([--enable-omninames], [enable omninames]),
[ if test "x${enableval}" = "xyes"; then omni=true; fi ])

if test ${omni} = true; then
	NO_CHECK_OMNI=""
	LOCAL_IOR="0"
	COMMENT_OMNI=""
fi

AC_SUBST(NO_CHECK_OMNI)
AC_SUBST(LOCAL_IOR)
AC_SUBST(COMMENT_OMNI)
AM_CONDITIONAL(HAVE_OMNINAMES, test x$omni != x)

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_STRUCT_TM

# Checks for library functions.
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile
				 Utilities/Makefile
				 Utilities/xslt/Makefile
				 Utilities/xslt/mk-map.sh
				 Utilities/check-configure.sh
				 conf/Makefile
				 src/Makefile
				 src/Algorithms/Makefile
				 src/Algorithms/Controller/Makefile
				 src/Algorithms/Imitator/Makefile
				 docs/Makefile
				 docs/Dox.cfg
				 lib/Various/Makefile
				 lib/Makefile])


AC_OUTPUT
