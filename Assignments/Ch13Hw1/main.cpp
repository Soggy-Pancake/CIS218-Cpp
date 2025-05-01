/*String Search
Write a program that asks the user for the name of a file and a string to search for. 
The program will search the file for all occurrences of the specified string and display all lines that contain the string. 
After all occurrences have been located, the program should report the number of times the string appeared in the file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

bool getFile(fstream &stream){
    string filename;

    while(true){
        printf("Enter file name (type '0' to exit): ");
        getline(cin, filename);

        if(filename == "0"){
            return false;
        }

        stream.open(filename, ios::in);
        if(stream.good() && !stream.fail()){
            return true;
        }
        printf("File not found! (cwd: %s )\n", filesystem::current_path().string().c_str());
    }
    return false;
}

int subSearch(string &mainString, string &substring){
    if(mainString.length() < substring.length())
        return 0;

    int count = 0;

    for(int i = 0; i < mainString.length() - substring.length() + 1; i++){
        if(mainString[i] == substring[0]){
            for(int j = 1; j < substring.length(); j++){
                if(mainString[i + j] != substring[j]){
                    break;
                }
                if(j == substring.length() - 1){
                    count++;
                }
            }
        }
    }

    return count;
}

int main(){

    fstream file;
    int lineNum;

    if(getFile(file)){

        string line, search;
        int found, occurances = 0;

        printf("Substring to search for: ");
        getline(cin, search);

        printf("\nlineNum  | line\n");

        while(!file.eof()){

            ++lineNum;
            getline(file, line);

            found = subSearch(line, search);

            if(found > 0){
                printf("%-8d | %s\n", lineNum, line.c_str());
                occurances += found;
            }
        }

        printf("\nFound occurances: %d\n", occurances);
    }

    file.close();
    return 0;
}