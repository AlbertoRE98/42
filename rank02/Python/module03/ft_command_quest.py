import sys


def main():

    print("====Command Quest====")
    print("Program name: ft_command_quest.py")
    if (len(sys.argv) <= 1):
        print("No arguments provided.")
    else:
        print("Arguments provided:")
        for i, arg in enumerate(sys.argv):
            print(f"Argument {i}: {arg}")
    print("Total Arguments:", len(sys.argv))


if __name__ == "__main__":
    main()
