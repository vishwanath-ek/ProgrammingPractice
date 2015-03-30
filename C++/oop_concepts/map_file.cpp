#include <iostream>
#include <fstream>
#include <cerrno>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>

const std::string file_path = "/home/vishwanath/Documents/test.txt";
typedef std::map<std::string, int> mapStringInt;

void
readFileFillMap( mapStringInt &words_count ){
    std::ifstream file_stream(file_path.c_str());
    if( file_stream.is_open() ){
        while( file_stream.good() ){
            std::string word;
            file_stream >> word;
            if( !word.empty() ){
                if( words_count.find(word) == \
                    words_count.end() ){
                    words_count.insert(std::make_pair(word, 1));
                } else {
                    words_count.insert(std::make_pair(word, ++(words_count[word])));
                }
            }
        }
    } else {
        std::cerr << "File Open Error.\n" << strerror(errno) << std::endl;
        exit(errno);
    }
}

void
printWordsCount(mapStringInt &words_count,\
mapStringInt::iterator &it_map){
    for(it_map = words_count.begin(); it_map != words_count.end(); ++it_map){
        std::cout << it_map->first << "----> " << it_map->second << std::endl;
    }

    return;
}

int
main(){
    mapStringInt words_count;
    mapStringInt::iterator it_map;

    readFileFillMap(words_count);
    printWordsCount(words_count, it_map);
    return 0;
}
