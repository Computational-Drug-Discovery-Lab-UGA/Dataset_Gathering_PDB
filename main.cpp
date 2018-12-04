#include "common_includes.h"
#include "util.h"


int main(int argc, char *argv[]) {
  try{
    std::vector<std::string> files;
    if(argc < 2){//to do this in clion you need to go to run configurations and put directory path there
      std::cout<<"ERROR must specify directory as program argument"<<std::endl;
      exit(1);
    }
    std::string keyword1;
    std::string directory = argv[1];

    //something I made that needs to be tested if you want to use it
    //std::string parent_directory = getParentDirectory(directory);

    if(argc == 3){
      keyword1 = argv[2];
    }
    else{
      keyword1 = "DNA";
    }

    //cant remember if this works on windows. let me know
    std::string newDirectory = directory + "/" + keyword1;
    std::mkdir(newDirectory.c_str());

    parseDirectory(directory, files);

    int numFiles = (int) files.size();
    std::string currentFile = "";

    for(int i = 0; i < numFiles; ++i){

      //with vectors you can actually do something cool here
      //dont have to but you could do this
      //for(auto file = files.begin(); file != files.end(); ++file)
      //currentFile = *file;

      currentFile = files[i];
      std::ifstream file(currentFile);
      if(!file.is_open()){
        //probably want to keep moving and not throw an error
        std::cout<<"Failed to open file!"<<std::endl;
        continue; //will skip everything below and go to next value in for loop
      }

      std::string line = "";

      while(getline(file, line)){
        if(line.find(keyword1) != std::string::npos){
          //std::cout << "files containing 'DNA' include: " << currentFile << "\n";
          std::ifstream src(currentFile.c_str(), std::ios::binary);

          //std::string newDirPath = "/Users/jacknadaud/Desktop/PDBS/DNAPDB";
          //you should be creating the directory before this loop, so I put that at the top

          replaceAll(currentFile, std::string("324pdb"), std::string("DNAPDB"));
          std::ofstream dest(currentFile.c_str(), std::ios::binary);
          dest<<src.rdbuf();
          break;//this will get you out of the while loop going line by line
        }
        if(line.find("ATOM") != std::string::npos || line.find("HETATM") != std::string::npos){
          break;
          //this would mean that you are at coordinate information and if you make it here you havent found the keyword
        }
      }
    }


    //NOTE SOOOOO how would you do this for a list of keywords????
    //you would have another for loop inside of your while loop to check each line for each keyword

    //TODO make sure that you can create a directory within another directory and put files in there in the new newDirectory
    //TODO allow for multiple keywords
    //TODO parameterize ^^^
    //TODO MAYBE make this program find keywords that you find on specific lines

  }
  catch (const std::exception &e){
    std::cerr << "Caught exception: " << e.what() << '\n';
    std::exit(1);
  }
  catch (...){
    std::cerr << "Caught unknown exception\n";
    std::exit(1);
  }
}
