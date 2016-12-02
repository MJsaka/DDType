## Process this file with automake to produce Makefile.in
bin_PROGRAMS = ddtype
schemadir = $(pkgdatadir)/schema
dist_schema_DATA = resources/schema.dtd resources/zm.xml

ddtype_SOURCES = \
				 main.cc \
				 model/schema.hpp \
				 model/schema.cpp \
				 model/schema_manager.hpp \
				 model/schema_manager.cpp \
				 view/main_window.hpp \
				 view/main_window.cpp \
				 view/main_view.hpp \
				 view/main_view.cpp \
				 view/type_view.hpp \
				 view/type_view.hpp \
				 view/practise_view.hpp \
				 view/practise_view.cpp \
				 view/test_view.hpp \
				 view/test_view.cpp 

EXTRA_DIST = $(dist_schema_DATA)

uninstall-local:
	-rm -r $(schemadir)
	-rm -r $(pkgdatadir)
