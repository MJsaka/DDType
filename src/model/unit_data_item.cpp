//
//  unit_data_item.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "unit_data_item.hpp"
#include <libxml++/libxml++.h>

namespace DDType
{
	UnitDataItem::UnitDataItem(xmlpp::Node* data_item_node)
	{
		auto target_path = data_item_node->get_first_child("target")->get_path();
		m_target = data_item_node->eval_to_string(target_path);

		auto code_nodes = data_item_node->get_children("code");
		for(auto code_node : code_nodes)
		{
			auto code = data_item_node->eval_to_string(code_node->get_path());
			m_codes.push_back(code);
		}
	}
}
