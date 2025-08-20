import tkinter as tk
root = tk.Tk()

def login():
    pass

def make(userstatus):
    if userstatus == "logout":
        pass
    else:
        leave = tk.BooleanVar()

        winlabel = tk.Label(pady=20, text="You must be logged in to make questions.")
        winlabel.pack()

        send_button = tk.Button(pady=20, text="Return to main menu", command=leave.set(True)) # Button to press as an alternative to the enter key.
        send_button.pack()

        root.wait_variable(leave)