
#ifndef DRAGON_H_
#define DRAGON_H_
#include "battleCards.h"

class Dragon : public BattleCards{
public:
    Dragon();
    Dragon(const Dragon& dragon)=default;
    Dragon& operator=(const Dragon& dragon)=default;
    ~Dragon()=default;
    void printInfo(std::ostream &os)const override;
    void applySpecialEffect(Player &player) override;
};


#endif
