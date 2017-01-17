//
//  practise_window.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef practise_window_hpp
#define practise_window_hpp
#include "type_interface.hpp"
#include <gtkmm.h>
#include <glibmm.h>
namespace DDType 
{
	class PractiseWindow : public TypeInterface, public Gtk::Window
	{
		public:
			PractiseWindow();
			void finish();
			void match_success();
			void match_fail();
			void tip();
			bool on_destroy(GdkEventAny*);
			sigc::signal<void,Glib::ustring> signal_key_pressed();
		private:
	};
}

#endif
