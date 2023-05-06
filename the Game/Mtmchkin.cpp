#include "Mtmchkin.h"


static int geInputFromUser();
static void getName(std::string& playerName, std::string& playerJob);
static bool isValidPlayersNumbers(std::string& input, int min, int max);
static bool isNameIsValid(std::string& playerName);
static std::unique_ptr<Player> initializePlayer();
static void updatePlayersQueue(std::vector<std::unique_ptr<Player>>& players,int* index);
static bool isPlayerJobValid(const std::string& playerJob);
static std::unique_ptr<Card> initializeCard(std::string& cardName,const int line);


static int geInputFromUser()
{
    static const int MIN_PLAYERS_NUMBER = 2;
    static const int MAX_PLAYERS_NUMBER = 6;
    printEnterTeamSizeMessage();
    std::string input;
    getline(std::cin,input);
    while (!isValidPlayersNumbers(input, MIN_PLAYERS_NUMBER, MAX_PLAYERS_NUMBER))
    {
        getline(std::cin,input);
    }
    return stoi(input);
}


static void getName(std::string& playerName, std::string& playerJob)
{
    std::string input;
    getline(std::cin,input);
    const std::string SEPARATING_WORDS = " ";
    playerName = input.substr(0,input.find(SEPARATING_WORDS));
    while(!isNameIsValid(playerName))
    {
        printInvalidName();
        getline(std::cin,input);
        playerName = input.substr(0,input.find(SEPARATING_WORDS));
    }
    const std::string WORD_FINISH = "\n";
    playerJob = input.substr(playerName.length()+1,input.find(WORD_FINISH));
    while(!isPlayerJobValid(playerJob))
    {
        getName(playerName, playerJob);
    }
}

static bool isValidPlayersNumbers(std::string& input, int min, int max)
{
    if(input.length() != 1 || input[0] < std::to_string(min)[0]||input[0] > std::to_string(max)[0])
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        return false;
    }
    return true;
}


static bool isNameIsValid(std::string& playerName)
{
    static const int MAX_NAME_LEN =15;
    if(playerName.length()>MAX_NAME_LEN || playerName.size() <=0)
    {
        return false;
    }
    for (std::string::size_type i = 0; i <playerName.length() ; ++i)
    {
        if(!(playerName[i] >= 'a' && playerName[i] <= 'z') && !(playerName[i]>='A' && playerName[i]<='Z'))
        {
            return false;
        }
    }
    return true;
}

static std::unique_ptr<Player> initializePlayer()
{
    std::string playerName,playerJob;
    getName(playerName, playerJob);
    if(playerJob == "Warrior")
    {
        return std::unique_ptr<Warrior>(new Warrior(playerName));
    }else if(playerJob== "Healer"){
        return std::unique_ptr<Healer>(new Healer(playerName));
    }else {
        return std::unique_ptr<Ninja>(new Ninja(playerName));
    }
}


static void updatePlayersQueue(std::vector<std::unique_ptr<Player>>& players,int* index)
{
    int tmp = *index;
    std::vector<std::unique_ptr<Player>>::size_type i = tmp;

    const int HIGHEST_LEVEL = 10;
    if(players[i]->getLevel() == HIGHEST_LEVEL)
    {
        while(i > 0 && players[i-1]->getLevel()!=HIGHEST_LEVEL)
        {
            swap(players[i],players[i-1]);
            i--;
        }
        return;
    }
    if(players[i]->playerKilled())
    {
        for (i = tmp + 1; i != players.size(); i++)
        {
            if(!players[i]->playerKilled())
            {
                swap(players[i],players[i-1]);
                ++tmp;
            }
        }
        --(*index);
        return;
    }
}

static bool isPlayerJobValid(const std::string& playerJob)
{
    if(playerJob == "Warrior" || playerJob =="Healer" || playerJob =="Ninja"){
        return true;
    }else{
        printInvalidClass();
        return false;
    }
}

static std::unique_ptr<Card> initializeCard(std::string& cardName,const int line)
{
   if(cardName == "Mana"){
        return std::unique_ptr<Mana>(new Mana());
    }else if(cardName == "Gremlin"){
        return std::unique_ptr<Gremlin>(new Gremlin());
    }else if(cardName == "Dragon"){
       return std::unique_ptr<Dragon>(new Dragon());
    }else if(cardName== "Merchant"){
        return std::unique_ptr<Merchant>(new Merchant());
    }else if(cardName == "Treasure"){
       return std::unique_ptr<Treasure>(new Treasure());
   }else if(cardName == "Well"){
        return std::unique_ptr<Well>(new Well());
    }else if(cardName== "Witch"){
        return std::unique_ptr<Witch>(new Witch());
    }else if(cardName== "Barfight"){
        return std::unique_ptr<Barfight>(new Barfight());
    }else{
        throw DeckFileFormatError(line);
    }
}

Mtmchkin::Mtmchkin(const std::string &fileName): m_rounds(0)
{
    printStartGameMessage();
    std::ifstream cardsFiles(fileName);
    if(!cardsFiles)
    {
        throw DeckFileNotFound();
    }
    std::string cardName;
    int cardDeckSize =0;
    int line =0;

    while (getline(cardsFiles,cardName))
    {
        m_cardsDeck.push_back(move(initializeCard(cardName, ++line)));
        cardDeckSize++;
    }

    static const int MINIMUM_CARDS_NUM =5;
    if(cardDeckSize<MINIMUM_CARDS_NUM)
    {
        throw DeckFileInvalidSize();
    }

    int teamSize = geInputFromUser();
    int countPlayers =0;
    while(countPlayers < teamSize)
    {
        printInsertPlayerMessage();
        m_players.push_back(move(initializePlayer()));
        countPlayers++;
    }
}


void Mtmchkin::playRound()
{
    if(isGameOver()){
        return;
    }else{
        int index =0;
        printRoundStartMessage(m_rounds+1);
       for(std::vector<std::unique_ptr<Player>>::size_type i =0; i<m_players.size();i++)
       {
           if (m_players[i]->isActive())
           {
               printTurnStartMessage(m_players[i]->getName());
               m_cardsDeck.front()->playCard(*m_players[i]);
               if(m_players[i]->playerKilled())
               {
                   i--;
               }
               updatePlayersQueue(m_players, &index);
               m_cardsDeck.push_back(move(m_cardsDeck.front()));
               m_cardsDeck.pop_front();
           }
           index++;
       }
        m_rounds++;
        if(isGameOver())
        {
            printGameEndMessage();
        }
    }
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_rounds;
}

bool Mtmchkin::isGameOver() const
{
    for (const std::unique_ptr<Player>& itr : m_players)
    {
        if(itr->isActive())
        {
            return false;
        }
    }
    return true;
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int rank =0;
    for (const std::unique_ptr<Player>& itr : m_players)
    {
        printPlayerLeaderBoard(rank+1,*itr);
        rank++;
    }
}
