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

//directory of sample pdb folder /Users/jacknadaud/Desktop/PDBS/324pdb
//created a new directory with address /Users/jacknadaud/Desktop/PDBS/DNAPDB for new PDBS

void replaceAll(std::string& source, const std::string& from, const std::string& to) {
    std::string newString;
    newString.reserve(source.length());  // avoids a few memory allocations

    std::string::size_type lastPos = 0;
    std::string::size_type findPos;

    while(std::string::npos != (findPos = source.find(from, lastPos)))
    {
        newString.append(source, lastPos, findPos - lastPos);
        newString += to;
        lastPos = findPos + from.length();
    }

    // Care for the rest after last occurrence
    newString += source.substr(lastPos);

    source.swap(newString);
}

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

int main(int argc, char *argv[]) {

    std::vector<std::string> files;
    std::string directory = "/Users/jacknadaud/Desktop/PDBS/324pdb";
    parseDirectory(directory, files);

        int numFiles = (int) files.size();
        std::string currentFile = "";
        for (int i = 0; i < numFiles; ++i) {
            currentFile = files[i];
            std::ifstream file(currentFile);
            if (!file.is_open()) {
                std::cerr << "Failed to open file!\n";
            }
            const std::string keyword1 = "DNA";
            std::string pdb;
            while (getline(file, pdb)) {
                if (pdb.find(keyword1) != std::string::npos) {

                    //std::cout << "files containing 'DNA' include: " << currentFile << "\n";

                    std::string newDirPath = "/Users/jacknadaud/Desktop/PDBS/DNAPDB";
                    copyFile(directory, newDirPath);

                    return copyFile(argv[1], argv[2]) ? 0 : 1;




                    /*/  method below uses void replaceAll and changes filename
                         puts in new folder but new files are just empty pdbs

                     std::string newDirPath = "/Users/jacknadaud/Desktop/PDBS/DNAPDB";
                    replaceAll(currentFile, std::string("324pdb"), std::string("DNAPDB"));
                    std::ifstream src(currentFile.c_str(), std::ios::binary);
                    std::ofstream dest(currentFile.c_str(), std::ios::binary);
                    dest<<src.rdbuf();

                    /*/

                    /*/  method below similar to one in code, can't figure out

                    std::string currentFile = directory + "/" + files[i];
                    std::string newFileName = newDirPath + "/" + files[i];
                    std::cout << newFileName <<"\n";
                    std::ifstream src(currentFile.c_str(), std::ios::binary);
                    std::ofstream dest(newFileName.c_str(), std::ios::binary);
                    dest<<src.rdbuf();
                    /*/
                }
            }
        }
    }







