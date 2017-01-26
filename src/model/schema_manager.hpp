//
//  schema_manager.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef schema_manager_hpp
#define schema_manager_hpp
#include "schema.hpp"

namespace DDType
{
	class SchemaManager 
	{
		public:
			static const SchemaManager& shared_manager();
			static void update_schemas();

			const std::vector<Schema>& schemas() const {return m_schemas;};
			const Glib::ustring unit_data_path(const Gtk::TreeModel::Path& path) const;
			const Glib::ustring unit_info_path(const Gtk::TreeModel::Path& path) const;
			bool is_catalog(const Gtk::TreeModel::Path& path) const;

		private:
			SchemaManager();
			SchemaManager(SchemaManager&);
			SchemaManager& operator= (const SchemaManager&);

			static SchemaManager* sm_manager;

			std::vector<Schema> m_schemas;
			const Glib::ustring unit_path(const Gtk::TreeModel::Path& path) const;
	};
}
#endif
