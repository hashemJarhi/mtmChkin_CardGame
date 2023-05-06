
#ifndef HEALER_H_
#define HEALER_H_

#include "Player.h"
#include "../utilities.h"

class Healer: public Player{
public:
    Healer(const std::string& name);
    Healer(const Healer& P)=default;
    Healer& operator=(const Healer& P)=default;
    ~Healer()override =default;
    void heal(const int raise) override;
    void printInfo(std::ostream &os) const override;
    std::string getType() const override;
private:
    std::string m_type;
};



#endif
