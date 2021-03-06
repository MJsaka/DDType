/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2016 mjsaka <mjsaka@qq.com>
 * 
 * ddtype is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * ddtype is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.";
 */

#include <glibmm.h>
#include <gtkmm.h>
#include <iostream>
#include "view/window_manager.hpp"

#include "config.h"

int
main (int argc, char *argv[])
{
	Gtk::Main app(argc, argv);
	DDType::WindowManager::shared_manager().show_main_window();
	app.run();
	return 0;
}

