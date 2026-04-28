import subprocess
import tkinter as tk
from tkinter import filedialog, messagebox

def run_command(cmd):
    result = subprocess.run(cmd, capture_output=True, text=True)
    messagebox.showinfo("Result", result.stdout)

def select_file():
    return filedialog.askopenfilename()

from tkinter import simpledialog

def encrypt():
    file = select_file()
    if not file:
        return

    password = simpledialog.askstring("Password", "Enter password", show="*")
    if not password:
        return

    output = file + ".enc"

    run_command(["../build/encryptor.exe", "encrypt", file, output, password])

def decrypt():
    file = select_file()
    if not file:
        return

    password = simpledialog.askstring("Password", "Enter password", show="*")
    if not password:
        return

    output = file + ".dec"

    run_command(["../build/encryptor.exe", "decrypt", file, output, password])

def preview():
    file = select_file()
    if not file:
        return

    password = simpledialog.askstring("Password", "Enter password", show="*")
    if not password:
        return

    run_command(["../build/encryptor.exe", "preview", file, password])
    
root = tk.Tk()
root.title("Secure File Encryptor")

tk.Button(root, text="Encrypt", command=encrypt).pack(pady=10)
tk.Button(root, text="Decrypt", command=decrypt).pack(pady=10)
tk.Button(root, text="Preview", command=preview).pack(pady=10)

root.mainloop()