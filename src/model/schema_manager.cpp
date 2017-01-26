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
	const static std::string schema_path("/usr/local/share/ddtype/schema/def/zm.xml");
	const static Glib::ustring data_path_base("/usr/local/share/ddtype/schema/data/");
	SchemaManager* SchemaManager::sm_manager = nullptr;

	SchemaManager::SchemaManager(){}
	const SchemaManager& SchemaManager::shared_manager()
	{
		if(!sm_manager)
		{
			sm_manager = new SchemaManager;
			update_schemas();
		}
		return *sm_manager;
	}

	void SchemaManager::update_schemas()
	{
		try {
			auto parser = new xmlpp::DomParser(schema_path, true);
			auto root = parser->get_document()->get_root_node();
			Schema schema(root);
			sm_manager->m_schemas.push_back(schema);
			delete parser;
		}
		catch (xmlpp::exception e){
			std::cout<<std::string(e.what());
		}
	}
	const Glib::ustring SchemaManager::unit_data_path(const Gtk::TreeModel::Path& path) const
	{
		return data_path_base + unit_path(path) + "data.xml";
	}
	const Glib::ustring SchemaManager::unit_info_path(const Gtk::TreeModel::Path& path) const
	{
		return data_path_base + unit_path(path) + "info.xml";
	}
	bool SchemaManager::is_catalog(const Gtk::TreeModel::Path& path) const
	{
		Unit unit = m_schemas[path[0]];
		for (int i = 1; i < path.size(); ++i)
		{
			auto sub = unit.sub_units();
			unit = sub[path[i]];
		}
		return unit.sub_units().size() > 0;
	}
	const Glib::ustring SchemaManager::unit_path(const Gtk::TreeModel::Path& path) const
	{
		Glib::ustring upath;
		auto schema = m_schemas[path[0]];
		upath += schema.path() + "/";

		Unit unit = schema;
		for (int i = 1; i < path.size(); ++i)
		{
			auto sub = unit.sub_units();
			unit = sub[path[i]];
			upath += unit.path() + "/";
		}
		return upath;
	}
}
