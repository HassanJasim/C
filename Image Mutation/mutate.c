#include "a4.h"
#include <stdlib.h>

void mutate(Individual *individual , double rate){
    // calculates the size of the image
    int size = individual->image.width*individual->image.height;
    // calculates the number of pixels that need to be changed
    int pixNum = rate/100*size;
    // goes through the image
    for(int i = 0 ; i < pixNum ; i++){
        // generates a random number from 0 -> size of image
        int randomPix = rand() % size;
        // generates a random value for that pixel
        individual->image.data[randomPix].r = rand() % individual->image.max_color + 1;
        individual->image.data[randomPix].g = rand() % individual->image.max_color + 1;
        individual->image.data[randomPix].b = rand() % individual->image.max_color + 1; 
    }
};

void mutate_population(Individual *individual , int population_size , double rate){
    for(int i = population_size/4 ; i < population_size ; i++){
        mutate(individual + i, rate);
    }
};
