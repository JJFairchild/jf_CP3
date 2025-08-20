
import time
import math
import random

import tkinter as tk
from tkinter import messagebox
root = tk.Tk()

def ask_question(question): # Function to ask the user a specific question
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
            questionlabel.config(text="Correct!")
            end_time=time.time()
            correct.set(max(1, math.floor(5 - 0.4 * (end_time-start_time))))
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

    def leave():
        correct.set('BACK')
        root.quit()

    button_frame = tk.Frame(root)
    button_frame.pack(pady=20)

    questionlabel = tk.Label(button_frame, text=question[0])
    answer1 = tk.Button(button_frame, text=question[1], command=lambda: check_correct(1))
    answer2 = tk.Button(button_frame, text=question[2], command=lambda: check_correct(2))
    answer3 = tk.Button(button_frame, text=question[3], command=lambda: check_correct(3))
    answer4 = tk.Button(button_frame, text=question[4], command=lambda: check_correct(4))

    questionlabel.pack(pady=10)
    answer1.pack(padx=10, pady=20, side="left")
    answer2.pack(padx=10, side="left")
    answer3.pack(padx=10, side="left")
    answer4.pack(padx=10, side="left")

    back_button = tk.Button(root, text="Back", command=lambda: leave()) # Back button
    back_button.pack(pady=10, padx=10, side="left")

    root.mainloop()  # start event loop here, will quit when check_correct calls root.quit()

    # After root.quit() is called (after 1 second delay), cleanup widgets
    questionlabel.destroy()
    answer1.destroy()
    answer2.destroy()
    answer3.destroy()
    answer4.destroy()
    button_frame.destroy()
    back_button.destroy()

    return correct.get()

def get_category(questions):
    category = tk.StringVar()

    categories = "" # Shows all the available categories
    for i in questions:
        categories +=("\n" + i)

    # Set up widgets

    catlabel = tk.Label(pady=20, text="Select category to play:" + categories)
    catlabel.pack()

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
    catlabel.destroy()
    cat_input.destroy()
    send_button.destroy()
    back_button.destroy()

    return category.get().strip()