

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string filename = "../pdbs/1arf.txt";
    // check that file was opened
    ifstream file("../pdbs/1arf.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!\n";
        return -1;
    }
    //search keyword
    const string keyword = "DNA BINDING";

    //read loop
    string PDBline;
    while (getline(file, PDBline)) {
        if (PDBline.find(keyword) != string::npos) {
            cout << filename << "\n";
            // Print name of file

        }
    }
}
