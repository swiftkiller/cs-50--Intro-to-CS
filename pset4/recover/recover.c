#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *inptr = argv[1] ;

    // Open input file
    FILE *card = fopen(inptr, "r") ;

    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", inptr);
        return 2;
    }
    // Makeing buffer
    uint8_t buffer[512] ;

    // Opening image file
    FILE *pic ;
    int c = 0 ;
    int f = 0 ;
    while (fread(buffer, sizeof(buffer), 1, card) == 1)
    {
        // Check if buffer is jpeg or not
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (f == 1)
            {
                fclose(pic), f = 0 ;
            }
            char file[] = "image.jpg" ;
            char *filename = file ;
            f = 1 ;
            sprintf(filename, "%03i.jpg", c++);
            pic = fopen(filename, "w") ;
        }
        // Checking if jpeg file is open or not
        if (f == 1)
        {
            fwrite(buffer, sizeof(buffer), 1, pic) ;
        }
    }

    return 0 ;
}
