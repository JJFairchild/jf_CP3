# Jonas Fairchild, Quiz Game

import csv # Import modules
import random
import copy

import tkinter as tk # Set up tkinter
root = tk.Tk()
root.title("Quiz Game")
root.geometry("400x200")

questions = {}

with open("Quiz Game/questions.csv", "r", newline='') as file: # Gets the csv file into 'questions'
    questioncsv = csv.reader(file)
    next(questioncsv)
    for question in questioncsv:
        if len(question)==1:
            type=question[0]
            questions[type] = []
        else:
            questions[type].append(question)

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
                        break
                    score += int(result)
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