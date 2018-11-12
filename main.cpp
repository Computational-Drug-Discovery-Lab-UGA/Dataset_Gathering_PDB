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


//directory of sample pdb folder I used is /Users/jacknadaud/Desktop/324pdb

void parseDirectory(std::string dirPath, std::vector<std::string> &files) {
}
int main(int argc, char *argv[]) {
    std::vector<std::string> files;
    std::string dirPath = "/Users/jacknadaud/Desktop/324pdb";

    DIR *dir;
    struct dirent *in_file;
    if ((dir = opendir("/Users/jacknadaud/Desktop/324pdb")) != nullptr) {

        //std::string newdirectoryname;
        //mkdir( newdirectoryname.c_str())

        while ((in_file = readdir(dir)) != nullptr) {
            std::string currentFileName = in_file->d_name;
            if (currentFileName.find(".pdb") == std::string::npos &&
                currentFileName.find(".json") == std::string::npos)
                continue; //do we have any .json files or a reason to keep extension?
            currentFileName = dirPath + "/" + currentFileName;
            //files.push_back(currentFileName);

            std::cout<< currentFileName<< "\n";
            std::ifstream file(currentFileName);
            if (!file.is_open()) {
                std::cerr << "Failed to open file!\n";
                return -1;
            }

            const std::string keyword1 = "DNA";
            while (getline(file, currentFileName)) {
                if (currentFileName.find(keyword1) != std::string::npos) {
                    std::cout << "files containing 'DNA' include: " << currentFileName << "\n";
                    break;
                }
                /*/
                int numFiles = (int) files.size();
                std::string currentFile = "";
                for (int i = 0; i < numFiles; ++i) {
                    currentFile = files[i];}
                //*/

                /*/
                std::string currentFile = dirPath + "/" + files[i];
                std::string currentFileName = newDirPath + "/" +files[i];
                std::ifstream src(fileName.c_str(), std::ios::binary);
                std::ofstream dest(currentFileName.c_str(), std::ios::binary);
                dest<<src.rdbuf();
                //*/
            }
            closedir(dir);
        }
    } else {
        perror("");
        return EXIT_FAILURE;
    }

}