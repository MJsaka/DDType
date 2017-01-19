//
//  type_controller.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef type_controller_hpp
#define type_controller_hpp
#include <glibmm.h>
#include "../view/type_interface.hpp"
#include "../model/unit_data_item.hpp"

namespace DDType
{
	class TypeController
	{
		public:
			TypeController();
			void on_typed(Glib::ustring c);
			void set_data_path(std::string path);
			void set_interface(TypeInterface& interface);
		private:
			TypeInterface& m_interface;
			std::list<UnitDataItem> m_unit_data_list;
			int m_max_code_len_of_current_item;
			Glib::ustring m_input;
	};
}
#endif
