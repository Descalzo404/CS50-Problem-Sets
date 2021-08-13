#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get the name of the user
    string name = get_string("What is your name?\n");
    //prints his name
    printf("hello, %s\n", name);
}
