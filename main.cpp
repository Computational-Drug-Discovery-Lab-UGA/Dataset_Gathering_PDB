#include <dirent.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <sys/stat.h>
#include <algorithm>
#include <iterator>

//directory of sample pdb folder /Users/jacknadaud/Desktop/324pdb

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

int main(int argc, char *argv[]) {

    std::vector<std::string> files;
    std::string directory = "/Users/jacknadaud/Desktop/324pdb";
    parseDirectory(directory, files);
    //while () {
        int numFiles = (int) files.size();
        std::string currentFile = "";
        for (int i = 0; i < numFiles; ++i) {
            currentFile = files[i];
        }
        std::ifstream file(currentFile);
        if (!file.is_open()) {
            std::cerr << "Failed to open file!\n";
            //return -1;
        }
        const std::string keyword1 = "DNA";
        while (getline(file, currentFile)) {
            if (currentFile.find(keyword1) != std::string::npos) {
                std::cout << "files containing 'DNA' include: " << currentFile << "\n";
                break;
            }
        }
    }
//}






/*/
        std::string currentFile = dirPath + "/" + files[i];
        std::string currentFileName = newDirPath + "/" +files[i];
        std::ifstream src(fileName.c_str(), std::ios::binary);
        std::ofstream dest(currentFileName.c_str(), std::ios::binary);
        dest<<src.rdbuf();


        //*/
