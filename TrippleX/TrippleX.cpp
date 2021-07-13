#include <iostream> //Calls external code libary to be used
#include <cstdlib>  //Inicialised random number generator
#include <ctime>    // Calls ability to use time

void PrintIntroduction()
{
    std::cout << "\n\n          c,_.--.,y\n             7 a.a(\n           (   ,_Y)\n           :  '---;\n       ___.'|.  - (\n     .'\""
                 ""
                 "S,._'--'_2..,_\n     |    ':::::=:::::  \n     .     f== ;-,---.' T\n      Y.   r,-,_/_      |\n      |:/___.---' '---./\n      |'`             )\n       /             ,\n       ':;,.________.;L\n       /  '---------' |\n       |              /\n       L---'-,--.-'--,-'\n        T    /   /   Y\n        |   Y    ,   |\n        |   /    (   |\n        (   )     /,_L\n        7-./      )  `,\nsnd    /  _(      '._  /\n     '---'           '--'\n";
    std::cout << "Shriek has been improsoned by Lord Farquaad...\nTo get out he must use his head instead of his brawn to unlock the doors to the prioson..."; //Prints to terminal (\n breakes line)
    std::cout << std::endl;                                                                                                                                    //std::endl breaks line
}

bool bPlayGame(int Difficulty)
{

    //Generates the Random Number for the code
    int FirstCode = rand() % Difficulty + Difficulty;
    int SecondCode = rand() % Difficulty + Difficulty;
    int ThridCode = rand() % Difficulty + Difficulty;

    //Sum of 3 parts of the code
    const int CodeSum = FirstCode + SecondCode + ThridCode;
    // Multiples the 3 parts of the code together.
    const int CodeProduct = FirstCode * SecondCode * ThridCode; //Const means we dont want to change the vairable later in the code

    //Print Sum and Product to terminal
    std::cout << std::endl;
    std::cout << "The security level for this door is " << Difficulty;
    std::cout << "\nShrek looks at the number lock and see scratched into the door...\n";
    std::cout << "You have ... attemps until the gards will know whats going on";
    std::cout << "\n+ There are 3 numbers in the code";
    std::cout << "\n+ The Codes add-up to: " << CodeSum;
    std::cout << "\n+ The Codes Multiply's to give: " << CodeProduct << std::endl;

    //For Testing Purposes Only
    std::cout << FirstCode << std::endl
              << SecondCode << std::endl
              << ThridCode << std::endl;
    //Decalre Varable for players guess to be held in
    int PlayerGuessFirstCode, PlayerGuessSecondCode, PlayerGuessThridCode;

    //Get Players Guess
    std::cout << "What is the 3 number code:\n";
    std::cin >> PlayerGuessFirstCode >> PlayerGuessSecondCode >> PlayerGuessThridCode;

    //Create Sum and Product of Players Guesses
    int GuessSum = PlayerGuessFirstCode + PlayerGuessSecondCode + PlayerGuessThridCode;
    int GuessProduct = PlayerGuessFirstCode * PlayerGuessSecondCode * PlayerGuessThridCode;

    //Is player guess correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {

        std::cout << "\nClick, Click, Click, Clunk\nYou hear the bolt of the door retract and the door opens\nQuick Run through!!\n\n\n";
        return true;
    }
    else
    {

        std::cout << "\nClick, Click, Click, Nothing.\nThe numbers you input was wrong try again and see if you can open the door\n\n\n";
        return false;
    }
}

int main() //Main Function
{

    srand(time(NULL)); // Create new random set of numbers based on the time of day

    int LevelDifficulty = 1;
    int const MaxLevel = 5;
    int PlayerLives = 3;

    PrintIntroduction(); // Call Introduction

    while (LevelDifficulty <= MaxLevel && PlayerLives > 0) //Loop Game until passes Max Difficulty and PlayerLives is not 0
    {

        bool bLevelComplete = bPlayGame(LevelDifficulty);

        std::cin.clear();  // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        else
        {
            --PlayerLives;
        }
    }

    std::cout << "You rush through the door to find you are free, Well Done its time to go back you your swamp.";

    return 0;
}