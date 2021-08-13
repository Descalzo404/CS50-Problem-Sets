#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

//defining the type byte
typedef uint8_t BYTE;

//defining the size of the block
#define block 512
//defining the size of the file name
#define filenamesize 8

bool is_start_of_jpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    //if it has no command-line argument
    if (argc != 2)
    {
        printf("Missing command-line argument!\n");
        return 1;
    }
    FILE *inside_file = fopen(argv[1], "r");
    //if there is no file
    if (inside_file == NULL)
    {
        printf("Missing file!\n");
        return 1;
    }
    
    BYTE buffer[block];
    bool found_first_jpeg = false;
    int number_of_files = 0;
    FILE *jpeg;
    //reading the file and restoring the jpegs
    while (fread(buffer, block, 1, inside_file))
    {
        //starts or close a jpeg file
        if (is_start_of_jpeg(buffer))
        {
            if (!found_first_jpeg)
            {
                found_first_jpeg = true;
            }
            else
            {
                fclose(jpeg);
            }
                
            char filename[filenamesize];
            sprintf(filename, "%03i.jpg", number_of_files++);
            jpeg = fopen(filename, "w");
            if (jpeg == NULL)
            {
                return 1;
            }
            fwrite(buffer, block, 1, jpeg);
        }
        //keeps writing in the same jpeg file
        else if (found_first_jpeg)
        {
            fwrite(buffer, block, 1, jpeg);
        }
    }
    fclose(jpeg);
    fclose(inside_file);

}
//check if it is the beggining of a jpeg
bool is_start_of_jpeg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

}
