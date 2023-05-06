#include "Healer.h"

Healer::Healer(const std::string& name): Player(name),m_type("Healer") {}

void Healer::heal(const int raise)
{
    if(raise <= 0 || m_playerHP == m_playerMaxHP){
        return;
    }else{
        static const int HEALER_SPECIAL_FACTOR =2;
        m_playerHP += HEALER_SPECIAL_FACTOR * raise;
        if (m_playerHP > m_playerMaxHP)
        {
            m_playerHP = m_playerMaxHP;
        }
    }
}

void Healer::printInfo(std::ostream &os) const
{
    printPlayerDetails(os, this->getName(), m_type, this->m_playerLevel, this->m_playerForce, this->m_playerHP, this->m_moneyInPocket);
}
std::string Healer::getType() const
{
    return m_type ;
}