from cs50 import get_int


def main():
    height = get_height()
    width = height - 1
    i = 0
    j = 0

    while (width != 0):
        for j in range(width):
            print(" ", end="")
        for i in range(height - width):
            print("#", end="")
        print("  ", end="")
        for i in range(height-width):
            print("#", end="")
        print()
        width -= 1
    for i in range(height):
        print("#", end="")
    print("  ", end="")
    for i in range(height):
        print("#", end="")
    print()


def get_height():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            return n


main()