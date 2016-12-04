//
//  item_data_model.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef item_data_model_hpp
#define item_data_model_hpp

#include <glibmm.h>

namespace DDType
{
	class ItemData {
		private:
			Glib::ustring target;
			std::vector<Glib::ustring> codes;
	};
}
#endif
