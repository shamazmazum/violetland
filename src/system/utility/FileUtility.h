#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
//dirent for windows can be obtained at http://www.softagalleria.net/dirent.php
#include <dirent.h>

#ifndef FILEUTILITY_H_
#define FILEUTILITY_H_

class FileUtility {
private:
	std::string m_appPath, m_resPath, m_usrPath;
public:
	enum PathType
	{
		common = 0, image, anima, sound, music, user
	};
	FileUtility(char *argPath);
	static void truncateFullPathToDir(char *path);
	static bool copyFile(const char srcPath[], const char destPath[]);
	void traceResPath();
	void setFullResPath(std::string path);
	std::string getFullPath(PathType type, std::string resource);
	std::vector<std::string> getFilesFromDir(std::string dir);
	int getFilesCountFromDir(std::string dir);
};

#endif /* FILEUTILITY_H_ */