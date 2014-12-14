#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

typedef map<string, int> string_map;
typedef map<char, int> char_map;
/*
 * This program reads input from a file and makes a map
 * of the word and the frequency of its occurance.
 * Also a vector is used for the same functionality for 
 * storing unique words by reading all words into vector
 * and later processing it to make it unique.
 */

void
populate_string_map(ifstream &in, usual_map &string_occurance){

}

int
main(){
    ifstream in; ofstream out;
    string_map string_occurance;
    char_map char_occurance;

    in.open("readfile.txt");
    out.open("unique.txt");

    populate_string_map(in, string_occurance);
    
    in.close();
    out.close();
    return 0;
}
