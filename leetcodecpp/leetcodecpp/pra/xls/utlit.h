
#pragma   once  
#include <Windows.h>
#include <string>
#include <functional>
#include <iostream>
#include <vector>

//windows 遍历目录
static int runpath(const std::string& Path, std::function<void(const std::string&,const std::string&)> f)
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
				runpath(szFile, f);
			}
		}
		else
		{
			//找到文件，处理之
			std::string fname = Path + "\\" + FindFileData.cFileName;
			f(fname, FindFileData.cFileName);

		}
	} while (FindNextFile(hFind, &FindFileData));

	FindClose(hFind);

	return 0;
}


static std::vector<std::string> split(std::string strtem, char a)
{
	std::vector<std::string> strvec;

	std::string::size_type pos1, pos2;
	pos2 = strtem.find(a);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		strvec.push_back(strtem.substr(pos1, pos2 - pos1));

		pos1 = pos2 + 1;
		pos2 = strtem.find(a, pos1);
	}
	strvec.push_back(strtem.substr(pos1));
	return strvec;
}

