//
//  window_manager.cpp
//  ddtype
//  created by mjsaka on 2016/11/2.
//  Copyright © 2016 mjsaka. All rights reserved.
//

#include "window_manager.hpp"
#include <iostream>
namespace DDType
{
	WindowManager* WindowManager::sm_manager;
	WindowManager::WindowManager()
	{
		m_main_window = new MainWindow;
		m_practise_window = new PractiseWindow;
		m_test_window = new TestWindow;
	}
	WindowManager::WindowManager(const WindowManager&){}
	WindowManager::~WindowManager()
	{
		delete m_main_window;
		delete m_practise_window;
		delete m_test_window;
	}
	const WindowManager& WindowManager::shared_manager()
	{
		if(!sm_manager)
		{
			sm_manager = new WindowManager;
		}
		return *sm_manager;
	}
	void WindowManager::show_main_window() const
	{
		std::cout<<"show_main_window"<<std::endl;
		m_main_window->show_all();
	}
	void WindowManager::show_practise_window(const Glib::ustring path) const
	{
		std::cout<<"show_practise_window"<<std::endl;
		m_main_window->hide();
		m_practise_window->show_all();
	}
	void WindowManager::show_test_window(const Glib::ustring path) const
	{
		std::cout<<"show_test_window"<<std::endl;
		m_main_window->hide();
		m_test_window->show_all();
	}
}
