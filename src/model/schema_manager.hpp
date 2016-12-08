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
			static void update_schemas();
			static const std::vector<Schema>& schemas() {return sm_schemas;};
			static const Glib::ustring unit_data_path(const Gtk::TreeModel::Path& path);

		private:
			SchemaManager();
			SchemaManager(SchemaManager&);
			SchemaManager& operator= (const SchemaManager&);
			static std::vector<Schema> sm_schemas;
	};
}
#endif
