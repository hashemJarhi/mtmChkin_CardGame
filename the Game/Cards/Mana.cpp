#include "Mana.h"
static const int POWER = 10;
Mana::Mana(): Card("Mana"), m_power(POWER)
{}

void Mana::playCard(Player &player)
{
    printManaMessage(player.getType() == "Healer");
    if(player.getType() == "Healer")
    {
        player.heal(this->m_power);
    }
}
