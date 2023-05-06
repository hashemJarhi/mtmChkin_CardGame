#include "battleCards.h"

BattleCards::BattleCards(const std::string &name,int force,int loot, int damage): Card(name),m_force(force),m_loot(loot),m_damage(damage) {}

void BattleCards::playCard(Player &player)
{
    if(player.attackPower() >= this->m_force)
    {
        printWinBattle(player.getName(),this->getName());
        player.increaseCoins(this->m_loot);
        player.addLevel();
    }else{
        printLossBattle(player.getName(),this->getName());
        applySpecialEffect(player);
    }
}