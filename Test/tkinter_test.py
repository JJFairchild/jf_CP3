import tkinter as tk
from tkinter import scrolledtext

root = tk.Tk()
root.title("Chat Box")

# Chat display area with scroll
chat_display = scrolledtext.ScrolledText(root, wrap=tk.WORD, width=50, height=15, state='disabled')
chat_display.pack(padx=10, pady=10)

# Input field
chat_input = tk.Entry(root, width=40)
chat_input.pack(side="left", padx=(10, 0), pady=(0, 10))

# Send button
def send_message():
    message = chat_input.get().strip()
    if message:
        # Enable text box to insert message
        chat_display.config(state='normal')
        chat_display.insert(tk.END, "You: " + message + "\n")
        chat_display.config(state='disabled')
        chat_display.yview(tk.END)  # Scroll to bottom
        chat_input.delete(0, tk.END)

send_button = tk.Button(root, text="Send", command=send_message)
send_button.pack(side="left", padx=10, pady=(0, 10))

# Optional: bind Enter key to send
chat_input.bind("<Return>", lambda event: send_message())

root.mainloop()