#!/bin/sh -e

cd $(dirname $0)

if [ -f Makefile ]
then
	make maintainer-clean || true
fi

echo Cleaning autotools files...
find . -type d -name autom4te.cache -print0 | xargs -0 rm -rf \;
find . -type f \( -name missing -o -name install-sh -o -name mkinstalldirs \
	-o -name depcomp -o -name ltmain.sh -o -name configure \
	-o -name config.sub -o -name config.log -o -name config.guess -o -name aclocal.m4 \
	-o -name Makefile.in  -o -name py-compile \) -print0 | xargs -0 rm -f
rm -f m4/lt*m4 m4/libtool.m4
rm -f doltcompile
rm -f doltlibtool
# rm -f debian-devel/control debian-devel/rules install-stamp
