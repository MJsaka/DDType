## Process this file with automake to produce Makefile.in
schemadir = $(pkgdatadir)/schema

nobase_dist_schema_DATA = def/zm.xml \
						  dtd/schema.dtd \
						  dtd/unit_data.dtd \
						  dtd/unit_log.dtd \
						  data/zm/dz/data.xml \
						  data/zm/zg/zg/data.xml \
						  data/zm/zg/fg/data.xml 

uninstall-local:
	-rm -r $(schemadir)
