//
//  type_interface.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "type_interface.hpp"

namespace DDType 
{
	void TypeInterface::set_type_callback(const sigc::slot<void, char>& slot)
	{
		m_signal_key_typed.connect(slot);
	}
}
