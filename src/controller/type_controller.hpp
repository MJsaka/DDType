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
			TypeController(TypeInterface& window);
			void on_typed(char c);
			void set_unit_path(std::string path);
		private:
			TypeInterface& m_window;
			std::list<UnitDataItem> m_unit_data_list;
			int m_max_code_len_of_current_item;
			std::vector<char> m_input;
	};
}
#endif
