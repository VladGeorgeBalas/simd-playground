#include <stdio.h>
#include <stdint.h>
// #include <stdlib.h>

struct __attribute__((packed)) uint24_t { unsigned long v:24; };
typedef struct uint24_t uint24_t;

typedef struct __attribute__((packed)) bmp_file{
    uint8_t header_field[2];
    uint32_t file_size;
    uint16_t reserved_data_0;
    uint16_t reserved_data_1;
    uint32_t data_offset;
} bmp_file;

typedef struct __attribute__((packed)) BITMAPINFOHEADER{
    uint32_t size_of_header;
    uint32_t bitmap_width;
    uint32_t bitmap_height;
    uint16_t color_planes;
    uint16_t bits_per_pixel;
    uint32_t compresion_method;
    uint32_t image_size;
    uint32_t horizontal_rezolution;
    uint32_t vertical_rezolution;
    uint32_t number_of_colors;
    uint32_t number_of_important_colors;
}BITMAPINFOHEADER;

// PLACEHOLDER - aici vine functia scrisa in assembly
extern int my_func(int a, int b);

int main(){
    bmp_file my_bmp;
    BITMAPINFOHEADER my_BITMAPINFOHEADER;

    char img_file_path[] = "test.bmp";
    FILE* img_file = fopen(img_file_path, "rb");

    fseek(img_file, 0, SEEK_SET);
    fread(&my_bmp, sizeof(bmp_file), 1, img_file);

    fseek(img_file, 14, SEEK_SET);
    fread(&my_BITMAPINFOHEADER, sizeof(my_BITMAPINFOHEADER), 1, img_file);

    printf("%c%c \n", my_bmp.header_field[0], my_bmp.header_field[1]);
    printf("%u \n", my_bmp.file_size);
    printf("%u \n", my_bmp.data_offset);

    printf("%u \n", my_BITMAPINFOHEADER.bits_per_pixel);
    printf("%u \n", my_BITMAPINFOHEADER.image_size);

    void* raw_image_data;
    if(my_BITMAPINFOHEADER.bits_per_pixel == 24){
        uint24_t raw_image_data[my_BITMAPINFOHEADER.bitmap_height][my_BITMAPINFOHEADER.bitmap_width];

        fseek(img_file, my_bmp.data_offset, SEEK_SET);
        fread(raw_image_data, my_BITMAPINFOHEADER.image_size / 3, 1, img_file);

        printf("%d \n", my_func(0, 0));
    }

    return 0;
}
