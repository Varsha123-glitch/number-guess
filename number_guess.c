#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame(int lower, int upper, int maxAttempts);
int getDifficultyLevel();

int main() {
    int lower = 1, upper = 100, maxAttempts;

    // Welcome message
    printf("Welcome to the Advanced Number Guessing Game!\n");

    // Get the difficulty level
    int difficulty = getDifficultyLevel();

    // Set the range and max attempts based on difficulty
    switch (difficulty) {
        case 1:  // Easy
            upper = 50;
            maxAttempts = 10;
            break;
        case 2:  // Medium
            upper = 100;
            maxAttempts = 7;
            break;
        case 3:  // Hard
            upper = 200;
            maxAttempts = 5;
            break;
        default:
            printf("Invalid difficulty level. Defaulting to Medium.\n");
            upper = 100;
            maxAttempts = 7;
            break;
    }

    // Start the game
    playGame(lower, upper, maxAttempts);

    return 0;
}

void playGame(int lower, int upper, int maxAttempts) {
    int number, guess, attempts = 0;

    // Initialize random number generator
    srand(time(0));

    // Generate a random number between lower and upper
    number = (rand() % (upper - lower + 1)) + lower;

    printf("\nI have generated a number between %d and %d. Try to guess it!\n", lower, upper);

    // Main game loop
    while (attempts < maxAttempts) {
        printf("Attempt %d/%d - Enter your guess: ", attempts + 1, maxAttempts);
        if (scanf("%d", &guess) != 1) {
            // Clear invalid input and prompt again
            while(getchar() != '\n');
            printf("Invalid input! Please enter an integer.\n");
            continue;
        }

        attempts++;

        if (guess > number) {
            printf("Too high! Try again.\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            return;
        }

        // Provide a hint after 3 incorrect guesses
        if (attempts == 3) {
            printf("Hint: The number is %s.\n", (number % 2 == 0) ? "even" : "odd");
        }
    }

    printf("Sorry, you've used all your attempts. The correct number was %d.\n", number);
}

int getDifficultyLevel() {
    int difficulty;

    printf("\nSelect difficulty level:\n");
    printf("1. Easy (Range: 1-50, Max Attempts: 10)\n");
    printf("2. Medium (Range: 1-100, Max Attempts: 7)\n");
    printf("3. Hard (Range: 1-200, Max Attempts: 5)\n");
    printf("Enter your choice (1/2/3): ");
    if (scanf("%d", &difficulty) != 1) {
        // Clear invalid input and set default difficulty
        while(getchar() != '\n');
        printf("Invalid input! Defaulting to Medium.\n");
        difficulty = 2;
    }

    return difficulty;
}
