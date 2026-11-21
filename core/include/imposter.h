#include <cstdint>
#include <iostream>
#include <vector>


class ImposterGame {
   public: 
   std::vector<std::string> players={};//name, imposter?
   uint8_t nImposters = -1;
   uint16_t guessTimeS=-1;
   uint8_t imposterIndex=1;

   void calcGuessTime();

};
