#pragma once

#include <string>
#include <vector>

namespace TabulaRasa
{
class IOManager
{
public:
    static bool ReadFileToBuffer(const std::string& filePath, std::vector<unsigned char>& buffer);
};
}


