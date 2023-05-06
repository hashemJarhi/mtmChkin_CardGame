#include "../Mtmchkin.h"


int main()
{
    const int MAX_NUMBER_OF_ROUNDS = 100;
    try {
        Mtmchkin game("deck.txt");
        while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS)
        {
            game.playRound();
            game.printLeaderBoard();
        }
    }catch (const DeckFileNotFound& badFile){
        std::cerr << badFile.what() << std::endl;
    }catch(const DeckFileFormatError& badFormat) {
        std::cerr << badFormat.what() << std::endl;
    }catch(const DeckFileInvalidSize& badSize){
        std::cerr << badSize.what() << std::endl;
    }catch(const std::bad_alloc& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}