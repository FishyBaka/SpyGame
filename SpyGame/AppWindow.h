#pragma once
#include "Window.h"

class AppWindow: public Window
{
public:
	AppWindow(LPCWSTR name = L"Fuck", int width = 1020, int height = 800): 
		Window(name, width, height)
	{}
	// Inherited via Window
	virtual void onCreate() override;

	virtual void onUpdate() override;

	virtual void onDestroy() override;

};

