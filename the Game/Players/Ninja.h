
#ifndef NINJA_H_
#define NINJA_H_
#include "Player.h"
#include "../utilities.h"

class Ninja: public Player{
public:
    Ninja(const std::string& name);
    Ninja(const Ninja& P)=default;
    Ninja& operator=(const Ninja& P)=default;
    ~Ninja()override =default;
    void increaseCoins(const int raise) override;
    void printInfo(std::ostream &os) const override;
    std::string getType() const override;
private:
    std::string m_type;
};





#endif
