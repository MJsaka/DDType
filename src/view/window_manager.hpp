//
//  window_manager.hpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//
#ifndef window_manager_hpp
#define window_manager_hpp

#include <gtkmm.h>
#include <glibmm.h>
#include "main_window.hpp"
#include "practise_window.hpp"
#include "test_window.hpp"

namespace DDType 
{
	class WindowManager
	{
		private:
			WindowManager();
			WindowManager(const WindowManager&);
			~WindowManager();

			MainWindow* m_main_window;
			PractiseWindow* m_practise_window;
			TestWindow* m_test_window;
			static WindowManager* sm_manager;
		public:
			void show_main_window() const;
			void show_practise_window(const Glib::ustring path) const;
			void show_test_window(const Glib::ustring path) const;
			static const WindowManager& shared_manager();
	};
}

#endif
