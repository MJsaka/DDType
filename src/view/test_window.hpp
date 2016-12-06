//
//  test_window.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef test_window_hpp
#define test_window_hpp
#include "type_interface.hpp"
namespace DDType
{

	class TestWindow : public TypeInterface, public Gtk::Window
	{
	};
}

#endif
