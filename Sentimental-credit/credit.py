from cs50 import get_int
import math

# Defining main function
def main():
    creditcardnumber = get_int ("Number: ")
    size = sizeofcard(creditcardnumber)
    first2 = first_two_digits (creditcardnumber)
    checksum = luhns_algorithm(creditcardnumber)
    s = check(size, first2, checksum)
    print(s)




# Getting the length of the credit card
def sizeofcard(number):
    return len(str(number))

# Getting the first 2 digits, i found this function in stackoverflow
def first_two_digits (number):
    return number // 10 ** (int(math.log(number, 10)) - 2 + 1)

# Getting the value of Luhn's Algorithm
def luhns_algorithm(number):
    loops = 0
    other_digit = 0
    other_digit_sum = 0
    digits = 0
    while number:
        if (loops % 2) == 0:
            digits += (number % 10)
        else:
            other_digit = 2 * (number % 10)
            other_digit_sum += (other_digit % 10)
            other_digit = int(other_digit / 10)
            while other_digit > 0:
                other_digit_sum += (other_digit % 10)
                other_digit = int(other_digit / 10)
        loops += 1
        number = int(number / 10)
    sumdigits = other_digit_sum + digits
    return sumdigits

# Checking the creditcards
def check(size, first2digits, checksum):
    if (checksum % 10) != 0:
        s = "INVALID"
        return s
    elif size == 15 and (first2digits == 34 or first2digits == 37):
        s = "AMEX"
        return s
    elif size == 16 and (first2digits == 51 or first2digits == 52 or first2digits == 53 or first2digits == 54 or first2digits == 55):
        s = "MASTERCARD"
        return s
    elif (size == 16 or size == 13) and int(first2digits / 10) == 4:
        s = "VISA"
        return s
    else:
        s = "INVALID"
        return s

# Running the program
main()