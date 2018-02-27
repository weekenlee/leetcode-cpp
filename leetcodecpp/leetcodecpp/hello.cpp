#include "stdafx.h"
#include<iostream>
#include<thread>

void job() {
	std::cout << "hello concurrent \n";
}

int main()
{
	std::thread t(job);
	t.join();
	char c = getchar();
	return 0;
}