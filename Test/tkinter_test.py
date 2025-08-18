import tkinter as tk
from tkinter import messagebox

root = tk.Tk()
root.title("Chat Box")
root.geometry("400x300")

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

get_category({"Category": [[]]})

root.mainloop()