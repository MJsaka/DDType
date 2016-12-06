//
//  type_controller.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "type_controller.hpp"
#include <sigc++/sigc++.h>

namespace DDType 
{
	TypeController::TypeController(TypeInterface& window):m_window(window)
	{
		m_window.set_type_callback(sigc::mem_fun(*this, &TypeController::on_typed));
	}
	void TypeController::set_unit_path(Glib::ustring)
	{
	}
	void TypeController::on_typed(char c)
	{
	}
}
