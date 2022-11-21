#pragma once

#include <Windows.h>
#include <string>


class Window
{
public:
	//big 3
	Window(LPCWSTR name=L"Fuck", int width=1020, int height=800);
	~Window();
	bool init();
	bool release();

	bool broadcast();
	bool isRun();

	//EVENTS
	virtual void onCreate() {};
	virtual void onUpdate() {};
	virtual void onDestroy();

protected:
	HWND _m_hwnd;
	WNDCLASSEX* _wc;
	bool _m_is_run;
	LPCWSTR _name;
	int _width;
	int _height;
};

