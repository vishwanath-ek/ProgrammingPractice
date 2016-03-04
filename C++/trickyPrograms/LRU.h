#ifndef LRU_H
#define LRU_H

#include <list>
#include <map>

typedef std::map<int, std::list<int>::iterator>::iterator mapItr;
typedef std::list<int>::iterator listItr;
class LRUCache {
    public:
        LRUCache (int restrictCount = 3): maxCount(restrictCount), count(0){}

        void lookupAndInsert(int page);
        void printMapList();
    private:
        unsigned int maxCount;
        unsigned int count;
        std::map<int, std::list<int>::iterator> lookupMap;
        std::list<int> lruList; // keep front as MRU and back as LRU
};

#endif
