#pragma once

#include <Windows.h>
#include <string>


class Window
{
public:
	//big 3
	Window(std::string name="cancer", int width=1020, int height=800);
	~Window();
	bool init();
	bool release();

	bool broadcast();
	bool isRun();

	//EVENTS
	virtual void onCreate()=0;
	virtual void onUpdate()=0;
	virtual void onDestroy();

protected:
	HWND _m_hwnd;
	bool _m_is_run;
	std::string _name;
	int _width;
	int _height;
};

