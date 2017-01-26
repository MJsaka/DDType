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
#include "../controller/type_controller.hpp"
#include <gtkmm.h>
#include <glibmm.h>
#include <iostream>
#include <sigc++/sigc++.h>

namespace DDType {

	MainWindow::MainWindow()
	{
		m_practise_button = Gtk::ToolButton("Practise");
		m_practise_button.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::on_practise_button));
		m_test_button = Gtk::ToolButton("Test");
		m_test_button.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::on_test_button));

		m_h_button_box.pack_start(m_practise_button);
		m_h_button_box.pack_start(m_test_button);
		//m_h_button_box.get_style_context()->add_class("linked");
		m_h_button_box.get_style_context()->context_save();
		m_actionbar.set_center_widget(m_h_button_box);
		m_headerbar.set_custom_title(m_actionbar);
		m_headerbar.set_show_close_button(true);
		
		construct_tree_view();
		m_current_path = Gtk::TreeModel::Path(1);
		
		m_buffer = m_info_view.get_buffer();
		m_h_box.pack_start(m_tree_view,true,true);
		m_h_box.pack_start(m_info_view,true,true);
		m_h_box.set_spacing(5);

		m_v_box.pack_start(m_headerbar,false,false);
		m_v_box.pack_start(m_h_box,true,true);

		set_title("DDType");
		set_border_width(0);
		set_default_icon_name("ddtype");
		add(m_v_box);
		signal_delete_event().connect(sigc::mem_fun(*this,&MainWindow::on_destroy));
	}
	void MainWindow::construct_tree_view()
	{
		m_model_columns.add(m_col_name);
		m_ref_tree_store = Gtk::TreeStore::create(m_model_columns);
		auto schemas = SchemaManager::shared_manager().schemas();
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
			m_buffer->set_text(SchemaManager::shared_manager().unit_data_path(path));
		}
	}
	void MainWindow::on_tree_row_expanded(const Gtk::TreeModel::iterator& iter, const Gtk::TreeModel::Path& path)
	{
		if(path.size() == 1)
		{
			m_tree_view.expand_all();
		}
	}
	void MainWindow::on_practise_button() const
	{
		if(!SchemaManager::shared_manager().is_catalog(m_current_path))
		{
			Glib::ustring path = SchemaManager::shared_manager().unit_data_path(m_current_path);
			WindowManager::shared_manager().show_practise_window(path);
		}
	}
	void MainWindow::on_test_button() const
	{
		if(!SchemaManager::shared_manager().is_catalog(m_current_path))
		{
			Glib::ustring path = SchemaManager::shared_manager().unit_data_path(m_current_path);
			WindowManager::shared_manager().show_test_window(path);
		}
	}
	bool MainWindow::on_destroy(GdkEventAny*)
	{
		iconify();
		return true;
	}
}
