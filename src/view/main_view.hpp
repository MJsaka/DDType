//
//  main_view.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef main_view_hpp
#define main_view_hpp

#include <gtkmm.h>
#include "../model/schema.hpp"

namespace DDType{

	class MainView : public Gtk::HBox 
	{
		public:
			MainView();
			void on_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column);
			void on_row_expanded(const Gtk::TreeModel::iterator&, const Gtk::TreeModel::Path&);
		private:
			Gtk::TreeModelColumn<Glib::ustring> m_col_name;
			Gtk::TreeModel::ColumnRecord m_model_columns;
			Glib::RefPtr<Gtk::TreeStore> m_ref_tree_store;
			Gtk::TreeView m_tree_view;
			Gtk::TextView m_info_view;
		protected:
			void fill_tree_iter(Gtk::TreeStore::iterator& iter, Item& item);
			void construct_tree_view();
	};
}

#endif
