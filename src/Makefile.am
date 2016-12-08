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

schemadefdir = $(schemadir)/def
dist_schemadef_DATA = resources/def/zm.xml 

schemadtddir = $(schemadir)/dtd
dist_schemadtd_DATA = resources/dtd/schema.dtd \
				resources/dtd/unit_data.dtd \
				resources/dtd/unit_log.dtd

schemadatadir = $(pkgdatadir)/schema/data
zmdir = $(schemadatadir)/zm
zmdzdir = $(zmdir)/dz
dist_zmdz_DATA = resources/data/zm/dz/data.xml 
zmzgzgdir = $(zmdir)/zg/zg
dist_zmzgzg_DATA = resources/data/zm/zg/zg/data.xml 
zmzgfgdir = $(zmdir)/zg/fg
dist_zmzgfg_DATA = resources/data/zm/zg/fg/data.xml 

EXTRA_DIST = $(dist_schemadef_DATA) $(dist_schemadtd_DATA) $(dist_zmdz_DATA) $(dist_zmzgzg_DATA) $(dist_zmzgfg_DATA)

uninstall-local:
	-rm -r $(pkgdatadir)
