// Created by Kilian
// Basic Rock Paper Scissor with 2 Player Mode or Computer and 2 Options between String and Number

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm> // für std::transform

enum struct Result {
    Player_1_Wins,
    Player_2_Wins,
    Draw
};

enum struct Item {
    Paper,
    Scissors,
    Rock
};


Item read_item(int player) {
    int playeritem(0);
    std::cout << "Player " << player << ": (1) paper, (2) scissors (3) rock:" << std::endl;
    std::cin >> playeritem;
    std::cout << std::endl;
    switch (playeritem) {
        case 1: return Item::Paper;
        case 2: return Item::Scissors;
        case 3: return Item::Rock;
        default: return Item::Rock;
    }
}

Item read_item_item(int player) {
    std::string input;
    std::cout << "Player " << player << ": Choose one (paper, scissors, rock): ";
    std::cin >> input;

    // Convert input to lower case
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (input == "paper") return Item::Paper;
    if (input == "scissors") return Item::Scissors;
    if (input == "rock") return Item::Rock;

    // Fallback (optional)
    std::cout << "Invalid input. Defaulting to Rock.\n";
    return Item::Rock;
}

Item random_item() {
    int r = rand() % 3 + 1;
    switch (r) {
        case 1: std::cout << "Computer says: Paper!" << std::endl; return Item::Paper;
        case 2: std::cout << "Computer says: Scissors!" << std::endl; return Item::Scissors;
        case 3: std::cout << "Computer says: Rock!" << std::endl; return Item::Rock;
        default: std::cout << "Computer says: Rock but Error!" << std::endl; return Item::Rock;
    }
}

Result play_items(Item i1, Item i2) {

    if (i1 == i2) {
        return Result::Draw;
    }

    if(i1 == Item::Paper) {
        if(i2 == Item::Scissors)
        return Result::Player_2_Wins;
        else
        return Result::Player_1_Wins;
    }

    if(i1 == Item::Scissors ) {
        if(i2 == Item::Paper)
        return Result::Player_1_Wins;
        else
        return Result::Player_2_Wins;
    }

    if(i1 == Item::Rock ) {
        if(i2 == Item::Paper)
        return Result::Player_2_Wins;
        else
        return Result::Player_1_Wins;
    }


}

int main() {
    srand(time(NULL));

    int scorePlayer1 = 0;
    int scorePlayer2 = 0;
    int Playermode(0);
    int rounds(0);
    bool player2human;

    std::cout << "Play against a computer (1) or 2 player mode (2)?" << std::endl;
    std::cin >> Playermode;
    std::cout << std::endl;
    std::cout << "How many rounds?" << std::endl;
    std::cin >> rounds;

    if(Playermode == 2) {
        player2human = true;
    }

    if(player2human == true) {
        std::cout << "Player 2 is human" << std::endl;
    }

    for (int playrounds = 1; playrounds <= rounds ; playrounds++) {

        std::cout << "*** Round " << playrounds << " of " << rounds << " ***" << std::endl;

        Item i1 = read_item(1);
        Item i2 = player2human ? read_item(2) : random_item();
        Result res = play_items(i1, i2);
        switch (res) {
            case Result::Player_1_Wins: std::cout<< "Player 1 (You) wins the round!" << std::endl; ++scorePlayer1; break;
            case Result::Player_2_Wins: std::cout<< "Player 2 wins the round!" << std::endl; ++scorePlayer2; break;
            case Result::Draw: std::cout<< "Draw" << std::endl; break;
            default: std::cout<< "Error" << std::endl; break;
        }
        std::cout << "Current score: " << scorePlayer1 << " - " << scorePlayer2 << std::endl;

        if ( playrounds == rounds) {
            if (scorePlayer1 > scorePlayer2) {
                std::cout << "*** Final result: player 1 wins! ***" << std::endl;
            }
            else if (scorePlayer1 < scorePlayer2) {
                std::cout << "*** Final result: player 2 wins! ***" << std::endl;
            }
            else if (scorePlayer1 == scorePlayer2) {
                std::cout << "*** Final result: draw game.... ***" << std::endl;
            }
        }
    }
}

