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
			SchemaManager();
			const std::vector<Schema>& schemas() const {return m_schemas;};

		private:
			std::vector<Schema> m_schemas;
	};
}
#endif
