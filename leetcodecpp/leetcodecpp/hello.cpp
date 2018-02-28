#include"stdafx.h"
#include<iostream>
#include<thread>
#include<vector>
#include<algorithm>

void job(unsigned i) {
	std::cout << "hello concurrent in job " << i << std::endl;
}

//int main()
//{
//	std::vector<std::thread> threads;
//	for (unsigned i = 0; i < 20; i++) {
//		threads.push_back(std::thread(job, i));
//	}
//	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
//	char c = getchar();
//	return 0;
//}