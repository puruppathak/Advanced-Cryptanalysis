/*
    Project name - Party1 stores files on a cloud server and later allows other Parties to retrieve (some of) them.
    This module does the authorization of the user and provides filename to download from cloud.
    
    Please refer README for more details about execution
    
    Authors - Ketan Ghotekar (kg1689)
              Puru Pathak    (ppp280)
*/

#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <openssl/md5.h>
#include <openssl/sha.h>

using namespace std;

void WriteStringtoFile(string hash, string fileName)
{
    std::ofstream write_file;
    write_file.open(fileName.c_str());
    
    if (write_file.is_open())
    {
        write_file << hash;
        write_file.close();
    }
    else cout << "Error creating file !";
    
}

string readFile(char* file)
{
        string line;
        std::ifstream fileName(file, fstream::binary);
    
        if (fileName.is_open())
        {
            if(!fileName.eof())
                getline(fileName, line); 
            fileName.close();
            return line;
        }
        else cout << "Error reading file !";
    
        return NULL;
}




string to_hex(unsigned char s) {
    stringstream ss;
    ss << hex << (int) s;
    return ss.str();
}   

string sha256(string line) {    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, line.c_str(), line.length());
    SHA256_Final(hash, &sha256);

    string output = "";    
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        output += to_hex(hash[i]);
    }
    return output;
}

int main(int argc, char* argv[])
 {
    
    if(argc<2)
    {
        cout<<"Usage is ./ghotekar-pathak-authorize filename.txt"<<endl;
        return 1;
    }
 
    string filename = readFile(argv[1]);
    string sha_result=sha256(filename);
    WriteStringtoFile(sha_result,"enc_filename.txt");
    cout << "enc_filename.txt has been generated successfully ! You can use this enc_filename.txt to download from the cloud."<<endl; 
    return 0;
}

