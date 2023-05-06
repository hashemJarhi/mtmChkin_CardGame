

#ifndef FIGHTER_H_
#define FIGHTER_H_
#include "Player.h"
#include "../utilities.h"

class Warrior: public Player{
public:
     Warrior(const std::string& name);
    Warrior(const Warrior& P)=default;
    Warrior& operator=(const Warrior& P)=default;
    ~Warrior()override =default;
    int attackPower() const override;
    void printInfo(std::ostream &os) const override;
    std::string getType() const override;
private:
    std::string m_type;
};




#endif
