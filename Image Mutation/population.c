#include "a4.h"
#include <stdlib.h>

PIXEL *generate_random_image (int width , int height , int max_color){
    PIXEL *array = malloc(sizeof(PIXEL)*width*height);
    for(int i = 0 ; i < height*width ; i++){
        array[i].r = rand() % max_color + 1;
        array[i].g = rand() % max_color + 1;
        array[i].b = rand() % max_color + 1;
    }
    return array;
};
Individual *generate_population (int population_size , int width , int height , int max_color){
    Individual *population_array = malloc(sizeof(Individual)*population_size);
    for(int i = 0; i < population_size; i++){
        population_array[i].image.width = width;
        population_array[i].image.height = height;
        population_array[i].image.max_color = max_color;
        population_array[i].image.data = generate_random_image(width , height , max_color);
    }
    return population_array;
};

// int main(int argc, char const *argv[])
// {
//     Individual *p;
//     p = generate_population(10, 5, 5, 35);
//     return 0;
// }
