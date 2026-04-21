import subprocess
import sys
import os

BASE = os.path.dirname(os.path.abspath(__file__))

APPS = {
    "1": ("Exex", "exex_main.py"),
    "2": ("Secure", "secure_main.py")
}

def run(file):
    path = os.path.join(BASE, file)

    if not os.path.exists(path):
        print("Не найден:", path)
        return

    subprocess.run([sys.executable, path])


while True:
    print("\n=== LAUNCHER ===")
    for k, v in APPS.items():
        print(k, "-", v[0])
    print("0 - выход")

    c = input("> ")

    if c == "0":
        break
    elif c in APPS:
        run(APPS[c][1])
