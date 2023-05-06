#include "Dragon.h"

static const int DRAGON_FORCE = 25;
static const int DRAGON_LOOT = 1000;
Dragon::Dragon(): BattleCards("Dragon",DRAGON_FORCE,DRAGON_LOOT,DRAGON_FORCE)
{}

void Dragon::printInfo(std::ostream &os) const
{
    printCardDetails(os,this->getName());
    printMonsterDetails(os,this->m_force,this->m_force,this->m_loot,true);
    printEndOfCardDetails(os);
}

void Dragon::applySpecialEffect(Player &player)
{
    player.setHPToZero();
}