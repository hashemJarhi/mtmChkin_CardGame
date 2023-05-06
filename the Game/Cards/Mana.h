
#ifndef MANA_H_
#define MANA_H_
#include "Card.h"

class Mana: public Card{
public:
    Mana();
    Mana(const Mana& mana)=default;
    Mana& operator=(const Mana& mana)=default;
    ~Mana()=default;
    void playCard(Player& player) override;
private:
    int m_power;
};

#endif
