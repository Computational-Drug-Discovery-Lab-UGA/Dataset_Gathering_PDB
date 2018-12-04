void replaceAll(std::string& source, const std::string& from, const std::string& to);

//copyFile is unused now
bool copyFile(std::string SRC, std::string DEST);

void parseDirectory(std::string dirPath, std::vector<std::string> &files);

std::string getParentDirectory(std::string directory);
