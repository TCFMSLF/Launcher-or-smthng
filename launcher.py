import subprocess
import os

BASE = os.path.dirname(os.path.abspath(__file__))

APPS = {
    "1": ("Exex", "Exex.c"),
    "2": ("Secure", "Secure.c"),
    "3": ("sesEf", "sesEf.c")
}

def compile_and_run(source_file):
    source_path = os.path.join(BASE, source_file)
    output_file = source_file.replace(".c", "")

    output_path = os.path.join(BASE, output_file)

    if not os.path.exists(source_path):
        print("Файл не найден:", source_path)
        return

    print(f"[INFO] Компиляция {source_file}...")

    compile_result = subprocess.run([
        "gcc",
        source_path,
        "-o",
        output_path
    ])

    if compile_result.returncode != 0:
        print("[ERROR] Ошибка компиляции")
        return

    print(f"[INFO] Запуск {output_file}...\n")

    subprocess.run([output_path])


while True:
    print("\n=== C LAUNCHER ===")

    for key, (name, _) in APPS.items():
        print(f"{key} - {name}")

    print("0 - выход")

    choice = input("> ")

    if choice == "0":
        break
    elif choice in APPS:
        name, file = APPS[choice]
        compile_and_run(file)
    else:
        print("Ошибка ввода")