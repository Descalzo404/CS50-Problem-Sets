from cs50 import get_int

# Getting the height
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

for i in range(height):
    # First pyramid
    for j in range(height):
        if j < (height - (i + 1)):
            print(" ", end="")
        else:
            print("#", end="")
    # Space between pyramids
    print("  ", end="")

    # Second pyramid
    for j2 in range(height):
        if j2 <= i:
            print("#", end="")
        else:
            print("", end="")
    print("")