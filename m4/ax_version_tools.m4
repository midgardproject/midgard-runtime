dnl Call executable --version, and try to figure out the version
dnl number from the output.
dnl
dnl Usage; AX_PROGRAM_VERSION([executable])
AC_DEFUN([AX_PROGRAM_VERSION], [dnl
`$$1 --version </dev/null 2>/dev/null | head -n1 | grep -o '[[0-9.]]*'`dnl
])

dnl Creates a command line parameter --disable-OPTIONNAME, which if
dnl specified by the user adds a fake dependency to
dnl missing_deps_CONDITIONALFEATURE.
dnl
dnl Usage: AX_FEATURE_DISABLEABLE([$1=option name], [$2=conditional feature], [$3=description])
AC_DEFUN([AX_FEATURE_DISABLEABLE], [
AC_ARG_ENABLE([$1],
     AS_HELP_STRING([--disable-$1],
                    [$3 [[default=no]]]),,
     [enable_$1=undef])
if test x$enable_$1 = xno
then
	missing_deps_$2=", disabled by user"
fi
])

dnl Check the existence (and optionally version) of a program and
dnl record information about this missing dependency on failure to
dnl the variable named missing_deps_CONDITIONALFEATURE.
dnl
dnl Usage: AX_DISABLE_FEATURE_ON_PROG([$1=description], [$2=conditional feature],
dnl                                   [$3=subst var], [$4=lookup list],
dnl				      [$5=needed version (optional)])
AC_DEFUN([AX_DISABLE_FEATURE_ON_PROG], [
AC_ARG_VAR([$3], [$1])
AC_CHECK_PROGS([$3], [$4], [:])
if test $$3 = :
then
  missing_deps_$2="$missing_deps_$2, $1"
else
  if test x$5 != x
  then
    disable_feature_on_prog_ver=AX_PROGRAM_VERSION([$3])
    AX_COMPARE_VERSION([$disable_feature_on_prog_ver], [ge], [$5], [],
    		       [AC_MSG_WARN([$1 version mismatch; wanted $5, has: $disable_feature_on_prog_ver])
		        missing_deps_$2="$missing_deps_$2, $1 >= $5"])
  fi
fi
])

dnl Reports the current state of missing_deps_CONDITIONALFEATURE
dnl variable to the user in an easy to read fashion.
dnl
dnl Usage: AX_FEATURE_SUMMARIZE([$1=conditional feature], [$2=enabled msg], [$3=disabled msg])
AC_DEFUN([AX_FEATURE_SUMMARIZE], [
if test "$missing_deps_$1" = ""
then
	AC_MSG_NOTICE([$2])
else
	missing_deps_$1=`echo $missing_deps_$1 | cut -c3-`
	AC_MSG_WARN([$3, missing dependencies: $missing_deps_$1])
fi
])
