//
//  main_view.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "main_view.hpp"
#include "../model/schema.hpp"
#include "../model/schema_manager.hpp"
#include <gtkmm.h>
#include <glibmm.h>
#include <iostream>
#include <sigc++/sigc++.h>

namespace DDType {

	MainView::MainView()
	{
		construct_tree_view();
		pack_end(m_tree_view,true,true);
		pack_end(m_info_view,true,true);
		set_spacing(5);
	}
	void MainView::construct_tree_view()
	{
		m_model_columns.add(m_col_name);
		m_ref_tree_store = Gtk::TreeStore::create(m_model_columns);
		auto schema_manager = SchemaManager();
		auto schemas = schema_manager.schemas();
		for (auto schema : schemas)
		{
			auto tree_iter_schema = m_ref_tree_store->append();
			fill_tree_iter(tree_iter_schema,schema);
		}
		m_tree_view = Gtk::TreeView(m_ref_tree_store);
		m_tree_view.append_column("name",m_col_name);
		m_tree_view.set_headers_visible(false);
		m_tree_view.set_activate_on_single_click(true);
		m_tree_view.signal_row_activated().connect(sigc::mem_fun(*this, &MainView::on_row_activated));
		m_tree_view.signal_row_expanded().connect(sigc::mem_fun(*this, &MainView::on_row_expanded));
	}
	void MainView::fill_tree_iter(Gtk::TreeStore::iterator& iter, Item& item)
	{
		Gtk::TreeModel::Row row = *iter;
		row[m_col_name] = item.name();
		for(auto sub_item : item.sub_items())
		{
			auto child_iter = m_ref_tree_store->append(row.children());
			fill_tree_iter(child_iter,sub_item);
		}
	}
	void MainView::on_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column)
	{
		Gtk::TreeModel::iterator iter = m_ref_tree_store -> get_iter(path);
		if(iter){
			Gtk::TreeRow row = *iter;
			std::cout<<row[m_col_name]<<std::endl;
		}
	}
	void MainView::on_row_expanded(const Gtk::TreeModel::iterator& iter, const Gtk::TreeModel::Path& path)
	{
		if(path.size() == 1)
		{
			m_tree_view.expand_all();
		}
	}
}
