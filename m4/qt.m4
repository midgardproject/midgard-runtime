dnl Usage: PKG_CHECK_MODULES_SUBST([name], [package to check for])
AC_DEFUN([PKG_CHECK_MODULES_SUBST], [
PKG_CHECK_MODULES([$1], [$2])
AC_SUBST([$1_CFLAGS])
AC_SUBST([$1_LIBS])])

AC_DEFUN([AC_PROG_QT_MOC], [
MOC=`pkg-config QtCore --variable=moc_location`
AC_CHECK_FILE([$MOC], [],
   AC_MSG_ERROR([Can't find moc compiler: $MOC]))
AC_SUBST([MOC])])

AC_DEFUN([AC_PROG_QT_UIC], [
UIC=`pkg-config QtCore --variable=uic_location`
AC_CHECK_FILE([$UIC], [],
   AC_MSG_ERROR([Can't find uic compiler: $UIC]))
AC_SUBST([UIC])])

AC_DEFUN([AC_PROG_QT_RCC], [
RCC=`pkg-config QtCore --variable=exec_prefix`/bin/rcc
AC_CHECK_FILE([$RCC], [],
   AC_MSG_ERROR([Can't find rcc compiler: $RCC]))
AC_SUBST([RCC])])
