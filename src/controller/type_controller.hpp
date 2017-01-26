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
			static TypeController& shared_controller();

			void on_typed(Glib::ustring input);
			void set_data_path(std::string path);
			void set_interface(TypeInterface* interface);
			Glib::ustring targets();
		private:
			TypeController();
			TypeController(const TypeController&);
			TypeController& operator=(const TypeController&);

			static TypeController* sm_controller;

			TypeInterface* m_interface;
			std::list<UnitDataItem> m_unit_data_list;
			std::list<UnitDataItem> m_miss_data_list;
			const UnitDataItem* m_current_data_item;
			void match(Glib::ustring input);
			void match_success();
			void match_fail();
			void tip();
	};
}
#endif
