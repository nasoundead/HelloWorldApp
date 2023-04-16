#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
using std::cout;
using std::endl;

int main() {
    std::string res;
    res = system("python3 test.py");
    cout << res << endl;
    return 0;
}