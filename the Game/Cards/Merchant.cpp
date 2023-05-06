#include "Merchant.h"

static const int NOTHING = 0;
static const int BUFF = 2;
static const int POTION =1;

static int getInputFromUser(int min, int max);
static bool isValidNumber(std::string& input,int min,int max);
static void dontBuy(Player &player);
static void buyPotion(Player &player);
static void buyBuff(Player &player);


static bool isValidNumber(std::string& input,int min,int max)
{

    if(input.length() != 1 ||input[0] >  std::to_string(max)[0] || input[0] < std::to_string(min)[0])
    {
        return false;
    }
    return true;
}

static int getInputFromUser(int min, int max)
{
    std::string input;
    getline(std::cin,input);
    while (!isValidNumber(input, min, max))
    {
        printInvalidInput();
        getline(std::cin,input);
    }
    return stoi(input);
}
static void buyBuff(Player &player)
{
    static const int BUFF_PRICE = 10;
    static const int RAISE = 1;
    if(!player.buy(BUFF_PRICE)){
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout, player.getName(), BUFF, NOTHING);
    }else{
        printMerchantSummary(std::cout, player.getName(), BUFF, BUFF_PRICE);
        player.increasePower(RAISE);
    }
}

static void buyPotion(Player &player)
{
    static const int POTION_PRICE = 5;
    static const int RAISE = 1;
    if(!player.buy(POTION_PRICE)){
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout, player.getName(),POTION, NOTHING);
    }else{
        printMerchantSummary(std::cout, player.getName(), POTION, POTION_PRICE);
        player.heal(RAISE);
    }
}

static void dontBuy(Player &player)
{
    printMerchantSummary(std::cout, player.getName(), NOTHING, NOTHING);
}

Merchant::Merchant(): Card("Merchant")
{}

void Merchant::playCard(Player &player)
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(), player.returnMoney());
    int userInput = getInputFromUser(NOTHING, BUFF);
    if(userInput == BUFF){
        buyBuff(player);
    }else if (userInput == POTION){
        buyPotion(player);
    }else{
        dontBuy(player);
    }
}


