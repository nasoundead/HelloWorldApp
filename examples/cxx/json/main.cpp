#include <iostream>

#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

int main() {

    std::ifstream f("example.json");
    json data = json::parse(f);
    std::cout << data << std::endl;

    std::cout << data["data"] << std::endl;
    std::cout << data["happy"] << std::endl;
    return 0;
}