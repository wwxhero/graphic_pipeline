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
	unsigned int n = 0;
	unsigned int fps = 0;
	unsigned int t = ::GetTickCount();
	while (!_kbhit() || _getch() != 'q')
	{
		unsigned int t_prime = ::GetTickCount();
		unsigned int t_startCPU = t_prime;
		unsigned int t_10000 = t_startCPU * 10000;
		double r = double(t_10000 % PI_10000) / double(10000); //r in [0, 2*PI)
		unsigned int t_durCPU = (sin(r)+1)*100;
		unsigned int t_durGPU = (cos(r)+1)*100;
		unsigned int t_endCPU = t_startCPU + t_durCPU;

		thread_id ++;
		LogItem item = { "glTestFunc", t_startCPU, t_endCPU, t_durCPU, t_durGPU, thread_id, fps, "dummieFile.cpp", 0 };
#ifdef _LOG_FILE_
		LogOut(&item);
#else
		std::cout << item.func
			<< "," << item.tmStartCPU
			<< "," << item.tmEndCPU
			<< "," << item.tmDurCPU
			<< "," << item.tmDurGPU
			<< "," << item.idThread
			<< "," << item.idProcess
			<< "," << item.filePath
			<< "," << item.nLine << std::endl;
#endif
		n ++;
		if (t_prime - t > 1000)
		{
			fps = n;
			n = 0;
			t = t_prime;
		}
	}
	std::cout << "Total number of log items is "<< thread_id << std::endl;

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
