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
	class Unit 
	{
		public:
			explicit Unit(const xmlpp::Node* unit_node);
			Glib::ustring name() const {return m_name;};
			Glib::ustring path() const {return m_path;};
			Glib::ustring info() const {return m_info;};
			const std::vector<Unit>& sub_units() const {return m_sub_units;};

		private:
			Glib::ustring m_name;
			Glib::ustring m_path;
			Glib::ustring m_info;
			std::vector<Unit> m_sub_units;

		protected:
	};
	using Schema = Unit;
}

std::ostream& operator<<(std::ostream&, const DDType::Unit&);
#endif
