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
#include "../include/imposter.h"

#include "../defs.h"
#include "utils/utils.h"
void ImposterGame::calcGuessTime()
{
    guessTimeS = players.size()*IMPOSTER_PLAYER_TO_TIME_CONSTANT;
}
void ImposterGame::makeRound()
{
    std::string line = readLine("IMPOSTER_DEFAULT_WORDLIST",
                                RandomInt(0, getLineCount("IMPOSTER_DEFAULT_WORDLIST")-1));
    size_t commaI = line.find(',');
    currentWord = line.substr(0, commaI);
    currentImposterTip = line.substr(commaI + 1);
    makeImposters();
    calcGuessTime();
}

void ImposterGame::makeImposters()
{
    imposterIndex.clear();
    uint8_t created = 0;
    while (created < nImposters)
    {
        uint8_t index = RandomInt(0, players.size()-1);
        if (std::find(imposterIndex.begin(), imposterIndex.end(), index) !=
            imposterIndex.end())
            continue; // this index is already present in the array, so we have to skip
                      // this iteration
        imposterIndex.push_back(index);
        created++;
    }
}