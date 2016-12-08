//
//  schema.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef schema_hpp
#define schema_hpp

#include <glibmm.h>
#include <gtkmm.h>
#include <libxml++/libxml++.h>

namespace DDType
{
	class Unit 
	{
		public:
			explicit Unit(const xmlpp::Node* unit_node);
			const bool is_catalog() const {return m_is_catalog;};
			const Glib::ustring& name() const {return m_name;};
			const Glib::ustring& path() const {return m_path;};
			const std::vector<Unit>& sub_units() const {return m_sub_units;};

		private:
			bool m_is_catalog;
			Glib::ustring m_name;
			Glib::ustring m_path;
			std::vector<Unit> m_sub_units;

		protected:
	};
	using Schema = Unit;
}

std::ostream& operator<<(std::ostream&, const DDType::Unit&);
#endif
