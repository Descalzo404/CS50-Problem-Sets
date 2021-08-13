#include <cs50.h>
#include <stdio.h>

int checksumf(long number, int digitscount);
int digitsf(long number);
int first_two_digitsf(long number);

int main(void)
{
    // Getting all the values and storing in 
    long credit_card = get_long("What is your credit card number?\n");
    int digits = digitsf(credit_card);
    int checksum = checksumf(credit_card, digits);
    int first_two_digits = first_two_digitsf(credit_card);
    // Check the cards
    if ((checksum % 10) != 0)
    { 
        printf("INVALID\n");
    }

    // Check if American express
    else if (digits == 15)
    {
        if (first_two_digits == 34 || first_two_digits == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // Check if Mastercard or VISA
    else if (digits == 16)
    {
        if (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54 || first_two_digits == 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((first_two_digits / 10) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // Check if VISA
    else if (digits == 13 && (first_two_digits / 10) == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }


}

// Count the number of digits
int digitsf(long number)
{
    int count = 0;
    do
    {
        count++;
        number /= 10;
    }
    while (number != 0);
    // Return the number of digits
    return count;
}

// Make the Luhn's Algorithm
int checksumf(long number, int digitscount)
{
    int loops = 0;
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;

    while (number)
    {
        if (loops % 2 == 0)
        {
            n1 += (number % 10);
        }
        else
        {
            n2 += 2 * (number % 10);
            do
            {
                n3 += n2 % 10;
                n2 /= 10;
            }
            while (n2 > 0);
        }
        loops ++;
        number /= 10;
    }

    int result = n3 + n1;
    // Return the checksum value
    return result;
}

// Get the two firts digits
int first_two_digitsf(long number)
{
    while (number >= 100)
    {
        number /= 10;
    }
    // First two digits
    return number;
}
