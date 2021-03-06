// testLogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "libLogger.h"
#include <math.h>
#include <conio.h>
#define PI_10000 31416
int main()
{
	std::cout << "testing on LogOut Function.... hit 'q' for quiting the test\n";
	unsigned int thread_id = 0;
	while (!_kbhit() || _getch() != 'q')
	{
		unsigned int t_startCPU = ::GetTickCount();
		unsigned int t_10000 = t_startCPU * 10000;
		double r = double(t_10000 % PI_10000) / double(10000); //r in [0, 2*PI)
		unsigned int t_durCPU = (sin(r)+1)*100;
		unsigned int t_durGPU = (cos(r)+1)*100;
		unsigned int t_endCPU = t_startCPU + t_durCPU;

		thread_id ++;
		LogItem item = { "glTestFunc", t_startCPU, t_endCPU, t_durCPU, t_durGPU, thread_id, 0, "dummieFile.cpp", 0 };
		LogOut(&item);
	}
	std::cout << thread_id;

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
