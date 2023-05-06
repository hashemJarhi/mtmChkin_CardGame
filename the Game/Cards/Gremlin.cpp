#include "Gremlin.h"

static const int GERMLIN_FORCE = 5;
static const int GERMLIN_LOOT = 2;
static const int GERMLIN_DAMAGE = 10;
Gremlin::Gremlin(): BattleCards("Gremlin", GERMLIN_FORCE, GERMLIN_LOOT, GERMLIN_DAMAGE)
{}

void Gremlin::printInfo(std::ostream &os) const
{
    printCardDetails(os,this->getName());
    printMonsterDetails(os,this->m_force,this->m_damage,this->m_loot);
    printEndOfCardDetails(os);
}

void Gremlin::applySpecialEffect(Player &player)
{
    player.injure(this->m_damage);
}
