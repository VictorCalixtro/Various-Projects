# Victor Calixtro
# 4/9/15
# Purpose: To play a simple guessing game
import random
def main():
    guess = 0 
    
    print("Lets play the guessing game!")
    print("The number im guesssing is between 1 and 100")
    print()
    
    guess = int(input("Enter a number between 1 and 100(or press 0 to end): "))
    while guess < 0 or guess > 100:
        print("The number must be between 1 and 100")
        guess = int(input("Enter a number between 1 and 100(or press 0 to end): "))
    
    guessAgain, count = playGuessingGame(guess)
    
    print("You quit", "You guessed a total of:", count, "times.")

   
def playGuessingGame(guess): # This function will count the number of guesses and serve as the game.
    #It will return the number of guesses to main and contol if the game is to end. It also gets one parameter.
    ranNum = 0
    ranNum = random.randrange(1, 100)
    count = 1
    
    while guess != 0:
        while guess > ranNum and guess != 0:
            print("Too high, try again")
            guess = int(input("Enter a number between 1 and 100 (or press 0 to end): "))
            count += 1
            while guess < 0 or guess > 100 and guess != 0:
                print("The number must be between 1 and 100")
                guess = int(input("Enter a number between 1 and 100 (or press 0 to end): "))
        while guess < ranNum and guess != 0:
            print("Too low, try again")
            guess = int(input("Enter a number between 1 and 100 (or press 0 to end): "))
            count += 1
            while guess < 0 or guess > 100 and guess != 0:
                print("The number must be between 1 and 100")
                guess = int(input("Enter a number between 1 and 100 (or press 0 to end): "))
        if guess == ranNum:
            print("Congrats you did it!")
            print("Lets play again!")
            guess = int(input("Enter a number between 1 and 100 to play again(or press 0 to end): "))
            while guess < 0 or guess > 100:
                print("The number must be between 1 and 100")
                guess = int(input("Enter a number between 1 and 100 to play again(or press 0 to end): "))

    return guess, count


    
    
main()
