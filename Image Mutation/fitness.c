#include "a4.h"
#include <stdlib.h>
#include <math.h>

double comp_distance(const PIXEL *A , const PIXEL *B , int image_size){
    double d = 0;
    for(int i = 0 ; i < image_size; i++){
        d += (A[i].r - B[i].r)*(A[i].r - B[i].r) + (A[i].g - B[i].g)*(A[i].g - B[i].g) + (A[i].b - B[i].b)*(A[i].b - B[i].b);
    };
    return sqrt(d);
};
void comp_fitness_population(const PIXEL * image , Individual *individual , int population_size){
    for(int i = 0 ; i < population_size ; i++){
        individual[i].fitness = comp_distance(image, individual[i].image.data, individual[i].image.width*individual[i].image.height);
        //printf("%f\n", individual[i].fitness);
    };
};