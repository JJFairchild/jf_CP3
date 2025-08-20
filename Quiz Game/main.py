# Jonas Fairchild, Quiz Game

"""
To do:
- Allow users to create lists of questions
- User profiles (Admin users can create new lists of questions, normal users can just select from lists of questions to do)
"""


import random # Import modules
import copy

from file_handling import * # Import files
from ask_questions import *

import tkinter as tk # Set up tkinter
root = tk.Tk()
root.title("Quiz Game")
root.geometry("400x200")

userstatus = "login" # Whether or not the user is logged in, doubles as text for homescreen login/logout
questions = read()

def main(): # Main function, runs the whole program

    def run_main_function(command): # Function that decides what other function to run

        # Cleans up widgets
        gamelabel.destroy()
        make.destroy()
        play.destroy()
        quit.destroy()

        match command:
            case 0:
                pass # Runs question maker function
            case 1:
                category = get_category(questions)
                if category == "BACK":
                    main()
                    return

                score = 0
                cat_copy = copy.deepcopy(questions[category])
                for i in range(10):
                    index = random.randrange(len(cat_copy))
                    question = cat_copy.pop(index)
                    result = ask_question(question)
                    if result == "BACK":
                        run_main_function(1)
                        return
                    score += int(result)
                win_screen(score)
                main()
                return
            case 2:
                root.destroy()

    # Creates widgets
    gamelabel = tk.Label(text="Quiz Game")
    make = tk.Button(root, text="Make Questions", command=lambda: run_main_function(0))
    play = tk.Button(root, text="Play", command=lambda: run_main_function(1))
    quit = tk.Button(root, text="Quit Game", command=lambda: run_main_function(2))

    # Adds widgets to screen
    gamelabel.pack(pady=20)
    make.pack(padx=30, side="left")
    play.pack(padx=30, side="left")
    quit.pack(padx=30, side="left")

main()
root.mainloop()