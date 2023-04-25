#include <iostream>
// #include<zlib.h>
// #include <libpng12/png.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib-libpng.h"

using namespace std;

int main(int argc, char *argv[])
{
    int width = 0, height = 0;
    int rowbytes = 0;
    if (argc != 2)
    {
        cout << "usage: " << argv[0] << " filename" << endl;
        return 1;
    }
    cout << "work on: " << argv[1] << endl;
    /* Read png file */
    png_bytepp image_data = read_png_file(argv[1], &rowbytes, &width, &height);

    /* Write png file */
    const char *output_png_file = "copy.png";
    if (!write_png_file(output_png_file, image_data, width, height))
    {
        fprintf(stderr, "error writing into .png file\n");
    }
    else
    {
        fprintf(stdout, "Check output %s file\n", output_png_file);
    }

    // done with it, free image data memory space
    free_image_data(image_data, height);
    // reset values
    width = 0;
    height = 0;
    rowbytes = 0;
    return 0;
}