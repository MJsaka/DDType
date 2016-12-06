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
			void on_tree_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column);
			void on_tree_row_expanded(const Gtk::TreeModel::iterator&, const Gtk::TreeModel::Path&);
		private:
			Gtk::HBox m_h_box;
			Gtk::TreeView m_tree_view;
			Gtk::TextView m_info_view;
			Gtk::TreeModelColumn<Glib::ustring> m_col_name;
			Gtk::TreeModel::ColumnRecord m_model_columns;
			Glib::RefPtr<Gtk::TreeStore> m_ref_tree_store;
			Glib::RefPtr<Gtk::TextBuffer> m_buffer;
		protected:
			void fill_tree_iter(Gtk::TreeStore::iterator& iter, Unit& unit);
			void construct_tree_view();
	};
}

#endif
