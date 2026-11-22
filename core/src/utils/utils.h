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
#ifndef CORE_SRC_UTILS_H
#define CORE_SRC_UTILS_H
#include <cstdint>
#include <string>

std::string readFile(std::string path);
std::string readLine(std::string path, uint64_t line);
uint64_t getLineCount(std::string path);
int RandomInt(int lower, int upper);
#endif