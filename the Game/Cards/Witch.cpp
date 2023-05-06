#include "Witch.h"
static const int WITCH_FORCE = 11;
static const int WITCH_LOOT = 2;
static const int WITCH_DAMAGE = 10;

Witch::Witch(): BattleCards("Witch",WITCH_FORCE,WITCH_LOOT,WITCH_DAMAGE){}

void Witch::printInfo(std::ostream &os) const
{
    printCardDetails(os,this->getName());
    printMonsterDetails(os,this->m_force,this->m_damage,this->m_loot);
    printEndOfCardDetails(os);
}

void Witch::applySpecialEffect(Player &player)
{
    player.injure(this->m_damage);
    player.decreaseForce();
}