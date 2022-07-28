//
// Created by stepan7 on 13.07.22.
//

#include "LineHelper.h"
#include "../blocks/Creator.h"
#include <regex>
#include <iostream>


std::vector<std::string> LineHelper::SplitStringByTokens(const std::string& s) {
    std::vector<std::string> elems;
    std::regex re(R"(^(\d+)\s*([-+=*\/])\s*(\S+)\s+(.+)$)");
    std::cmatch result;

    if (std::regex_match(s.c_str(), result, re)) {
        for (int i = 1; i < result.size(); i++) {
            elems.push_back(result[i]);
        }
    }

    return elems;
}

void SplitStringToVector(std::string s, std::vector<std::string> &v){

    std::string temp = "";
    for(char i : s){

        if(i==' '){
            v.push_back(temp);
            temp = "";
        }
        else{
            temp.push_back(i);
        }

    }
    v.push_back(temp);

}

std::unique_ptr<Block> LineHelper::ParseLineToBlock(const std::vector<std::string> &splitLine) {
    int id = std::stoi(splitLine[0]);
    const std::string &command = splitLine[2];
    const std::string &args = splitLine[3];
    std::vector<std::string> argsVector;
    SplitStringToVector(args, argsVector);

    auto t = Creator::mapper(command)->FactoryMethod(id, argsVector);

    return nullptr;
}
