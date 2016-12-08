//
//  units_manager.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "schema_manager.hpp"
#include <iostream>

namespace DDType
{
	const static std::string schema_path("/usr/local/share/ddtype/schema/zm.xml");
	const static Glib::ustring data_path_base("/usr/local/share/ddtype/schema/data");
	std::vector<Schema> SchemaManager::sm_schemas;

	void SchemaManager::update_schemas()
	{
		try {
			auto parser = new xmlpp::DomParser(schema_path, true);
			auto root = parser->get_document()->get_root_node();
			Schema schema(root);
			sm_schemas.push_back(schema);
			delete parser;
		}
		catch (xmlpp::exception e){
			std::cout<<std::string(e.what());
		}
	}
	const Glib::ustring SchemaManager::unit_data_path(const Gtk::TreeModel::Path& path)
	{
		Glib::ustring sub_path;
		auto schema = sm_schemas[path[0]];
		sub_path += "/" + schema.path();

		Unit& unit = schema;
		auto sub = schema.sub_units();
		for (int i = 1; i < path.size(); ++i)
		{
			unit = sub[path[i]];
			sub_path += "/" + unit.path();
			sub = unit.sub_units();
		}
		sub_path += ".xml";
		return data_path_base + sub_path;
	}
}
