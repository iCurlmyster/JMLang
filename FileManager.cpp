#include "FileManager.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <fstream>
#if defined (__APPLE__) || defined (__linux) || defined (__unix) || defined (__posix)
	#include <sys/stat.h>
	const std::string HOME_PATH = getenv("HOME");
	#define MKDIR_FAILED 0
	const std::string PATH_DELIMETER = "/";
#elif defined (__WIN32) || defined (_WIN64)
	#include <direct.h>
	const std::string HOME_PATH = getenv("HOMEDRIVE") + getenv("HOMEPATH");
	#define MKDIR_FAILED 0
	const std::string PATH_DELIMETER = "\\";
#else
	const std::string HOME_PATH = "";
	#define MKDIR_FAILED 1
#endif

FileManager::FileManager(){}

FileManager::~FileManager(){}

std::string FileManager::homeDirectory()
{
	if (HOME_PATH != "") return HOME_PATH;
	return "";
}
std::string FileManager::desktopDirectory()
{
	if(HOME_PATH != "") return HOME_PATH + PATH_DELIMETER + "Desktop";
	return "";
}

void FileManager::createDirectory(std::string dir)
{
	if(!MKDIR_FAILED)
	{
		#if defined (__APPLE__) || defined (__linux) || defined (__unix) || defined (__posix)

		if((mkdir(dir.c_str(),0777)))
			std::cout<<"Directory creation failed."<<std::endl;

		#elif defined (__WIN32) || defined (_WIN64)

		if((_mkdir(dir.c_str())))
			std::cout<<"Directory creation failed."<<std::endl;

		#endif
	}
}

void FileManager::writeToFile(std::string file,std::string data)
{
	std::ofstream out_file (file);
	if (!out_file.fail()) {
		out_file << data;
		out_file.close();
	}
	else {
		std::cout<<"Error opening file.\n";
	}
}

std::vector<std::string> FileManager::getFileData(std::string file)
{
	std::vector<std::string> data;
	std::string str = "";
	std::ifstream in_file (file);
	while(!in_file.eof())
	{
		str = "";
		std::getline(in_file,str);
		data.push_back(str);
	}
	in_file.close();
	return data;
}
