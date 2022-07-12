#include <iostream>
#include <fstream>
#include "config//Config.h"

int main(){
    try{
        Config config("conf.txt");
        config.ParseConfig();
    }catch (const std::ifstream::failure& e) {
        std::cout << "Exception opening/reading file";
    }
    return 0;
}
