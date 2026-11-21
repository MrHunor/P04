#ifndef CORE_SRC_UTILS_H
#define CORE_SRC_UTILS_H
#include <cstdint>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string>

std::string readFile(std::string path);
std::string readLine(std::string path, uint64_t line);
uint64_t getLineCount(std::string path);
#endif