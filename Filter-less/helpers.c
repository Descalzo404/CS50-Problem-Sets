#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE nimage = image[i][j];
            //getting the average of gray
            int grayscale = round((nimage.rgbtRed + nimage.rgbtBlue + nimage.rgbtGreen) / 3.0);
            image[i][j].rgbtRed = grayscale;
            image[i][j].rgbtBlue = grayscale;
            image[i][j].rgbtGreen = grayscale;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            //getting the sepiared
            int sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.189 * image[i][j].rgbtBlue) + (0.769 * image[i][j].rgbtGreen));
            //checking if it pass 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            //getting the sepiagreen
            int sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.168 * image[i][j].rgbtBlue) + (0.686 * image[i][j].rgbtGreen));
            //checking if it pass 255
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            //getting the sepiablue
            int sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.131 * image[i][j].rgbtBlue) + (0.534 * image[i][j].rgbtGreen));
            //checking if it pass 255
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;


        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //getting a copy
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = temp;


        }
    }

    return;
}

//function that gets the average of the surrouding pixels and turns the chosen pixel to that color
RGBTRIPLE b_pixel(int line, int column, int height, int width, RGBTRIPLE image[height][width])
{
    float red = 0;
    float green = 0;
    float blue = 0;
    int counter = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int real_i = line + i;
            int real_j = column + j;
            //checking the boundaries
            if (real_i >= 0 && real_j >= 0 && real_i < height && real_j < width)
            {
                counter ++;
                red += image[real_i][real_j].rgbtRed;
                green += image[real_i][real_j].rgbtGreen;
                blue += image[real_i][real_j].rgbtBlue;
            }
        }
    }
    //setting the pixel to the average color
    RGBTRIPLE b_pixel;
    b_pixel.rgbtRed = round(red / counter);
    b_pixel.rgbtGreen = round(green / counter);
    b_pixel.rgbtBlue = round(blue / counter);
    return b_pixel;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newimage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            newimage[i][j] = b_pixel(i, j, height, width, image);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[i][j] = newimage[i][j];
        }
    }
    return;
}
