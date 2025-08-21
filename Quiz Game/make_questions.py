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
    if userstatus == "logout":
        category = tk.StringVar()

        # Create a frame for the make screen
        make_frame = tk.Frame(root)
        make_frame.pack(pady=20)

        cat_label = tk.Label(make_frame, text="Enter your new category name:")
        cat_label.pack()

        def leave():
            category.set("BACK")
            make_frame.destroy()

        back_button = tk.Button(make_frame, text="Back", command=leave)
        back_button.pack(padx=10, side="left")

        cat_input = tk.Entry(make_frame, width=40)
        cat_input.pack(padx=15, side="left")
        cat_input.bind("<Return>", lambda event: get_cat())

        def get_cat():
            message = cat_input.get().strip()
            if not questions.get(message.capitalize()):
                category.set(message.capitalize())
                make_frame.destroy()
            else:
                messagebox.showerror("Error","That category already exists. Try again.")

        # Wait for the user to enter a category
        root.wait_variable(category)
        cat_name = category.get()
        if cat_name == "BACK":
            return "BACK"

        # Now let user add questions
        leave_questions = tk.BooleanVar()
        new_questions = []

        def add_question():
            q_text = q_entry.get().strip()
            if q_text:
                new_questions.append(q_text)
                q_entry.delete(0, tk.END)
            else:
                messagebox.showerror("Error", "Please enter a question or press Stop.")

        def stop_adding():
            leave_questions.set(True)

        # Create frame for adding questions
        q_frame = tk.Frame(root)
        q_frame.pack(pady=20)

        q_label = tk.Label(q_frame, text=f"Add questions for category '{cat_name}':")
        q_label.pack()

        q_entry = tk.Entry(q_frame, width=60)
        q_entry.pack(padx=10, pady=5)
        q_entry.bind("<Return>", lambda event: add_question())

        add_button = tk.Button(q_frame, text="Add Question", command=add_question)
        add_button.pack(pady=5)

        stop_button = tk.Button(q_frame, text="Stop Adding", command=stop_adding)
        stop_button.pack(pady=5)

        # Wait until user presses Stop
        root.wait_variable(leave_questions)

        q_frame.destroy()

        # Save questions in dictionary
        questions[cat_name] = new_questions
        return questions

    else:
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
