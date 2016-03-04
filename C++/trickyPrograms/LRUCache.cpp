#include <iostream>
#include <algorithm>
#include "LRU.h"

using std::cout; using std::endl;

void LRUCache::lookupAndInsert(int page){
    if( (count == maxCount) &&
        (lookupMap.find(page) == lookupMap.end()) ){
        // Remove LRU from list
        int listPage = lruList.back();
        lruList.pop_back();
        lookupMap.erase(listPage);
        lruList.push_front(page);
        listItr itr = std::find(lruList.begin(), lruList.end(), page);
        lookupMap.insert(std::make_pair(page, itr)); 
        return;
    }

    if(lookupMap.find(page) == lookupMap.end()){
        lruList.push_front(page);
        listItr itr = std::find(lruList.begin(), lruList.end(), page);
        lookupMap[page] = itr;
        ++count;
        return;
    }

    listItr itr = lookupMap[page];
    lruList.push_front(page);
    lruList.erase(itr);

    return;
}

void LRUCache::printMapList() {
    mapItr itrMap = lookupMap.begin();
    cout << "---- MAP ----" << endl;
    for(; itrMap != lookupMap.end(); ++itrMap){
        cout << itrMap->first << " - " << *(itrMap->second) << endl;
    }

    cout << "---- LIST ----" << endl;
    for(listItr itr = lruList.begin(); itr != lruList.end(); ++itr){
        cout << *itr << " ";
    }
    cout << endl;
}

int main(){
    LRUCache cache;
    cache.lookupAndInsert(5);
    cache.lookupAndInsert(6);
    cache.lookupAndInsert(7);
    cache.lookupAndInsert(8);
    cache.lookupAndInsert(8);
    cache.lookupAndInsert(7);

    cache.printMapList();
    return 1;
}
