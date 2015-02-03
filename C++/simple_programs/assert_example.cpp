#include <cstdio>
#define NDEBUG
#include <cassert>

int
main(){
    int i = 0;
    assert(i <= 0);
    printf("This is after assert i <= 0, value of i is %d\n", i);
    assert(i < 0);
    printf("This is after assert i < 0, value of i is %d\n", i);

    return 0;
}
