//
// Created by sam4p on 10/11/2018.
//


#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string filename = "1pru(1).txt";
    // check that file was opened
    ifstream file("1pru(1).txt");
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
