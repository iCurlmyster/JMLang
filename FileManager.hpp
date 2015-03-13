#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class FileManager
{

public:
	FileManager();
	~FileManager();

	std::string homeDirectory();
	std::string desktopDirectory();

	void createDirectory(std::string dir);
	void writeToFile(std::string file,std::string data);

	template<typename T>
	void writeToFile(std::string file, std::vector<T> data, std::string delim)
	{
		std::ofstream out_file (file);
		if (out_file.fail()) std::cout<< "File failed to open.\n";

		if (data[0] != NULL)
			out_file << data[0]->toString();
		for(int i = 1; i<data.size();i++)
		{
			if (data[i] != NULL)
				out_file << delim << data[i]->toString();
		}
		out_file << "\n";
		out_file.close();
	}

	std::vector<std::string> getFileData(std::string file);

};


#endif
