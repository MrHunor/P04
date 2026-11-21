#include <cstdint>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

std::string readFile(std::string path)
{
    std::string retval;
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file.");
    std::string line;
    while (getline(file, line))
    {
        retval += line;
    }
    file.close();
    return retval;
}

std::string readLine(std::string path, uint64_t line)
{
    std::string retval;
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file.");
    std::string lineBuff;
    uint64_t lineI = 0;
    while (getline(file, lineBuff))
    {
        if (lineI == line)
        {
            retval = lineBuff;
            break;
        }
        lineI++;
    }
    return retval;
}

uint64_t getLineCount(std::string path)
{
    uint64_t retval = 0;
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file.");
    std::string lineBuff;
    while (getline(file, lineBuff))
    {
        if (retval == std::numeric_limits<uint64_t>::max() - 1)
            throw std::runtime_error("Failed to increse line counter; out of bounds.");
        retval++;
    }
    return retval;
}