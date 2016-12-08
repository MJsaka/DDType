//
//  schema.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "schema.hpp"
#include <glibmm.h>
#include <iostream>
#include <libxml++/libxml++.h>

namespace DDType
{
	Unit::Unit(const xmlpp::Node* unit_node)
	{
		auto name_path = unit_node->get_first_child("name")->get_path();
		m_name = unit_node->eval_to_string(name_path);

		auto path_path = unit_node->get_first_child("path")->get_path();
		m_path = unit_node->eval_to_string(path_path);

		auto units_node = unit_node->get_first_child("units");
		if (units_node != nullptr)
		{
			m_is_catalog = true;
			auto sub_unit_nodes = units_node->get_children("unit");
			for(auto iter : sub_unit_nodes)
			{
				auto unit = Unit(iter);
				m_sub_units.push_back(unit);
			}
		}else
		{
			m_is_catalog = false;
		}
	}
}
std::ostream& operator<<(std::ostream& os, const DDType::Unit& unit)
{
	const static auto sep = Glib::ustring("    ");
	static auto left_sep = Glib::ustring();

	os<<left_sep<<unit.name()<<sep<<unit.path()<<std::endl;

	left_sep += sep;
	for(auto iter : unit.sub_units())
	{
		os<<iter;
	}
	left_sep = left_sep.substr(0,left_sep.size() - sep.size());

	return os;
}

