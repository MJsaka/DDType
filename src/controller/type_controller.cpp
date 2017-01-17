//
//  type_controller.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "type_controller.hpp"
#include <sigc++/sigc++.h>
#include <glibmm.h>
#include <libxml++/libxml++.h>
#include <iostream>

namespace DDType 
{
	void TypeController::set_interface(TypeInterface& interface)
	{
		m_interface = interface;
		interface.signal_key_pressed().connect(sigc::mem_fun(*this,&TypeController::on_typed));
	}
	void TypeController::set_unit_path(std::string path)
	{
		m_unit_data_list = std::list<UnitDataItem>();
		try {
			auto parser = new xmlpp::DomParser(path, true);
			auto root = parser->get_document()->get_root_node();
			for(auto data_item_node : root->get_children("item"))
			{
				auto data_item = UnitDataItem(data_item_node);
				m_unit_data_list.push_back(data_item);
			}
			delete parser;
		}
		catch (xmlpp::exception e){
			std::cout<<e.what()<<std::endl;
		}
	}
	void TypeController::on_typed(Glib::ustring c)
	{
	}
}
