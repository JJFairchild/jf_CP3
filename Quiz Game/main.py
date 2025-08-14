# Jonas Fairchild, Quiz Game

import os # Import modules
import csv
import time

import tkinter as tk # Set up tkinter
root = tk.Tk()
root.title("Quiz Game")
root.geometry("400x100")

answer1 = tk.Button(root) # Create widgets
answer2 = tk.Button(root)
answer3 = tk.Button(root)
answer4 = tk.Button(root)
text = tk.Label(root)

answer1.pack(padx=20, pady=20, side="left") # Adds widgets to screen
answer2.pack(padx=20, side="left")
answer3.pack(padx=20, side="left")
answer4.pack(padx=20, side="left")
text.pack(pady=10)

question_list = {}

with open("Quiz Game/questions.csv", "r", newline='') as file:
    questions = csv.reader(file)
    next(questions)
    for question in questions:
        if len(question)==1:
            type=question[0]
            question_list[type] = []
        else:
            question_list[type].append(question)

def ask_question(question):

    def check_correct(answer):
        answer1.pack_forget()
        answer2.pack_forget()
        answer3.pack_forget()
        answer4.pack_forget()
        if answer==question[5]:
            text.config(text="Correct!")
        else:
            text.config(text="Not quite!")
        root.update()
        time.sleep(1)
    
    answer1.config(text=question[1], command=lambda: check_correct(1))
    answer2.config(text=question[2], command=lambda: check_correct(2))
    answer3.config(text=question[3], command=lambda: check_correct(3))
    answer4.config(text=question[4], command=lambda: check_correct(4))
    text.config(text=question[0])
    root.update()
    

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