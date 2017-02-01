//
//  practise_window.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "practise_window.hpp"
#include "window_manager.hpp"
#include "../controller/type_controller.hpp"
#include <sigc++/sigc++.h>
#include <iostream>

namespace DDType
{
	PractiseWindow::PractiseWindow():
		m_table(10,10,true),
		m_entry_alignment(Gtk::ALIGN_CENTER,Gtk::ALIGN_CENTER,0)
	{
		set_title("Practise");
		set_border_width(0);

		m_entry_buffer = m_entry.get_buffer();
		m_entry.set_alignment(Gtk::Align::ALIGN_CENTER);
		m_entry_buffer->signal_inserted_text().connect(sigc::mem_fun(*this,&PractiseWindow::on_insert));
		m_entry_alignment.add(m_entry);

		m_v_box.pack_start(m_table,true,true);
		m_v_box.pack_start(m_entry_alignment,false,false,30);
		m_v_box.set_border_width(5);

		add(m_v_box);
		set_can_focus(false);
		signal_delete_event().connect(sigc::mem_fun(*this,&PractiseWindow::on_destroy));
	}
	void PractiseWindow::show(Glib::ustring path)
	{
		std::cout<<"PractiseWindow::show(Glib::ustring)"<<std::endl;
		m_path = path;	
		TypeController::shared_controller().set_data_path(m_path);
		TypeController::shared_controller().set_interface(this);
		show();
	}
	void PractiseWindow::show()
	{
		fill_grid();
		m_entry_buffer->set_text("");
		show_all();
	}
	void PractiseWindow::fill_grid()
	{
		for(auto pl : m_labels)
		{
			delete pl;
		}
		m_labels = std::list<Gtk::Label*>();
		std::cout<<"PractiseWindow::fill_grid()"<<std::endl;
		auto targets = TypeController::shared_controller().targets();
		auto target = targets.begin();
		int left = 0;
		int top = 0;
		while(target!=targets.end() && left<10 && top<10)
		{
			int width = target->size();
			if(left + width > 10)
			{
				left = 0;
				top++;
			}
			//std::cout<<"left:"<<left<<"\ttop:"<<top<<"\t"<<*target<<std::endl;
			Gtk::Label* label = new Gtk::Label(*target,Gtk::Align::ALIGN_CENTER);
			m_labels.push_back(label);
			m_table.attach(*label,left,left+width,top,top+1);
			target++;
			if(left + width == 10)
			{
				left = 0;
				top++;
			}else{
				left += width;
			}
		}
		m_current_label = m_labels.begin();
	}
	void PractiseWindow::finish()
	{
		std::cout<<"finish"<<std::endl;
		close();
	}
	void PractiseWindow::match_success()
	{
		std::cout<<"match_success"<<std::endl;
		m_entry_buffer->set_text("");
		(**m_current_label).set_text("");
		m_current_label++;
		if(m_current_label == m_labels.end())
		{
			show();
		}
	}
	void PractiseWindow::match_fail()
	{
		std::cout<<"match_fail"<<std::endl;
		m_entry_buffer->set_text("");
		Glib::ustring mark = "<span foreground=\"red\">" + (**m_current_label).get_text() + "</span>";
		(**m_current_label).set_markup(mark);
		m_current_label++;
		if(m_current_label == m_labels.end())
		{
			show();
		}
	}
	void PractiseWindow::tip()
	{
		std::cout<<"tip"<<std::endl;
	}
	void PractiseWindow::retry_miss()
	{
		std::cout<<"retry_miss"<<std::endl;
		show();
	}
	bool PractiseWindow::on_destroy(GdkEventAny*)
	{
		WindowManager::shared_manager().show_main_window();
		hide();
		return true;
	}
	void PractiseWindow::on_insert(guint pos, const gchar* str, guint n_chars)
	{
		std::cout<<"on_insert:"<<m_entry_buffer->get_text()<<std::endl;
		m_signal_key_pressed.emit(m_entry_buffer->get_text());
	}
}
