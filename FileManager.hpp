#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

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
	void writeToFile(std::string file, std::vector<T> data)
{
	std::ofstream out_file (file);
	for(int i = 0; i<data.size();i++)
	{
		out_file << data[i] << "\n";
	}
	out_file.close();
}

	std::vector<std::string> getFileData(std::string file);

};


#endif
