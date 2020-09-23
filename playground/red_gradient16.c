#include "../BMP.c"

int main() {
    struct BMP * image = BMP_create(320, 320, 16, 0);

    int height = BMP_getheight(image);
    int width = BMP_getwidth(image);

    struct Color16 color = {0};

    for (int row = height-1; row >= 0; row--) 
    {
        if (row % 10 == 0) 
        {
            color.red++;
        }

        for (int col = 0; col < width; col++) 
        {
            BMP_set_pixel(image, row, col, (void *) &color);
        }
    }   

    BMP_save(image, "red_gradient16.bmp");
    return 0;
}
