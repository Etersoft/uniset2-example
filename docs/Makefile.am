DOC_CFG_USER = Dox.cfg
DOC_CFG_DEVEL = DoxDevel.cfg

DIRS = html
DOCFILES = ${DIRS}/*.{html,css,png,gif}
########################################################################

if HAVE_DOXYGEN

all-local: user
	

user: ${DOC_CFG_USER}
	${DOXYGEN} $<

devel: ${DOC_CFG_DEVEL}
	${DOXYGEN} $<

clean-local:
	rm -rf ${DOCFILES} *~

# install
ddir = $(datadir)/doc/@PACKAGE@-@VERSION@/html
d_DATA = html/*

endif