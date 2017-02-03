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
			void show(Glib::ustring path);
			void finish();
			void match_success();
			void match_fail();
			void tip();
			void retry_miss();
			bool on_destroy(GdkEventAny*);
		private:
			Glib::ustring m_path;
	};
}

#endif
