//
//  practise_window.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "practise_window.hpp"
#include "window_manager.hpp"
#include <sigc++/sigc++.h>

namespace DDType
{
	PractiseWindow::PractiseWindow()
	{
		set_title("Practise");
		set_border_width(5);
		signal_delete_event().connect(sigc::mem_fun(*this,&PractiseWindow::on_destroy));
	}
	void PractiseWindow::finish()
	{
	}
	void PractiseWindow::match_success()
	{
	}
	void PractiseWindow::match_fail()
	{
	}
	void PractiseWindow::tip()
	{
	}
	bool PractiseWindow::on_destroy(GdkEventAny*)
	{
		hide();
		WindowManager::shared_manager().show_main_window();
		return true;
	}
	sigc::signal<void,Glib::ustring> PractiseWindow::signal_key_pressed()
	{
	}
}
