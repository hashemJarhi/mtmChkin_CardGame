#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <string>
#include <vector>
#include "Cards/Card.h"
#include <memory>
#include "Exception.h"
#include "Players/Warrior.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Player.h"
#include "Cards/Dragon.h"
#include "Cards/Barfight.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Cards/Witch.h"
#include <fstream>
#include <deque>
class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    Mtmchkin(const Mtmchkin& Mtm)=delete;
    Mtmchkin& operator=(const Mtmchkin& Mtm)=delete;

private:
    std::vector<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Card>> m_cardsDeck;
    int m_rounds;
};



#endif /* MTMCHKIN_H_ */
