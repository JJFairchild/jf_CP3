#Jonas Fairchild, Quiz Game

import os
import csv
import time

import tkinter as tk
root = tk.Tk()
root.title("Quiz Game")
root.geometry("400x100")


question_list = []

with open("Quiz Game/questions.csv", "r", newline='') as file:
    questions = csv.reader(file)
    next(questions)
    for question in questions:
        question_list.append(question)

def ask_question(question):

    def check_correct(answer):
        answer1.destroy()
        answer2.destroy()
        answer3.destroy()
        answer4.destroy()
        if answer==question[5]:
            questionlabel.config(text="Correct!")
        else:
            questionlabel.config(text="Not quite!")
        root.update()
        time.sleep(1)
    
    questionlabel = tk.Label(root, text=question[0])
    questionlabel.pack(pady=10)

    answer1 = tk.Button(root, text=question[1], command=lambda: check_correct(1))
    answer2 = tk.Button(root, text=question[2], command=lambda: check_correct(2))
    answer3 = tk.Button(root, text=question[3], command=lambda: check_correct(3))
    answer4 = tk.Button(root, text=question[4], command=lambda: check_correct(4))

    answer1.pack(padx=20, pady=20, side="left")
    answer2.pack(padx=20, side="left")
    answer3.pack(padx=20, side="left")
    answer4.pack(padx=20, side="left")

def question_game():
    while True:
        os.system('cls')
        match input("Select a game mode.\n1. Random Questions\n2. General Knowledge\n3. Science\n4. History\n5. Literature/art\n6. Technology"):
            case "1":
                pass
            case "2":
                pass
            case "3":
                break
            case _:
                print("That's not a valid input. Try again.")
        input("Done reading?: ")
"""
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
"""

def main():
    pass

root.mainloop()