#include <iostream>
#include "play.hpp"

std::string grid[9] = {" ", " ", " "," ", " ", " "," ", " ", " ",};
int player = 2; 
int position = 0; 

void introduction(){

    std::cout << "Press enter when ready to play \n";
    std::cin.ignore();

    std::cout << "Player 1 : x\n";
    std::cout << "Player 2 : o\n";

    std::cout << "\n";

    std::cout << "Here is the 3x3 grid used for the game:\n\n";
    std::cout << "     |     |      \n";
    std::cout << "  1  |  2  |  3   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  4  |  5  |  6   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  7  |  8  |   9  \n";
    std::cout << "     |     |      \n\n";

    std::cout << "\n";

}

void draw(){

    std::cout << "     |     |      \n";

    std::cout << "  " << grid[0] << "  |  " << grid[1] << "  |  " << grid[2] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << grid[3] << "  |  " << grid[4] << "  |  " << grid[5] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << grid[6] << "  |  " << grid[7] << "  |  " << grid[8] << "\n";
    std::cout << "     |     |      \n";

    std::cout << "\n";

}

bool grid_filled(){

    bool filled = true;

    for (int i = 0; i < 9; i++){

        if (grid[i] == " "){

            filled =false;
        }
    
    }

    return filled; 

}

bool check_winner(){

    bool win = false; 

    // rows 
    if ( grid[0] == grid[1] and grid[1] == grid[2] and grid[0] != " "){
        win = true; 
    }  
    else if ( grid[3] == grid[4] and grid[4] == grid[5] and grid[3] != " "){
        win = true; 
    }  
    else if ( grid[6] == grid[7] and grid[7] == grid[8] and grid[6] != " "){
        win = true; 
    }  

    //columns
    else if ( grid[0] == grid[3] and grid[3] == grid[6] and grid[0] != " "){
        win = true; 
    }
    else if ( grid[1] == grid[4] and grid[4] == grid[7] and grid[1] != " "){
        win = true; 
    }  
    else if ( grid[2] == grid[5] and grid[5] == grid[8] and grid[2] != " "){
        win = true; 
    }      

    //diagonals 
    else if ( grid[0] == grid[4] and grid[4] == grid[8] and grid[0] != " "){
        win = true; 
    } 
    else if ( grid[2] == grid[4] and grid[4] == grid[6] and grid[2] != " "){
        win = true; 
    } 

    return  win;

}

void change_player(){

    if ( player == 1){

        player++;
    }
    else{
        player--;
    }
}

void set_position(){



    std::cout << "It is the turn of Player " << player << "\n";
    std::cout << "Please enter a  number between 1 and 9 \n";

   while( !(std::cin >> position)){
        std::cout << "Please enter a  number between 1 and 9 \n"; 
        std::cin.clear();
        std::cin.ignore();
    }

    while (grid[position - 1] != " "){
        std::cout << "Oh no this position is already filled! Please select another location:";
        std::cin >> position;
    }

    if (player == 1){
        grid[position - 1] = "x";
    }
    else if ( player == 2){
        grid[position - 1] = "o";
    }
    
}

void play_turn(){

    // need to alternate between the players
    // check if grid is filled or not OR if one player has won
    // if not player should play

    while ( check_winner() == false and grid_filled() == false ){

        change_player();
        set_position();
        draw();

    }

    
}

void end_game(){


    if (check_winner()){
        std::cout << "We have a winner! Congrats Player" << player << "\n";
        
    }
    else if (grid_filled()){
        std::cout << "We have a tie!" << "\n";
        
    }

}
