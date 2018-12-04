#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

PPM_IMAGE *read_ppm(const char *file_name){
    // opens the file
    FILE *file = fopen(file_name , "r");
    // Program exits if file pointer returns NULL.
    if (file == NULL){
        printf("Error! opening file");
        exit(1);
    }
    // allocates memory for the image
    PPM_IMAGE *image = malloc(sizeof(PPM_IMAGE));
    // stores values from file into the image structure
    fscanf(file,"P3\n%d %d\n%d\n", &image->width, &image->height, &image->max_color);
    // creating an array of type PIXELs
    PIXEL *pixel_data = malloc(sizeof(PIXEL)*image->width*image->height);
    // store the value of width and height into a variable
    int width = image->width;
    int height = image->height;
    // sets the pointer to the beginning of the array
    image->data = &pixel_data[0];
    // iterates through the file and stores the value in an array of structs
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){  
            fscanf(file,"%hhu %hhu %hhu", &pixel_data[i*(width)+j].r, &pixel_data[i*(width)+j].g, &pixel_data[i*(width)+j].b);
        }
        fscanf(file, "\n");
    }
    // closes the file
    fclose(file);
    // returns the image
    return image;
};
void write_ppm(const char *file_name , const PPM_IMAGE *image){
    // opens the file
    FILE *file = fopen(file_name , "w");
    // prints file header
    fprintf(file, "P3\n%d %d\n%d\n", image->width, image->height,image->max_color);
    // store the value of width and height into a variable
    int width = image->width;
    int height = image->height;
    // prints the rest of the values
    for(int i = 0 ; i < height*width ; i++){
        fprintf(file,"%d %d %d ", image->data[i].r, image->data[i].g, image->data[i].b);
    }
    // closes the file
    fclose(file);
};

