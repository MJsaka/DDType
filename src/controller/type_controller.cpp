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
	TypeController* TypeController::sm_controller = nullptr;
	TypeController::TypeController()
	{
		m_interface = nullptr;
		m_current_data_item = nullptr;
	}
	TypeController& TypeController::shared_controller()
	{
		if(!sm_controller)
		{
			sm_controller = new TypeController;
		}
		return *sm_controller;
	}
	void TypeController::set_interface(TypeInterface* interface)
	{
		if(m_interface){
			m_interface->signal_key_pressed().clear();
		}  
		m_interface = interface;
		interface->signal_key_pressed().connect(sigc::mem_fun(*this,&TypeController::on_typed));
	}
	void TypeController::set_data_path(std::string path)
	{
		m_unit_data_list = std::list<UnitDataItem>();
		m_miss_data_list = std::list<UnitDataItem>();
		try {
			auto parser = new xmlpp::DomParser(path, true);
			auto root = parser->get_document()->get_root_node();
			for(auto data_item_node : root->get_children("item")){
				auto data_item = UnitDataItem(data_item_node);
				m_unit_data_list.push_back(data_item);
			}
			delete parser;

			m_current_data_item = &(m_unit_data_list.front());
		}
		catch (xmlpp::exception e){
			std::cout<<e.what()<<std::endl;
		}
	}

	Glib::ustring TypeController::targets()
	{
		Glib::ustring ts;
		for(auto ud : m_unit_data_list)
		{
			ts += ud.target();
		}
		return ts;
	}
	void TypeController::on_typed(Glib::ustring input)
	{
		if (input == "\t"){
			tip();
		}else{
			match(input);
		}
	}
	void TypeController::tip()
	{
		m_interface->tip();
	}
	void TypeController::match(Glib::ustring input)
	{
		if(input == m_current_data_item->target()){
			match_success();
			return;
		}
		for(auto code : m_current_data_item->codes()){
			if(input == code){
				match_success();
				return;
			}else if(input.length() <= code.length() && input == code.substr(0,input.length())){
				return;
			}
		}
		match_fail();
	}
	void TypeController::match_success()
	{
		m_unit_data_list.pop_front();
		if(!m_unit_data_list.empty()){
			m_current_data_item = &(m_unit_data_list.front());
			m_interface->match_success();
		}else if(m_miss_data_list.empty()){
			m_interface->finish();
		}else{
			m_unit_data_list = m_miss_data_list;
			m_miss_data_list = std::list<UnitDataItem>();
			m_interface->retry_miss();
		}
	}
	void TypeController::match_fail()
	{
		m_miss_data_list.push_back(*m_current_data_item);
		m_unit_data_list.pop_front();
		if(!m_unit_data_list.empty()){
			m_current_data_item = &(m_unit_data_list.front());
			m_interface->match_fail();
		}else{
			m_unit_data_list = m_miss_data_list;
			m_miss_data_list = std::list<UnitDataItem>();
			m_interface->retry_miss();
		}
	}
}
