//
//  main_window.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "main_window.hpp"
#include <gtkmm.h>
#include <glibmm.h>
#include <iostream>

namespace DDType {
	MainWindow::MainWindow()
	{
		set_title("DDType");
		set_border_width(5);
		add(m_main_view);
		show_all();
	}

}
