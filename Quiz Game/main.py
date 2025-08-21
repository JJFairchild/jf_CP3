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
from make_questions import make as make_func, login

import tkinter as tk # Set up tkinter
root = tk.Tk()
root.title("Quiz Game")
root.geometry("400x200")

user_status = "logout" # Whether or not the user is logged in, doubles as text for homescreen login/logout
questions = read()

def main(): # Main function, runs the whole program

    def run_main_function(command): # Function that decides what other function to run
        global questions
        global user_status

        # Cleans up widgets
        game_label.destroy()
        make.destroy()
        play.destroy()
        quit.destroy()
        log_button.destroy()
        login_frame.destroy()
        button_frame.destroy()

        match command:
            case 0: # Reassignes questions to the output of make() if valid
                new_cat = make_func(root, user_status, questions)
                if new_cat == "BACK":
                    main()
                    return
                questions = new_cat
                main()
                return
            case 1: # Forces the user to answer 10 questions and tracks the score
                category = get_category(root, questions)
                if category == "BACK":
                    main()
                    return

                score = 0
                cat_copy = copy.deepcopy(questions[category])
                for i in range(10):
                    index = random.randrange(len(cat_copy))
                    question = cat_copy.pop(index)
                    result = ask_question(root, question)
                    if result == "BACK":
                        run_main_function(1)
                        return
                    score += int(result)
                win_screen(root, score)
                main()
                return
            case 2: # Kills the program
                root.destroy()
            case 3: # Log in/out
                log_return = login(root, userstatus)
                if log_return == "BACK":
                    main()
                    return
                userstatus = log_return
                main()
                return

    # Creates widgets
    game_label = tk.Label(text="Quiz Game")

    button_frame = tk.Frame(root)
    make = tk.Button(button_frame, text="Make Questions", command=lambda: run_main_function(0))
    play = tk.Button(button_frame, text="Play", command=lambda: run_main_function(1))
    quit = tk.Button(button_frame, text="Quit Game", command=lambda: run_main_function(2))

    login_frame = tk.Frame(root)
    log_button = tk.Button(login_frame, text=user_status.capitalize(), command=lambda: run_main_function(3)) # Log in/out button

    # Adds widgets to screen
    game_label.pack(pady=20)
    button_frame.pack(pady=10)
    make.pack(padx=30, side="left")
    play.pack(padx=30, side="left")
    quit.pack(padx=30, side="left")

    login_frame.pack(side="bottom", anchor="sw", fill="x")
    log_button.pack(padx=10, pady=10, side="left")

    
    

main()
root.mainloop()