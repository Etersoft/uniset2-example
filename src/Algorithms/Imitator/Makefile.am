bin_PROGRAMS = imitator

BUILT_SOURCES = Imitator_SK.h Imitator_SK.h
 
imitator_LDADD = $(top_builddir)/lib/libUniSetExample.la
#imitator_CPPFLAGS = 
imitator_SOURCES = Imitator_SK.cc Imitator.cc imitator-main.cc

Imitator_SK.h Imitator_SK.cc: imitator.src.xml
	@UNISET_CODEGEN@ -n Imitator --topdir $(top_builddir)/ --ask --no-main imitator.src.xml

clean-local:
	rm -rf *_SK.cc *_SK.h *.log

#style:
#	astyle $(ASTYLE_OPT) *.cc *.h
