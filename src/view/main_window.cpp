//
//  main_window.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "main_window.hpp"
#include "window_manager.hpp"
#include "../model/schema.hpp"
#include "../model/schema_manager.hpp"
#include <gtkmm.h>
#include <glibmm.h>
#include <iostream>
#include <sigc++/sigc++.h>

namespace DDType {

	MainWindow::MainWindow()
	{
		m_toolbar.set_toolbar_style(Gtk::TOOLBAR_BOTH);
		m_toolbar.set_icon_size(Gtk::IconSize(48));

		m_practise_button = Gtk::ToolButton("Practise");
		m_practise_button.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::on_practise_button));
		
		m_test_button = Gtk::ToolButton("Test");
		m_test_button.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::on_test_button));

		m_toolbar.append(m_practise_button);
		m_toolbar.append(m_test_button);
		
		construct_tree_view();
		m_current_path = Gtk::TreeModel::Path(1);
		
		m_buffer = m_info_view.get_buffer();
		m_h_box.pack_start(m_tree_view,true,true);
		m_h_box.pack_start(m_info_view,true,true);
		m_h_box.set_spacing(5);

		m_v_box.pack_start(m_toolbar,false,false);
		m_v_box.pack_start(m_h_box,true,true);

		set_title("DDType");
		set_border_width(5);
		signal_delete_event().connect(sigc::mem_fun(*this,&MainWindow::on_destroy));
		add(m_v_box);
	}
	void MainWindow::construct_tree_view()
	{
		m_model_columns.add(m_col_name);
		m_ref_tree_store = Gtk::TreeStore::create(m_model_columns);
		SchemaManager::update_schemas();
		auto schemas = SchemaManager::schemas();
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
		m_current_path = path;
		Gtk::TreeModel::iterator iter = m_ref_tree_store -> get_iter(path);
		if(iter){
			m_buffer->set_text(SchemaManager::unit_data_path(path));
		}
	}
	void MainWindow::on_tree_row_expanded(const Gtk::TreeModel::iterator& iter, const Gtk::TreeModel::Path& path)
	{
		if(path.size() == 1)
		{
			m_tree_view.expand_all();
		}
	}
	void MainWindow::on_practise_button()
	{
		if(!SchemaManager::is_catalog(m_current_path))
		{
			std::cout<<m_current_path.to_string()<<std::endl;
			Glib::ustring path = SchemaManager::unit_data_path(m_current_path);
			WindowManager::shared_manager().show_practise_window(path);
		}
	}
	void MainWindow::on_test_button()
	{
		if(!SchemaManager::is_catalog(m_current_path))
		{
			WindowManager::shared_manager().show_test_window(SchemaManager::unit_data_path(m_current_path));
		}
	}
	bool MainWindow::on_destroy(GdkEventAny*)
	{
		iconify();
		return true;
	}
}
