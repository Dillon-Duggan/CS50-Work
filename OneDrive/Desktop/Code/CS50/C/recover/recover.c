#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    // Open image file if valid
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file");
        return 2;
    }
    // Store blocks of 512 byes in an array
    unsigned char buffer[512];

    // Keep track of number of images generated
    int imgcount = 0;

    // Pointer to file for recovered images
    FILE *output = NULL;

    // Allocate memory for char filename[8]
    char *filename = malloc(8 * sizeof(char));

    // Read the blocks of 512 bytes
    while (fread(buffer, sizeof(char), 512, input))
    {
        // Ensure bytes indicate start of .jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (imgcount > 0)
            {
                fclose(output);
            }
            // Write new jpg filenames
            sprintf(filename, "%03i.jpg", imgcount);

            // Open output to write into
            output = fopen(filename, "w");

            // Add to image counter
            imgcount++;
        }
        // Check if output has been used
        if (output != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output);
        }
    }
    free(filename);
    fclose(output);
    fclose(input);

    return 0;
}