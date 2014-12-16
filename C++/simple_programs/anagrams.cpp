#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>

const std::string FILE_NAME = "anagrams.txt";

std::string
getSignature(std::string word){
    for(unsigned int i = 0; i < word.length() - 1; i++){
        for(unsigned int j = i+1; j < word.length(); j++){
            if(word[i] > word[j]){
                char t = word[i];
                word[i] = word[j];
                word[j] = t;
            }
        }
    }
    return word;
}

void
readFileAndMakeListOfAnagrams(std::map<std::string,
                std::set<std::string> > &final_map,
                std::ifstream &in){
    in.open(FILE_NAME.c_str());
    while( !in.fail() && !in.eof() ){
        std::string word;
        in >> word;
        const std::string signature = getSignature(word);
        std::cout << signature <<std::endl;
    }
}

int
main(){
    // Create a map of string & a set of strings,
    // to store a unique set of anagrams ...
    std::map<std::string, std::set<std::string> > final_map;
    std::ifstream in;
    readFileAndMakeListOfAnagrams(final_map, in);

    return 0;
}
