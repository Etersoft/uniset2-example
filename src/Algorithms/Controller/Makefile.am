bin_PROGRAMS = controller

BUILT_SOURCES = Controller_SK.h Controller_SK.h
 
controller_LDADD = $(top_builddir)/lib/libUniSetExample.la
#controller_CPPFLAGS = 
controller_SOURCES = Controller_SK.cc Controller.cc controller-main.cc

Controller_SK.h Controller_SK.cc: controller.src.xml
	@UNISET_CODEGEN@ -n Controller --topdir $(top_builddir)/ --ask --no-main controller.src.xml

clean-local:
	rm -rf *_SK.cc *_SK.h *.log

#style:
#	astyle $(ASTYLE_OPT) *.cc *.h
