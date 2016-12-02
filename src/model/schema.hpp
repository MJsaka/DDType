//
//  schema.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef schema_hpp
#define schema_hpp

#include <glibmm.h>
#include <libxml++/libxml++.h>

namespace DDType
{
	class Item 
	{
		public:
			explicit Item(const xmlpp::Node* item_node);
			Glib::ustring name() const {return m_name;};
			Glib::ustring path() const {return m_path;};
			Glib::ustring info() const {return m_info;};
			const std::vector<Item>& sub_items() const {return m_sub_items;};

		private:
			Glib::ustring m_name;
			Glib::ustring m_path;
			Glib::ustring m_info;
			std::vector<Item> m_sub_items;

		protected:
	};
	using Schema = Item;
}

std::ostream& operator<<(std::ostream&, const DDType::Item&);
#endif
