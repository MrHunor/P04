#ifndef CORE_INCLUDE_IMPOSTER_H
#define CORE_INCLUDE_IMPOSTER_H
#include <cstdint>
#include <iostream>
#include <vector>

class ImposterGame
{
  public:
    std::vector<std::string> players = {};
    uint8_t nImposters = -1;
    uint16_t guessTimeS = -1;
    std::vector<uint8_t> imposterIndex = {};
    std::string currentWord = "";
    std::string currentImposterTip = "";

    void calcGuessTime();

    void makeRound();

    void makeImposters();
};
#endif