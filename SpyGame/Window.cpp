#include "Window.h"
#include <iostream>

//Window* window=nullptr;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//GetWindowLong(hwnd,)

	switch (msg)
	{
	case WM_CREATE:
	{
		// Event fired when the window is created
			// collected here..
		Window* window = (Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;
		// .. and then stored for later lookup
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);

		window->onCreate();
		break;
	}

	case WM_DESTROY:
	{
		// Event fired when the window is destroyed
		Window* window = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		window->onDestroy();
		::PostQuitMessage(0);
		break;
	}


	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return NULL;
}

Window::Window(LPCWSTR name, int width, int height)
{
	this->_name = name;
	
	this->_width = width;
	this->_height = height;

	//Setting up WNDCLASSEX object
	WNDCLASSEX wc;
	{
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		wc.hInstance = NULL;

		wc.lpszClassName = this->_name;
		wc.lpszMenuName = L"";
		wc.style = NULL;
		wc.lpfnWndProc = &WndProc;
	}
	this->_wc = &wc;
	this->_m_hwnd = NULL;
	this->_m_is_run = false;
}

Window::~Window()
{

}


bool Window::init()
{

	if (!::RegisterClassEx(this->_wc)) // If the registration of class will fail, the function will return false
	{
		std::cout << "this cancer";
		return false;
	}
		//Creation of the window
	this->_m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, this->_name, this->_name, WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, CW_USEDEFAULT, this->_width, this->_height,
		NULL, NULL, NULL, this);

	//if the creation fail return false
	if (!this->_m_hwnd)
	{
		std::cout << "now this cancer";
		return false;
	}
	//show up the window
	::ShowWindow(this->_m_hwnd, SW_SHOW);
	::UpdateWindow(this->_m_hwnd);




	//set this flag to true to indicate that the window is initialized and running
	this->_m_is_run = true;



	return true;
}

bool Window::broadcast()
{
	MSG msg;


	while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	this->onUpdate();

	Sleep(1);

	return true;
}


bool Window::release()
{
	this->_m_is_run = false;
	//Destroy the window
	if (!::DestroyWindow(this->_m_hwnd))
		return false;

	return true;
}

bool Window::isRun()
{
	return this->_m_is_run;
}

void Window::onDestroy()
{
	this->_m_is_run = false;
}