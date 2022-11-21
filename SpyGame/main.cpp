
#include <iostream>
#include "AppWindow.h"


int main() 
{
	AppWindow app = AppWindow(L"fuck off", 300, 600);
	if (!app.init())
	{
		return 1;
	}
	while (app.isRun())
	{
		app.broadcast();
	}
	std::cout << "YOUR MAMA DONE" << std::endl;
	return 0;
}