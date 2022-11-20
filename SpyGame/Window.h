#pragma once

#include <Windows.h>

class Window
{
public:
	//big 3
	Window();
	~Window();
	bool init();
	bool release();

	//
	bool broadCast();
	bool isRun();

	//EVENTS
	virtual void onCreate()=0;
	virtual void onUpdate()=0;
	virtual void onDestroy();


protected:
	HWND m_hwnd;
	bool m_is_run;
};

