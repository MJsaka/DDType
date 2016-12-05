## Process this file with automake to produce Makefile.in

SUBDIRS = src 

export AM_CPPFLAGS = \
	-std=c++11 \
	$(GTKMM_CFLAGS) \
	$(LIBXMLPP_CFLAGS) \
	$(LIBSIGCXX_CFLAGS)

export AM_CXXFLAGS = \
	$(AM_CPPFLAGS) 

export AM_LDFLAGS = \
	$(GTKMM_LIBS) \
	$(LIBXMLPP_LIBS) \
	$(LIBSIGCXX_LIBS)

dist_doc_DATA = \
				AUTHORS \
				COPYING \
				ChangeLog \
				NEWS \
				README 

# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(docdir)

