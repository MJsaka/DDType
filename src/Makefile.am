## Process this file with automake to produce Makefile.in
bin_PROGRAMS = ddtype
schemadir = $(pkgdatadir)/schema
dist_schema_DATA = resources/schema.dtd resources/zm.xml

ddtype_SOURCES = \
				 main.cc \
				 controller/type_controller.hpp \
				 controller/type_controller.cpp \
				 model/schema.hpp \
				 model/schema.cpp \
				 model/schema_manager.hpp \
				 model/schema_manager.cpp \
				 view/window_manager.hpp \
				 view/window_manager.cpp \
				 view/main_window.hpp \
				 view/main_window.cpp \
				 view/type_interface.hpp \
				 view/type_interface.cpp \
				 view/practise_window.hpp \
				 view/practise_window.cpp \
				 view/test_window.hpp \
				 view/test_window.cpp 

EXTRA_DIST = $(dist_schema_DATA)

uninstall-local:
	-rm -r $(schemadir)
	-rm -r $(pkgdatadir)
