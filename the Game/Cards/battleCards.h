
#ifndef MTMCHKIN_CPP_BATTLECARDS_H
#define MTMCHKIN_CPP_BATTLECARDS_H
#include "Card.h"


class BattleCards : public Card{
public:
    BattleCards(const std::string &name,int force,int loot, int damage);
    BattleCards(const BattleCards& battleCard)=default;
    BattleCards& operator=(const BattleCards& battleCard)=default;
    ~BattleCards()=default;
    void printInfo(std::ostream &os)const override =0;
    void playCard(Player& player) override;
    virtual void applySpecialEffect(Player &player) = 0;
protected:
    int m_force;
    int m_loot;
    int m_damage;
};



#endif //MTMCHKIN_CPP_BATTLECARDS_H
