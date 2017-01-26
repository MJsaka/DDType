//
//  main_window.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef main_window_hpp
#define main_window_hpp

#include <gtkmm.h>
#include "../model/schema.hpp"

namespace DDType{

	class MainWindow : public Gtk::Window
	{
		public:
			MainWindow();
			bool on_destroy(GdkEventAny*);
			void on_tree_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column);
			void on_tree_row_expanded(const Gtk::TreeModel::iterator&, const Gtk::TreeModel::Path&);
			void on_practise_button() const;
			void on_test_button() const;
		private:
			Gtk::VBox m_v_box;
			Gtk::HBox m_h_box;

			Gtk::HeaderBar m_headerbar;
			Gtk::ActionBar m_actionbar;
			Gtk::HButtonBox m_h_button_box;
			Gtk::ToolButton m_practise_button;
			Gtk::ToolButton m_test_button;

			Gtk::TreeView m_tree_view;
			Gtk::TreeModelColumn<Glib::ustring> m_col_name;
			Gtk::TreeModel::ColumnRecord m_model_columns;
			Glib::RefPtr<Gtk::TreeStore> m_ref_tree_store;
			Gtk::TreeModel::Path m_current_path;

			Gtk::TextView m_info_view;
			Glib::RefPtr<Gtk::TextBuffer> m_buffer;

			void fill_tree_iter(Gtk::TreeStore::iterator& iter, Unit& unit);
			void construct_tree_view();
	};
}

#endif
