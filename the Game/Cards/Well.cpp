#include "Well.h"
static const int FALL_DAMAGE = 10;
Well::Well(): Card("Well"),m_fall(FALL_DAMAGE)
{}

void Well::playCard(Player &player)
{
    printWellMessage(player.getType()=="Ninja");
    if(player.getType()!="Ninja")
    {
        player.injure(this->m_fall);
    }
}
