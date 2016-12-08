//
//  unit_data_item.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef unit_data_item_hpp
#define unit_data_item_hpp

#include <glibmm.h>
#include <libxml++/libxml++.h>

namespace DDType
{
	class UnitDataItem {
		public:
			explicit UnitDataItem(xmlpp::Node* data_item_node);
			const Glib::ustring& target() const {return m_target;};
			const std::vector<Glib::ustring>& codes() const {return m_codes;};
		private:
			Glib::ustring m_target;
			std::vector<Glib::ustring> m_codes;
	};
}
#endif
