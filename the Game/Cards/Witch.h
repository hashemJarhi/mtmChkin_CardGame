
#ifndef WITCH_H_
#define WITCH_H_
#include "battleCards.h"

class Witch: public BattleCards{
public:
    Witch();
    Witch(const Witch& witch)=default;
    Witch& operator=(const Witch& witch)=default;
    ~Witch()=default;
    void printInfo(std::ostream &os)const override;
    void applySpecialEffect(Player &player) override;
};


#endif
