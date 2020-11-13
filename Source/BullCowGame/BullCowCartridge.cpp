// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    
    SetupGame();
    
    PrintLine(TEXT("The Hidden Word is: %s."), *HiddenWord); //Debug line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{   
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    } 
    else // Check PlayerGuess
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to Bull Cow!"));
    
    HiddenWord = TEXT("Cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;

    // Welcome P1
    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives!"), Lives);
    PrintLine(TEXT("Type in your guess to contine."));

    const TCHAR HW[] = TEXT("plums");
    // const TCHAR HW[] = {TEXT("c"), TEXT("a"), TEXT("k"), TEXT("e"), TEXT("s"), TEXT("\0")};
    PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]); // print out "c"
    PrintLine(TEXT("The 4th character of HW is: %c"), HW[3]);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Game Over! Press Enter to Play Again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You win!"));
        EndGame();
        return;
    }
    
    // Check if right number of characters
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("Try again! You have %i lives remaining."), Lives);
        PrintLine(TEXT("The hidden word is %i letters long."), HiddenWord.Len());
        return;
    }

    // Check if isogram
    if (!IsIsogram())
    {
        // CODE HERE
        PrintLine(TEXT("No repeating letters. Guess again!"));
        return;
    }

    // Remove a life
    PrintLine(TEXT("Wrong! You lost a life."));

    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("The hidden word was: %s."), *HiddenWord);
        PrintLine(TEXT("You have no lives left!"));
        EndGame();
        return;
    }

    // Show P1 Bulls and Cows
    PrintLine(TEXT("Guess again.  You have %i lives left."), Lives);
    // Check if Lives > 0
    // If yes, GuessAgain
    // Show Lives left
    // If no, show GameOver and HiddenWord
    // Prompt to PlayAgain, Press Enter to play again
    // Check P1 Input
    //PlayAgain or Quit
}

// bool UBullCowCartridge::IsIsogram()
// {
//     // algo: iterate through the letters to make sure they don't match
//     if (HW[0] != HW[1])
//     {

//     }
// }
