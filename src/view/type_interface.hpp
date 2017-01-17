//
//  type_interface.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef type_interface_hpp
#define type_interface_hpp

#include <glibmm.h>
#include <sigc++/sigc++.h>

namespace DDType 
{
	class TypeInterface
	{
		public:
			virtual void finish() = 0;
			virtual void match_success() = 0;
			virtual void match_fail() = 0;
			virtual void tip() = 0;
			virtual sigc::signal<void,Glib::ustring> signal_key_pressed() = 0;
	};
}

#endif
