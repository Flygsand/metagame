TESTS = testrunner
check_PROGRAMS = testrunner
testrunner_SOURCES = testrunner.c test_util.h $(top_builddir)/src/util.h test_types $(top_builddir)/src/types.h test_metagame.h $(top_builddir)/src/metagame.h
testrunner_CFLAGS = @CHECK_CFLAGS@
testrunner_LDADD = $(top_builddir)/src/libmetagame.la @CHECK_LIBS@