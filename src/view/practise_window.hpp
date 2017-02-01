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
			void show(Glib::ustring path);
			void show();
			void finish();
			void match_success();
			void match_fail();
			void tip();
			void retry_miss();
			bool on_destroy(GdkEventAny*);
			void on_insert(guint, const gchar*, guint);
		private:
			Gtk::VBox m_v_box;
			Gtk::Table m_table;
			std::list<Gtk::Label*> m_labels;
			std::list<Gtk::Label*>::iterator m_current_label;
			Gtk::Alignment m_entry_alignment;
			Gtk::Entry m_entry;
			Glib::RefPtr<Gtk::EntryBuffer> m_entry_buffer;
			void fill_grid();
	};
}

#endif
