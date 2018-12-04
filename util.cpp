#include "util.h"
//directory of sample pdb folder with 324 pdb files  /Users/jacknadaud/Desktop/PDBS/324pdb
//created a new directory with address  /Users/jacknadaud/Desktop/PDBS/DNAPDB  where pdbs are moved

void replaceAll(std::string& source, const std::string& from, const std::string& to) {
    std::string newString;
    newString.reserve(source.length());

    std::string::size_type lastPos = 0;
    std::string::size_type findPos;

    while(std::string::npos != (findPos = source.find(from, lastPos)))
    {
        newString.append(source, lastPos, findPos - lastPos);
        newString += to;
        lastPos = findPos + from.length();
    }
    newString += source.substr(lastPos);

    source.swap(newString);
}

//copyFile is unused now
bool copyFile(std::string SRC, std::string DEST) {
    std::ifstream src(SRC, std::ios::binary);
    std::ofstream dest(DEST, std::ios::binary);
    dest << src.rdbuf();
    return src && dest;
}

void parseDirectory(std::string dirPath, std::vector<std::string> &files) {
    DIR *dir;
    if (nullptr == (dir = opendir(dirPath.c_str()))){
        printf("Error : Failed to open input directory %s\n",dirPath.c_str());
        exit(-1);
    }
    struct dirent* in_file;
    while((in_file = readdir(dir)) != nullptr){
        std::string currentFileName = in_file->d_name;
        if(currentFileName.find(".pdb") == std::string::npos &&
           currentFileName.find(".json") == std::string::npos) continue;
        currentFileName = dirPath + "/" + currentFileName;
        files.push_back(currentFileName);
    }
    closedir(dir);
}

std::string getParentDirectory(std::string directory){
  return directory.substr(directory.length() - (directory.find_last_of("/")+1));
  //need to test
}
