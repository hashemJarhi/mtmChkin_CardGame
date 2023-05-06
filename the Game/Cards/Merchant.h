
#ifndef MERCHANT_H_
#define MERCHANT_H_
#include "Card.h"

class Merchant:public Card{
public:
    Merchant();
    Merchant(const Merchant& merchant)=default;
    Merchant& operator=(const Merchant& merchant)=default;
    ~Merchant()=default;
    void playCard(Player& player) override;
};

#endif
