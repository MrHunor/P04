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