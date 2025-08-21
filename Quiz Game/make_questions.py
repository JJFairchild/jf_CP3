import tkinter as tk
from tkinter import messagebox

def login(root, userstatus):

    newuserstatus = tk.StringVar()

    if userstatus == "login":

        usernames = ["User"]
        passwords = ["123"]

        def leave():
            newuserstatus.set("BACK")

        user_label = tk.Label(pady=5, text="Enter your username:")
        user_label.pack()

        back_button = tk.Button(root, text="Back", command=lambda: leave()) # Back button
        back_button.pack(padx=10, side="left")

        user_input = tk.Entry(root, width=40)
        user_input.pack(padx=15, side="left")
        user_input.bind("<Return>", lambda event: enter_password())

        send_button = tk.Button(root, text="Accept", command=lambda: enter_password()) # Button to press as an alternative to the enter key.
        send_button.pack(padx=10, side="left")

        def enter_password():
            username = user_input.get().strip()
            if username in usernames:
                user_label.config(text="Enter your password:")
                user_input.bind("<Return>", lambda event: password_entry())
                send_button.config(command=lambda: password_entry())

                root.update()

                def password_entry():
                    if passwords[usernames.index(username)] == user_input.get().strip():
                        newuserstatus.set("logout")
                    else:
                        messagebox.showerror("Error","Incorrect password. (enter 123)")
            else:
                messagebox.showerror("Error","That user does not exist. To obtain admin priviliges, contact another admin to be considered for creating questions. (or, you could just enter User as username and 123 as password. your choice.)")
            
        root.wait_variable(newuserstatus)
        user_input.destroy()
        send_button.destroy()
        user_label.destroy()
        back_button.destroy()
    
    else:
        newuserstatus.set("login")

    return newuserstatus.get().strip()

def make(root, userstatus, questions):
    if userstatus == "logout": # If user is logged in (counterintuitive, I know. logout/login is the name of the button on the homescreen; so, if they are logged in, they can only log out, thus their state is logout.)
        
        # --- Category Selection ---
        category = tk.StringVar()

        # Create widgets
        make_frame = tk.Frame(root)
        make_frame.pack(pady=20)

        cat_label = tk.Label(make_frame, text="Enter your new category name:")
        cat_label.pack()

        def leave(): # Exit function
            category.set("BACK")
            make_frame.destroy()

        back_button = tk.Button(make_frame, text="Back", command=leave)
        back_button.pack(padx=10, side="left")

        cat_input = tk.Entry(make_frame, width=40)
        cat_input.pack(padx=15, side="left")
        cat_input.bind("<Return>", lambda event: get_cat())

        send_button = tk.Button(make_frame, text="Accept", command=lambda: get_cat()) # Button to press as an alternative to the enter key.
        send_button.pack(padx=10, side="left")

        def get_cat(): # Function to check if the given category is valid.
            message = cat_input.get().strip()
            if not questions.get(message.capitalize()):
                category.set(message.capitalize())
                make_frame.destroy()
            else:
                messagebox.showerror("Error", "That category already exists. Try again.")

        # Wait for category entry
        root.wait_variable(category)
        cat_name = category.get()
        if cat_name == "BACK":
            return "BACK"

        # --- Question Adding ---
        leave_questions = tk.BooleanVar() # Whether the user decided to finish the category.
        new_questions = [] # List of questions in the new category.

        def add_question(): # Function to ensure that all inputs are valid
            q_text = q_entry.get().strip()
            a1 = a1_entry.get().strip()
            a2 = a2_entry.get().strip()
            a3 = a3_entry.get().strip()
            a4 = a4_entry.get().strip()
            correct = correct_entry.get().strip()

            if not q_text or not a1 or not a2 or not a3 or not a4 or not correct:
                messagebox.showerror("Error", "All fields must be filled!")
                return
            if correct not in ("1","2","3","4"):
                messagebox.showerror("Error", "Correct answer must be 1, 2, 3, or 4")
                return

            new_questions.append([q_text, a1, a2, a3, a4, int(correct)])

            # Clear entries for next question (not .destroy() so it can be reused)
            q_entry.delete(0, tk.END)
            a1_entry.delete(0, tk.END)
            a2_entry.delete(0, tk.END)
            a3_entry.delete(0, tk.END)
            a4_entry.delete(0, tk.END)
            correct_entry.delete(0, tk.END)

        def stop_adding(): # Sets leave_questions to True (user has finished adding questions)
            leave_questions.set(True)

        # Add widgets
        q_frame = tk.Frame(root)
        q_frame.pack(pady=20)

        tk.Label(q_frame, text=f"Add questions for category '{cat_name}'").pack()

        q_entry = tk.Entry(q_frame, width=60)
        q_entry.pack(pady=2)
        q_entry.insert(0, "Question text") # Inserts text to let the user know what each box is for (adding separate labels would be too painful for me sorry)

        a1_entry = tk.Entry(q_frame, width=60)
        a1_entry.pack(pady=2)
        a1_entry.insert(0, "Answer 1")

        a2_entry = tk.Entry(q_frame, width=60)
        a2_entry.pack(pady=2)
        a2_entry.insert(0, "Answer 2")

        a3_entry = tk.Entry(q_frame, width=60)
        a3_entry.pack(pady=2)
        a3_entry.insert(0, "Answer 3")

        a4_entry = tk.Entry(q_frame, width=60)
        a4_entry.pack(pady=2)
        a4_entry.insert(0, "Answer 4")

        correct_entry = tk.Entry(q_frame, width=60)
        correct_entry.pack(pady=2)
        correct_entry.insert(0, "Correct # (1-4)")

        add_button = tk.Button(q_frame, text="Add Question", command=add_question)
        add_button.pack(pady=5)

        stop_button = tk.Button(q_frame, text="Stop Adding", command=stop_adding)
        stop_button.pack(pady=5)

        root.wait_variable(leave_questions) # Wait until the user stops adding

        q_frame.destroy()

        # Save questions
        questions[cat_name] = new_questions
        return questions

    else: # Error message for not being logged in as an admin.
        leave = tk.BooleanVar()

        def exit():
            leave.set(True)

        make_frame = tk.Frame(root)
        make_frame.pack(pady=20)

        log_label = tk.Label(make_frame, text="You must be logged in to make questions.")
        log_label.pack()

        return_button = tk.Button(make_frame, text="Return to main menu", command=exit)
        return_button.pack()

        root.wait_variable(leave)

        make_frame.destroy()
        return "BACK"

