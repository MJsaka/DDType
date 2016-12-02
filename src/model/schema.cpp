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
	Item::Item(const xmlpp::Node* item_node)
	{
		const static auto sep = Glib::ustring("    ");
		static auto left_sep = Glib::ustring();

		auto name_path = item_node->get_first_child("name")->get_path();
		m_name = item_node->eval_to_string(name_path);

		auto path_path = item_node->get_first_child("path")->get_path();
		m_path = item_node->eval_to_string(path_path);

		auto info_path = item_node->get_first_child("info")->get_path();
		m_info = item_node->eval_to_string(info_path);

		m_sub_items = std::vector<Item>();

		auto items_node = item_node->get_first_child("items");
		//std::cout<<left_sep<<"before items"<<std::endl;
		left_sep += sep;
		if (items_node != nullptr)
		{
			auto sub_item_nodes = items_node->get_children("item");
			for(auto iter : sub_item_nodes)
			{
				auto item = Item(iter);
				m_sub_items.push_back(item);
			}
		}
		left_sep = left_sep.substr(0,left_sep.size() - sep.size());
		//std::cout<<left_sep<<"after items"<<std::endl;
	}
}
std::ostream& operator<<(std::ostream& os, const DDType::Item& item)
{
	const static auto sep = Glib::ustring("    ");
	static auto left_sep = Glib::ustring();

	os<<left_sep<<item.name()<<sep<<item.path()<<sep<<item.info()<<std::endl;

	//std::cout<<left_sep<<"before items print"<<std::endl;
	left_sep += sep;
	for(auto iter : item.sub_items())
	{
		os<<iter;
	}
	left_sep = left_sep.substr(0,left_sep.size() - sep.size());
	//std::cout<<left_sep<<"after items print"<<std::endl;

	return os;
}

