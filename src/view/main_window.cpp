//
//  main_window.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "main_window.hpp"
#include "../model/schema.hpp"
#include "../model/schema_manager.hpp"
#include <gtkmm.h>
#include <glibmm.h>
#include <iostream>
#include <sigc++/sigc++.h>

namespace DDType {

	MainWindow::MainWindow()
	{
		construct_tree_view();
		m_buffer = m_info_view.get_buffer();
		m_h_box.pack_start(m_tree_view,true,true);
		m_h_box.pack_start(m_info_view,true,true);
		m_h_box.set_spacing(5);

		set_title("DDType");
		set_border_width(5);
		add(m_h_box);
		show_all();
	}
	void MainWindow::construct_tree_view()
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
		m_tree_view.signal_row_activated().connect(sigc::mem_fun(*this, &MainWindow::on_tree_row_activated));
		m_tree_view.signal_row_expanded().connect(sigc::mem_fun(*this, &MainWindow::on_tree_row_expanded));
	}
	void MainWindow::fill_tree_iter(Gtk::TreeStore::iterator& iter, Unit& unit)
	{
		Gtk::TreeModel::Row row = *iter;
		row[m_col_name] = unit.name();
		for(auto sub_unit : unit.sub_units())
		{
			auto child_iter = m_ref_tree_store->append(row.children());
			fill_tree_iter(child_iter,sub_unit);
		}
	}
	void MainWindow::on_tree_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column)
	{
		Gtk::TreeModel::iterator iter = m_ref_tree_store -> get_iter(path);
		if(iter){
			Gtk::TreeRow row = *iter;
			std::cout<<row[m_col_name]<<std::endl;
			m_buffer->set_text(row[m_col_name]);
		}
	}
	void MainWindow::on_tree_row_expanded(const Gtk::TreeModel::iterator& iter, const Gtk::TreeModel::Path& path)
	{
		if(path.size() == 1)
		{
			m_tree_view.expand_all();
		}
	}
}
