#Jonas Fairchild, Quiz Game

import os
import csv


question_list = []

with open("Quiz Game/questions.csv", "r", newline='') as file:
    questions = csv.reader(file)
    next(questions)
    for question in questions:
        question_list.append(question)



def question_game():
    while True:
        os.system('cls')
        match input("Select a game mode.\n1. Random Questions\n2. General Knowledge\n3. Science\n4. UNFINISHED"):
            case "1":
                pass
            case "2":
                pass
            case "3":
                break
            case _:
                print("That's not a valid input. Try again.")
        input("Done reading?: ")

def main():
    while True:
        os.system('cls')
        match input("What do you want to do?\n1. Play question game\n2. Make questions\n3. Exit"):
            case "1":
                question_game()
            case "2":
                pass
            case "3":
                break
            case _:
                print("That's not a valid input. Try again.")
        input("Done reading?: ")