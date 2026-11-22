/*
 *   P04 - A android party-game libary.
 *   Copyright (C) 2026  MrHunor
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.(root/LICENSE)  If not, see
 *   <https://www.gnu.org/licenses/>.
 */
#include <cstdint>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string>
#include <random>

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

std::mt19937 getRandomGen()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    return gen;
}

int RandomInt(int lower, int upper)
{
    std::uniform_int_distribution<int> dist(lower, upper);
    auto gen = getRandomGen();
    return dist(gen);
}