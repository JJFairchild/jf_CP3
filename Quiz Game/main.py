# Jonas Fairchild, Quiz Game

import csv # Import modules
import time
import random

import tkinter as tk # Set up tkinter
from tkinter import messagebox
root = tk.Tk()
root.title("Quiz Game")
root.geometry("400x300")

question_list = {}

with open("Quiz Game/questions.csv", "r", newline='') as file: # Gets the csv file into question_list
    questions = csv.reader(file)
    next(questions)
    for question in questions:
        if len(question)==1:
            type=question[0]
            question_list[type] = []
        else:
            question_list[type].append(question)

def ask_question(question):
    correct = tk.IntVar() # Whether or not the answer is correct. Will be 1 or 0.

    def check_correct(answer): # A function to give the user the result and assign 'correct' the proper value.
        if answer==int(question[5]):
            questionlabel.config(text="Correct!")
            correct.set(1)
        else:
            questionlabel.config(text="Not quite!")
            correct.set(0)
        root.update()
        time.sleep(1)
    
    #Creates widgets
    questionlabel = tk.Label(text=question[0])
    answer1 = tk.Button(root, text=question[1], command=lambda: check_correct(1))
    answer2 = tk.Button(root, text=question[2], command=lambda: check_correct(2))
    answer3 = tk.Button(root, text=question[3], command=lambda: check_correct(3))
    answer4 = tk.Button(root, text=question[4], command=lambda: check_correct(4))

    # Adds widgets to screen
    questionlabel.pack(pady=10)
    answer1.pack(padx=20, pady=20, side="left")
    answer2.pack(padx=20, side="left")
    answer3.pack(padx=20, side="left")
    answer4.pack(padx=20, side="left")
    
    root.wait_variable(correct) # Waits for 'correct' to be assigned a value by check_correct()

    # Cleans up widgets
    questionlabel.destroy()
    answer1.destroy()
    answer2.destroy()
    answer3.destroy()
    answer4.destroy()

    return correct.get() # Returns the value of 'correct' for score keeping.

def get_category(questions):
    category = tk.StringVar()

    categories = ""
    for i in questions:
        categories +=("\n" + i)

    catlabel = tk.Label(text="Select category to play:" + categories)
    catlabel.pack()

    cat_input = tk.Entry(root, width=40)
    cat_input.pack(padx=25, side="left")
    cat_input.bind("<Return>", lambda event: accept_msg())

    def accept_msg():
        message = cat_input.get().strip()
        if questions.get(message.capitalize()):
            category.set(message.capitalize())
        else:
            messagebox.showerror("Error","That's not an item on the list. Try again.")
    
    send_button = tk.Button(root, text="Accept", command=lambda: accept_msg())
    send_button.pack(padx=25, side="left")

    root.wait_variable(category)

    catlabel.destroy()
    cat_input.destroy()
    send_button.destroy()

def main(): # Main function, runs the whole program

    def run_main_function(command): # Function that decides what other function to run
        # Cleans up widgets
        gamelabel.destroy()
        make.destroy
        play.destroy()
        quit.destroy

        match command:
            case 0:
                pass # Runs question maker function
            case 1:
                category = get_category(questions)
                score = 0
                count = 0
                score += ask_question(random.choice(category))
            case 2:
                root.destroy()
    
    #Creates widgets
    gamelabel = tk.Label(text="Quiz Game")
    make = tk.Button(root, text="Make Questions", command=lambda: run_main_function(0))
    play = tk.Button(root, text="Play", command=lambda: run_main_function(1))
    quit = tk.Button(root, text="Quit Game", command=lambda: run_main_function(2))

    # Adds widgets to screen
    gamelabel.pack(pady=10)
    make.pack(padx=30, pady=20, side="left")
    play.pack(padx=30, side="left")
    quit.pack(padx=30, side="left")

main()
root.mainloop()