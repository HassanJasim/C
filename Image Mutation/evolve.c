#include "a4.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int compare(const void *a, const void *b){
    Individual *first = (Individual *)a;
    Individual *second = (Individual *)b;
   return (first->fitness - second->fitness);
};
PPM_IMAGE *evolve_image(const PPM_IMAGE *image , int num_generations , int population_size , double rate){
    srand(time(NULL));
    // generates a random population of population_size
    // Individual *population = malloc(sizeof(Individual)*population_size);
    Individual *population = generate_population(population_size, image->width, image->height, image->max_color);
    // computes the fitness of each individual
    comp_fitness_population(image->data, population, population_size);
    // sorts the individuals in non-decreasing order of fitness. The first individual will have
    // the closest distance to the original image, and it is the most “fitted”
    qsort(population, population_size, sizeof(Individual), compare);
    // goes through the generation
    for(int i = 0 ; i < num_generations ; i++){
        printf("Gen: %d\t", i);
        // does a crossover on the population
        crossover(population, population_size);
        // mutates individuals from population_size/4 to population_size-1.
        mutate_population(population, population_size, rate);
        // computes the fitness of each individual in the population
        comp_fitness_population(image->data, population, population_size);
        // sorts the individuals in non-decreasing order of fitness value
        qsort(population, population_size, sizeof(Individual), compare);
        if(rate >= 1e-2){
            rate -= 0.000025;
        }
        printf("Fitness: %f\n", population[0].fitness);
    }
    for(int i = 1 ; i < num_generations ; i++){
        free_image(&population[i].image);
    }
    // retunrs the PPM image
    PPM_IMAGE *returnImage = &population[0].image;
    return returnImage;
};


void free_image(PPM_IMAGE *p){
    free(p);
};