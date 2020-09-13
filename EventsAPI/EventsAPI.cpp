// EventAPI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <windows.h>

HANDLE h = INVALID_HANDLE_VALUE;
HANDLE h2 = INVALID_HANDLE_VALUE;
std::vector<int> data;

DWORD WINAPI ClientTread(LPVOID arg)
{
	SetEvent(h2);
	DWORD res = WaitForSingleObject(h, INFINITE);
	ResetEvent(h);

	std::cout << data[0] << data[1];

	return 0;
}

DWORD WINAPI ServerTread(LPVOID arg)
{
	DWORD res = WaitForSingleObject(h2, INFINITE);

	data.push_back(100500);
	data.push_back(100501);

	SetEvent(h);
	ResetEvent(h2);

	return 0;
}
int main()
{
	h = CreateEventA(0, FALSE, FALSE, "MyClient");
	h2 = CreateEventA(0, FALSE, FALSE, "MyServer");

	CreateThread(0, 0, ClientTread, 0, 0, 0);
	CreateThread(0, 0, ServerTread, 0, 0, 0);

	Sleep(10000);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
