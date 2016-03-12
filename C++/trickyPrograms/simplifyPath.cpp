#include <iostream>
#include <stack>
#include <algorithm>

using std::cout; using std::endl;

std::string simplifyPath(std::string A) {
    std::string path;
    std::stack<char> pathStack;
    std::string::const_iterator it = A.begin();
    for(; it != A.end(); it++){
        char currentChar = *it;
        if(pathStack.empty()){
            pathStack.push(currentChar);
            continue;
        }
        if( currentChar == '.' && pathStack.top() == '.'){
            pathStack.pop();
            pathStack.pop();
            while(pathStack.top() != '/'){
                pathStack.pop();
            }
            continue;
        } else if ( currentChar == '/' && pathStack.top() == '/' ){
            continue;
        } else if ( currentChar == '/' && pathStack.top() == '.' ){
            pathStack.pop();
            continue;
        }
        pathStack.push(currentChar);
    }
    while( !pathStack.empty() ){
        path += pathStack.top();
        pathStack.pop();
    }
    std::reverse(path.begin(), path.end());
    return path;
}

int main(){
    std::string path = "/a/./b/../../c/";
     cout << simplifyPath(path) << endl;

    return 0;
}
