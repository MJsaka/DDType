//
//  test_window.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef test_window_hpp
#define test_window_hpp
#include "type_interface.hpp"
#include <gtkmm.h>
namespace DDType
{

	class TestWindow : public TypeInterface, public Gtk::Window
	{
		public:
			TestWindow();
			void finish();
			void match_success();
			void match_fail();
			void tip();
			bool on_destroy(GdkEventAny*);
			sigc::signal<void,Glib::ustring> signal_key_pressed();
	};
}

#endif
