//
//  units_manager.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "schema_manager.hpp"
#include <iostream>

namespace DDType
{
	const std::string schema_path("/usr/local/share/ddtype/schema/zm.xml");
	SchemaManager::SchemaManager()
	{
		std::cout<<"before schemas"<<std::endl;
		m_schemas = std::vector<Schema>();
		try {
			auto parser = new xmlpp::DomParser(schema_path, true);
			auto root = parser->get_document()->get_root_node();
			Schema schema(root);
			m_schemas.push_back(schema);
			std::cout<<schema;
		}
		catch (xmlpp::exception e){
			std::cout<<std::string(e.what());
		}
		std::cout<<"after schemas"<<std::endl;
	}
}
