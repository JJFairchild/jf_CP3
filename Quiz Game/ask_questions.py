import time
import math
import random

import tkinter as tk
from tkinter import messagebox


def ask_question(root, question): # Function to ask the user a specific question
    start_time = time.time()
    
    ques_answers = [] # Shuffles the answers
    correct_ans = question[int(question[5])]

    for i in range(1, 5):
        ques_answers.append(question[i])
    random.shuffle(ques_answers)

    for i in range(1, 5):
        question[i] = ques_answers[i-1]
    question[5] = str(question.index(correct_ans))

    correct = tk.StringVar()

    def check_correct(answer):
        if answer == int(question[5]):
            question_label.config(text="Correct!")
            end_time=time.time()
            correct.set(max(1, math.floor(6 - 0.4 * (end_time-start_time)))) # Changes the amount of points you get based on how long it took you to answer
        else:
            question_label.config(text="Not quite!")
            correct.set(0)

        # Disable all buttons immediately to prevent multiple clicks
        answer_1.config(state="disabled")
        answer_2.config(state="disabled")
        answer_3.config(state="disabled")
        answer_4.config(state="disabled")

        # Schedule closing after 1 second, so user can see feedback
        root.after(1000, root.quit)  # will exit mainloop below

    def leave():
        correct.set('BACK')
        root.quit()

    button_frame = tk.Frame(root)
    button_frame.pack(pady=20)

    question_label = tk.Label(button_frame, text=question[0])
    answer_1 = tk.Button(button_frame, text=question[1], command=lambda: check_correct(1))
    answer_2 = tk.Button(button_frame, text=question[2], command=lambda: check_correct(2))
    answer_3 = tk.Button(button_frame, text=question[3], command=lambda: check_correct(3))
    answer_4 = tk.Button(button_frame, text=question[4], command=lambda: check_correct(4))

    question_label.pack(pady=10)
    answer_1.pack(padx=10, pady=20, side="left")
    answer_2.pack(padx=10, side="left")
    answer_3.pack(padx=10, side="left")
    answer_4.pack(padx=10, side="left")

    back_button = tk.Button(root, text="Back", command=lambda: leave()) # Back button
    back_button.pack(pady=10, padx=10, side="left")

    root.mainloop()  # start event loop here, will quit when check_correct calls root.quit()

    # After root.quit() is called (after 1 second delay), cleanup widgets
    question_label.destroy()
    answer_1.destroy()
    answer_2.destroy()
    answer_3.destroy()
    answer_4.destroy()
    button_frame.destroy()
    back_button.destroy()

    return correct.get()

def get_category(root, questions):
    category = tk.StringVar()

    categories = "" # Shows all the available categories
    for i in questions:
        categories +=("\n" + i)

    # Set up widgets

    cat_label = tk.Label(pady=20, text="Select category to play:" + categories)
    cat_label.pack()

    back_button = tk.Button(root, text="Back", command=lambda: leave()) # Back button
    back_button.pack(padx=10, side="left")

    cat_input = tk.Entry(root, width=40)
    cat_input.pack(padx=15, side="left")
    cat_input.bind("<Return>", lambda event: accept_msg())

    def accept_msg(): # Function for the message box to call when pressed.
        message = cat_input.get().strip()
        if questions.get(message.capitalize()):
            category.set(message.capitalize())
        else:
            messagebox.showerror("Error","That's not an item on the list. Try again.")
    
    def leave():
        category.set('BACK')

    send_button = tk.Button(root, text="Accept", command=lambda: accept_msg()) # Button to press as an alternative to the enter key.
    send_button.pack(padx=10, side="left")

    root.wait_variable(category) # Waits for a category to be selected

    # Cleans up widgets
    cat_label.destroy()
    cat_input.destroy()
    send_button.destroy()
    back_button.destroy()

    return category.get().strip()

def win_screen(root, points):
    leave = tk.BooleanVar()

    def exit():
        leave.set(True)

    win_label = tk.Label(pady=20, text=f"Congrats! You got {points} points!")
    win_label.pack()

    win_button = tk.Button(pady=20, text="Return to main menu", command = lambda: exit()) # Button to press as an alternative to the enter key.
    win_button.pack()

    root.wait_variable(leave)

    win_label.destroy()
    win_button.destroy()

