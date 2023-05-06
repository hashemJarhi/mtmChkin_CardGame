#include "Treasure.h"

static const int MONEY = 10;
Treasure::Treasure(): Card("Treasure"), m_treasure(MONEY)
{}

void Treasure::playCard(Player &player)
{
    printTreasureMessage();
    player.increaseCoins(this->m_treasure);
}
