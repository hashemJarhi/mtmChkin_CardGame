
#ifndef TREASURE_H_
#define TREASURE_H_
#include "Card.h"
class Treasure:public Card{
public:
    Treasure();
    Treasure(const Treasure& treasure)=default;
    Treasure& operator=(const Treasure& treasure)=default;
    ~Treasure()=default;
    void playCard(Player& player) override;
private:
    int m_treasure;
};



#endif
