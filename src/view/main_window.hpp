//
//  main_window.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef main_window_h
#define main_window_h
#include <glibmm.h>
#include <gtkmm.h>
#include "main_view.hpp"
#include "practise_view.hpp"
#include "test_view.hpp"

namespace DDType{
	class MainWindow : public Gtk::Window
	{
		public:
			MainWindow();
		private:
			MainView m_main_view;
			PractiseView m_practise_view;
			TestView m_test_view;
		protected:
	};
}
#endif
