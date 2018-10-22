#include <fstream>
#include <iostream>
#include <string>


int main(int argc, char* argv[]) {
    std::string filename = "../pdbs/1pru(1).txt";
    std::ifstream file("../pdbs/1pru(1).txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!\n";
        return -1;
    }

    std::string PDB;
    const std::string keyword1="DNA-BINDING";
    while (getline(file, PDB)) {
        if (PDB.find(keyword1) != std::string::npos) {
            std::cout <<"files containing 'DNA-BINDING' include: " <<filename << "\n";
            break;
        }
    }
    const std::string keyword2="RNA-BINDING";
    while (getline(file, PDB)) {
        if (PDB.find(keyword2) != std::string::npos) {
            std::cout << "files containing 'RNA-BINDING' include: " << filename << "\n";
            break;
        }
    }
}