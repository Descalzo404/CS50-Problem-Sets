#include <cs50.h>
#include <stdio.h>

void pyramid(int heigh);

int main(void)
{
    int n;
    //getting a positive integer between 1 through 8
    do
    {
        n = get_int("How tall?\n");
    }
    while (n > 8 || n < 1);
    //Printing the pyramid
    pyramid(n);
}

//Building the pyramids
void pyramid(int heigh)
{
    //Running the lines
    for (int i = 0; i < heigh; i++)
    {
        //Running the columns first pyramid
        for (int j = 0; j < heigh; j++)
        {
            if (j < (heigh - (i + 1)))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
            
        }
        //Making the space between pyramids
        printf("  ");
        //Runing the columns second pyramid
        for (int j2 = 0; j2 < heigh; j2++)
        {
            if (i >= j2)
            {
                printf("#");
            }
            else
            {
                printf("");
            }
        }

        printf("\n");
    }
}
