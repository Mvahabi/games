import tkinter as tk
from tkinter import simpledialog

# Global variable to store the count
click_count = 0
root = None

def on_click(event):
    global click_count
    global root
    click_count += 1
    if click_count == 100:
        user_input = simpledialog.askstring("Restart?", "Do you want to restart? (y/n)", parent=root) ### this line
        if user_input and (user_input.upper() == "Y" or user_input.upper() == "YES"):
            click_count = 0
        else:
            print("Allah Hafez")
            root.destroy()  ### this line
    elif 0 < click_count <= 33:
        print(f"Subhan-Allah: {click_count}")
    elif 34 < click_count <= 66:
        print(f"Alhamdul_Illah: {click_count}")
    elif 67 < click_count <= 99:
        print(f"La Ilaha Illallah: {click_count}")

def main():
    global click_count
    global root
    root = tk.Tk()
    root.geometry("300x200")
    root.title("Tasbih Click Counter")
    root.configure(bg="cyan")

    label = tk.Label(root, text="Click anywhere to count", font=("Helvetica", 16), bg="#f0f0f0")
    label.pack(pady=20)

    root.bind("<Button-1>", on_click)
    root.mainloop()

if __name__ == "__main__":
    main()
