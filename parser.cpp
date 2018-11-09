//
// Created by jack nadaud on 11/9/18.
//

#include <dirent.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdlib.h>
#include <vector>
//directory of sample pdb folder I used is /Users/jacknadaud/Desktop/324pdb
//this directory name will be different on your computers, so change it when you run it
//some things are left as comments that are still being worked on or used for reference, don't delete
//this won't run because both it and main have a main function now

int main(int argc, char* argv[]) {

    //void parseDirectory(std::string dirPath, std::vector<std::string> &files)
    std::vector<std::string> files;
    std::string dirPath = "/Users/jacknadaud/Desktop/324pdb";

    DIR *dir;
    struct dirent *in_file;

    if ((dir = opendir("/Users/jacknadaud/Desktop/324pdb")) != nullptr) {

        while ((in_file = readdir(dir)) != nullptr) {
            std::string currentFileName = in_file->d_name;
            if (currentFileName.find(".pdb") == std::string::npos &&
                currentFileName.find(".json") == std::string::npos) continue; //do we have any .json files or a reason to keep extension?
            currentFileName = dirPath + "/" + currentFileName;
            files.push_back(currentFileName);
            int numFiles = (int) files.size();
            std::string currentFile="";
            for(int i = 0; i < numFiles; ++i){
                currentFile=files[i];
            }
        }
        closedir(dir);
    } else {
        perror("");
        return EXIT_FAILURE;
    }
}