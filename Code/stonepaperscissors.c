#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int player_score, computer_score, winning_score;  // Scores and winning point target
    char spc, choice, retry;
    
    srand(time(NULL));  // Initialize random number generator
    
    while (1)  // Main game loop
    {
        player_score = 0;  // Reset player score
        computer_score = 0;  // Reset computer score
        
        // Ask the player for the number of points to win
        printf("\n--- Welcome to Stone, Paper, Scissors ---\n");
        printf("How many points should the game be played to? ");
        scanf("%d", &winning_score);
        
        if (winning_score <= 0) {
            printf("Invalid point count. Please enter a positive number.\n");
            continue;  // Restart the loop if the input is invalid
        }
        
        while (player_score < winning_score && computer_score < winning_score)
        {
            int comp = rand() % 100;  // Generate computer's random choice
            
            // Map random number to computer's choice
            if(comp < 33)
                choice = 's';  // Computer chooses Stone
            else if(comp >= 33 && comp < 66)
                choice = 'p';  // Computer chooses Paper
            else
                choice = 'c';  // Computer chooses Scissors
            
            // Display game rules
            printf("\n--- Stone, Paper, Scissors ---\n");
            printf("1. Stone ('s') beats Scissors ('c').\n");
            printf("2. Scissors ('c') beats Paper ('p').\n");
            printf("3. Paper ('p') beats Stone ('s').\n");
            printf("Enter s for Stone, p for Paper, c for Scissors: ");
            scanf(" %c", &spc);  // Get player's choice
            
            // Determine the result of the round
            if(spc == choice)
            {
                printf("Computer chose %c. It's a draw.\n", choice);
            }
            else if((spc == 's' && choice == 'c') || (spc == 'c' && choice == 'p') || (spc == 'p' && choice == 's'))
            {
                printf("Computer chose %c. You win this round!\n", choice);
                player_score++;
            }
            else if(spc == 's' || spc == 'p' || spc == 'c')  // Valid input, but a loss
            {
                printf("Computer chose %c. You lose this round.\n", choice);
                computer_score++;
            }
            else  // Invalid input
            {
                printf("Invalid input. Please choose 's', 'p', or 'c'.\n");
                continue;
            }
            
            // Display current score
            printf("\n--- Current Score ---\n");
            printf("Player: %d\n", player_score);
            printf("Computer: %d\n", computer_score);
        }
        
        // Determine and announce the winner
        printf("\n--- Final Score ---\n");
        printf("Player: %d\n", player_score);
        printf("Computer: %d\n", computer_score);
        
        if (player_score >= winning_score)
            printf("Congratulations! You win the game!\n");
        else
            printf("Sorry, the computer wins the game.\n");
        
        // Ask if the player wants to retry
        printf("\nWould you like to play again? (y for yes, n for no): ");
        scanf(" %c", &retry);
        
        if(retry == 'n')
        {
            printf("Thanks for playing! Goodbye!\n");
            break;  // Exit the main loop to end the game
        }
        else if(retry != 'y')
        {
            printf("Invalid input. Reseting the game.\n");
            continue;
        }
    }
    
    return 0;
}
