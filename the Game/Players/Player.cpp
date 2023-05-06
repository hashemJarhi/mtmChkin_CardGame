#include "Player.h"

static const int DEFUALT_MAX_HP =100;
static const int DEFUALT_FORCE =5;
static const int DEFUALT_COINS =10;
static const int DEFUALT_LEVEL =1;

Player::Player(const std::string& name): m_name(name)
                                        , m_moneyInPocket(DEFUALT_COINS)
                                        , m_playerMaxHP(DEFUALT_MAX_HP)
                                        , m_playerHP(DEFUALT_MAX_HP),
                                         m_playerLevel(DEFUALT_LEVEL),
                                         m_playerForce(DEFUALT_FORCE)
{}



void Player::addLevel()
{
    static const int MAX_LEVEL =10;
    if(this->m_playerLevel < MAX_LEVEL)
    {
        this->m_playerLevel++;
    }
}
int Player::attackPower() const
{
    return ((this->m_playerForce) + (this->m_playerLevel));
}
int Player::getLevel() const
{
    return this->m_playerLevel;
}

bool Player::isMaxLevel() const
{
    static const int MAX_LEVEL =10;
    return (this->m_playerLevel == MAX_LEVEL);
}

std::string Player::getName() const
{
    return this->m_name;
}

void Player::decreaseForce()
{
    if(this->m_playerForce > 0)
    {
        (this->m_playerForce)--;
    }
}

void Player::setHPToZero()
{
    this->m_playerHP =0;
}

int Player::returnMoney() const
{
    return this->m_moneyInPocket;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    player.printInfo(os);
    return os;
}

bool Player::isActive() const
{
    return (this->m_playerHP > 0 && !this->isMaxLevel());
}
void Player::increasePower(const int raise)
{
    if(raise <= 0 ){
        return;
    }else{
        this->m_playerForce += raise;
    }
}

void Player::heal(const int raise)
{
    if(raise <= 0 || this->m_playerHP == this->m_playerMaxHP){
        return;
    }else{
        if (this->m_playerHP + raise >= this->m_playerMaxHP){
            this->m_playerHP = m_playerMaxHP;
        }else{
            this->m_playerHP += raise;
        }
    }
}

void Player::injure(const int damage)
{
    if(this->m_playerHP <= 0 || damage <= 0)
    {
        return;
    }
    if((this->m_playerHP - damage) <= 0){
        this-> m_playerHP = 0;
    }else{
        this->m_playerHP -= damage;
    }
}

bool Player::playerKilled() const
{
    return (this->m_playerHP <= 0);
}

void Player::increaseCoins(int const money)
{
    if(money > 0)
    {
        this->m_moneyInPocket += money;
    }
}

bool Player::buy(const int price)
{
    if(price <= 0)
    {
        return true;
    }

    if(this->m_moneyInPocket < price){
        return false;
    }else{
        this->m_moneyInPocket -= price;
        return true;
    }
}
