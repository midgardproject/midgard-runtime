bin_PROGRAMS = midgard2-runtime

midgard2_runtime_SOURCES = main.cpp serverprocess.cpp serverprocess.h mainwindow.h mainwindow.cpp phpprocess.h phpprocess.cpp runtime.h runtime.cpp runtimeprocess.h runtimeprocess.cpp sconnect.h

AM_CXXFLAGS = $(QtCore_CFLAGS) $(QtGui_CFLAGS) $(QtWebKit_CFLAGS)
AM_LDFLAGS = $(QtCore_LIBS) $(QtGui_LIBS) $(QtWebKit_LIBS)

# moccing
nodist_midgard2_runtime_SOURCES = mocs.cpp
QT_TOMOC = $(filter %.h, $(midgard2_runtime_SOURCES))
include $(top_srcdir)/am/qt.am
