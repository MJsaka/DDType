//
//  test_window.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "test_window.hpp"
#include "window_manager.hpp"
#include "../controller/type_controller.hpp"
#include <sigc++/sigc++.h>

namespace DDType
{
	TestWindow::TestWindow()
	{
		set_title("Test");
		set_border_width(0);
		signal_delete_event().connect(sigc::mem_fun(*this,&TestWindow::on_destroy));
	}
	void TestWindow::show(Glib::ustring path)
	{
		m_path = path;	
		TypeController::shared_controller().set_data_path(path);
		TypeController::shared_controller().set_interface(this);
		show_all();
	}
	void TestWindow::finish()
	{
	}
	void TestWindow::match_success()
	{
	}
	void TestWindow::match_fail()
	{
	}
	void TestWindow::tip()
	{
	}
	void TestWindow::retry_miss()
	{
	}
	bool TestWindow::on_destroy(GdkEventAny*)
	{
		WindowManager::shared_manager().show_main_window();
		hide();
		return true;
	}
}
