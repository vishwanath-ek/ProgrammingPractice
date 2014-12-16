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
    std::string word;
    while( !in.fail() && (in >> word) ){
        // Sort the words in alphabetical order to get a unique key
        // for anagrams
        const std::string signature = getSignature(word);
        final_map[signature].insert(word);
        //std::cout << signature <<std::endl;
    }
    return;
}

void
printMap(std::map<std::string,
         std::set<std::string> > &final_map){
    std::map<std::string, std::set<std::string> >::const_iterator it_map;
    std::set<std::string>::const_iterator it_set;
    for(it_map = final_map.begin(); it_map != final_map.end(); ++it_map){
        std::cout << it_map->first << ": ";
        for(it_set = (it_map->second).begin(); it_set != (it_map->second).end(); ++it_set){
            if( std::distance(it_set, (it_map->second).end()) > 1){                
                std::cout << *it_set <<", ";
            } else {
                std::cout << *it_set << std::endl;
            }
        }
    }
    return;
}

int
main(){
    // Create a map of string & a set of strings,
    // to store a unique set of anagrams ...
    std::map<std::string, std::set<std::string> > final_map;
    std::ifstream in;
    readFileAndMakeListOfAnagrams(final_map, in);
    printMap(final_map);
    //getMaxNumberOfAnagrams(final_map);

    return 0;
}
