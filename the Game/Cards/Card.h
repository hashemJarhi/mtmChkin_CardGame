
#ifndef CARD_H_
#define CARD_H_
#include <string>
#include "iostream"
#include "../utilities.h"
#include "../Players/Player.h"


class Card{
public:
    Card(const std::string& name);
    Card(const Card& P)=default;
    Card& operator=(const Card& P)=default;
    virtual ~Card()=default;
    std::string getName() const;
    friend std::ostream& operator<<(std::ostream& os, Card& card);
    virtual void printInfo(std::ostream& os) const;
    virtual void playCard(Player& player)=0;
private:
    std::string m_name;
};

#endif
