#include <math.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            int avg =
                (round) ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) /
                         3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            copy[i][j] = image[i][j];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            int red = round(.393 * copy[i][j].rgbtRed + .769 * copy[i][j].rgbtGreen +
                            .189 * copy[i][j].rgbtBlue);
            if (red > 255)
                red = 255;

            image[i][j].rgbtRed = red;

            int green = round(.349 * copy[i][j].rgbtRed + .686 * copy[i][j].rgbtGreen +
                              .168 * copy[i][j].rgbtBlue);
            if (green > 255)
                green = 255;

            image[i][j].rgbtGreen = green;

            int blue = round(.272 * copy[i][j].rgbtRed + .534 * copy[i][j].rgbtGreen +
                             .131 * copy[i][j].rgbtBlue);
            if (blue > 255)
                blue = 255;

            image[i][j].rgbtBlue = blue;
        }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            copy[i][j] = image[i][j];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            int avgr = 0, avgg = 0, avgb = 0, surr_pixs = 0;
            for (int k = max(0, i - 1); k <= min(height - 1, i + 1); k++)
                for (int l = max(0, j - 1); l <= min(width - 1, j + 1); l++)
                {
                    avgr += copy[k][l].rgbtRed;
                    avgg += copy[k][l].rgbtGreen;
                    avgb += copy[k][l].rgbtBlue;
                    surr_pixs++;
                }
            avgr = round((float) avgr / surr_pixs);
            avgg = round((float) avgg / surr_pixs);
            avgb = round((float) avgb / surr_pixs);

            image[i][j].rgbtRed = avgr;
            image[i][j].rgbtGreen = avgg;
            image[i][j].rgbtBlue = avgb;
        }
    return;
}
