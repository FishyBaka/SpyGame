
#include <iostream>
#include "AppWindow.h"


int main() 
{
	AppWindow app;
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