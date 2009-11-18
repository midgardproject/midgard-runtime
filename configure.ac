AC_PREREQ([2.61])
AC_INIT([MidgardRuntime], [0.1~unreleased], [mdk@new-wild.com], MidgardRuntime)

AC_CONFIG_SRCDIR([Makefile.am])
AM_INIT_AUTOMAKE([-Wall -Werror foreign dist-bzip2 tar-ustar 1.9])

AC_CONFIG_MACRO_DIR([m4])

AC_PROG_CC
CFLAGS="$CXXFLAGS -Wall"
AC_PROG_CXX
CXXFLAGS="$CXXFLAGS -Wall"
LT_INIT([disable-static])
DOLT

# check for libraries
PKG_CHECK_MODULES_SUBST([QtCore], [QtCore])
PKG_CHECK_MODULES_SUBST([QtGui], [QtGui])
PKG_CHECK_MODULES_SUBST([QtWebKit], [QtWebKit])

AC_PROG_QT_MOC
AC_PROG_QT_UIC
AC_PROG_QT_RCC

# tools for documentation
AX_FEATURE_DISABLEABLE([doc], [BUILD_DOCS], [disable building of documentation])
AX_DISABLE_FEATURE_ON_PROG([doxygen], [BUILD_DOCS], [DOXYGEN], [doxygen])
AM_CONDITIONAL([MIDGARD_RUNTIME_BUILD_DOCS], [test "$missing_deps_BUILD_DOCS" = ""])

# coverage tools
AX_FEATURE_DISABLEABLE([coverage], [COVERAGE], [disable unittests' coverage support])
AX_DISABLE_FEATURE_ON_PROG([GCov coverage recording tool], [COVERAGE], [GCOV], [gcov])
AX_DISABLE_FEATURE_ON_PROG([LCov coverage visualization tool], [COVERAGE], [LCOV], [lcov])
AM_CONDITIONAL([MIDGARD_RUNTIME_COVERAGE], [test "$missing_deps_COVERAGE" = ""])

AC_CONFIG_FILES([
        Makefile
	src/Makefile
])

AC_OUTPUT

AX_FEATURE_SUMMARIZE([BUILD_DOCS],
		     [Building of documentation is enabled],
		     [Documentation won't be built])

AX_FEATURE_SUMMARIZE([COVERAGE],
		     [Unit testing coverage support is enabled],
		     [Coverage won't be supported during unit testing])
