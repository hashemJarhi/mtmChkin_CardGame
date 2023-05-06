#include "Ninja.h"

Ninja::Ninja(const std::string& name): Player(name), m_type("Ninja") {}

void Ninja::increaseCoins(const int raise)
{
    static const int NINJA_SPECIAL_FACTOR = 2;
    if(raise > 0)
    {
        m_moneyInPocket += NINJA_SPECIAL_FACTOR * raise;
    }
}

void Ninja::printInfo(std::ostream &os) const
{
    printPlayerDetails(os, this->getName(), m_type, m_playerLevel, m_playerForce, m_playerHP, m_moneyInPocket);
}

std::string Ninja::getType() const
{
    return m_type ;
}