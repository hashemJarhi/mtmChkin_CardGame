#include "Card.h"

Card::Card(const std::string &name):m_name(name) {}

std::ostream& operator<<(std::ostream& os, Card& card)
{
    card.printInfo(os);
    return os;
}

void Card::printInfo(std::ostream &os) const
{
    printCardDetails(os,this->m_name);
    printEndOfCardDetails(os);
}

std::string Card::getName() const
{
    return m_name;
}
