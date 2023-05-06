
#ifndef WELL_H_
#define WELL_H_
#include "Card.h"

class Well: public Card{
public:
    Well();
    Well(const Well& well)=default;
    Well& operator=(const Well& well)=default;
    ~Well()=default;
    void playCard(Player& player) override;
private:
   int m_fall;
};

#endif
