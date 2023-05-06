
#ifndef GERMLIN_H_
#define GERMLIN_H_
#include "battleCards.h"

class Gremlin: public BattleCards{
public:
    Gremlin();
    Gremlin(const Gremlin& germlin)=default;
    Gremlin& operator=(const Gremlin& germlin)=default;
    ~Gremlin()=default;
    void printInfo(std::ostream &os)const override;
    void applySpecialEffect(Player &player) override;
};


#endif
