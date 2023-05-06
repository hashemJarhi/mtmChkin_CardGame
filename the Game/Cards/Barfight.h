
#ifndef BARFIGHT_H_
#define BARFIGHT_H_
#include "Card.h"

class Barfight:public Card{
public:
    Barfight();
    Barfight(const Barfight& barFight)=default;
    Barfight& operator=(const Barfight& barFight)=default;
    ~Barfight()=default;
    void playCard(Player& player) override;
private:
    int m_damage;
};

#endif
