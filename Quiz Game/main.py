# Jonas Fairchild, Quiz Game

import csv # Import modules
import time
import random
import copy

import tkinter as tk # Set up tkinter
from tkinter import messagebox
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

def ask_question(question): # Function to ask the user a specific question

    ques_answers = [] # Shuffles the answers
    for i in range(1, 5):
        ques_answers.append(question[i])
    ques_answers = random.shuffle(ques_answers)

    ques_copy = copy.copy(question)
    for i in range(1, 5):
        ques_copy[i] = ques_answers[i-1]

    correct = tk.IntVar()

    def check_correct(answer):
        if answer == int(question[5]):
            questionlabel.config(text="Correct!")
            correct.set(1)
        else:
            questionlabel.config(text="Not quite!")
            correct.set(0)

        # Disable all buttons immediately to prevent multiple clicks
        answer1.config(state="disabled")
        answer2.config(state="disabled")
        answer3.config(state="disabled")
        answer4.config(state="disabled")

        # Schedule closing after 1 second, so user can see feedback
        root.after(1000, root.quit)  # will exit mainloop below

    button_frame = tk.Frame(root)
    button_frame.pack(pady=20)

    questionlabel = tk.Label(button_frame, text=question[0])
    answer1 = tk.Button(button_frame, text=question[1], command=lambda: check_correct(1))
    answer2 = tk.Button(button_frame, text=question[2], command=lambda: check_correct(2))
    answer3 = tk.Button(button_frame, text=question[3], command=lambda: check_correct(3))
    answer4 = tk.Button(button_frame, text=question[4], command=lambda: check_correct(4))

    questionlabel.pack(pady=10)
    answer1.pack(padx=20, pady=20, side="left")
    answer2.pack(padx=20, side="left")
    answer3.pack(padx=20, side="left")
    answer4.pack(padx=20, side="left")

    root.mainloop()  # start event loop here, will quit when check_correct calls root.quit()

    # After root.quit() is called (after 1 second delay), cleanup widgets
    questionlabel.destroy()
    answer1.destroy()
    answer2.destroy()
    answer3.destroy()
    answer4.destroy()
    button_frame.destroy()

    return correct.get()

def get_category(questions):
    category = tk.StringVar()

    categories = "" # Shows all the available categories
    for i in questions:
        categories +=("\n" + i)

    # Set up widgets
    catlabel = tk.Label(pady=20, text="Select category to play:" + categories)
    catlabel.pack()

    cat_input = tk.Entry(root, width=40)
    cat_input.pack(padx=25, side="left")
    cat_input.bind("<Return>", lambda event: accept_msg())

    def accept_msg(): # Function for the message box to call when pressed.
        message = cat_input.get().strip()
        if questions.get(message.capitalize()):
            category.set(message.capitalize())
        else:
            messagebox.showerror("Error","That's not an item on the list. Try again.")
    
    send_button = tk.Button(root, text="Accept", command=lambda: accept_msg()) # Button to press as an alternative to the enter key.
    send_button.pack(padx=25, side="left")

    root.wait_variable(category) # Waits for a category to be selected

    # Cleans up widgets
    catlabel.destroy()
    cat_input.destroy()
    send_button.destroy()

    return category.get().strip()

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
                score = 0
                cat_copy = copy.deepcopy(questions[category])
                for i in range(10):
                    index = random.randrange(len(cat_copy))
                    question = cat_copy.pop(index)
                    score += ask_question(question)
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