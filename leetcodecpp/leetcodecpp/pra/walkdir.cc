// hellocmd.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#undef UNICODE
#include <windows.h>
#include <string>
#include <iostream>


std::ostream& nl(std::ostream& os) {
	return os << "\n";
}


//windows 遍历目录
int runpath(const std::string&  Path)
{
	std::string szFind = Path + "\\*.*";
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = FindFirstFile(szFind.c_str(), &FindFileData);
	if (INVALID_HANDLE_VALUE == hFind)
		return -1;

	do
	{
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (strcmp(FindFileData.cFileName, ".") != 0 && strcmp(FindFileData.cFileName, "..") != 0)
			{
				//发现子目录，递归之
				std::string szFile = Path + "\\" + FindFileData.cFileName;
				runpath(szFile);
			}
		}
		else
		{
			//找到文件，处理之
			std::string fname = FindFileData.cFileName;
			if (fname.find("tabula") != -1) {
				std::cout << Path << "\\" << fname << std::endl;
			}

		}
	} while (FindNextFile(hFind, &FindFileData));

	FindClose(hFind);

	return 0;
}

int main()
{
	std::cout << "hello world" << nl;

	std::string path = "D:";
	runpath(path);

	std::string endword;
	std::cin >> endword;
    return 0;
}

