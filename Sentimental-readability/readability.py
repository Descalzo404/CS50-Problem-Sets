from cs50 import get_string


def main():
    text = get_string("Text: ")
    if (Coleman_Liau_index(text) >= 16):
        print("Grade 16+")
    elif (Coleman_Liau_index(text) < 1):
        print("Before Grade 1")
    else:
        print("Grade", Coleman_Liau_index(text))


def Coleman_Liau_index(string):
    stop = ('.', '?', '!')
    words = 0
    letters = 0
    sentences = 0
    checkword = 0
    for c in string:
        if c.isalpha() == True and checkword == 1:
            checkword = 1
            letters += 1

        elif c.isalpha() == True and checkword == 0:
            letters += 1
            checkword = 1
            words += 1

        elif c in stop:
            sentences += 1
            checkword = 0

        elif c == " ":
            checkword = 0

    letters = (100 * letters) / (words)
    sentences = (100 * sentences) / (words)
    index = 0.0588 * letters - 0.296 * sentences - 15.8
    return round(index)

main()

