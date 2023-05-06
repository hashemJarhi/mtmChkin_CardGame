
#ifndef PLAYER_H_
#define PLAYER_H_
#include "string"
#include "iostream"

class Player{
public:
    Player(const std::string& name);
    Player(const Player& P)=default;
    Player& operator=(const Player& P)=default;
    virtual ~Player()=default;

    virtual int attackPower() const;
    std::string getName()const;
    void addLevel();
    int getLevel()const;
    bool isMaxLevel()const;
    void increasePower(const int raise);
    virtual void heal(const int raise);
    void injure(const int damage);
    bool playerKilled() const;
    virtual void increaseCoins(const int money);
    bool buy(const int amount);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    virtual void printInfo(std::ostream& os)const=0;
    void decreaseForce();
    void setHPToZero();
    int returnMoney()const;
    bool isActive() const;
    virtual std::string getType() const= 0;

private:
    std::string m_name;
protected:
    int m_moneyInPocket,m_playerMaxHP, m_playerHP,m_playerLevel ,m_playerForce;
};



#endif
