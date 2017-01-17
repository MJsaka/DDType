//
//  test_window.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "test_window.hpp"
#include "window_manager.hpp"
#include <sigc++/sigc++.h>

namespace DDType
{
	TestWindow::TestWindow()
	{
		set_title("Test");
		set_border_width(5);
		signal_delete_event().connect(sigc::mem_fun(*this,&TestWindow::on_destroy));
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
	bool TestWindow::on_destroy(GdkEventAny*)
	{
		hide();
		WindowManager::shared_manager().show_main_window();
		return true;
	}
	sigc::signal<void,Glib::ustring> TestWindow::signal_key_pressed()
	{
	}
}
