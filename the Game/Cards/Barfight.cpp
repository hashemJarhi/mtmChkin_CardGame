#include "Barfight.h"
static const int DAMAGE = 10;

Barfight::Barfight(): Card("Barfight"),m_damage(DAMAGE)
{}

void Barfight::playCard(Player &player)
{
    printBarfightMessage(player.getType() == "Warrior");
    if(player.getType() != "Warrior")
    {
        player.injure(this->m_damage);
    }

}
