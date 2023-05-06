#include "Warrior.h"

Warrior::Warrior(const std::string& name): Player(name), m_type("Warrior"){}

int Warrior::attackPower() const
{
    static const int WARRIOR_FACTOR = 2;
    return WARRIOR_FACTOR * m_playerForce + m_playerLevel;
}

void Warrior::printInfo(std::ostream &os) const
{
    printPlayerDetails(os, this->getName(), m_type, m_playerLevel, m_playerForce, m_playerHP, m_moneyInPocket);
}
std::string Warrior::getType() const
{
    return m_type;
}