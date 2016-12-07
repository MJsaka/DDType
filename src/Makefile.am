## Process this file with automake to produce Makefile.in
bin_PROGRAMS = ddtype

ddtype_SOURCES = \
				 main.cc \
				 controller/type_controller.hpp \
				 controller/type_controller.cpp \
				 model/schema.hpp \
				 model/schema.cpp \
				 model/schema_manager.hpp \
				 model/schema_manager.cpp \
				 model/unit_data_item.hpp \
				 model/unit_data_item.cpp \
				 model/unit_log_item.hpp \
				 model/unit_log_item.cpp \
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

schemadir = $(pkgdatadir)/schema
dist_schema_DATA = \
				   resources/schema.dtd \
				   resources/zm.xml 

schemadatadir = $(pkgdatadir)/schema_data
zmdir = $(schemadatadir)/zm
dist_zm_DATA = \
				   resources/unit_data.dtd \
				   resources/zm/dz.xml \
				   resources/zm/zg_zg.xml \
				   resources/zm/zg_fg.xml

EXTRA_DIST = $(dist_schema_DATA) $(dist_zm_DATA)

uninstall-local:
	-rm -r $(zmdir)
	-rm -r $(schemadir)
	-rm -r $(pkgdatadir)
